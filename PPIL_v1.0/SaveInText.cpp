#include "SaveInText.h"



void SaveInText::visite(ShapesManager& Sm)
{
	try 
	{
		ofstream save(_fileName);
		if (!save) throw Error("failed to create a save file");
		for (vector<Shape*>::const_iterator it = Sm.getListShape().begin(); it != Sm.getListShape().end(); it++) 
		{
			save << (*it)->serialize();
			save << "\n";
		}
		for (vector<Shape*>::const_iterator it = Sm.getGroupShape().begin(); it != Sm.getGroupShape().end(); it++) 
		{
			vector<Shape*> tmp = dynamic_cast<Group*>(*it)->getList();
			for (vector<Shape*>::const_iterator itbis = tmp.begin(); itbis != tmp.end(); itbis++) 
			{
				save << (*itbis)->serialize();
				save << "\n";
			}
		}
	}
	catch (exception const& err) 
	{
		cout << err.what() << endl;
		exit(-1);
	}
}
