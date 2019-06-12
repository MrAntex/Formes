#include "Forme.h"



Forme::Forme(Point _pt, Color coul) 
	: pt(_pt), couleur(coul){}

Forme::Forme(istream & is)
	: pt(is)
{
	is >> couleur.r;
	is >> couleur.g;
	is >> couleur.b;
}

Forme::Forme(Forme const & orig) 
	: pt(orig.pt), couleur(orig.couleur) {}


void Forme::ecrire(ostream & os) const
{
	os << couleur.r << " " << couleur.g << " " << couleur.b << " " << pt.getAncre().x << " " << pt.getAncre().y;
}

Forme* Forme::charger(istream & is)
{
	string type;
	is >> type;
	if (type == "Rectangle ")
		return new Rectangle(is);
	if (type == "Cercle ")
		return new Cercle(is);
	if (type == "Triangle ")
		return new Triangle(is);
	if (type == "Ellipse ")
		return new Ellipse(is);
}


Forme::~Forme() {}


void Forme::dessiner(RenderWindow& fenetre, bool isactive) const
{
	pt.dessiner(fenetre, isactive);	
}

