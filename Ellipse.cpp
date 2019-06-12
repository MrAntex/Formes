#include "Ellipse.h"

Ellipse::Ellipse(Point _ancre, Vector2f _taille, Color coul)
	: Forme(_ancre,coul), taille(_taille)
{}

Ellipse::Ellipse(istream & is)
	: Forme(is)
{
	is >> taille.x;
	is >> taille.y;
}

Ellipse::Ellipse(Ellipse const & orig)
	: Ellipse(orig.getPoint(), orig.taille, orig.getColor())
{}

Ellipse::~Ellipse()
{}
void Ellipse::ecrire(ostream & os)
{
	os << "Ellipse ";
	Forme::ecrire(os);
	os << taille.x << " " << taille.y;
}

void Ellipse::dessiner(RenderWindow & fenetre, bool isactive) const
{
	EllipseShape E(taille);
	E.setPosition(getPoint().getAncre());
	E.setOutlineThickness(6);
	E.setOutlineColor(getColor());
	E.setFillColor(Color::Transparent);
	fenetre.draw(E);

	Forme::dessiner(fenetre, isactive);

	//Ancre de modification
	Point pt_mod(Vector2f(getPoint().getAncre().x + taille.x, getPoint().getAncre().y + taille.y));
	pt_mod.dessiner(fenetre, isactive);
	Forme::dessiner(fenetre, isactive);
}

bool Ellipse::isOver(Vector2f curseur)
{
	Vector2f ancre2 = Vector2f(getPoint().getAncre().x + 8, getPoint().getAncre().y + 8);
	if (curseur.x > getPoint().getAncre().x && curseur.y > getPoint().getAncre().y && curseur.x < ancre2.x && curseur.y < ancre2.y)
	{

		return true;

	}
	else
	{
		return false;
	}
}

inline bool Ellipse::modif(Vector2f curseur)
{
	Vector2f ancre2 = Vector2f(getPoint().getAncre().x + taille.x, getPoint().getAncre().y + taille.y);
	Vector2f ancre3 = Vector2f(ancre2.x + 8, ancre2.y + 8);
	if (curseur.x > ancre2.x && curseur.y > ancre2.y && curseur.x < ancre3.x && curseur.y < ancre3.y)
	{
		cout << "coucou";
		return true;
	}
	else
	{
		return false;
	}
}

Vector2f Ellipse::Size(Vector2f curseur)
{
	Vector2f _taille = curseur - getPoint().getAncre();
	setTaille(_taille);
	return(_taille);
}
