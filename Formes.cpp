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

Forme* Formes::modif(Vector2f curseur)
{
	for (size_t i = 0; i < nbFormes; i++)
	{
		if (formes[i]->modif(curseur))
		{
			return formes[i];
		}
	}
	return nullptr;
}

void Formes::supprimer(Forme* forme) {
	for (size_t i = 0; i < nbFormes && nbFormes > 0; i++) {

		if (formes[i] = forme) {

			delete formes[i];

			formes[i] = formes[--nbFormes];
			//delete formes[nbFormes];
			cout << "Il y a " << nbFormes << " formes." << endl;
		}
		
	}


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
	uint k;
	for (size_t i = 0; i < nbFormes; i++)
	{
		k = nbFormes - 1 - i;
		formes[k]->dessiner(w, isactive);
	}
}

Forme* Formes::isOver(Vector2f curseur)
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






void Formes::swaPleinAll() {
		for (size_t i = 0; i < nbFormes; i++)
		{
			formes[i]->swaPlein();
		}
}










void Formes::clignAll() {
	for (size_t i = 0; i < nbFormes; i++)
	{
		formes[i]->cligno();
	}
}

void Formes::pulAll() {
	for (size_t i = 0; i < nbFormes; i++)
	{
		formes[i]->pul();
	}
}

void Formes::flash(uint mil) {
	int count = 0;

	for (size_t i = 0; i < nbFormes; i++)
	{
		Forme *forme = NULL;
		forme = formes[i];

		if (forme->getCligno()) {
			count++;

			if (forme->getColor() != Color::Transparent && forme->getCoulBord() != Color::Transparent) {
				forme->setColor(Color::Transparent);
				forme->setCoulBord(Color::Transparent);
				cout << "Swapped invisible" << endl;
			}

			else if (forme->getColor() == Color::Transparent && forme->getCoulBord() == Color::Transparent) {
				Color c1 = forme->getColor2();
				Color c2 = forme->getCoulBord2();
				forme->setColor(c1);
				forme->setCoulBord(c2);
				cout << "Swapped visible" << endl;
			}

		}
	}

	if (count > 0) {
		sleep(milliseconds(mil));
	
	}

	

}

uint Formes::pulse(uint mil, uint epp) {
	int count = 0;
	//int epp = 0;
	for (size_t i = 0; i < nbFormes; i++)
	{
		Forme* forme = NULL;
		forme = formes[i];
		
		if (forme->getPulse()) {
			count++;

			if (epp>=0 && epp <= 20) {
				forme->setEpaiss(forme->getEpaiss() + 2);
				epp++;
				cout << "+ gros : " << epp << endl;
				cout << "Eppaisseur : " << forme->getEpaiss() << endl;
			}

			else if (epp>20 && epp<41){
				forme->setEpaiss(forme->getEpaiss() - 2);
				epp++;
				cout << "- gros : " << epp << endl;
				cout << "Eppaisseur : " << forme->getEpaiss() << endl;

			}
			else if (epp >= 41){
				epp = 1;
			}

		}
	}
	if (count > 0)
		sleep(milliseconds(mil));
	
	return epp;
}
void Formes::resetEppaiss() {
	for (size_t i = 0; i < nbFormes; i++)
	{
		formes[i]->setEpaiss(formes[i]->getBEpaiss());	
	}
}

void Formes::resetClig() {
	for (size_t i = 0; i < nbFormes; i++) {
		if (formes[i]->getColor() == Color::Transparent && formes[i]->getCoulBord() == Color::Transparent) {
			cout << "tested forme " << i << endl;
			//Color c1 = formes[i]->getColor2();
			//Color c2 = formes[i]->getCoulBord2();

			formes[i]->setColor(formes[i]->getColor2());
			formes[i]->setCoulBord(formes[i]->getCoulBord2());
		}
	}
}

void Formes::coulAll() {
	for (size_t i = 0; i < nbFormes; i++)
	{
		formes[i]->coul();
	}
}

void Formes::coulSwap(uint mili) {
	int count = 0;
	//int epp = 0;
	for (size_t i = 0; i < nbFormes; i++)
	{
		Forme* forme = NULL;
		forme = formes[i];

		if (forme->getCoul()) {
			Uint8 ch = 5;
			count++;
			uint v1;
			v1 = rand() % 3 + 1;
			uint v2 = rand() % 2;
			cout << "va = " << v1 << endl;
			cout << "v2 = " << v2 << endl;

			forme->setColor(Color(rand() % 256, rand() % 256, rand() % 256));

		}
		if (count > 0)
			sleep(milliseconds(mili));

		
	}

	
}

void Formes::resetCoul() {
	for (size_t i = 0; i < nbFormes; i++) {
		if (formes[i]->getColor() != formes[i]->getColor2())
			formes[i]->setColor(formes[i]->getColor2());
	}
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