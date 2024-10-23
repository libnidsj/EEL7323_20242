template <class T>

class CCylinder : public CShape3d {
	protected:
		T myRadius;
		T myHeight;

		void calcVolume(){
			myVolume = PI * myRadius * myRadius * myHeight;
		}
	public:
		CCylinder(T r = 0.0f, T h = 0.0f){
			myRadius = r;
			myHeight = h;
		}
};

