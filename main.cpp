// ConsoleApplication2.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include "Point.h"
#include "cercle.h"
#include "rectangle.h"
#include "triangle.h"
#include "Bouton.h"
#include "Formes.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

using namespace sf;
using namespace std;


/*void renderingThread(sf::RenderWindow* window)
//{
	// la boucle de rendu
	//while (window->isOpen())
	//{
		// dessin...
		//Point p(Color::Blue, 200, 8);
		// fin de la frame
		//window->display();
	//}
}*/


//palette de couleur
Color bleu = Color::Blue;
Color rouge = Color::Red;
Color jaune = Color::Yellow;
Color noir = Color::Black;
Color violet = Color::Magenta;
Color vert = Color::Green;

Color gris(90, 90, 180);

//Vecteurs test triangle
Vector2f a = Vector2f(450, 250);
Vector2f b = Vector2f(300, 250);
Vector2f c = Vector2f(300, 400);



/*
void Deplacement(Rectangle& form, RenderWindow& window)
{
	Vector2f coord = form.getAncre(), MousePosition(a);
	if (Mouse::isButtonPressed(Mouse::Left))
	{
		while (MousePosition != form.getAncre())
		{
			MousePosition = Vector2f(Mouse::getPosition(window));

			if (MousePosition != form.getAncre())
			{
				if (MousePosition.x > form.getAncre().x){
					form.move(Vector2f(0.1f, 0.f));
				}
				else if (MousePosition.x < form.getAncre().x){
					form.move(Vector2f(-0.1f, 0.f));
				}

				if (MousePosition.y > form.getAncre().y){
					form.move(Vector2f(0.f, 0.1f));
				}
				else if (MousePosition.x > form.getAncre().x){
					form.move(Vector2f(0.f, -0.1f));
				}
			}
			window.clear();
			form.dessiner(window);
			window.display();
		}
	}
}

*/

// Création de l'instance de Formes pour contenir les instances de Forme
Formes tab_formes;
Forme* ptrforme = nullptr;



