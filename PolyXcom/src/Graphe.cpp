/*
 * Graphe.cpp
 *
 *  Created on: 27 nov. 2016
 *      Author: Valentin BISSUEL
 */

#include "Graphe.h"
#include "Noeud.h"
#include "Carte.h"
#include <iostream>
#include <cstdlib>
#include <list>
using namespace std;

Graphe::Graphe(Carte *map) {
	int i = 0,
		j = 0;

	_sizeX = map->get_sizeX();							// La nombre de Noeud du graphe
	_sizeY = map->get_sizeY();							// est �gale � la taille de la carte

	_graphe = new Noeud *[_sizeX];						//
	//cout << " allocation tableau _sizeX...\n";
	for( i = 0 ; i < _sizeX ; i++ ){					// Initialisation du graphe selon
		_graphe[i] = new Noeud [_sizeY];				// l'algorithme A*
		//cout << " allocation tableau _sizeY ...\n";
		for( j = 0 ; j < _sizeY ; j++ ){
			_graphe[i][j] = Noeud(i,j);
			//cout << "adresse Noeud : " << &_graphe[i][j] << "\n";
			if( map->moveIsPossible(i, j) == false 		// Si c'est une case infranchissable
				&& map->get_IDin(i, j) != 0 ){			// c'est � dire un obstacle
				_graphe[i][j].set_costFromBegin(-1);	// on met des couts negatifs �
				_graphe[i][j].set_costFromEnd(-1);		// FromEnd et FromBegin (_G et _H dans le Noeud)
			}
		}
	}
	cout << " + graphe de taille " << _sizeX*_sizeY << " cr�e" << endl;
}

Noeud Graphe::lowestNode(list<Noeud> &l){
	Noeud min;
	/*int sizeL,i;
	list<Noeud>::iterator lit (*l.begin()), lend(*l.end());
	sizeL = l.size();


	cout << " taille " << l.size() << endl ;
	for( i = 0 ; i<sizeL ; i++){
		lit++;
		//cout << " on a "<< l.front().get_heuristic() << endl ;
	}

	min = l.front();
	lit++;
	while(lit != lend){
		if( min.get_heuristic() >= l.front().get_heuristic() ){
			min = l.front();
		}
		lit++;
	}
	cout << "le noeud minimal est " << min.get_X() << "," << min.get_Y() << endl;*/
	return min;
}

bool Graphe::isIn(list<Noeud> &l, Noeud &cible){
	bool rep = false;
	list<Noeud>::iterator lit (l.begin()), lend(l.end());
	while( lit !=lend && rep == false){
		if( (*lit).get_X() == cible.get_X()
		 && (*lit).get_Y() == cible.get_Y() ){
			rep = true;
			cout << "isIn: Noeud pr�sent " << endl;
		}
		lit++;
	}
	return rep;
}


list<Noeud> Graphe::find_Voisin(int xC, int yC, int xA, int yA, int xB, int yB){
	list<Noeud> l;

	if( xC != _sizeX-1 ){;
		l.push_back(this->get_Noeud(xC + 1, yC ));
		if( yC != _sizeY-1 ){
			l.push_back(this->get_Noeud(xC + 1, yC+ 1));
		} else {
			cout << "find_Voisin: y=" << _sizeY-1 << "  inaccessible car CY = " << yC << endl;
		}
		if( yC != 0 ){
			l.push_back(this->get_Noeud(xC + 1, yC - 1));
		} else {
			cout << "find_Voisin: y=" << 0 << "  inaccessible car CY = " << yC << endl;
		}
	} else {
		cout << "find_Voisin: x=" << _sizeX-1 << "  inaccessible car CX = " << xC << endl;
	}
	if( xC != 0 ){
		l.push_back(this->get_Noeud(xC - 1, yC ));
		if( yC != _sizeY-1 ){
			l.push_back(this->get_Noeud(xC - 1, yC + 1));
		} else {
			cout << "find_Voisin: y=" << _sizeY-1 << "  inaccessible car CY = " << yC << endl;
		}
		if( yC != 0 ){
			l.push_back(this->get_Noeud(xC - 1, yC - 1));
		} else {
			cout << "find_Voisin: y=" << 0 << "  inaccessible car CY = " << yC << endl;
		}
	} else {
		cout << "find_Voisin: x=" << 0 << "  inaccessible car CX = " << xC << endl;
	}
	if( yC != _sizeY-1 ){
		l.push_back(this->get_Noeud(xC, yC + 1));
	} else {
		cout << "find_Voisin: y=" << _sizeY-1 << "  inaccessible car CY = " << yC << endl;
	}
	if( yC != 0 ){
		l.push_back(this->get_Noeud(xC, yC - 1));
	} else {
		cout << "find_Voisin: y=" << 0 << "  inaccessible car CY = " << yC << endl;
	}
	return l;
}


void Graphe::display(){
	int i,												// indice parcours sur l'axe Y
		j;												// indice parcours sur l'axe X

	cout << " *** affichage du graphe *** " << endl;
	cout << " ----------------- " << endl;
	for( i = _sizeY-1 ; i >= 0 ; i-- ){
		for( j = 0 ; j < _sizeX ; j++ ){
			cout << " | " << _graphe[j][i].get_costFromBegin() << " ; " << _graphe[j][i].get_costFromEnd() << " ; " << _graphe[j][i].get_heuristic();
		}
		cout << " | "<< endl << " ----------------- " << endl;
	}
	cout << " *** fin affichage *** " << endl;
}

Noeud Graphe::get_Noeud(int x, int y){
	return _graphe[x][y];
}

Graphe::~Graphe() {
	cout << " - graphe d�truit" << endl;
}

