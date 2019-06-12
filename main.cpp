// ConsoleApplication2.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include "Point.h"
#include "Image.h"
#include "Formes.h"
#include "cercle.h"
#include "Ellipse.h"
#include "rectangle.h"
#include "triangle.h"
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

//Vector test triangle
Vector2f a = Vector2f(450, 250);
Vector2f b = Vector2f(300, 250);
Vector2f c = Vector2f(300, 400);

//image
String bite = "bite.png";


/*
void Deplacement(Rectangle R,RenderWindow& window, bool veref)
{
	if (Mouse::isButtonPressed(Mouse::Left) && veref == true)
	{
		while (Mouse::isButtonPressed(Mouse::Left))
		{
			R.setPoint(Vector2f(Mouse::getPosition(window)));
			window.clear();
			R.dessiner(window);
			window.display();
		}
	}
}
*/

//pointeur sur forme
Formes tab_formes;
Forme * ptrforme = nullptr;
Forme * ptrforme2 = nullptr;



int main()
{
	RenderWindow window(VideoMode(1200, 800, 64), "Un debut a tout, pas vrai?", Style::Close | Style::Titlebar);

	//fond blanc de la fenetre
	RectangleShape fond(Vector2f(1200, 800));
	fond.setFillColor(Color::White);

	Rectangle R(Point (Vector2f (300,250)), Vector2f (300, 100), bleu);
	Cercle C(Point(Vector2f (100, 350)), 100, rouge);
	Triangle T(a, b, c, rouge);
	Ellipse E( Point(Vector2f(50,200)), Vector2f(50,150),violet);


	Img I(Point(Vector2f(325,400)), bite);
	
	
	//bool
	
	bool dep = false;

	//enregistrement des formes dans le tableau de forme
	tab_formes.ajouter(& R);
	tab_formes.ajouter(& C);
	tab_formes.ajouter(& E);
	tab_formes.ajouter(& I);
	tab_formes.ajouter(& T);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();

			//interaction souris
			if (event.type == Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == Mouse::Left)
				{
					ptrforme = tab_formes.isOver(Vector2f(Mouse::getPosition(window)));

					ptrforme2 = tab_formes.modif(Vector2f(Mouse::getPosition(window)));
				}
				
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
		}

		//dessin
		window.clear();

		window.draw(fond);

		tab_formes.dessiner(window, tab_formes.isOver(Vector2f(Mouse::getPosition(window))));
		
		//interaction clavier
		/*if (event.type == Event::KeyPressed)
		{
			if (event.key.code == Keyboard::P)
			{
				C.dessiner(window, verif = !verif);
			}
		}
		*/


		window.display();
	}
	return 0;
}









//Triangle T(a, b, c, rouge);
	//T.dessiner(window);


	//Point p(Vector2f(200, 80));
	//p.draw(window);
	/*
	Point p1(80, 70, rouge);
	p1.dessiner(window, true);


	Point pt2(300, 300, 200, 100, 0);
	pt2.dessiner(window, true);
	*/
