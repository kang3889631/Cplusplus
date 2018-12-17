#include <iostream>
#include <cstring>
using namespace std;
// 在此处补充你的代码
class Array2 {
public:
	int row = 0, column = 0;
	int arr[100][100] = {0};
	int i, j;
	Array2(int r = 0, int c = 0) :row(r), column(c) {};
	int& opertor[](const int& a){
		return 0;
	}
};
int main() {
	Array2 a(3, 4);
	int i, j;
	for (i = 0; i < 3; ++i)
		for (j = 0; j < 4; j++)
			a[i][j] = i * 4 + j;
	/*
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
	*/
	return 0;
}