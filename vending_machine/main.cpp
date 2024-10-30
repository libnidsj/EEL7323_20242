#include <iostream>
#include "state_machine.h"
#include "io.h"
#include "clock_calendar.h"
#include <stdio.h>
#include <time.h>

using namespace std;

volatile unsigned int *data = (volatile unsigned int *)0x80000a00;
volatile unsigned int *output = (volatile unsigned int *)0x80000a04;
volatile unsigned int *direction = (volatile unsigned int *)0x80000a08;


int gasta_tempo (int n) {
  int i,j;
  int freq=n-1;
  for (i=0; i<=n; ++i) {
     std::cout << "i = " << i << std::endl;
     for (j=0;j< 2;++j);
  }

int main() {
	
	clock_t clockCounter;
	clock_t lastSecondCounter;

	vendingMachine vendingMain;
	io inputHandler(vendingMain);
	ClockCalendar dateTime;

	dateTime.setClock(4, 47, 54, 1);
	dateTime.setCalendar(23,10,2024);
	
	dateTime.readClock(hours, minutes, seconds, pm);
	dateTime.readCalendar(month, day, year);
	
	/*
	cout << day << "/" << month << "/" << year << "\n";
	if(pm == 1){
		cout << hours << ":" << minutes << ":" << seconds << " pm" << "\n\n"; 
	} else {
		cout << hours << ":" << minutes << ":" << seconds << " am" << "\n\n"; 
	}
	*/
	
	lastSecondCounter = clock();
	
	while(1) {
		
		inputHandler.run();
		clockCounter = clock();
		if(clockCounter - lastSecondCounter >= 125000000) {
			lastSecondCounter = clockCounter;
		}

	}
	
	return 0;
	
}
