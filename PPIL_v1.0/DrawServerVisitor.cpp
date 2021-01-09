#include <iostream>
#include <sstream>
#include "DrawServerVisitor.h"
#include "ShapesManager.h"

void DrawServerVisitor::visite(ShapesManager Sm) {
	try {
		vector<Shape*> tmp = Sm.getListShape();
		for (vector<Shape*>::iterator it = tmp.begin(); it != tmp.end(); it++) {
			//(*it)->draw();
			int err;
			string str = (*it)->serialize();
			//cout << str << endl;
			char cstr[BUFSIZ];
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
		vector<Group*> tmp2 = Sm.getGroupShape();
		for (vector<Group*>::iterator it = tmp2.begin(); it != tmp2.end(); it++) {
			vector<Shape*> tmp3 = (*it)->getList();
			for (vector<Shape*>::iterator itbis = tmp3.begin(); itbis != tmp3.end(); itbis++) {
				//(*it)->draw();
				int err;
				string str = (*itbis)->serialize();
				//cout << str << endl;
				char cstr[BUFSIZ];
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
		}
	}
	catch (exception const& err) {
		cout << err.what() << endl;
		exit(-1);
	}
}