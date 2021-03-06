/**
 * Polytech Marseille
 * Case 925 - 163, avenue de Luminy
 * 13288 Marseille CEDEX 9
 *
 *
 *
 * Ce fichier est l'oeuvre d'�l�ves de Polytech Marseille. Il ne peut �tre
 * reproduit, utilis� ou modifi� sans l'avis express de ses auteurs.
 */

/**
 * @author BARTHOLOMEAU Vincent <vincent.bartholomeau@etu.univ-amu.fr>
 * @author BISSUEL Valentin <valentin.bissuel@etu.univ-amu.fr>
 *
 * @version 0.0.1 / 24/11/2016
 *
 * @file main.c
 * @brief Le main permet de lancer le jeu, charger une partie, la reinitialiser ou quitter le jeu.
 */

#include <iostream>				// Biblioth�que pour la console
#include <SFML/Graphics.hpp>	// Biblioth�que multim�dia
#include "IHMmanager.h"			// Appel de la contr�leur
#include "Menu.h"				// Appel de l'Etat Menu

int main(){
	cout << " lancement de PolyXcom " << endl;

	// Cr�ation de la fen�tre
	RenderWindow window( VideoMode( VideoMode::getDesktopMode().width
								  , VideoMode::getDesktopMode().height
								  , VideoMode::getDesktopMode().bitsPerPixel
								  )
						, "PolyXcom"
						, Style::Close | Style::Titlebar | Style::Fullscreen);
	IHMmanager ihm(window);			// Cr�ation du gestionnaire de d'Etats de Jeu
	ihm.PushState( new Menu() );	// Ajout de l'Etat Menu Principal

	// On fait tourner en boucle l'IHM manager
	while( ihm.isRunning() ){		// tant que la fen�tre est toujours ouvert
		ihm.HandleEvents();			// maj des evenements externes de l'Etat Actif
		ihm.Update();				// maj des variables de l'etat actif
		ihm.Draw();					// maj de la fen�tre
	}
}
