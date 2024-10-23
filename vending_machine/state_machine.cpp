#include "state_machine.h"
#include <iostream>

using namespace std;

vendingMachine::vendingMachine() {
	actualState = 0;
	devolutionState = 0;
	M025 = 0;
	M050 = 0;
	M100 = 0;
	DEV = 0;
	MEET = 0;
	ETIRPS = 0;
	
	releaseMEET = 0;
	releaseETIRPS = 0;
}

void vendingMachine::setActualState(int nextState) {
	actualState = nextState;
}

void vendingMachine::setDevolutionState(int nextDevolutionState) {
	devolutionState = nextDevolutionState;
}

int vendingMachine::getActualState() {
	return actualState;
}

int vendingMachine::getDevolutionState() {
	return devolutionState;
}

void vendingMachine::setSignals(bool M025_NEW, bool M050_NEW, bool M100_NEW, bool DEV_NEW, bool MEET_NEW, bool ETIRPS_NEW) {
	M025 = M025_NEW;
	M050 = M050_NEW;
	M100 = M100_NEW;
	DEV = DEV_NEW;
	MEET = MEET_NEW;
	ETIRPS = ETIRPS_NEW;
}

bool vendingMachine::getM025() {
	return M025;
}

bool vendingMachine::getM050() {
	return M050;
}

bool vendingMachine::getM100() {
	return M100;
}

bool vendingMachine::getDEV() {
	return DEV;
}

bool vendingMachine::getMEET() {
	return MEET;
}

bool vendingMachine::getETIRPS() {
	return ETIRPS;
}

bool vendingMachine::getReleaseMEET() {
	return releaseMEET;
}

bool vendingMachine::getReleaseETIRPS() {
	return releaseETIRPS;
}

void vendingMachine::setReleaseMEET(bool newState) {
	releaseMEET = newState;
}

void vendingMachine::setReleaseETIRPS(bool newState) {
	releaseETIRPS = newState;
}

void vendingMachine::stateMachineRun() {
	
	int nextStateInner = 0;
	int nextDevolutionStateInner = 0;
			
	switch(getActualState()){
		
		case 0:
			if(getM025()){
				nextStateInner = 25;
			} else if(getM050()) {
				nextStateInner = 50;
			} else if(getM100()) {
				nextStateInner = 100;
			} else {
				nextStateInner = 0;
			}
			nextDevolutionStateInner = 0;
			break;
			
		case 25:
			if(getDEV()){
				nextStateInner = 0;
				nextDevolutionStateInner = 25;
			} else if(getM025()) {
				nextStateInner = 50;
				nextDevolutionStateInner = 0;
			} else if(getM050()) {
				nextStateInner = 75;
				nextDevolutionStateInner = 0;
			} else if(getM100()) {
				nextStateInner = 125;
				nextDevolutionStateInner = 0; 
			} else {
				nextStateInner = 25;
				nextDevolutionStateInner = 0;
			}
			break;
			
		case 50:
			if(getDEV()){
				nextStateInner = 0;
				nextDevolutionStateInner = 50;
			} else if(getM025()) {
				nextStateInner = 75;
				nextDevolutionStateInner = 0;
			} else if(getM050()) {
				nextStateInner = 100;
				nextDevolutionStateInner = 0;
			} else if(getM100()) {
				nextStateInner = 150;
				nextDevolutionStateInner = 0; 
			} else {
				nextStateInner = 50;
				nextDevolutionStateInner = 0;
			}
			break;
			
		case 75:
			if(getDEV()){
				nextStateInner = 0;
				nextDevolutionStateInner = 75;
			} else if(getM025()) {
				nextStateInner = 100;
				nextDevolutionStateInner = 0;
			} else if(getM050()) {
				nextStateInner = 125;
				nextDevolutionStateInner = 0;
			} else if(getM100()) {
				nextStateInner = 150;
				nextDevolutionStateInner = 25; 
			} else {
				nextStateInner = 75;
				nextDevolutionStateInner = 0;
			}
			break;
		
		case 100:
			if(getDEV()){
				nextStateInner = 0;
				nextDevolutionStateInner = 100;
			} else if(getM025()) {
				nextStateInner = 125;
				nextDevolutionStateInner = 0;
			} else if(getM050()) {
				nextStateInner = 150;
				nextDevolutionStateInner = 0;
			} else if(getM100()) {
				nextStateInner = 200;
				nextDevolutionStateInner = 50; 
			} else {
				nextStateInner = 100;
				nextDevolutionStateInner = 0;
			}
			break;
			
		case 125:
			if(getDEV()){
				nextStateInner = 0;
				nextDevolutionStateInner = 125;
			} else if(getM025()) {
				nextStateInner = 150;
				nextDevolutionStateInner = 0;
			} else if(getM050()) {
				nextStateInner = 150;
				nextDevolutionStateInner = 25;
			} else if(getM100()) {
				nextStateInner = 225;
				nextDevolutionStateInner = 75; 
			} else {
				nextStateInner = 125;
				nextDevolutionStateInner = 0;
			}
			break;
			
		case 150:
			if(getDEV()){
				nextStateInner = 0;
				nextDevolutionStateInner = 150;
			} else if(getM025()) {
				nextStateInner = 150;
				nextDevolutionStateInner = 25;
			} else if(getM050()) {
				nextStateInner = 150;
				nextDevolutionStateInner = 50;
			} else if(getM100()) {
				nextStateInner = 150;
				nextDevolutionStateInner = 100; 
			} else if(getMEET()) {
				nextStateInner = 0;
				nextDevolutionStateInner = 0;
				setReleaseMEET(1);
			} else if(getETIRPS()) {
				nextStateInner = 0;
				nextDevolutionStateInner = 0;
				setReleaseETIRPS(1);
			} else {
				nextStateInner = 150;
				nextDevolutionStateInner = 0;
			}
			break;
	}
	
	
	setSignals(0,0,0,0,0,0);
	setActualState(nextStateInner);
	setDevolutionState(nextDevolutionStateInner);
	
}