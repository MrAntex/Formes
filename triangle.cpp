#include "triangle.h"
#include <cmath>


Triangle::Triangle(Point _ancre, Point _a2, Point _a3, Color coul)
	: Forme(_ancre, coul), a2(_a2), a3(_a3)
{}

Triangle::Triangle(const Triangle& orig) : Triangle(orig.getPoint().getAncre(), orig.a2, orig.a3, orig.getColor())
{}

Triangle::~Triangle(){}

void Triangle::dessiner(RenderWindow& fenetre, bool isactive) const
{
		ConvexShape triangle;
		triangle.setPointCount(3);
		triangle.setPoint(0, getPoint().getAncre());
		triangle.setPoint(1, a2.getAncre());
		triangle.setPoint(2, a3.getAncre());
		triangle.setFillColor(getColor());
		triangle.setOutlineThickness(getEpaiss());
		triangle.setOutlineColor(getCoulBord());
		fenetre.draw(triangle);
		Forme::dessiner(fenetre, isactive);
}

bool Triangle::isOver(Vector2f curseur)
{
	// distances entre chaque point du triangle
	double b = sqrt(pow((a2.getAncre().x - getPoint().getAncre().x), 2) + pow((a2.getAncre().y - getPoint().getAncre().y), 2));
	double c = sqrt(pow((a2.getAncre().x - a3.getAncre().x), 2) + pow((a2.getAncre().y - a3.getAncre().y), 2));
	double a = sqrt(pow((getPoint().getAncre().x - a3.getAncre().x), 2) + pow((getPoint().getAncre().y - a3.getAncre().y), 2));

	// distances Curseur <-> Points du triangle
	double Cb = sqrt(pow((a3.getAncre().x - curseur.x), 2) + pow((a3.getAncre().y - curseur.y), 2));
	double Cc = sqrt(pow((getPoint().getAncre().x - curseur.x), 2) + pow((getPoint().getAncre().y - curseur.y), 2));
	double Ca = sqrt(pow((a2.getAncre().x - curseur.x), 2) + pow((a2.getAncre().y - curseur.y), 2));

	// calculs des angles
	double ang_A = acos((pow(Cc, 2) + pow(Cb, 2) - pow(a, 2)) / (2 * Cc * Cb));
	double ang_B = acos((pow(Ca, 2) + pow(Cc, 2) - pow(b, 2)) / (2 * Ca * Cc));
	double ang_C = acos((pow(Ca, 2) + pow(Cb, 2) - pow(c, 2)) / (2 * Ca * Cb));

	double deg_A = ang_A * (180 / 3.1415926535f);
	double deg_B = ang_B * (180 / 3.1415926535f);
	double deg_C = ang_C * (180 / 3.1415926535f);

	if ((deg_A <= (deg_B + deg_C + 1) && deg_A >= (deg_B + deg_C - 1)) || (deg_B <= (deg_A + deg_C +1) && deg_B >= (deg_A + deg_C -1)) || (deg_C <= (deg_A + deg_B +1) && deg_C >= (deg_A + deg_B - 1))) {
		//cout << "dehors" << endl;
		//cout << "Ang A : " << deg_A << endl << "Ang B : " << deg_B << endl << "Ang C : " << deg_C << endl << endl;

		return false;
	}
	else {
		//cout << "dedans" << endl;
		//cout << "Ang A : " << deg_A << endl << "Ang B : " << deg_B << endl << "Ang C : " << deg_C << endl << endl;

		return true;


	}

}
Vector2f Triangle::Size(Vector2f curseur)
{
	return Vector2f();
}

bool Triangle::modif(Vector2f curseur)
{
	return false;
}

void Triangle::move(Vector2f mouse)
{
	a2 = a2.getAncre() + (mouse - getPoint().getAncre());
	a3 = a3.getAncre() + (mouse - getPoint().getAncre());
	setPoint(mouse);
}
	
Vector2f Triangle::getCentre() {
	return (Vector2f((a2.getAncre().x + a3.getAncre().x + getPoint().getAncre().x) / 3, (a2.getAncre().y + a3.getAncre().y + getPoint().getAncre().y) / 3));
}