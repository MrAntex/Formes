// ConsoleApplication2.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include "Point.h"
#include "cercle.h"
#include "rectangle.h"
#include "triangle.h"
#include "Bouton.h"
#include "ellipse.h"
#include "Image.h"
#include "Formes.h"
#include <iostream>
#include <string>
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

Vector2f n1 = Vector2f(200, 100);
Vector2f n2 = Vector2f(100, 300);
Vector2f n3 = Vector2f(300, 300);

//image
String image_nom = "fleur_2.png";

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
Forme* ptrforme2 = nullptr;
Forme* selected = nullptr;

bool first = true;


int main()
{
	bool dep = false, clig = false, pul = false, coul = false;
	bool Bclig = false, Bpul = false, Bcoul = false;
	bool BsR = false, BsG = false, BsB = false, BsA = false;
	
	uint tempoClig = 300;
	uint tempoCoul = 60;
	uint tempoPul = 30;
	uint epp = 1;

	uint Sr = 127, Sg = 127, Sb = 127, Sa = 255;


	// Fenetre principale
	RenderWindow window(VideoMode(800, 600, 64), "Formax", Style::Default | Style::Titlebar);

	// Fenetre secondaire de menu
	RenderWindow menu1(VideoMode(200, 500,64), "Menu", Style::Default | Style::Titlebar);
	menu1.setPosition(Vector2i(window.getPosition().x + (int)window.getSize().x + 20, window.getPosition().y));
	
	RenderWindow menu2(VideoMode(200, 500, 64), "Menu", Style::Default | Style::Titlebar);
	menu2.setPosition(Vector2i(window.getPosition().x + (int)window.getSize().x + 20, window.getPosition().y));

	RenderWindow menuCouleur(VideoMode(200, 500, 64), "Menu", Style::Default | Style::Titlebar);
	menuCouleur.setPosition(Vector2i(window.getPosition().x + (int)window.getSize().x + 20, window.getPosition().y));

	// -- Setup du menu 1 : --

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
	menu1.setVisible(false);
	menuCouleur.setVisible(false);
	// -- Fin du setup du menu 1 --

	// Chargement de la police à utiliser
	sf::Font FKufi;
	if (!FKufi.loadFromFile("ReemKufi-Regular.ttf"))
	{
		std::cout << "La police n'a pas pu être chargée."; // si non chargée
	}

	// -- Setup du menu 2 : --


	// Bouton du clignotement
	Bouton bClig(Vector2f(30, 20), Vector2f(140, 90), "Cligno", Color::Black, gris, 4, 3);
	Text TClig;
	TClig.setString(to_string(tempoClig));
	TClig.setFont(FKufi);
	TClig.setFillColor(Color::Black);
	TClig.setPosition(Vector2f(75, 25));
	TClig.setCharacterSize(30);
	

	// Bouton retour
	Bouton bRet(Vector2f(40, 380), Vector2f(120, 100), "Retour", Color::Black, gris, 4, 2);
	
	// Bouton de la pulsation
	Bouton bPul(Vector2f(47, 122), Vector2f(106, 106), "Pulse", Color::Black, gris, 4, 3);
	Text TPul;
	TPul.setString(to_string(tempoPul));
	TPul.setFont(FKufi);
	TPul.setFillColor(Color::Black);
	TPul.setPosition(Vector2f(75, 130));
	TClig.setCharacterSize(30);
	

	
	// Bouton rotation
	Bouton bRot(Vector2f(25, 250), Vector2f(150, 110), "Couleur", Color::Black, gris, 4, 3);
	Text TCoul;
	TCoul.setString(to_string(tempoCoul));
	TCoul.setFont(FKufi);
	TCoul.setFillColor(Color::Black);
	TCoul.setPosition(Vector2f(75, 260));
	TClig.setCharacterSize(30);
	


	// On cache le menu 2
	menu2.setVisible(false);

	// -- Fin du setup du menu 2 --

	// -- Setup menu Couleur --
	Bouton BC1(Vector2f(40, 20), Vector2f(30, 30), "", Color::Black, gris, 4, 2, Color::Black);
	Bouton BC2(Vector2f(80, 20), Vector2f(30, 30), "", Color::Black, gris, 4, 2, Color::White);
	Bouton BC3(Vector2f(120, 20), Vector2f(30, 30), "", Color::Black, gris, 4, 2, Color::Red);
	
	Bouton BC4(Vector2f(40, 60), Vector2f(30, 30), "", Color::Black, gris, 4, 2, Color::Green);
	Bouton BC5(Vector2f(80, 60), Vector2f(30, 30), "", Color::Black, gris, 4, 2, Color::Blue);
	Bouton BC6(Vector2f(120, 60), Vector2f(30, 30), "", Color::Black, gris, 4, 2, Color::Yellow);
	
	Bouton BC7(Vector2f(40, 100), Vector2f(30, 30), "", Color::Black, gris, 4, 2, Color::Magenta);
	Bouton BC8(Vector2f(80, 100), Vector2f(30, 30), "", Color::Black, gris, 4, 2, Color::Cyan);
	Bouton BC9(Vector2f(120, 100), Vector2f(30, 30), "", Color::Black, gris, 4, 2, Color(255, 115,5));

	Bouton BC10(Vector2f(40, 140), Vector2f(30, 30), "", Color::Black, gris, 4, 2, Color(100,70,35));
	Bouton BC11(Vector2f(80, 140), Vector2f(30, 30), "", Color::Black, gris, 4, 2, Color(255,96,250));
	Bouton BC12(Vector2f(120, 140), Vector2f(30, 30), "", Color::Black, gris, 4, 2, Color(0,255,150));



	Bouton BRg(Vector2f(30, 210), Vector2f(20, 20), "<", Color::Black, gris, 4, 2);
	Bouton BR(Vector2f(70, 210), Vector2f(60, 20), "R", Color::Black, gris, 4, 2, rouge); // rajouter le rect de couleur derriere
	Bouton BRd(Vector2f(150, 210), Vector2f(20, 20), ">", Color::Black, gris, 4, 2);

	Bouton BGg(Vector2f(30, 250), Vector2f(20, 20), "<", Color::Black, gris, 4, 2);
	Bouton BG(Vector2f(70, 250), Vector2f(60, 20), "G", Color::Black, gris, 4, 2, vert); // rajouter le rect de couleur derriere
	Bouton BGd(Vector2f(150, 250), Vector2f(20, 20), ">", Color::Black, gris, 4, 2);

	Bouton BBg(Vector2f(30, 290), Vector2f(20, 20), "<", Color::Black, gris, 4, 2);
	Bouton BB(Vector2f(70, 290), Vector2f(60, 20), "B", Color::Black, gris, 4, 2, bleu); // rajouter le rect de couleur derriere
	Bouton BBd(Vector2f(150, 290), Vector2f(20, 20), ">", Color::Black, gris, 4, 2);

	Bouton BAg(Vector2f(30, 330), Vector2f(20, 20), "<", Color::Black, gris, 4, 2);
	Bouton BA(Vector2f(70, 330), Vector2f(60, 20), "A", Color::Black, gris, 4, 2); // rajouter le rect de couleur derriere
	Bouton BAd(Vector2f(150, 330), Vector2f(20, 20), ">", Color::Black, gris, 4, 2);


	
	Bouton BV(Vector2f(50, 400), Vector2f(100, 50), "Valider", Color::Black, gris, 4, 1); // rajouter le rect derriere

	RectangleShape RectValid(Vector2f(100, 50));
	RectValid.setFillColor(Color(Sr,Sg,Sb,Sa));
	RectValid.setPosition(50, 400);

	Text rgb;
	rgb.setString("( " + to_string(Sr) + " , " + to_string(Sg) + " , " + to_string(Sb) + " , " + to_string(Sa) + " )");
	rgb.setFont(FKufi);
	rgb.setFillColor(Color::Black);
	rgb.setPosition(Vector2f(20, 360));
	rgb.setCharacterSize(20);





	// -- Fin du setup du menu Couleur --

	//fond blanc de la fenetre principale
	RectangleShape fond(Vector2f(800, 600));
	fond.setFillColor(Color::White);

	//Rectangle R(Vector2f(200,150), 300, 100, bleu);
	
	int Vmenu = 0;

	


	// Ajout des formes de test :

	Cercle C(Point(Vector2f(100, 350)), 100, violet);
	tab_formes.ajouter(&C);
	//C.dessiner(window, true);

	//Ellipse E(Point(Vector2f(50, 200)), Vector2f(50, 150), violet);
	//tab_formes.ajouter(&E);
//	tab_formes.supprimer(&C);

	Triangle T(a, b, c, rouge);
	tab_formes.ajouter(&T);
	//T.dessiner(window);

	Rectangle LeRect(Point(Vector2f(300, 250)), Vector2f(300, 100), bleu);
	tab_formes.ajouter(&LeRect);
	//tab_formes.supprimer(&LeRect);
	
	Img I(Point(Vector2f(325, 400)), image_nom);
	tab_formes.ajouter(&I);

		// Tant que la fenetre principale est ouverte
		while (window.isOpen())
		{
			tab_formes.flash(tempoClig);
			epp = tab_formes.pulse(tempoPul, epp);
			tab_formes.coulSwap(tempoCoul);

			if (selected != nullptr) {
				selected->setCoulBord(Color::Black);
				selected->setEpaiss(selected->getBEpaiss() + 1);
				menuCouleur.setVisible(true);
				
			}

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
						menu1.setVisible(true);
						// et on le place à coté de la fenetre principale
						menu1.setPosition(Vector2i(window.getPosition().x + (int)window.getSize().x + 20, window.getPosition().y));
						menu1.display();
					}
					else if(Vmenu == 1) {  // si menu deja ouvert on le ferme
						Vmenu = 2; 
						menu1.setVisible(false);
						menu2.setVisible(true);
						menu2.setPosition(Vector2i(window.getPosition().x + (int)window.getSize().x + 20, window.getPosition().y));
						menu2.display();
					}

					else if (Vmenu == 2){
						Vmenu = 0;
						menu2.setVisible(false);
					}
					std::cout << "M"; // debug
					
					//sf::sleep(sf::milliseconds(300));

				}

				if (event.key.code == sf::Keyboard::Up && window.hasFocus() && selected != nullptr) {
					tab_formes.monterForme(selected);
				}
				if (event.key.code == sf::Keyboard::Down && window.hasFocus() && selected != nullptr) {
					tab_formes.descendreForme(selected);
				}
				if (event.key.code == sf::Keyboard::Right && window.hasFocus() && selected != nullptr) {
						selected->setEpaiss(selected->getBEpaiss() + 1);
						selected->setBEpaiss(selected->getBEpaiss() + 1);
					
				}
				if (event.key.code == sf::Keyboard::Left && window.hasFocus() && selected != nullptr) {
					if (selected->getBEpaiss() > 0 && selected->getEpaiss() > 0) {
						selected->setEpaiss(selected->getBEpaiss() - 1);
						selected->setBEpaiss(selected->getBEpaiss() - 1);
					}

				} 
			}

			if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
				
				ptrforme = tab_formes.isOver(Vector2f(Mouse::getPosition(window)));
				
				ptrforme2 = tab_formes.modif(Vector2f(Mouse::getPosition(window)));

				 if (ptrforme != nullptr && selected == nullptr) {
					selected = ptrforme;
				}
				 else if (ptrforme != selected) {
					 selected->setEpaiss(selected->getBEpaiss() - 1);
					 selected->setCoulBord(selected->getCoulBord2());
					 selected = ptrforme;
					 if (selected == nullptr)
						 menuCouleur.setVisible(false);
				 }

				 
				
				
				dep = !dep;
			}
			
			if (event.type == Event::MouseMoved)
			{
				if (dep)
				{
					if (ptrforme != nullptr && ptrforme2 == nullptr) {
						ptrforme->move(Vector2f(Mouse::getPosition(window)));

					}
					if (ptrforme2 != nullptr)
					{
						ptrforme2->Size(Vector2f(Mouse::getPosition(window)));
					}
				}
			}
			if (event.type == Event::MouseButtonReleased)
			{
				dep = !dep;
			}

			if (event.type == Event::KeyPressed && event.key.code == Keyboard::P)
			{
				if (dep) {
					if (ptrforme != nullptr) {
						ptrforme->swaPlein();

					}
				}
				else {
					tab_formes.swaPleinAll();
				}
			}
			if (event.type == Event::KeyPressed && event.key.code == Keyboard::C)
			{
				
				cout << "C" << endl;
				clig = !clig;
				tab_formes.flash(tempoClig);
				
					if (selected != nullptr) {
						selected->cligno();

					}
				
				else {
					tab_formes.clignAll();
				}
				if (!clig) {
					tab_formes.resetClig();
					sleep(milliseconds(100));
					cout << "resetted" << endl;
				}
			}

			if (event.type == Event::KeyPressed && event.key.code == Keyboard::O)
			{
				cout << "O" << endl;
				pul = !pul;
				epp = tab_formes.pulse(tempoPul, epp);
				if (!pul) {
					tab_formes.resetEppaiss();
					epp = 1;
				}
				
					if (selected != nullptr) {
						selected->pul();

					}
				
				else {
					tab_formes.pulAll();
				}
				
			}

			if (event.type == Event::KeyPressed && event.key.code == Keyboard::S)
			{
				cout << "S" << endl;
				
				if (dep) {
					if (selected != nullptr) {
						tab_formes.supprimer(selected);

					}
				}
				

			}
			if (event.type == Event::KeyPressed && event.key.code == Keyboard::I)
			{
				cout << "I" << endl;
				coul = !coul;
				tab_formes.coulSwap(tempoCoul);
				if (!coul) {
					
				}
				
					if (selected != nullptr) {
						selected->coul();

					}
				
				else {
					tab_formes.coulAll();
				}

			}
		}

		while (menu1.pollEvent(event))
		{ // Event handler du menu

			if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::M) {
					// on répète le code pour ouvrir/fermer le menu
					// pour pouvoir le faire avec ou sans le focus
					if (Vmenu == 0) {
						Vmenu = 1;
						menu1.setVisible(true);
					}
					else if (Vmenu == 1) {
						Vmenu = 2;
						menu1.setVisible(false);
						menu2.setVisible(true);
					}
					else if (Vmenu == 2) {
						Vmenu = 0;
						menu2.setVisible(false);
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

					Rectangle *NvoRecangle = new Rectangle(Point(Vector2f(100, 130)), Vector2f (200, 50), vert);
					tab_formes.ajouter(NvoRecangle);
				}
				if (bTrig.test_clic(Vector2f(event.mouseButton.x, event.mouseButton.y))) {
					// Si Triangle
					cout << "Triangle !" << endl;
					bTrig.swap();

					Triangle *NvoTriangle = new Triangle(n1, n2, n3, rouge);
					tab_formes.ajouter(NvoTriangle);
				}
				if (bPnt.test_clic(Vector2f(event.mouseButton.x, event.mouseButton.y))) {
					// Si Point
					cout << "Point !" << endl;
					bPnt.swap();

					Point NvoPt(Vector2f(400, 400));
					NvoPt.dessiner(window, true);
				}

				if (bCerc.test_clic(Vector2f(event.mouseButton.x, event.mouseButton.y))) {
					// Si Cercle
					cout << "Cercle !" << endl;
					bCerc.swap();

					Cercle *NvoCercle = new Cercle(Vector2f(200, 200), 50, violet);
					tab_formes.ajouter(NvoCercle);
				}

			}

			if (event.type == Event::MouseButtonReleased && event.mouseButton.button == Mouse::Left) {
				// Si clic gauche relaché
				if (bRect.test_clic(Vector2f(event.mouseButton.x, event.mouseButton.y))) {
					// si souris sur le bouton du rectangle
					bRect.swap(); // changement a nouveau de la couleur
				}

				if (bTrig.test_clic(Vector2f(event.mouseButton.x, event.mouseButton.y))) {
					// Si Triangle
					bTrig.swap();
				}

				if (bPnt.test_clic(Vector2f(event.mouseButton.x, event.mouseButton.y))) {
					// Si Point
					bPnt.swap();

					
				}

				if (bCerc.test_clic(Vector2f(event.mouseButton.x, event.mouseButton.y))) {
					// Si Cercle
					bCerc.swap();
				}
			}


		}

		while (menu2.pollEvent(event))
		{ // Event handler du menu

			if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::M) {
					// on répète le code pour ouvrir/fermer le menu
					// pour pouvoir le faire avec ou sans le focus
					if (Vmenu == 0) {
						Vmenu = 1;
						menu1.setVisible(true);
					}
					else if (Vmenu == 1) {
						Vmenu = 2;
						menu1.setVisible(false);
						menu2.setVisible(true);
					}
					else if (Vmenu == 2) {
						Vmenu = 0;
						menu2.setVisible(false);
					}
					std::cout << "M"; // debug

					//sf::sleep(sf::milliseconds(300));


				}
			}

			// Button handler :
			if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
				// si clic gauche enfoncé

				if (bRet.test_clic(Vector2f(event.mouseButton.x, event.mouseButton.y))) {
					// Si la souris est sur le bouton du Rectangle
					cout << "Retour !" << endl; // debug
						bRet.swap(); // on change la couleur du bouton
						if (Bclig) {
							Bclig = false;
							bClig.swap();
						}
						if (Bcoul) {
							Bcoul = false;
							bRot.swap();
						}
						if (Bpul) {
							Bpul = false;
							bPul.swap();
						}


				}
				if (bRot.test_clic(Vector2f(event.mouseButton.x, event.mouseButton.y))) {
					// Si Triangle
					cout << "Couleur !" << endl;
					if (bRot.getCouleurBout() != bRot.getCouleurSec()) { // est cliqué
						bRot.swap(); // on change la couleur du bouton
						Bcoul = true;
					}
					else {
						bRot.swap(); // on change la couleur du bouton
						Bcoul = false;
					}

				}
				if (bClig.test_clic(Vector2f(event.mouseButton.x, event.mouseButton.y))) {
					// Si Point
					cout << "Cligno !" << endl;
					if (bClig.getCouleurBout() != bClig.getCouleurSec()) { // est cliqué
						bClig.swap(); // on change la couleur du bouton
						Bclig = true;
						cout << "true" << endl;
					}
					else {
						bClig.swap(); // on change la couleur du bouton
						Bclig = false;
						cout << "false" << endl;
					}
				}

				if (bPul.test_clic(Vector2f(event.mouseButton.x, event.mouseButton.y))) {
					// Si Cercle
					cout << "Pulse !" << endl;
					if (bPul.getCouleurBout() != bPul.getCouleurSec()) { // est cliqué
						bPul.swap(); // on change la couleur du bouton
						Bpul = true;
					}
					else {
						bPul.swap(); // on change la couleur du bouton
						Bpul = false;
					}
				}

			}

			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Down) {
				if (Bclig && tempoClig >0) {
					tempoClig = tempoClig - 2;
					//cout << "Temporisation Clignotement (+2) : " << tempoClig << endl;

				}
				if (Bpul && tempoPul>0) {
					tempoPul = tempoPul - 2;
					//cout << "Temporisation Pulsation (+2) : " << tempoPul << endl;

				}
				if (Bcoul && tempoCoul>0) {
					tempoCoul = tempoCoul - 2;
					//cout << "Temporisation Couleur (+2) : " << tempoCoul << endl;

				}
				TCoul.setString(to_string(tempoCoul));
				TPul.setString(to_string(tempoPul));
				TClig.setString(to_string(tempoClig));

			}

			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Up) {
				if (Bclig && tempoClig<500) {
					tempoClig = tempoClig + 2;
					//cout << "Temporisation Clignotement (-2) : " << tempoClig << endl;
				}
				if (Bpul && tempoPul<80) {
					tempoPul = tempoPul + 2;
					//cout << "Temporisation Pulsation (-2) : " << tempoPul << endl;

				}
				if (Bcoul && tempoCoul<500) {
					tempoCoul = tempoCoul + 2;
					//cout << "Temporisation Couleur (-2) : " << tempoCoul << endl;

				}

				TCoul.setString(to_string(tempoCoul));
				TPul.setString(to_string(tempoPul));
				TClig.setString(to_string(tempoClig));
			}

			if (event.type == Event::MouseButtonReleased && event.mouseButton.button == Mouse::Left) {
				// Si clic gauche relaché
				if (bRet.test_clic(Vector2f(event.mouseButton.x, event.mouseButton.y))) {
					// si souris sur le bouton du rectangle
					bRet.swap(); // changement a nouveau de la couleur
					Vmenu = 1;
					menu2.setVisible(false);
					menu1.setVisible(true);


				}
			}
				


		}

		while (menuCouleur.pollEvent(event))
		{ // Event handler du menu
			if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
				Vector2f souris(event.mouseButton.x, event.mouseButton.y);
				if (selected != nullptr) {
					if (BC1.test_clic(souris)) {
						selected->setColor(Color::Black);
						selected->setColor2(Color::Black);

						selected->setCoulBord(Color::Black);
						selected->setCoulBord2(Color::Black);
					}
					else if (BC2.test_clic(souris)) {
						selected->setColor(Color::White);
						selected->setColor2(Color::White);

						selected->setCoulBord(Color::White);
						selected->setCoulBord2(Color::White);
					}
					else if (BC3.test_clic(souris)) {
						selected->setColor(Color::Red);
						selected->setColor2(Color::Red);

						selected->setCoulBord(Color::Red);
						selected->setCoulBord2(Color::Red);
					}
					else if (BC4.test_clic(souris)) {
						selected->setColor(Color::Green);
						selected->setColor2(Color::Green);

						selected->setCoulBord(Color::Green);
						selected->setCoulBord2(Color::Green);
					}
					else if (BC5.test_clic(souris)) {
						selected->setColor(Color::Blue);
						selected->setColor2(Color::Blue);

						selected->setCoulBord(Color::Blue);
						selected->setCoulBord2(Color::Blue);
					}
					else if (BC6.test_clic(souris)) {
						selected->setColor(Color::Yellow);
						selected->setColor2(Color::Yellow);

						selected->setCoulBord(Color::Yellow);
						selected->setCoulBord2(Color::Yellow);
					}
					else if (BC7.test_clic(souris)) {
						selected->setColor(Color::Magenta);
						selected->setColor2(Color::Magenta);

						selected->setCoulBord(Color::Magenta);
						selected->setCoulBord2(Color::Magenta);
					}
					else if (BC8.test_clic(souris)) {
						selected->setColor(Color::Cyan);
						selected->setColor2(Color::Cyan);

						selected->setCoulBord(Color::Cyan);
						selected->setCoulBord2(Color::Cyan);
					}
					else if (BC9.test_clic(souris)) {
						selected->setColor(Color(255,115,5));
						selected->setColor2(Color(255,115,5));

						selected->setCoulBord(Color(255, 115, 5));
						selected->setCoulBord2(Color(255, 115, 5));
					}
					else if (BC10.test_clic(souris)) {
						selected->setColor(Color(100, 70, 35));
						selected->setColor2(Color(100,70,35));

						selected->setCoulBord(Color(100, 70, 35));
						selected->setCoulBord2(Color(100, 70, 35));
					}
					else if (BC11.test_clic(souris)) {
						selected->setColor(Color(255,96,250));
						selected->setColor2(Color(255, 96, 250));

						selected->setCoulBord(Color(255, 96, 250));
						selected->setCoulBord2(Color(255, 96, 250));
					}
					else if (BC12.test_clic(souris)) {
						selected->setColor(Color(0,255,150));
						selected->setColor2(Color(0, 255, 150));

						selected->setCoulBord(Color(0, 255, 150));
						selected->setCoulBord2(Color(0, 255, 150));
					}
					else if (BR.test_clic(souris)) {
						if (BR.getCouleurBout() != BR.getCouleurSec()) { // est cliqué
							BR.swap(); // on change la couleur du bouton
							BsR = true;
						}
						else {
							BR.swap(); // on change la couleur du bouton
							BsR = false;
						}
					}
					else if (BG.test_clic(souris)) {
						if (BG.getCouleurBout() != BG.getCouleurSec()) { // est cliqué
							BG.swap(); // on change la couleur du bouton
							BsG = true;
						}
						else {
							BG.swap(); // on change la couleur du bouton
							BsG = false;
						}
					}
					else if (BB.test_clic(souris)) {
					if (BB.getCouleurBout() != BB.getCouleurSec()) { // est cliqué
						BB.swap(); // on change la couleur du bouton
						BsB = true;
					}
					else {
						BB.swap(); // on change la couleur du bouton
						BsB = false;
					}
					}
					else if (BA.test_clic(souris)) {
					if (BA.getCouleurBout() != BB.getCouleurSec()) { // est cliqué
						BA.swap(); // on change la couleur du bouton
						BsA = true;
					}
					else {
						BA.swap(); // on change la couleur du bouton
						BsA = false;
					}
					}
					else if (BRd.test_clic(souris)) {
						
					}
					else if (BRg.test_clic(souris)) {
						
					}
					else if (BGd.test_clic(souris)) {
						
					}
					else if (BGg.test_clic(souris)) {
						
					}
					else if (BBd.test_clic(souris)) {
						
					}
					else if (BBg.test_clic(souris)) {
						
					}
					else if (BV.test_clic(souris)) {
						selected->setColor(Color(Sr, Sg, Sb, Sa));
						selected->setColor2(Color(Sr, Sg, Sb, Sa));

						selected->setCoulBord(Color(Sr, Sg, Sb,Sa));
						selected->setCoulBord2(Color(Sr, Sg, Sb,Sa));

						
					}
				}
			}

			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Right) {
				if (BsR && Sr < 255) {
					
					Sr = Sr + 2;
				}
				if (BsG && Sg < 255) {
					Sg = Sg + 2;
				}
				if (BsB && Sb < 255) {
					Sb = Sb + 2;
				}
				if (BsA && Sa < 255) {
					Sa = Sa + 2;
				}

				RectValid.setFillColor(Color(Sr, Sg, Sb, Sa));
				rgb.setString("( " + to_string(Sr) + " , " + to_string(Sg) + " , " + to_string(Sb) + " , " + to_string(Sa) + " )");
			}

			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Left) {
				if (BsR && Sr > 0) {
					Sr = Sr - 2;
				}
				if (BsG && Sg > 0) {
					Sg = Sg - 2;
				}
				if (BsB && Sb > 0) {
					Sb = Sb - 2;
				}
				if (BsA && Sa > 0) {
					Sa = Sa - 2;
				}

				RectValid.setFillColor(Color(Sr, Sg, Sb,Sa));
				rgb.setString("( " + to_string(Sr) + " , " + to_string(Sg) + " , " + to_string(Sb) + " , " + to_string(Sa) +  " )");

			}




		}
		window.clear();
		//fond dessiné	
		window.draw(fond);
		tab_formes.dessiner(window, tab_formes.isOver(Vector2f(Mouse::getPosition(window))));

		if (menu1.hasFocus() || first) {
			menu1.clear(); // Clear de la fenetre de menu
			menu1.draw(fondMenu); // Ajout du fond blanc du menu

			// Affichage des icones des formes
			menu1.draw(Ipnt);
			menu1.draw(Irect);
			menu1.draw(Icerc);
			menu1.draw(Itrig);

			// Affichage des boutons des formes
			bRect.afficher(menu1, FKufi);
			bCerc.afficher(menu1, FKufi);
			bTrig.afficher(menu1, FKufi);
			bPnt.afficher(menu1, FKufi);

			menu1.display();
		}
		//Affichage des boutons de couleur
		
		if (menuCouleur.hasFocus() || first) {
			menuCouleur.clear();
			menuCouleur.draw(fondMenu);
			BC1.afficher(menuCouleur, FKufi);
			BC2.afficher(menuCouleur, FKufi);
			BC3.afficher(menuCouleur, FKufi);
			BC4.afficher(menuCouleur, FKufi);
			BC5.afficher(menuCouleur, FKufi);
			BC6.afficher(menuCouleur, FKufi);
			BC7.afficher(menuCouleur, FKufi);
			BC8.afficher(menuCouleur, FKufi);
			BC9.afficher(menuCouleur, FKufi);
			BC10.afficher(menuCouleur, FKufi);
			BC11.afficher(menuCouleur, FKufi);
			BC12.afficher(menuCouleur, FKufi);
			BR.afficher(menuCouleur, FKufi);
			BG.afficher(menuCouleur, FKufi);
			BB.afficher(menuCouleur, FKufi);
			BA.afficher(menuCouleur, FKufi);
			BRd.afficher(menuCouleur, FKufi);
			BRg.afficher(menuCouleur, FKufi);
			BBg.afficher(menuCouleur, FKufi);
			BBd.afficher(menuCouleur, FKufi);
			BGd.afficher(menuCouleur, FKufi);
			BGg.afficher(menuCouleur, FKufi);
			BAd.afficher(menuCouleur, FKufi);
			BAg.afficher(menuCouleur, FKufi);
			menuCouleur.draw(RectValid);
			BV.afficher(menuCouleur, FKufi);
			menuCouleur.draw(rgb);


			menuCouleur.display();
		}
		// Affichage global de la fenetre du menu
		
		if (menu2.hasFocus() || first) {
			menu2.draw(fondMenu); // Ajout du fond blanc du menu
			bRot.afficher(menu2, FKufi);
			bPul.afficher(menu2, FKufi);
			bRet.afficher(menu2, FKufi);
			bClig.afficher(menu2, FKufi);
			menu2.draw(TClig);
			menu2.draw(TPul);
			menu2.draw(TCoul);

			// Affichage global de la fenetre du menu
			menu2.display();
		}
		// -- test forme --

		

		Point p(Vector2f(200, 80));
		Point pt2(T.getCentre());
		pt2.dessiner(window, true);
		p.dessiner(window, true);

		// -- Fin test forme --





		/*
		Point p1(Vector2f(400, 70));
		p1.dessiner(window, true);

		
		Point pt2(300, 300, 200, 100, 0);
		pt2.dessiner(window, true);
		*/
		
		//ELBUTTON.afficher(window, FKufi, Color::Black);
		window.display();
		first = false;
	}

	return 0;
}

/*

float b = sqrt(pow((a3.getAncre().x - curseur.x), 2) + pow((a3.getAncre().y - curseur.y), 2));
	float c = sqrt(pow((getPoint().getAncre().x - curseur.x), 2) + pow((getPoint().getAncre().y - curseur.y), 2));
	float a = sqrt(pow((a2.getAncre().x - curseur.x), 2) + pow((a2.getAncre().y - curseur.y), 2));



*/