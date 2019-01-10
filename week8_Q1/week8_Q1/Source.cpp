#include <iostream>
#include <string>
using namespace std;

int mystoi(string s) {
	int n = 0;
	if (s.length() == 4)
		n = (s.at(0) - '0') * 1000 + (s.at(1) - '0') * 100 + (s.at(2) - '0') * 10 + (s.at(3) - '0');
	if (s.length() == 3)
		n = (s.at(0) - '0') * 100 + (s.at(1) - '0') * 10 + (s.at(2) - '0');
	if (s.length() == 2)
		n = (s.at(0) - '0') * 10 + (s.at(1) - '0');
	if (s.length() == 1)
		n = (s.at(0) - '0');
	return n;
}
string myto_string(int k) {
	string s;
	int n = k;
	bool flag = false;

	if (n/10000 != 0) {
		s.push_back(n/10000 + 48);
		flag = true;
		n %= 10000;
	}
	if (n / 1000 != 0 || flag == true) {
		s.push_back(n / 1000 + 48);
		flag = true;
		n %= 1000;
	}
	if (n / 100 != 0 || flag == true) {
		s.push_back(n / 100 + 48);
		flag = true;
		n %= 100;
	}
	if (n / 10 != 0 || flag == true) {
		s.push_back(n / 10 + 48);
		flag = true;
		n %= 10;
	}
	s.push_back(n + 48);
	return s;
}
int main() {
	cout << myto_string(0) << endl;
	cout << myto_string(1) << endl;
	cout << myto_string(10) << endl;
	cout << myto_string(101) << endl;
	cout << myto_string(1002) << endl;
	return 0;
}