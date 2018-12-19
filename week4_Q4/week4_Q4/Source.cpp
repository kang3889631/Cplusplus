#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class Kang {
private:
	int *ptra, *ptrb, *ptrc;
	int size_a, size_b, size;
	char *c;
public:
	Kang(string a1, string b1, char c1) {
		size_a = a1.size();
		size_b = b1.size();
		string c(abs(size_a - size_b), '0');
		string a, b;
		if (size_a > size_b) {
			 a = a1;
			 b = c + b1;
		}
		if (size_a < size_b) {
			 a = c + a1;
			 b = b1;
		}
		size = b.size();
		ptra = new int[size];
		ptrb = new int[size];

		for (int i = 0; i < size; i++) {
			ptra[i] = a[i] - 48;
			ptrb[i] = b[i] - 48;
		}
		c = &c1;
	}

	int plus() {
		ptrc = new int[size];
		for (int i = size - 1; i >= 0; i--) {
			ptrc[i] = (ptra[i] + ptrb[i]) % 10;
		}
		return *ptrc;
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
	Kang k(a, b, c);
	return 0;
}