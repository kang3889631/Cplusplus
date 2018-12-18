#include <iostream>
#include <cstring>
using namespace std;
// 在此处补充你的代码
class Array2 {
private:
	int row = 0, column = 0;
	int *ptr;
public:
	Array2(int r = 0, int c = 0) :row(r), column(c) {
		ptr = new int[row*column];
	}
	Array2(Array2& a) :row(a.row), column(a.column) {
		if (ptr) delete[]ptr;
		ptr = new int[row*column];
		memcpy(ptr, a.ptr, sizeof(int)*row*column);
	}
	~Array2(){
		if (ptr) delete[]ptr;
	}
	Array2& operator=(const Array2& a) {
		if (ptr) delete[]ptr;
		row = a.row;
		column = a.column;
		ptr = new int[row*column];
		memcpy(ptr, a.ptr, sizeof(int)*row*column);
		return *this;
	}
	int* operator[](const int& i) {
		return ptr + i*column;
	}
	int& operator()(const int& i, const int& j) {
		return ptr[i*column+j];
	}
};
int main() {
	Array2 a(3, 4);
	int i, j;
	for (i = 0; i < 3; ++i)
		for (j = 0; j < 4; j++)
			a[i][j] = i * 4 + j;
	for (i = 0; i < 3; ++i) {
		for (j = 0; j < 4; j++) {
			cout << a(i, j) << ",";
		}
		cout << endl;
	}
	cout << "next" << endl;
	Array2 b;     b = a;
	for (i = 0; i < 3; ++i) {
		for (j = 0; j < 4; j++) {
			cout << b[i][j] << ",";
		}
		cout << endl;
	}
	return 0;
}