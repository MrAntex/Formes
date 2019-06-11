#include "cercle.h"
#pragma once
//#include <iostream>


Cercle::Cercle(Point _ancre,  float _taille, Color coul)
	: Forme(_ancre, coul), taille(_taille)
{}

Cercle::Cercle(const Cercle& orig) : Cercle(orig.getPoint(), orig.taille, orig.getColor()) {}

Cercle::~Cercle() {}


void Cercle::dessiner(RenderWindow& fenetre, bool isactive) const
{
	CircleShape cercle(taille);
	cercle.setPosition(getPoint().getAncre());
	cercle.setOutlineThickness(6);
	cercle.setOutlineColor(getColor());
	cercle.setFillColor(Color::Transparent);
	fenetre.draw(cercle);

	Forme::dessiner(fenetre, isactive);
}

bool Cercle::isOver(Vector2f curseur)
{
	Vector2f ancre2 = Vector2f(getPoint().getAncre().x + taille , getPoint().getAncre().y + taille);
	if(taille*taille > ((curseur.x - ancre2.x)*(curseur.x - ancre2.x) + (curseur.y - ancre2.y)*(curseur.y - ancre2.y)))
	{
		return true;
	}
	else
		return false;
}

bool Cercle::modif(Vector2f curseur)
{
	return false;
}
