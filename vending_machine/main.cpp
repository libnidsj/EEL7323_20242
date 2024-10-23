#include <iostream>
#include "state_machine.h"
#include "io.h"
#include "clock_calendar.h"

using namespace std;

volatile unsigned int *data = (volatile unsigned int *)0x80000a00;
volatile unsigned int *output = (volatile unsigned int *)0x80000a04;
volatile unsigned int *direction = (volatile unsigned int *)0x80000a08;

int hours;
int minutes;
int seconds;
int pm;
int day;
int month;
int year;
	

int main() {
	
	/*
	https://gse.ufsc.br/bezerra/disciplinas/cpp/boards/Leon_Atlys/examples/src/examples/time.c
	
	Use this to implement timer
	*/
	vendingMachine vendingMain;
	io inputHandler(vendingMain);
	ClockCalendar dateTime;
	
	dateTime.setClock(4, 47, 54, 1);
	dateTime.setCalendar(23,10,2024);
	
	dateTime.readClock(hours, minutes, seconds, pm);
	dateTime.readCalendar(month, day, year);
	
	cout << day << "/" << month << "/" << year << "\n";
	if(pm == 1){
		cout << hours << ":" << minutes << ":" << seconds << " pm" << "\n\n"; 
	} else {
		cout << hours << ":" << minutes << ":" << seconds << " am" << "\n\n"; 
	}
	
	while(1) {
		
		int receivedBTN0 = 0;
		// receivedBTN0 = *data & 0b00000000000000010000000000000000 >> 16;
		
		cout << "Pressione o botao quando as entradas estiverem selecionadas\n";
		if(receivedBTN0 = 1 || 1){
			inputHandler.run();
		} else {
			
		}
	}
	
	return 0;
	
}