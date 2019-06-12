#pragma once
#ifndef DEF_FORME
#define DEF_FORME

#include "Point.h"
#include "EllipseShape.h"
#include "rectangle.h"
#include "cercle.h"
#include "Ellipse.h"
#include "triangle.h"

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

	Forme(istream & is);

	virtual Vector2f Size(Vector2f curseur) = 0;

	Forme(Forme const & orig);



	//Sauvergarder/charger
	virtual void ecrire(ostream & os)const;
	virtual Forme* charger(istream & is);

	//friend ostream & operator<<(ostream & os, const Forme & forme);

	virtual ~Forme();

	inline Color getColor() const { return couleur; };

	inline Color setColor(Color _coul) { couleur = _coul; };

	virtual void  move(Vector2f mouse) = 0;
	
	inline void setPoint(Vector2f curseur) { pt.setAncre(curseur); };
	inline Point const & getPoint() const{ return pt; };
	
	//Affichage sur fenêtre
	virtual void dessiner(RenderWindow& fenetre, bool isactive = false)const;

	//Verification de si le curseur est sur la surface
	virtual bool isOver(Vector2f curseur) = 0;

	//Vérification de si curseur sur l'ancre de modification
	virtual bool modif(Vector2f curseur) = 0;

};
#endif