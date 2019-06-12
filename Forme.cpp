#include "Forme.h"


Forme::Forme(Point _pt, Color coul) 
	: pt(_pt), couleur(coul), rempli(true), couleur2(coul), coulBord(coul),coulBord2(coul),  epaiss(4), flash(false), pulse(false), b_epaiss(4), a_coul(false){}

Forme::Forme(Forme const & orig) 
	: pt(orig.pt), couleur(orig.couleur), rempli(orig.rempli) {}

Forme::~Forme() {}

/*
bool Forme::isOver(Vector2f curseur)
{
	Vector2f ancre2 = Vector2f(pt.getAncre().x + 7, pt.getAncre().y + 7);
	if (curseur.x > pt.getAncre().x && curseur.y > pt.getAncre().y && curseur.x < ancre2.x && curseur.y < ancre2.y)
	{
		pt.setColor(Color::Blue);
		cout << "souris";
		return true;

	}
	else
	{
		pt.setColor(Color::Black);

		return false;
	}
}*/

void Forme::dessiner(RenderWindow& fenetre, bool isactive) const
{
	pt.dessiner(fenetre, isactive);	
}




void Forme::swaPlein() {
	if (rempli) {
		couleur = Color::Transparent;

	}
	else {
		couleur = couleur2;
	}
	rempli = !rempli;
}