/*
 * IHMstate.h
 *
 *  Created on: 14 janv. 2017
 *      Author: Valentin BISSUEL
 */

#ifndef IHMSTATE_H_
#define IHMSTATE_H_

#include "IHMmanager.h"

class IHMmanager;

class IHMstate {
protected:
	IHMstate(){}
public:
	virtual void Init() = 0 ;
	//virtual void Cleanup() = 0;

	virtual void Pause() = 0 ;
	virtual void Resume() = 0 ;

	virtual void HandleEvents(IHMmanager* game) = 0;
	virtual void Update(IHMmanager* game) = 0;
	virtual void Draw(IHMmanager* game) = 0;

	void ChangeState(IHMmanager* game, IHMstate* state){
		game->ChangeState(state);
	}

	virtual ~IHMstate(){}
};

#endif /* IHMSTATE_H_ */
