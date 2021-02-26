#include "LoadWithText.h"
#include "ShapesManager.h"

void LoadWithText::visite(ShapesManager& Sm)
{
	try {
		ifstream save("save.txt");
		if (!save) throw Error("failed to open file");
		string line;
		while (getline(save, line)) {
			Shape* var = Sm.getCOR()->charge(line);
			if (var != NULL) {
				if (var->getFather() != NULL) { // si une forme appartient à un group
					bool here = false;
					for (vector<Shape*>::const_iterator it = Sm.getGroupShape().begin(); it != Sm.getGroupShape().end(); it++) { // on regarde si le group est deja la
						if ((*it)->getID() == var->getGroupID()) {
							here = true;
							if (here) {
								dynamic_cast<Group*>(*it)->addShape(var);
							}
						}
					}
					if (!here) {
						Group* G = new Group(var->getColorIfGrouped());
						G->setGroupID(var->getID());
						G->setID(var->getGroupID());
						G->addShape(var);
						Sm.addGroup(G);
						here = false;
					}
				}
				else {
					Sm.addShape(var);
				}
			}
			else {
				throw Error("the file contains an unknown shape");
			}
		}
	}
	catch (exception const& err) {
		cout << err.what() << endl;
		exit(-1);
	}
}