#include "triangle.h"


Triangle::Triangle(Point _ancre, Point _a2, Point _a3, Color coul)
	: Forme(_ancre, coul), a2(_a2), a3(_a3)
{}

Triangle::Triangle(const Triangle& orig) : Triangle(orig.getPoint().getAncre(), orig.a2, orig.a3, orig.getColor())
{}

void Triangle::dessiner(RenderWindow& fenetre, bool isactive) const
{
		ConvexShape triangle;
		triangle.setPointCount(3);
		triangle.setPoint(0, getPoint().getAncre());
		triangle.setPoint(1, a2.getAncre());
		triangle.setPoint(2, a3.getAncre());
		triangle.setFillColor(getColor());
		fenetre.draw(triangle);
		Forme::dessiner(fenetre, isactive);
}
