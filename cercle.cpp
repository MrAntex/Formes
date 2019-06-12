#include "cercle.h"


Cercle::Cercle(Point _ancre,  float _taille, Color coul)
	: Forme(_ancre, coul), taille(_taille)
{}

Cercle::Cercle(istream & is)
	:Forme(is)
{
	is >> taille;
}

Cercle::Cercle(const Cercle& orig) : Cercle(orig.getPoint(), orig.taille, orig.getColor()) {}

Cercle::~Cercle() {}

void Cercle::ecrire(ostream & os)const
{
	os << "Cercle ";
	Forme::ecrire(os);
	os << taille;
}



void Cercle::dessiner(RenderWindow& fenetre, bool isactive) const
{
	CircleShape cercle(taille);
	cercle.setPosition(getPoint().getAncre());
	cercle.setOutlineThickness(6);
	cercle.setOutlineColor(getColor());
	cercle.setFillColor(Color::Transparent);
	fenetre.draw(cercle);

	//Ancre de modification
	Point pt_mod(Vector2f(getPoint().getAncre().x + taille, getPoint().getAncre().y + taille));
	pt_mod.dessiner(fenetre, isactive);
}

bool Cercle::isOver(Vector2f curseur)
{
	Vector2f ancre2 = Vector2f(getPoint().getAncre().x + taille , getPoint().getAncre().y + taille);
		if (taille*taille > ((curseur.x - ancre2.x)*(curseur.x - ancre2.x) + (curseur.y - ancre2.y)*(curseur.y - ancre2.y)))
		{
			return true;
		}
		else
			return false;
}

bool Cercle::modif(Vector2f curseur)
{
	Vector2f ancre2 = Vector2f(getPoint().getAncre().x + taille, getPoint().getAncre().y + taille);
	Vector2f ancre3 = Vector2f(ancre2.x + 8, ancre2.y + 8);
	if (curseur.x > ancre2.x && curseur.y > ancre2.y && curseur.x < ancre3.x && curseur.y < ancre3.y)
	{
		return true;
	}
	else
		return false;
}

Vector2f Cercle::Size(Vector2f curseur)
{
	Vector2f _taille = curseur - getPoint().getAncre();
	setTaille(_taille.x);
	return(_taille);
}
