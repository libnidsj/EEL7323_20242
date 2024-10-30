#ifndef IO_H
#define IO_H

#include "state_machine.h"

class io{
		vendingMachine vendingIO;
		bool clockButton;
		bool M025;
		bool M050;
		bool M100;
		bool DEV;
		bool MEET;
		bool ETIRPS;
				
		int devolutionState;
		bool releaseMEET;
		bool releaseETIRPS;
	
	public:
		io(vendingMachine);
	
		void getActualOutput();
		void sendSignals();
		void getSignals();
		void run();
		void sendOutput();
	
};

extern volatile unsigned int *data;
extern volatile unsigned int *output;
extern volatile unsigned int *direction;

#endif