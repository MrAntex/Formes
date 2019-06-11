#pragma once
#ifndef DEF_ELLIPSE
#define DEF_ELLIPSE

#include "Forme.h"
#include "EllipseShape.h"


#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class Ellipse : public Forme
{
	Vector2f taille;

public:

	Ellipse(Point _ancre, Vector2f _taille, Color coul);

	Ellipse(Ellipse const& orig);


	//Destructeu(r
	~Ellipse() override;

	//Couleur statique

	inline void setTaille(Vector2f _taille) { taille = _taille; };

	void dessiner(RenderWindow& fenetre, bool isactive = false) const override;

	virtual bool isOver(Vector2f curseur);

	inline virtual bool modif(Vector2f curseur) { return false; };
	inline virtual string type(Vector2f curseur) { return "oui"; };

};
#endif