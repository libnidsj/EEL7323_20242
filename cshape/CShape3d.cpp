#include <iostream>
using namespace std;

const float PI = 3.1415f;

class CShape3d {
	protected:
		virtual void calcVolume() = 0;

		float myVolume;
	public:
		CShape3d() : myVolume(0.0f) { }

		float volume() {
			calcVolume();
			return myVolume;
		}
};

