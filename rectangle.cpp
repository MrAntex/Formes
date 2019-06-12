#include "rectangle.h"




Rectangle::Rectangle(Point _ancre, Vector2f _LH, Color coul )
	:  Forme(_ancre, coul), LH(_LH)
{}

Rectangle::Rectangle(Rectangle const& orig) : Rectangle (orig.getPoint().getAncre(), orig.LH ,orig.getColor()) {}
// Fais attention, lorsque tu utilise des fonctions sur la valeur retournée d'une autre fonction, à ne pas oublier de parenthèses, comme ici pour
// "orig.getAncre().getX()", où, je crois, tu avais oublié des parenthèses pour "getAncre".

Rectangle::~Rectangle() {}

void Rectangle::dessiner(RenderWindow& fenetre, bool isactive) const
{
		RectangleShape R(LH);
		R.setPosition(getPoint().getAncre());
		R.setFillColor(getColor());
		R.setOutlineThickness(getEpaiss());
		R.setOutlineColor(getCoulBord());
		fenetre.draw(R);
		Forme::dessiner(fenetre, isactive);
}

bool Rectangle::isOver(Vector2f curseur)
{
	Vector2f ancre2 = Vector2f(getPoint().getAncre().x + LH.x, getPoint().getAncre().y + LH.y);
	if (getPoint().getAncre().x < ancre2.x && getPoint().getAncre().y < ancre2.y)
	{
		if (curseur.x > getPoint().getAncre().x && curseur.y > getPoint().getAncre().y && curseur.x < ancre2.x && curseur.y < ancre2.y)
			return true;
		else
			return false;
	}
	if (getPoint().getAncre().x < ancre2.x && getPoint().getAncre().y > ancre2.y)
	{
		if (curseur.x > getPoint().getAncre().x && curseur.y < getPoint().getAncre().y && curseur.x < ancre2.x && curseur.y > ancre2.y)
			return true;
		else
			return false;
	}
	if (getPoint().getAncre().x > ancre2.x && getPoint().getAncre().y > ancre2.y)
	{
		if (curseur.x < getPoint().getAncre().x && curseur.y < getPoint().getAncre().y && curseur.x > ancre2.x && curseur.y > ancre2.y)
			return true;
		else
			return false;
	}
	if (getPoint().getAncre().x > ancre2.x && getPoint().getAncre().y < ancre2.y)
	{
		if (curseur.x < getPoint().getAncre().x && curseur.y > getPoint().getAncre().y && curseur.x > ancre2.x && curseur.y < ancre2.y)
			return true;
		else
			return false;
	}
}

bool Rectangle::modif(Vector2f curseur)
{
	Vector2f ancre2 = Vector2f(getPoint().getAncre().x + LH.x, getPoint().getAncre().y + LH.y);
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


Vector2f Rectangle::Size(Vector2f curseur)
{
	Vector2f _taille = curseur - getPoint().getAncre();
	setLH(_taille);
	return(_taille);
}






