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

	//Ellipse(istream& is);

	Ellipse(Ellipse const& orig);


	//Destructeur
	~Ellipse() override;

	//Sauvegarder/charger
	//virtual void ecrire(ostream& os);

	//Couleur statique
	inline virtual void  move(Vector2f mouse) { setPoint(mouse - taille); };

	inline void setTaille(Vector2f _taille) { taille = _taille; };

	void dessiner(RenderWindow& fenetre, bool isactive = false) const override;

	virtual bool isOver(Vector2f curseur);

	inline virtual bool modif(Vector2f curseur);

	virtual Vector2f Size(Vector2f curseur);
};
#endif