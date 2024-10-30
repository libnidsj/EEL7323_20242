#include "io.h"
#include <iostream>
#include <stdio.h>

using namespace std;

io::io(vendingMachine innerMachine) {
	vendingIO = innerMachine;
	clockButton = 0;
	M025 = 0;
	M050 = 0;
	M100 = 0;
	DEV = 0;
	MEET = 0;
	ETIRPS = 0;
	releaseMEET = 0;
	releaseETIRPS = 0;
}

void io::getActualOutput(){
	devolutionState = vendingIO.getDevolutionState();
	releaseMEET = vendingIO.getReleaseMEET();
	releaseETIRPS = vendingIO.getReleaseETIRPS();
}

void io::sendSignals(){

	vendingIO.setSignals(M025, M050, M100, DEV, MEET, ETIRPS);
	
}

void io::getSignals(){
	
	// 2^16 -> btn0
	// 2^17 -> btn1
	// ...

	// 2^8 -> SW0
	// 2^9 -> SW1
	// ...	
		
	M025 = (*data >> 8);
	M050 = (*data >> 9);
	M100 = (*data >> 10);
	DEV = (*data >> 11);
	MEET = (*data >> 12);
	ETIRPS = (*data >> 13);
	clockButton = (*data >> 16);
	
	if(clockButton == 1) {
		clockButton = (*data >> 16);
		while(clockButton == 1) {	// Break to not double click
			// DO NOTHING
		}
	}
	
	*direction = 0xffffffff;
	output = 0;
	
	/*
	cout << "Insira M025 1 ou 0: ";
	cin >> M025;
	cout << "Insira M050 1 ou 0: ";
	cin >> M050;
	cout << "Insira M100 1 ou 0: ";
	cin >> M100;
	cout << "Insira DEV 1 ou 0: ";
	cin >> DEV;
	cout << "Insira MEET 1 ou 0: ";
	cin >> MEET;
	cout << "Insira ETIRPS 1 ou 0: ";
	cin >> ETIRPS;
	*/
}

void io::sendOutput(){

	*direction = 0xffffffff;
	
	int ledMatrix = 0;
	
	switch (devolutionState) {
		case 25:
			ledMatrix = 1;  // 001
			cout << "Devolvendo 25 \n";
			break;
		
		case 50:
			ledMatrix = 2;  // 010
			cout << "Devolvendo 50 \n";
			break;
			
		case 75:
			ledMatrix = 3;  // 011
			cout << "Devolvendo 75 \n";
			break;
			
		case 100:
			ledMatrix = 4;  // 100
			cout << "Devolvendo 100 \n";
			break;
			
		case 125:
			ledMatrix = 5;  // 101
			cout << "Devolvendo 125 \n";
			break;
			
		case 150:
			ledMatrix = 6;  // 110
			cout << "Devolvendo 150 \n";
			break;
			

	}
	
	
	if (releaseMEET) {
		ledMatrix = ledMatrix + 8;  // 01xxx
		cout << "Entregando MEET \n";
	}
	
	if (releaseETIRPS) {
		ledMatrix = ledMatrix + 16;  // 10xxx
		cout << "Entregando ETIRPS \n";
	}
	
	*output = ledMatrix;
	
}

void io::run(){
	getSignals();
	sendSignals();
	vendingIO.stateMachineRun();
	getActualOutput();
	sendOutput();

	// cout << "M025: " << M025 << " M050: " << M050 << " M100: " << M100 << "\n";
}
