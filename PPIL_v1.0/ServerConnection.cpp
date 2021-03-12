#include "ServerConnection.h"

using namespace std;

ServerConnection* ServerConnection::_client{ nullptr };
mutex ServerConnection::_mutex;

ServerConnection::ServerConnection() 
{
	try 
	{
		WSADATA wsadata;
		int err = WSAStartup(MAKEWORD(2, 0), &wsadata);
		if (err) throw Error("Initialization failed");
		cout << "Initialization worked" << endl;
	}
	catch (exception const& err) 
	{
		cout << err.what() << endl;
		exit(-1);
	}
}

ServerConnection::~ServerConnection() 
{
	WSACleanup();
	cout << "Normal client stop" << endl;
}

ServerConnection* ServerConnection::getInstance() 
{
	lock_guard<mutex> lock(_mutex);
	if (_client == nullptr)
	{
		_client = new ServerConnection();
	}
	return _client;
}

void ServerConnection::openConnection() 
{
	try
	{
		SOCKET sock;
		sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
		if (sock == INVALID_SOCKET)
		{
			ostringstream flux;
			flux << "Socket creation has failed: error code = " << WSAGetLastError() << endl;
			throw(flux.str().c_str());
		}
		cout << "Socket create" << endl;

		SOCKADDR_IN sockaddr;
		sockaddr.sin_family = AF_INET;
		inet_pton(AF_INET, "127.0.0.1", &sockaddr.sin_addr.s_addr);
		sockaddr.sin_port = htons(9111);
		_sock = sock;
		int err = connect(_sock, (SOCKADDR*)&sockaddr, sizeof(sockaddr));
		if (err == SOCKET_ERROR) throw Error("Connection failed");
		cout << "Connection to the drawing server worked" << endl;
	}
	catch (exception const& err) 
	{
		cout << err.what() << endl;
		exit(-1);
	}
}

void ServerConnection::closeConnection()
{
	try 
	{
		int err;
		err = shutdown(_sock, SD_BOTH);
		if (err == SOCKET_ERROR) {
			throw Error("The shutdown didn't work correctly");
		}
		err = closesocket(_sock);
		if (err) {
			throw Error("the closing of the socket failed");
		}
	}
	catch (exception const& err)
	{
		cout << err.what() << endl;
		exit(-1);
	}
}

SOCKET ServerConnection::getSocket() 
{
	return _sock;
}
