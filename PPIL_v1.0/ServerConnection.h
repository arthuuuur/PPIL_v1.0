#pragma once

#include <iostream>
#include <sstream>
#include <mutex>
#include <winsock2.h>
#include <WS2tcpip.h>
#pragma comment(lib, "ws2_32.lib")

using namespace std;

/**
* A singleton pattern to initialize only once this class to have only one communication with the server
*/
class ServerConnection {
	
	private:
		
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
		* < the structure that contains information about the Windows Sockets implementation
		*/
		WSADATA _wsadata;

		/**
		* < the socket for communicate with the server
		*/
		SOCKET _sock;

		/**
		* < the structure that contains information about the server adress, the port, and the protocole
		*/
		SOCKADDR_IN _sockaddr;

		/**
		* ServerConnection
		*
		* initialize the WSADATA structure, the SOCKADDRIN structure and the SOCKET
		*/
		ServerConnection();

		/**
		* ~ServerConnection
		*/
		~ServerConnection();

	public:
		
		/**
		* This class should not be cloneable
		*/
		ServerConnection(ServerConnection& other) = delete;
		
		/**
		* this class should not be assignable
		*/
		void operator=(const ServerConnection&) = delete;
	
		/**
		* This is the method that create the only object of this class on the first run. 
		* On subsequents runs, it returns the existing object stored in the static field
		* 
		* @return {ServerConection}  : The only instance of this class
		*/
		static ServerConnection* getInstance();

		/**
		* open the connection to the server
		*/
		void openConnection();

		/**
		* close the connection to the server
		*/
		void closeConnection();

		/**
		* @return {SOCKET}  : the socket structure 
		*/
		SOCKET getSocket();
};



