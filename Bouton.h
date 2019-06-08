#pragma once

#ifndef DEF_BOUTON
#define DEF_BOUTON

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include <iostream>

using namespace sf;

class Bouton
{
	String texte;
	Color couleur;
	Color sec_couleur;
	int posTxt;
	RectangleShape bout;
	

	public:

		//constructeurs
		Bouton(Vector2f _ancre, Vector2f _taille, String _texte = "", Color _couleur = Color::Blue, Color _sec_couleur = Color::Yellow, int _eppaisseur = 4,unsigned int pos = 2);
		Bouton( const Bouton& orig );

		//destructeur
		~Bouton();

		//getters
		inline Color getCouleur() { return couleur; }
		inline Color getCouleurSec() { return sec_couleur; }
		inline Color getCouleurBout() { return bout.getOutlineColor(); }
		inline Vector2f getTaille() { return bout.getSize(); }
		inline Vector2f getAncre() { return bout.getPosition(); }
		inline String getTexte() { return texte; }
		inline unsigned int getWidth() { return bout.getOutlineThickness(); }

		//setters
		inline void setCouleur(Color coul) { couleur = coul; }
		inline void setCouleurSec(Color coul) { sec_couleur = coul; }
		inline void setCouleurBout(Color coul) { bout.setOutlineColor(coul); }
		inline void setWidth(unsigned int eppais) { bout.setOutlineThickness(eppais); }
		inline void setTexte(String _texte) { texte = _texte; }
		inline void setAncre(Vector2f _ancre) { bout.setPosition(_ancre); }
		inline void setTaille(Vector2f _taille) { bout.setSize(_taille); }

		//affichage initial du bouton
		void afficher(RenderWindow& fenetre, Font police, Color Tcouleur = Color::Black) const;

		//test pour savoir si le bouton est clique
		bool test_clic(Vector2f pos);

		//switch entre les 2 couleurs au moment du clic
		void swap();


	 };







#endif