#pragma once
#ifndef DEF_ELLIPSE
#define DEF_ELLIPSE

#include "Forme.h"
#include "EllipseShape.h"


#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class Ellipse : Forme
{
	float taille;


public:

	Ellipse(Point _ancre, float _taille, Color coul);

	Ellipse(Ellipse const& orig);


	//Destructeur
	~Ellipse() override;

	//Couleur statique

	inline void setTaille(float t) { taille = t; };

	void dessiner(RenderWindow& fenetre, bool isactive = false) const override;

	virtual bool isOver(Vector2f curseur);





};
#endif