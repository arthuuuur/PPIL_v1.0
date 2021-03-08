#include <iostream>
#include <sstream>
#include "DrawServerVisitor.h"
#include "ShapesManager.h"
#include "ServerConnection.h"

void DrawServerVisitor::visite(ShapesManager& Sm) 
{
	try {
		int err;
		char cstr[BUFSIZ];
		char reponse[BUFSIZ];
		string str;
		for (vector<Shape*>::const_iterator it = Sm.getListShape().begin(); it != Sm.getListShape().end(); it++) {
			
			str = (*it)->serialize(); 
			strcpy_s(cstr, sizeof(cstr), str.c_str());
			strcat_s(cstr, "\r\n");
			err = send(ServerConnection::getInstance()->getSocket(), cstr, strlen(cstr), 0);
			if (err == SOCKET_ERROR) {
				throw Error("failure to send the requeste");
			}
			char reponse[BUFSIZ];
			err = recv(ServerConnection::getInstance()->getSocket(), reponse, strlen(cstr), 0);
			if (err == SOCKET_ERROR) {
				throw Error("failure to receive the response");
			}
			char* p = strchr(reponse, '\n');
			*p = '\0';
			cout << reponse << endl;
		}
		vector<Shape*> groupShape = Sm.getGroupShape(); 
		for (vector<Shape*>::iterator it = groupShape.begin(); it != groupShape.end(); it++) {
			vector<Shape*> shapeOfGroup = dynamic_cast<Group*>(*it)->getList();
			for (vector<Shape*>::iterator itbis = shapeOfGroup.begin(); itbis != shapeOfGroup.end(); itbis++) {
				str = (*itbis)->serialize(); 
				strcpy_s(cstr, sizeof(cstr), str.c_str());
				strcat_s(cstr, "\r\n");
				err = send(ServerConnection::getInstance()->getSocket(), cstr, strlen(cstr), 0);
				if (err == SOCKET_ERROR) {
					throw Error("failure to send the requeste");
				}
				err = recv(ServerConnection::getInstance()->getSocket(), reponse, strlen(cstr), 0);
				if (err == SOCKET_ERROR) {
					throw Error("failure to receive the response");
				}
				char* p = strchr(reponse, '\n');
				*p = '\0';
				cout << reponse << endl;
			}
		}
	}
	catch (exception const& err) {
		cout << err.what() << endl;
		exit(-1);
	}
}