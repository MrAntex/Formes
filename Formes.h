#pragma once
#ifndef DEF_FORMES
#define DEF_FORMES

#include "Forme.h"

typedef unsigned long ulong;
typedef unsigned int uint;

using namespace sf;
using namespace std;

class Formes
{
	size_t maxFormes;
	size_t nbFormes;
	Forme **formes;

public:

	Formes(size_t taille = 200);

	~Formes();

	void ajouter(Forme *forme);

	void dessiner(RenderWindow &w, bool isactive = false) const;

	Forme *isOver(Vector2f curseur);

	Forme *modif(Vector2f curseur);
	
	void sauver(ostream &os) const;
	void charger(istream &is);
	

	friend ostream & operator<<(ostream & os, Forme forme);
};
#endif
