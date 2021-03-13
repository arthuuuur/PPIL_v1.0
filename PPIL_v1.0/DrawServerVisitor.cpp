#include "DrawServerVisitor.h"
#include "ShapesManager.h"
#include "ServerConnection.h"

void DrawServerVisitor::visite(ShapesManager& Sm) 
{
	try 
	{
		ServerConnection* client;
		client = ServerConnection::getInstance();
		client->openConnection();
		int err;
		char cstr[BUFSIZ];
		string str;
		for (vector<Shape*>::const_iterator it = Sm.getListShape().begin(); it != Sm.getListShape().end(); it++) 
		{
			str = (*it)->serialize(); 
			strcpy_s(cstr, sizeof(cstr), str.c_str());
			strcat_s(cstr, "\r\n");
			err = send(ServerConnection::getInstance()->getSocket(), cstr, (int)strlen(cstr), 0);
			if (err == SOCKET_ERROR) throw Error("failure to send the requeste");
		}
		vector<Shape*> groupShape = Sm.getGroupShape(); 
		for (vector<Shape*>::iterator it = groupShape.begin(); it != groupShape.end(); it++) 
		{
			vector<Shape*> shapeOfGroup = dynamic_cast<Group*>(*it)->getList();
			for (vector<Shape*>::iterator itbis = shapeOfGroup.begin(); itbis != shapeOfGroup.end(); itbis++) 
			{
				str = (*itbis)->serialize(); 
				strcpy_s(cstr, sizeof(cstr), str.c_str());
				strcat_s(cstr, "\r\n");
				err = send(ServerConnection::getInstance()->getSocket(), cstr, (int)strlen(cstr), 0);
				if (err == SOCKET_ERROR) throw Error("failure to send the requeste");
			}
		}
		client->closeConnection();
	}
	catch (exception const& err) 
	{
		cout << err.what() << endl;
		exit(-1);
	}
}