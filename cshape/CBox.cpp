template <class T>

class CBox : public CShape3d {
	protected:
		T myLength;
		T myWidth;
		T myHeight;

		void calcVolume(){
			myVolume = myWidth * myHeight * myLength;
		}
	public:
		CBox(T l = 0.0f, T w = 0.0f, T h = 0.0f){
			myLength = l;
			myWidth = w;
			myHeight = h;
		}
};

