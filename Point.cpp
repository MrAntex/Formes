#include "Point.h"
#pragma once
//#include <iostream>


Point::Point(Vector2f _ancre) : ancre(_ancre), couleur(sf::Color::Black)
{}



Point::Point(const Point& orig) : ancre(orig.ancre){}


Point::Point(istream & is)
{
	is >> ancre.x;
	is >> ancre.y;
}

Point::~Point() {}



void Point::dessiner(RenderWindow& fenetre, bool isactive) const
{
	RectangleShape pt(Vector2f(taille,taille));
	pt.setPosition(ancre);
	pt.setFillColor(couleur);
	fenetre.draw(pt);
}