int main()
{
	bool dep = false;


	// Fenetre principale
	RenderWindow window(VideoMode(800, 600, 64), "Un debut a tout, pas vrai?", Style::Default | Style::Titlebar);

	// Fenetre secondaire de menu
	RenderWindow menu(VideoMode(200, 500,64), "Menu", Style::Default | Style::Titlebar);
	menu.setPosition(Vector2i(window.getPosition().x + (int)window.getSize().x + 20, window.getPosition().y));
	
	// -- Setup du menu : --

	// Rectangle pour le fond blanc du menu
	RectangleShape fondMenu(Vector2f(200, 500));
	fondMenu.setFillColor(Color::White);
	fondMenu.setPosition(0, 0);

	// Icone de rectangle
	RectangleShape Irect(Vector2f(130, 70));
	Irect.setFillColor(Color::Green);
	Irect.setPosition(35, 25);
	
	// Bouton du rectangle
	Bouton bRect(Vector2f(30, 20), Vector2f(140, 80), "Rectangle", Color::Black, gris);

	// Icone de point
	RectangleShape Ipnt(Vector2f(20,20));
	Ipnt.setFillColor(Color::Black);
	Ipnt.setPosition(90,400);

	// Bouton du point
	Bouton bPnt(Vector2f(40, 380), Vector2f(120, 100), "Point", Color::Black, gris, 4, 3);

	
	//menu.draw(Irect);

	// Icone du cercle
	CircleShape Icerc(50);
	Icerc.setFillColor(violet);
	Icerc.setPosition(50, 125);
	//menu.draw(Icerc);

	// Bouton du cercle
	Bouton bCerc(Vector2f(47, 122), Vector2f(106, 106), "Cercle", Color::Black, gris);


	//Bouton ELBUTTON(Vector2f(200, 200), Vector2f(200, 70), "Krysthelle", Color::Green, Color::Blue, 5, 1);

	// Icone de triangle
	ConvexShape Itrig;
	Itrig.setPointCount(3);
	Itrig.setPoint(0, Vector2f(100, 260));
	Itrig.setPoint(1, Vector2f(35, 350));
	Itrig.setPoint(2, Vector2f(165, 350));
	Itrig.setFillColor(rouge);

	// Bouton triangle
	Bouton bTrig(Vector2f(25, 250), Vector2f(150, 110), "Triangle", Color::Black, gris);

	//Triangle Itrig(Vector2f(100,250), Vector2f(30,320), Vector2f(170,320), rouge);

	//sleep(milliseconds(3000));

	// On cache le menu
	menu.setVisible(false);

	// -- Fin du setup du menu --

	//fond blanc de la fenetre principale
	RectangleShape fond(Vector2f(800, 600));
	fond.setFillColor(Color::White);

	//Rectangle R(Vector2f(200,150), 300, 100, bleu);
	
	int Vmenu = 0;

	// Chargement de la police à utiliser
	sf::Font FKufi;
	if (!FKufi.loadFromFile("ReemKufi-Regular.ttf"))
	{
		std::cout << "La police n'a pas pu être chargée."; // si non chargée
	}


	// Ajout des formes de test :

	Cercle C(Vector2f(80, 70), 70, violet);
	tab_formes.ajouter(&C);
	//C.dessiner(window, true);

	Triangle T(a, b, c, rouge);
	tab_formes.ajouter(&T);
	//T.dessiner(window);

	Rectangle LeRect(Point(Vector2f(200, 200)), 140, 40, jaune);
	tab_formes.ajouter(&LeRect);
	
		// Tant que la fenetre principale est ouverte
		while (window.isOpen())
		{
		Event event;
		while (window.pollEvent(event)) // Event handler principal
		{
			if (event.type == Event::Closed)
				window.close(); // si on ferme la fenetre, elle se ferme :)

			if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::M) {
					// Appui sur M -> 
					
					if (Vmenu == 0) { // si menu fermé, on l'ouvre
						Vmenu = 1;
						menu.setVisible(true);
						// et on le place à coté de la fenetre principale
						menu.setPosition(Vector2i(window.getPosition().x + (int)window.getSize().x + 20, window.getPosition().y));
						menu.display();
					}
					else {  // si menu deja ouvert on le ferme
						Vmenu = 0; 
						menu.setVisible(false);
					}
					std::cout << "M"; // debug
					
					//sf::sleep(sf::milliseconds(300));

				}
			}

			if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
				/*if (ELBUTTON.test_clic(Vector2f(event.mouseButton.x, event.mouseButton.y))) {
					cout << "BOUTON CLIQUEEEEE WHOUOUUOOUOUOUAHAOUOUOUOUBITE" << endl;
					ELBUTTON.swap();
				}

				
			}

			if (event.type == Event::MouseButtonReleased && event.mouseButton.button == Mouse::Left) {
				if (ELBUTTON.test_clic(Vector2f(event.mouseButton.x, event.mouseButton.y))) {
					cout << "BOUTON BRISE, BOUTON LIBERE, DELIVRE" << endl;
					ELBUTTON.swap();
				}
				*/
				ptrforme = tab_formes.isOver(Vector2f(Mouse::getPosition(window)));
			}
			
			if (event.type == Event::MouseMoved)
			{

				//std::cout << "3" << std::endl;
				if (dep)
					if (ptrforme != nullptr) {
						ptrforme->move(Vector2f(Mouse::getPosition(window)));

					}
				//cout << Mouse::getPosition(window).x << " " << Mouse::getPosition(window).y << std::endl;
				//std::cout << "4" << std::endl;

			}
			if (event.type == Event::MouseButtonReleased)
			{
				dep = !dep;
			}

		}
		while (menu.pollEvent(event))
		{ // Event handler du menu

			if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::M) {
					// on répète le code pour ouvrir/fermer le menu
					// pour pouvoir le faire avec ou sans le focus
					if (Vmenu == 0) {
						Vmenu = 1;
						menu.setVisible(true);
					}
					else {
						Vmenu = 0;
						menu.setVisible(false);
					}
					std::cout << "M"; // debug

					//sf::sleep(sf::milliseconds(300));


				}
			}

			// Button handler :
			if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
				// si clic gauche enfoncé

				if (bRect.test_clic(Vector2f(event.mouseButton.x, event.mouseButton.y))) {
					// Si la souris est sur le bouton du Rectangle
					cout << "Rectangle !" << endl; // debug
					bRect.swap(); // on change la couleur du bouton
				}
				if (bTrig.test_clic(Vector2f(event.mouseButton.x, event.mouseButton.y))) {
					// Si Triangle
					cout << "Triangle !" << endl;
					bTrig.swap();
				}
				if (bPnt.test_clic(Vector2f(event.mouseButton.x, event.mouseButton.y))) {
					// Si Point
					cout << "Point !" << endl;
					bPnt.swap();
				}

				if (bCerc.test_clic(Vector2f(event.mouseButton.x, event.mouseButton.y))) {
					// Si Cercle
					cout << "Cercle !" << endl;
					bCerc.swap();
				}

			}

			if (event.type == Event::MouseButtonReleased && event.mouseButton.button == Mouse::Left) {
				// Si clic gauche relaché
				if (bRect.test_clic(Vector2f(event.mouseButton.x, event.mouseButton.y))) {
					// si souris sur le bouton du rectangle
					cout << "Rectangle relaché" << endl; // debug
					bRect.swap(); // changement a nouveau de la couleur
				}

				if (bTrig.test_clic(Vector2f(event.mouseButton.x, event.mouseButton.y))) {
					// Si Triangle
					cout << "Triangle relaché" << endl;
					bTrig.swap();
				}

				if (bPnt.test_clic(Vector2f(event.mouseButton.x, event.mouseButton.y))) {
					// Si Point
					cout << "Point relaché" << endl;
					bPnt.swap();
				}

				if (bCerc.test_clic(Vector2f(event.mouseButton.x, event.mouseButton.y))) {
					// Si Cercle
					cout << "Cercle relaché" << endl;
					bCerc.swap();
				}
			}


		}
		window.clear();
		//fond dessiné	
		window.draw(fond);
		tab_formes.dessiner(window, tab_formes.isOver(Vector2f(Mouse::getPosition(window))));

		menu.clear(); // Clear de la fenetre de menu
		menu.draw(fondMenu); // Ajout du fond blanc du menu

		// Affichage des icones des formes
		menu.draw(Ipnt);
		menu.draw(Irect);
		menu.draw(Icerc);
		menu.draw(Itrig);

		// Affichage des boutons des formes
		bRect.afficher(menu, FKufi);
		bCerc.afficher(menu, FKufi);
		bTrig.afficher(menu, FKufi);
		bPnt.afficher(menu, FKufi);

		// Affichage global de la fenetre du menu
		menu.display();



		// -- test forme --



		Point p(Vector2f(200, 80));
		p.dessiner(window, true);

		// -- Fin test forme --





		/*
		Point p1(80, 70, rouge);
		p1.dessiner(window, true);


		Point pt2(300, 300, 200, 100, 0);
		pt2.dessiner(window, true);
		*/
		
		//ELBUTTON.afficher(window, FKufi, Color::Black);
		window.display();
	}

	return 0;
}