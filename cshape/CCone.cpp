template <class T>

class CCone : public CShape3d {
	protected:
		T myRadius;
		T myHeight;

		void calcVolume(){
			myVolume = 0.333333f * PI * myRadius * myRadius * myHeight;
		}
	public:
		CCone(T r = 0.0f, T h = 0.0f){
			myRadius = r;
			myHeight = h;
		}
};

