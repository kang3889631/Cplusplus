#include <iostream>
using namespace std;
// 在此处补充你的代码
template<class T>
class CArray3D {
public:
	template<class T1>
	class CArray2D {
		T1 *a;
		int i, j;
	public:
		CArray2D() { a = NULL; }
		CArray2D(int m, int n) :i(m), j(n) {
			a = new T1[i*j];
		}
		T1 *operator[](const int& n) {
			return a + n*j;
		}
		~CArray2D(){
			if (a != NULL) delete[]a;
		}

	};
private:
	CArray2D<T> **array2D;
public:
	CArray3D() { array2D = NULL; }
	CArray3D(int a1, int a2, int a3) {
		array2D = new CArray2D<T>*[a1];
		for (int i = 0; i < a1; i++)
			array2D[i] = new CArray2D<T>(a2, a3);
	}
	CArray2D<T>&operator[](int i) {
		return *array2D[i];
	}
	~CArray3D(){
		if (array2D != NULL)
			delete[]array2D;
	}
};
int main()
{
	CArray3D<int> a(3, 4, 5);
	int No = 0;
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 4; ++j)
			for (int k = 0; k < 5; ++k)
				a[i][j][k] = No++;
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 4; ++j)
			for (int k = 0; k < 5; ++k)
				cout << a[i][j][k] << ",";
	return 0;
}