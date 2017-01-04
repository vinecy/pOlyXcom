/*
 * Soin.cpp
 *
 *  Created on: 15 d�c. 2016
 *      Author: Vincent
 */

#include"Soin.h"
#include<iostream>
using namespace std;

/** Constucteur de medkit*/
Soin::Soin()
{
	_uses=1;
	_heal=4;
}

/** change le nombre de medkit disponibles
 * @param q - quantit� de medkit a ajouter */
void Soin::add_uses(int q)
{
	_uses=_uses+q;
}

int Soin::get_heal()
{
	return(_heal);
}

void Soin::display_info()
{
	cout<<"Medkit( heal= "<<_heal<<" , uses= "<<_uses<<" )"<<endl;
}

int Soin::get_uses()
{
	return(_uses);
}

/** destructeur de Soin*/
Soin::~Soin()
{

}
