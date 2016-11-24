/**
 * Polytech Marseille
 * Case 925 - 163, avenue de Luminy
 * 13288 Marseille CEDEX 9
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
 * @todo -
 *
 * @bug -
 */

/**
 * @file Carte.cpp
 * @brief La classe Carte permet de g�rer les objets dans le monde
 */

#include <iostream>
#include "Carte.h"

using namespace std;

/** Le constructeur <b>Carte</b> initialise le tableau contenant les objets affichables
	 * @param x - la longueur de la carte
	 * @param y - la largeur de la carte */
Carte::Carte( int x , int y ) {
	sizeX = x ;
	sizeY = y ;
	map = new int*[sizeY];

	int i,		// indice parcours sur l'axe Y
		j;		// indice parcours sur l'axe X
	for( i = 0 ; i < sizeY ; i++ ){
		map[i] = new int[sizeX];
		for( j = 0 ; j < sizeX ; j++ ){
			map[i][j] = 0 ;
		}
	}

	map[0][0] = 2;
	map[0][2] = 1;
	map[0][3] = 3;
	map[1][0] = 1;
	map[1][1] = 1;
	map[2][0] = 3;
}

/** Le destructeur <b>Carte</b> */
Carte::~Carte() {

}

/** La m�thode <b>display</b> permet d'afficher la carte sur la console */
void Carte::display( void ) {
	int i;		// indice parcours sur l'axe Y
	cout << " ----------------- " << endl;
	for( i = sizeX-1 ; i >= 0 ; i-- ){
		cout << " | " << map[i][0] << " | " << map[i][1] << " | "<< map[i][2] << " | "<< map[i][3] << " | "<< endl;
		cout << " ----------------- " << endl;
	}
}
