#include "clock_calendar.h"
#include <iostream>

using namespace std;

Clock::Clock (){
	hr = 0;
	sec = 0;
	min = 0;
	isPm = 0;
}

void Clock::setClock(int h, int s, int m, int pm) {
	hr = h;
	sec = s;
	min = m;
	isPm = pm;
}

void Clock::readClock(int& h, int& s, int& m, int& pm) {
	
	h = hr;
	s = sec;
	m = min;
	pm = isPm;
	
}

void Clock::advance() {
	sec = sec + 1;
	if(sec > 59) {
		sec = 0;
		min = min + 1;
	};
	if(min > 59){
		min = 0;
		hr = hr + 1;
	}
	if(hr > 11){
		hr = 0;
		isPm = !isPm;
	}
}

Calendar::Calendar (){
	mo = 1;
	day = 1;
	yr = 2000;
}

void Calendar::setCalendar(int m, int d, int y){
	mo = m;
	day = d;
	yr = y;
}

void Calendar::readCalendar(int& m, int& d, int& y){
	y = yr;
	d = day;
	m = mo;
}

void Calendar::advance(){
	day = day + 1;
	if(mo == 2){
		if(day > 28) {
			day = 0;
			mo = mo + 1;
		}
	} else if (mo == 4 || mo == 6 || mo == 9 || mo == 11) {
		if(day > 30) {
			day = 0;
			mo = mo + 1;
		}
	} else {
		if(day > 31) {
			day = 0;
			mo = mo + 1;
		}
	}
	
	if(mo > 12) {
		mo = 0;
		yr = yr + 1;
	}
}

ClockCalendar::ClockCalendar () {
	
}

void ClockCalendar::advance (){ 
	int wasPm = isPm;
	Clock::advance(); 
	if (wasPm && !isPm){
		Calendar::advance(); 
	}	
}
