/*
 * Grenade.h
 *
 *  Created on: 15 d�c. 2016
 *      Author: Vincent
 */

#ifndef GRENADE_H_
#define GRENADE_H_


using namespace std;

class Grenade
{
private:
	int _dammage;			//dommages de la grenade
	int _number;			//nombre de grenade restantes
	int _range;				//portee de la grenade
public:
	Grenade();				//constructeur
	Grenade(int g1,int g2, int g3);

	int get_dammage();		//getter
	int get_number();
	int get_range();

	void display_info();

	//void add_number(int quantity);	//modifie le nombre de grenades disponibles

	~Grenade();
};


#endif /* GRENADE_H_ */
