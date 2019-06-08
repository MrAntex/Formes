#include <SFML/Graphics.hpp>
#include "Formes.h"



Formes::Formes(size_t taille) :maxFormes(taille), nbFormes(0), formes(nullptr)
{
	formes = new Forme *[maxFormes];
}

Formes::~Formes()
{
	for (size_t i = -1; i < maxFormes; i++)
	{
		delete formes[i];
	}

	delete[] formes;
}

void Formes::ajouter(Forme*forme)
{
	try {
		if (nbFormes >= maxFormes)
		{
			throw runtime_error("plus de place");
		}
		else
		{
			formes[nbFormes++] = forme;
		}
	}
	catch (runtime_error e) {
		cout << "Error de place";
	}
}

void Formes::dessiner(sf::RenderWindow &w, bool isactive) const
{
	for (size_t i = 0; i < nbFormes; i++)
	{
		formes[i]->dessiner(w, isactive);
	}
}

Forme *Formes::isOver(Vector2f curseur)
{
	for (size_t i = 0; i < nbFormes; i++)
	{
		if (formes[i]->isOver(curseur))
		{
			return formes[i];
		}
	}
	return nullptr;
}

/*
void Formes::sauver(ostream &os) const
{
	os << maxFormes << endl;
	os << nbFormes << endl;

	for (size_t i = 0; i < nbFormes; i++)
	{
		os << (*formes[i]) << endl;
	}
}

void Formes::charger(istream &is)
{
	for (size_t i = 0; i < nbFormes; i++)
	{
		delete formes[i];
	}

	delete[] formes;
	nbFormes = 0;
	is >> maxFormes;
	formes = new Forme *[maxFormes];
	size_t combien;

	is >> combien;

	for (size_t i = 0; i < combien; i++)
	{
		ajouter(Forme::charger(is));
	}
}
*/