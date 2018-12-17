#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
class Complex {
private:
	double r, i;
public:
	void Print() {
		cout << r << "+" << i << "i" << endl;
	}
	Complex & operator=(string s) {
		int pos = s.find("+", 0);
		string sTmp = s.substr(0, pos);
		r = atof(sTmp.c_str());
		sTmp = s.substr(pos + 1, s.length() - pos - 2);
		i = atof(sTmp.c_str());
		return *this;
	}
};
int main() {
	Complex a;
	a = "3+4i"; a.Print();
	a = "5+6i"; a.Print();
	return 0;
}