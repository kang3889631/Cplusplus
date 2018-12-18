#include <iostream>
#include <string>
using namespace std;

class Kang {
private:
	int *ptra, *ptrb;
	int size_a, size_b;
	char *c;
public:
	Kang(string a1, string b1, char c1) {
		size_a = a1.size();
		size_b = b1.size();
		ptra = new int[size_a];
		ptrb = new int[size_b];
		for (int i = 0; i < size_a; i++) {
			ptra[i] = a1[i] - 48;
		}
		for (int i = 0; i < size_b; i++) {
			ptrb[i] = b1[i] - 48;
		}
		c = &c1;
		cout << c << endl;
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