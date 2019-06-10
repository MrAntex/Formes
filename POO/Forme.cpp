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
