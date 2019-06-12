#pragma once
#ifndef DEF_SPRITE
#define DEF_SPRITE

#include "Forme.h"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>



using namespace sf;

class Img : public Forme
{
	//Texture de l'image
	String text;
	int opacite = 255;
	Color couleur;
	Vector2f LH;

public:

	//Constructeur
	Img(Point _ancre, String _text);

	//Copie du rectangle
	Img(Img const& orig);

	//Destructeur du rectangle
	~Img() override;

	int moin_transparence() { if(opacite > 0 ) return opacite = opacite - 1; };
	int plus_transparence() { if (opacite > 255)  return opacite = opacite - 1; };
	//Sauvegarder/charger

	//virtual void ecrire(ostream & os);

	
	void setLH(Vector2f curseur) { LH = curseur; };
	inline Vector2f getLH()const { return LH; };
	

	//dessiner la forme
	void dessiner(RenderWindow& fenetre, bool isactive = false) const override;
	inline virtual void  move(Vector2f mouse) { setPoint(Vector2f(mouse.x - LH.x / 2, mouse.y - LH.y / 2)); };

	//ancre de déplacement configuré sur la surface
	virtual bool isOver(Vector2f curseur);

	//Vérification de si le curseur sur l'ancre de modification
	virtual bool modif(Vector2f curseur);
	virtual Vector2f Size(Vector2f curseur);
};
#endif

