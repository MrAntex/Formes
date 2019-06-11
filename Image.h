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
	//Point modif;

public:

	//Constructeur d'une image
	Img(Point _ancre, String _text,Color coul);

	//Copie du rectangle
	Img(Img const& orig);

	//Destructeur du rectangle
	~Img() override;

	void dessiner(RenderWindow& fenetre, bool isactive = false) const override;

	//ancre de déplacement configuré sur la surface
	virtual bool isOver(Vector2f curseur);

	//Vérification de si le curseur sur l'ancre de modification
	virtual bool modif(Vector2f curseur);
	//inline virtual void pt_modif(Vector2f curseur) { Rectangle::setLH(curseur - getPoint().getAncre()); };
	inline virtual string type(Vector2f curseur) { if (modif(curseur)) return "oui"; };

};
#endif

