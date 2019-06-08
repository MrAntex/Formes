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

		CircleShape pt(taille);
		pt.setPosition(getPoint().getAncre());
		pt.setFillColor(getColor());
		fenetre.draw(pt);
		Forme::dessiner(fenetre, isactive);
}