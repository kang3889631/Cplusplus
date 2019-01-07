#include <iostream>
using namespace std;
int main() {
	double x;
	cin >> x;
	cout.precision(5);
	cout << fixed << x << endl;
	cout.precision(7);
	cout << scientific << x << endl;
	return 0;
}