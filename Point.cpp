#include "Point.h"
#pragma once
//#include <iostream>


Point::Point(Vector2f _ancre) : ancre(_ancre), couleur(sf::Color::Black)
{}



Point::Point(const Point& orig) : ancre(orig.ancre){}

Point::~Point() {}
/*
bool Point::isOver(Vector2f _ancre) const
{
	
	float dx = (ancre.x >= _ancre.x ? ancre.x - _ancre.x : _ancre.x - ancre.x);
	float dy = (ancre.y >= _ancre.y ? ancre.y - _ancre.y : _ancre.x - ancre.y);

	return (dx <= taille && dy <= taille);
}*/


void Point::dessiner(RenderWindow& fenetre, bool isactive) const
{
	RectangleShape pt(Vector2f(taille,taille));
	pt.setPosition(ancre);
	pt.setFillColor(couleur);
	fenetre.draw(pt);
}
/*
void Point::swapCoul(){
	if (swapped){
		Color tmp = couleur;
		couleur = deux_couleur;
		deux_couleur = tmp;



	}
}*/