#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <iomanip>
using namespace std;

class Kang {
private:
	int *ptra, *ptrb, *ptrc;
	int  size, new_size;
public:
	Kang(string a1, string b1) {
		int tmp = a1.size();
		if (b1.size() > a1.size())
			tmp = b1.size();
		size = (tmp / 4 + 1) * 4;
		string a0(size - a1.size(), '0');
		string b0(size - b1.size(), '0');
		string a = a0 + a1;
		string b = b0 + b1;
		new_size = size / 4;
		ptra = new int[new_size];
		ptrb = new int[new_size];
		cout << "a= " << a << endl;
		cout << "b= " << b << endl;
		for (int i = 0; i < new_size; i++) {
			string s1 = a.substr(i * 4, 4);
			string s2 = b.substr(i * 4, 4);
			stringstream geek1(s1);
			stringstream geek2(s2);
			geek1 >> ptra[i];
			geek2 >> ptrb[i];
		}
	}

	void plus() {
		ptrc = new int[new_size];
		int a = 0;
		for(int i=new_size-1;i>=0;i--){
			ptrc[i] = (ptra[i] + ptrb[i] + a) % 10000;
			if (ptra[i] + ptrb[i] + a >= 10000)
				a = 1;
			else
				a = 0;
		}
		cout << ptrc[0];
		for (int i = 1; i < new_size; i++) {
			cout << setfill('0') << setw(4) << ptrc[i];
		}
	}
	void minus() {
		ptrc = new int[new_size];
		int a = 0;
		for (int i = new_size - 1; i >= 0; i--) {
			ptrc[i] = abs((ptra[i] - ptrb[i] - a ));
			if (ptra[i] - ptrb[i] - a < 0)
				a = 1;
			else
				a = 0;
		}
		if (a == 1)
			cout << "-";
		int j = 0;
		for (int i = 0; i < new_size; i++) {
			if (ptrc[i] != 0) {
				j = i;
				break;
			}
		}
		if (j==0&&ptrc[0]==0)
			cout << "0";
		else {
			cout << ptrc[j];
			for (int i = j + 1; i < new_size; i++) {
				cout << setfill('0') << setw(4) << ptrc[i];
			}
		}
	}
	void times() {
		ptrc = new int[2 * size];
		

	}
	~Kang() {
		if (ptra) delete[]ptra;
		if (ptrb) delete[]ptrb;
	}
};

int main() {
	string a, b;
	char c;
	cin >> a;
	cin >> c;
	cin >> b;
	Kang k(a, b);
	if (c == '+')
		k.plus();
	if (c == '-')
		k.minus();
	if (c == '*')
		k.times();
	return 0;
}