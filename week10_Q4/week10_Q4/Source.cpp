#include <iostream>
using namespace std;
// 在此处补充你的代码
class CType {
private:
	int value;
public:
	int m;
	int sqr;
	CType() :value(0) {};
	void setvalue(int n) {
		value = n;
	}
	CType& operator++(int) {
		static CType tmp;
		tmp.value = value;
		value *= value;
		return tmp;
	}
	friend ostream& operator << (ostream& o, CType& cType) {
		o << cType.value;
		return o;
	}
};
int main(int argc, char* argv[]) {
	CType obj;
	int n;
	cin >> n;
	while (n) {
		obj.setvalue(n);
		cout << obj++ << " " << obj << endl;
		cin >> n;
	}
	return 0;
}