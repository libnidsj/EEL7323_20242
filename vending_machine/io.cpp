#include "io.h"
#include <iostream>

using namespace std;

io::io(vendingMachine innerMachine) {
	vendingIO = innerMachine;
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
	/*	
	M025 = (*data & 0x00000001);
	M050 = (*data & 0x00000002);
	M100 = (*data & 0x00000004);
	DEV = (*data & 0x00000008);
	MEET = (*data & 0x00000010);
	ETIRPS = (*data & 0x00000020);
	*/
	
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
}

void io::sendOutput(){

	// *direction = 0xffffffff;
	
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
	
	// *output = ledMatrix;
	
}

void io::run(){
	getSignals();
	sendSignals();
	vendingIO.stateMachineRun();
	getActualOutput();
	sendOutput();
}