#include "CShape3d.cpp"
#include "CBox.cpp"
#include "CCone.cpp"
#include "CCylinder.cpp"

int main(){
	CShape3d* shape;

	// Um ponteiro para CShape3d assume a forma de um CBox
	//
	shape = new CBox<int>(1, 2, 3);
	cout << "Volume do paralelogramo: " << shape->volume() << endl;
	delete shape;
	
	// Um ponteiro para CShape3d assume a forma de um CCone
	//
	shape = new CCone<int>(1, 2);
	cout << "Volume do cone: " << shape->volume() << endl;
	delete shape;

	// Um ponteiro para CShape3d assume a forma de um CCylinder
	//
	shape = new CCylinder<int>(1, 2);
	cout << "Volume do cilindro: " << shape->volume() << endl;
	delete shape;

	return 0;
}

