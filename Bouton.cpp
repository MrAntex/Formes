#include "Bouton.h"
#include <iostream>

using namespace sf;

Bouton::Bouton(Vector2f _ancre, Vector2f _taille, String _texte, Color _couleur, Color _sec_couleur, int _eppaisseur, unsigned int pos, Color coul_plein ) {
	bout.setPosition(_ancre);
	bout.setSize(_taille);
	bout.setOutlineColor(_couleur);
	bout.setOutlineThickness(_eppaisseur);
	bout.setFillColor(coul_plein);

	texte = _texte;
	couleur = _couleur;
	sec_couleur = _sec_couleur;
	posTxt = pos;

	
}

Bouton::~Bouton() {}


void Bouton::afficher(RenderWindow &fenetre, Font police, Color Tcouleur) const {

	fenetre.draw(bout);

	Text titre;
	titre.setString(texte);
	titre.setFont(police);
	titre.setFillColor(Tcouleur);

	titre.setCharacterSize(bout.getSize().y / 2);
	if (bout.getSize().x < 2 * bout.getSize().y) {
		titre.setCharacterSize((bout.getSize().x / (texte.getSize()+2))*2);
	}

	//titre.setPosition(Vector2f(bout.getPosition().x, bout.getPosition().y));
	titre.setOutlineColor(Color::Transparent); // a vérifier que ça ne nique pas tout
	titre.setPosition(Vector2f((bout.getPosition().x + ((bout.getSize().x / (texte.getSize()+1)))), (bout.getPosition().y + posTxt*(bout.getSize().y / 6))));

	fenetre.draw(titre);
	
}

bool Bouton::test_clic(Vector2f coord) {
	return ((coord.x <= bout.getPosition().x + bout.getSize().x) && (coord.x >= bout.getPosition().x) && (coord.y <= bout.getPosition().y + bout.getSize().y) && (coord.y > bout.getPosition().y));
}

void Bouton::swap() {
	if (bout.getOutlineColor() == couleur)
		bout.setOutlineColor(sec_couleur);
	else
		bout.setOutlineColor(couleur);
}