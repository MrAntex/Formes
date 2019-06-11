#include "Forme.h"



Forme::Forme(Point _pt, Color coul) 
	: pt(_pt), couleur(coul){}

Forme::Forme(Forme const & orig) 
	: pt(orig.pt), couleur(orig.couleur) {}

Forme::~Forme() {}


void Forme::dessiner(RenderWindow& fenetre, bool isactive) const
{
	pt.dessiner(fenetre, isactive);	
}

Vector2f Forme::Size(Vector2f curseur)
{
	string verif = type(curseur);
	Vector2f coord;

	if(verif == "Rectangle")
	{
		coord = curseur - getPoint().getAncre();
		return coord;
	}
	if(verif == "Cercle")
	{ }
	if(verif == "Triangle")
	{ }
}
