#pragma once
#ifndef DEF_FORME
#define DEF_FORME

#include "Point.h"

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

	//inline void fillForme(Shape) {};

	inline Point const & getPoint() const { return pt; };
	
	virtual void dessiner(RenderWindow& fenetre, bool isactive = false)const;

	bool isOver(Vector2f curseur);


};
#endif