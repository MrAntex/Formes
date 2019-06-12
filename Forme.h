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

	
	Point  pt;
	bool rempli;
	bool flash, pulse, a_coul;
	uint epaiss, b_epaiss;

protected:
	Color couleur, couleur2, coulBord, coulBord2;

public:

	Forme(Point _pt, Color _coul);

	Forme(Forme const & orig);

	virtual ~Forme();

	inline Color getColor() const { return couleur; };

	inline Color getColor2() const { return couleur2; };

	inline bool getRempli() const { return rempli; }

	inline uint getEpaiss() const { return epaiss; }

	inline uint getBEpaiss() const { return b_epaiss; }

	inline Color getCoulBord() const { return coulBord; }

	inline Color getCoulBord2() const { return coulBord2; }

	inline Point const& getPoint() const { return pt; };

	inline bool getCligno() const { return flash; }

	inline bool getPulse() const { return pulse; }

	inline bool getCoul() const { return a_coul; }

	inline void setEpaiss(uint ep) { epaiss = ep; }

	inline void setCoulBord(Color bordure) { coulBord = bordure; }

	inline void setCoulBord2(Color bordure) { coulBord2 = bordure; }

	inline void setColor(Color _coul) { couleur = _coul; }

	inline void setColor2(Color _coul) { couleur2 = _coul; }

	virtual inline void  move(Vector2f mouse) = 0;

	inline void setPoint(Vector2f curseur) { pt.setAncre(curseur); };

	void swaPlein(); // REDESSINER APRES

	//inline void fillForme(Shape) {};


	inline void cligno() { flash = !flash; }

	inline void pul() { pulse = !pulse; }

	inline void coul() { 
		if (a_coul) {
			setColor(getColor2());
		}
		a_coul = !a_coul; 
	}

	
	
	virtual void dessiner(RenderWindow& fenetre, bool isactive = false)const;

	virtual bool isOver(Vector2f curseur) = 0;

	virtual bool modif(Vector2f curseur) = 0;

	virtual Vector2f Size(Vector2f curseur) = 0;


};
#endif