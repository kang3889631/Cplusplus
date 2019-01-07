#include <iostream>
#include <iomanip>
using namespace std;
int main() {
	int x;
	cin >> x;
	cout << hex << x << endl;
	cout << dec << setfill('0') << setw(10) << x << endl;

	return 0;
}