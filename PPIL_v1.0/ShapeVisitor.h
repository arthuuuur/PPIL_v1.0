#pragma once


class Shape;
class Segment;
class Group;
class Circle;

class ShapeVisitor{
	
	public:
	
		virtual void visite(Shape* S) =0;
		virtual void visite(Group* G) =0;
	
};