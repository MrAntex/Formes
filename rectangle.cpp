#include "rectangle.h"




Rectangle::Rectangle(Point _ancre, uint _largeur, uint _hauteur, Color coul )
	:  Forme(_ancre, coul), l(_largeur), h(_hauteur)
{}

Rectangle::Rectangle(Rectangle const& orig) : Rectangle (orig.getPoint().getAncre(), orig.l, orig.h ,orig.getColor()) {}
// Fais attention, lorsque tu utilise des fonctions sur la valeur retourn�e d'une autre fonction, � ne pas oublier de parenth�ses, comme ici pour
// "orig.getAncre().getX()", o�, je crois, tu avais oubli� des parenth�ses pour "getAncre".

Rectangle::~Rectangle() {}

void Rectangle::dessiner(RenderWindow& fenetre, bool isactive) const
{
		RectangleShape R(Vector2f(l, h));
		R.setPosition(getPoint().getAncre());
		R.setFillColor(getColor());
		fenetre.draw(R);
		Forme::dessiner(fenetre, isactive);
}






