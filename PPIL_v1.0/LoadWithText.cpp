#include "LoadWithText.h"
#include "ShapesManager.h"
#include "SegmentDetector.h"
#include "CircleDetector.h"
#include "PolygonDetector.h"

LoadWithText::LoadWithText(string fileName) : _fileName(fileName)
{
	ShapeDetector* Segment = new SegmentDetector(NULL);
	ShapeDetector* Circle = new CircleDetector(Segment);
	ShapeDetector* Polygon = new PolygonDetector(Circle);
	cor = Polygon;
}

LoadWithText::~LoadWithText()
{
	free(cor);
}

void LoadWithText::visite(ShapesManager& Sm)
{
	try 
	{
		ifstream save(_fileName);
		if (!save) throw Error("failed to open file");
		string line;
		while (getline(save, line)) 
		{
			Shape* var =cor->charge(line);
			if (var != NULL) 
			{
				if (var->getID() != var->getGroupID()) 
				{ 
					bool here = false;
					for (vector<Shape*>::const_iterator it = Sm.getGroupShape().begin(); it != Sm.getGroupShape().end(); it++) 
					{ 
						if ((*it)->getID() == var->getGroupID()) 
						{
							here = true;
							if (here) {
								dynamic_cast<Group*>(*it)->addShape(var);
							}
						}
					}
					if (!here) 
					{
						Group* G = new Group(var->getColorIfGrouped());
						G->setGroupID(var->getGroupID());
						G->setID(var->getGroupID());
						G->addShape(var);
						Sm.addGroup(G);
						here = false;
					}
				}
				else 
				{
					Sm.addShape(var);
				}
			}
			else 
			{
				throw Error("the file contains an unknown shape");
			}
		}
	}
	catch (exception const& err) 
	{
		cout << err.what() << endl;
		exit(-1);
	}
}

