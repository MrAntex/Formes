#include "Ellipse.h"

Ellipse::Ellipse(Point _ancre, Vector2f _taille, Color coul)
	: Forme(_ancre,coul), taille(_taille)
{}

Ellipse::Ellipse(Ellipse const & orig)
	: Ellipse(orig.getPoint(), orig.taille, orig.getColor())
{}

Ellipse::~Ellipse()
{}

void Ellipse::dessiner(RenderWindow & fenetre, bool isactive) const
{
	EllipseShape E(taille);
	E.setPosition(getPoint().getAncre());
	E.setOutlineThickness(6);
	E.setOutlineColor(getColor());
	E.setFillColor(Color::Transparent);
	fenetre.draw(E);

	Forme::dessiner(fenetre, isactive);
}

bool Ellipse::isOver(Vector2f curseur)
{
	Vector2f ancre2 = Vector2f(getPoint().getAncre().x + 6, getPoint().getAncre().y + 6);
	if (curseur.x > getPoint().getAncre().x && curseur.y > getPoint().getAncre().y && curseur.x < ancre2.x && curseur.y < ancre2.y)
	{

		return true;

	}
	else
	{
		return false;
	}
}
