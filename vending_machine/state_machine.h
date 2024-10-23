#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

class vendingMachine{
	
	int actualState;
	int devolutionState;
	
	bool M025;
	bool M050;
	bool M100;
	bool DEV;
	bool MEET;
	bool ETIRPS;
	
	bool releaseMEET;
	bool releaseETIRPS;
		
public:


    vendingMachine();
	int getActualState();
	int getDevolutionState();
	void setActualState(int);
	void setDevolutionState(int);
	void setSignals(bool, bool, bool, bool, bool, bool);
	void stateMachineRun();
	
	void setReleaseETIRPS(bool);
	void setReleaseMEET(bool);
	
	bool getReleaseETIRPS();
	bool getReleaseMEET();
	
	bool getM025();
	bool getM050();
	bool getM100();
	bool getDEV();
	bool getMEET();
	bool getETIRPS();
};

void stateMachine(vendingMachine);

#endif