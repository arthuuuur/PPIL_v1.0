#pragma once

#include <iostream>
#include <sstream>
#include <mutex>
#include <winsock2.h>
#include <WS2tcpip.h>
#pragma comment(lib, "ws2_32.lib")

#include "Error.h"

using namespace std;

/**
* v1 singleton pattern to initialize only once this class to have only one communication with the server
*/
class ServerConnection {

private:

	/**
	* ServerConnection's constructor
	*
	* Initialize the WSADATA structure
	*/
	ServerConnection();

	/**
	* The only instance of this class
	*/
	static ServerConnection* _client;
	/**
	* To ensure mutual exclusion if two threads want to instantiate this class at the same time
	*/
	static mutex _mutex;

public:

	/**
	* The socket for communicate with the server
	*/
	SOCKET _sock;

	/**
	* ~ServerConnection
	* 
	* Clear the WSADATA structure
	*/
	~ServerConnection();

	/**
	* This class should not be cloneable
	*/
	ServerConnection(ServerConnection& other) = delete;

	/**
	* This class should not be assignable
	*/
	void operator=(const ServerConnection&) = delete;

	/**
	* This is the method that create the only object of this class on the first run.
	* On subsequents runs, it returns the existing object stored in the static field
	*
	* @return {ServerConection*}  : The only instance of this class
	*/
	static ServerConnection* getInstance();

	/**
	* Create and open the connection to the server
	*/
	void openConnection();

	/**
	* Close the socket and the connection to the server
	*/
	void closeConnection();

	/**
	* Getter of _sock
	* 
	* @return {SOCKET}  : The socket structure
	*/
	SOCKET getSocket();
};
