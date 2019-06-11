#include "rectangle.h"



Rectangle::Rectangle(Point _ancre, Vector2f _LH, Color coul )
	:  Forme(_ancre, coul), LH(_LH)
{}

Rectangle::Rectangle(Rectangle const& orig) : Rectangle (orig.getPoint().getAncre(), orig.LH ,orig.getColor()) {}
// Fais attention, lorsque tu utilise des fonctions sur la valeur retournée d'une autre fonction, à ne pas oublier de parenthèses, comme ici pour
// "orig.getAncre().getX()", où, je crois, tu avais oublié des parenthèses pour "getAncre".

Rectangle::~Rectangle() {}


void Rectangle::dessiner(RenderWindow& fenetre, bool  isactive) const
{
	
	RectangleShape R(getLH());
	R.setFillColor(getColor());
	R.setPosition(getPoint().getAncre());
	fenetre.draw(R);


	//Point de modification de forme
	Point pt_mod(Vector2f(getPoint().getAncre().x + LH.x , getPoint().getAncre().y + LH.y));
	pt_mod.dessiner(fenetre, isactive);
	Forme::dessiner(fenetre, isactive);
}


bool Rectangle::isOver(Vector2f curseur)
{
	Vector2f ancre2 = Vector2f(getPoint().getAncre().x + LH.x, getPoint().getAncre().y + LH.y);
	if (curseur.x > getPoint().getAncre().x && curseur.y > getPoint().getAncre().y && curseur.x < ancre2.x && curseur.y < ancre2.y)
	{
		
		return true;

	}
	else
	{
		return false;
	}
}

bool Rectangle::modif(Vector2f curseur)
{
	Vector2f ancre2 = Vector2f(getPoint().getAncre().x + LH.x, getPoint().getAncre().y + LH.y);
	Vector2f ancre3 = Vector2f(ancre2.x + 6, ancre2.y + 6);
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






