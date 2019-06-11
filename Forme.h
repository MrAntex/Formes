#pragma once
#ifndef DEF_FORME
#define DEF_FORME

#include "Point.h"
#include "EllipseShape.h"
#include <cmath>

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

using namespace std;

class Forme  {

	Color couleur;
	Point  pt;


public:

	Forme(Point _pt, Color _coul);

	Forme(Forme const & orig);

	virtual ~Forme();

	inline Color getColor() const { return couleur; };

	inline Color setColor(Color _coul) { couleur = _coul; };

	inline void  move(Vector2f mouse) { pt.setAncre(mouse); };


	inline Point const & getPoint() const { return pt; };
	
	//Affichage sur fenêtre
	virtual void dessiner(RenderWindow& fenetre, bool isactive = false)const;

	//Verification de si le curseur est sur la surface
	virtual bool isOver(Vector2f curseur) = 0;

	//Vérification de si curseur sur l'ancre de modification
	virtual bool modif(Vector2f curseur) = 0;

	Vector2f Size(Vector2f curseur);


	//Type forme
	virtual string type(Vector2f curseur) = 0;
};
#endif