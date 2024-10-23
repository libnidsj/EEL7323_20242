#ifndef CLOCK_CALENDAR_H
#define CLOCK_CALENDAR_H

class Clock { 
	protected: 
		int hr, min, sec, isPm; 
	public: 
		Clock (); 
		void setClock (int h, int s, int m, int pm); 
		void readClock (int& h, int& s, int& m, int& pm); 
		void advance (); 
	};
	
class Calendar { 
	protected: 
		int mo, day, yr; 
	public: 
		Calendar (); 
		void setCalendar (int m, int d, int y); 
		void readCalendar (int& m, int& d, int& y); 
		void advance (); 
	};
	
class ClockCalendar : public Clock, public Calendar { 
	public: 
		ClockCalendar (); 
		void advance (); 
	}; 

#endif