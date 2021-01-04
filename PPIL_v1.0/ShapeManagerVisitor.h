#pragma once

class ShapesManager;


class ShapeManagerVisitor{

	public:
	
		virtual void visite(ShapesManager Sm) = 0;	
};