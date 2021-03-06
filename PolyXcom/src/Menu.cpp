/*
 * Menu.cpp
 *
 *  Created on: 14 janv. 2017
 *      Author: Valentin BISSUEL
 */

#include "Menu.h"
#include "Partie.h"

#include <iostream>
using namespace std;

static RectangleShape bouton[3];	// bouton "nouvelle Partie", "Charger Partie", "Quitter la Partie"
static Text text[3];				// texte des boutons "nouvelle Partie", "Charger Partie", "Quitter la Partie"
static Image i;						// Fichier contenant la feuille de Sprite
static Texture t;					// Texture charg� � partir la feuille de Sprite
static Sprite logo;					// Image correspondant au logo et charg� � partir de la texture
static Font font;					// Police de caract�re

Menu::Menu(){
	Init();
	cout << " + Menu Construit " << endl;
}

/*
 * Initialisation de l'interface
 */
void Menu::Init(){
	if (!font.loadFromFile("src\\PressStart2P.ttf")){			// chargement de la police de caract�re
		cout << "erreur de chargement de la police" << endl;
	}
	if( !i.loadFromFile("src\\sprite.png") ){					// chargement de la feuille de sprite
		cout << "feuille de sprite introuvable " << endl;
	} else {
		i.createMaskFromColor(Color::White);					// application d'un masque de transparance sur l'arri�re fond
		t.loadFromImage(i);
		//t.update(i);
		//t.setSmooth(true);  // lissage des textures
		logo.setTexture(t);
		logo.setTextureRect(IntRect(1,391,69,74));
		logo.setScale(5, 5);
		//logo.setTextureRect(IntRect(1,1,63,63));
		cout << "feuille de sprite cr�e " << endl;
	}

	// Construction des boutons et attribution des couleur par d�faut
	for(int i=0 ; i<3 ; i++){
		bouton[i] = RectangleShape(Vector2f(400,100)); bouton[0].setFillColor(unSelected);
		text[i].setFont(font);
		text[i].setCharacterSize(22);
		text[i].setOutlineColor(Color::White);
	}
	text[0].setString("Nouvelle Partie");
	text[1].setString("Charger Partie");
	text[2].setString("Quitter la Partie");
}

void Menu::CleanUp(){
	cout << " ... Fermeture du Menu " << endl;
}

void Menu::Pause(){
	cout << " ||  Menu en pause " << endl;
}

void Menu::Resume(){
	cout << " |>  Reprise du menu " << endl;
}

void Menu::HandleEvents(IHMmanager* game){
	Event event;
	Window *window = game->get_myWindow();
	int x,y;

	while(window->pollEvent(event)){			// d�s qu'un evenement est d�clench�
		switch (event.type) // Type de l'�v�nement
		{
			case Event::Closed : // Bouton de fermeture
				game->CleanUp();
				break;
			case Event::KeyReleased : // Appui sur une touche du clavier
			{
				switch (event.key.code) // La touche qui a �t� appuy�e
				{
					case Keyboard::Up:  // Echap
						choix--;
						if(choix == 0) choix = 3;
						break;
					case Keyboard::Escape: // Echap
						window->close();
						break;
					case Keyboard::Down : // Echap
						choix++;
						if(choix == 4) choix = 1;
						break;
					case Keyboard::Return : // Echap
						valide = true;
						break;
					default :
						break;
				}
				break;
			}
			case Event::MouseMoved :
				x = event.mouseMove.x;
				y = event.mouseMove.y;
				if( bouton[0].getGlobalBounds().contains(x, y) == true ){
					choix = 1;
				} else if( bouton[1].getGlobalBounds().contains(x, y) == true ){
					choix = 2;
				} else if( bouton[2].getGlobalBounds().contains(x, y) == true ){
					choix = 3;
				} else {
					choix = 0; valide = false;
				}
				break;
			case Event::MouseButtonPressed :
				if( event.mouseButton.button == Mouse::Left ){
					valide = true;
				}
				break;
			default :
				break;
		}
	}

}
void Menu::Update(IHMmanager* game){
	int size_WindowX = game->get_myWindow()->getSize().x;
	int	size_WindowY = game->get_myWindow()->getSize().y;
	int espacement = 10;

	logo.setScale(5 * (game->_scaleBouton), 5 * (game->_scaleBouton) );

	bouton[0].setSize(Vector2f(400*game->_scaleBouton,100*game->_scaleBouton));
	bouton[1].setSize(Vector2f(400*game->_scaleBouton,100*game->_scaleBouton));
	bouton[2].setSize(Vector2f(400*game->_scaleBouton,100*game->_scaleBouton));

	text[0].setScale((game->_scaleBouton),(game->_scaleBouton));
	text[1].setScale((game->_scaleBouton),(game->_scaleBouton));
	text[2].setScale((game->_scaleBouton),(game->_scaleBouton));

	bouton[0].setPosition( ( (size_WindowX/2) - (bouton[0].getSize().x)/2 )
			, ( size_WindowY/2 ) );
	bouton[1].setPosition( ( (size_WindowX/2) - (bouton[1].getSize().x)/2 )
			, ( (bouton[0].getPosition().y) + (bouton[0].getSize().y) + espacement ) );
	bouton[2].setPosition( ( (size_WindowX/2) - (bouton[2].getSize().x)/2 )
			, ( (bouton[1].getPosition().y) + (bouton[1].getSize().y) + espacement ) );

	for( int i = 0 ; i < 3 ; i++ ){
		text[i].setPosition( (bouton[i].getPosition().x + bouton[i].getSize().x/2 - text[i].getGlobalBounds().width/2)
				, (bouton[i].getPosition().y + bouton[i].getSize().y/2 - text[i].getGlobalBounds().height/2) );
	}

	logo.setPosition( (size_WindowX/2) - (logo.getGlobalBounds().width/2)
			, (size_WindowY/4) - (logo.getGlobalBounds().height/2) );
	if( choix == 1 ) bouton[0].setFillColor(selected);
	else bouton[0].setFillColor(unSelected);
	if( choix == 2 ) bouton[1].setFillColor(selected);
	else bouton[1].setFillColor(unSelected);
	if( choix == 3 ) bouton[2].setFillColor(selected);
	else bouton[2].setFillColor(unSelected);

	fstream f("src\\save.txt", ios::in | ios::ate);
	if(!f) bouton[1].setFillColor(locked);

	if(valide == true){
		switch(choix){
		case 1:
		{
			cout << " * Nouvelle Partie " << endl;
			game->PushState(new Partie(1));
			choix = 0;
		}
		break;
		case 2:
		{
			cout << " * Charger Partie " << endl;
			if(f){
				f.close();
				game->PushState(new Partie(2));
			}
		}
		break;
		case 3:
		{
			cout << " * Bye " << endl;
			game->get_myWindow()->close();
		}// fin
		break;
		}
		valide = false;
	}
}
void Menu::Draw(IHMmanager* game){
	game->get_myWindow()->clear();
	game->get_myWindow()->draw(logo);
	for(int i = 0 ; i<3 ; i++){
		game->get_myWindow()->draw(bouton[i]);
		game->get_myWindow()->draw(text[i]);
	}
	game->get_myWindow()->display();
}


Menu::~Menu() {
	cout << " - Menu Detruit " << endl;
}

