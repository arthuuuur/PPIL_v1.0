#pragma once

#include <iostream>
#include <sstream>
#include <winsock2.h>
#include <WS2tcpip.h>
#pragma comment(lib, "ws2_32.lib")

class ServerConnection {

	public:

		/**
		 * < the structure that contains information about the Windows Sockets implementation
		 */
			WSADATA _wsadata;

		/**
		 * < the socket for communicate with a server
		 */
			SOCKET _sock;

		/**
		 * < the structure that contains information about the adress server, the port, and the protocole 
		 */
			SOCKADDR_IN _sockaddr;

		/**
		 * ServerConnection 
		 * 
		 * initialize the WSADATA structure, the SOCKADDRIN structure and the SOCKET
		 */
			ServerConnection();

		/**
		 * open the connection to the server
		 */
			void openConnection();

		/**
		 * close the connection to the server
		 */
			void closeConnection();
};