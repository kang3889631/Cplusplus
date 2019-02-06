#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
	int n;
	int a;
	string command;
	cin >> n;

	multiset<int> v;
	multiset<int> vsign;

	while (n--) {
		cin >> command >> a;

		if (command == "add") {
			v.insert(a);
			vsign.insert(a);
			cout << v.count(a) << endl;
		}
		else if (command == "ask") {
			if (vsign.count(a) > 0)
				cout << 1 << " " << v.count(a) << endl;
			else
				cout << 0 << " " << 0 << endl;
		}
		else if (command == "del") {
			cout << v.erase(a) << endl;  //size_type erase( const key_type &key ); ɾ������keyֵ������Ԫ�أ����ر�ɾ����Ԫ�صĸ�������
		}
	}

	return 0;
}