
#include <iostream>
using namespace std;

class A {
public:
	int val;
	A(int n=0) { val = n; }
	A &GetObj() {
		return *this;
	}
};

int main() {
	A a;
	cout << a.val << endl;
	a.GetObj() = 5;
	cout << a.val << endl;
}
//& means reference. You are claiming that the returned value is the reference of *this. 
//So when the returned value changes, its reference, i.e. *this, will also be changed.
