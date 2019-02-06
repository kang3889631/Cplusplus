#include <iostream>
#include <map>
using namespace std;

int main() {
	map<int, int> facer;
	map<int, int>::iterator it, it1;

	facer.insert({ 1000000000, 1 });  //向facer中添加元素

	int n, id, strength;
	cin >> n;
	while (n--) {
		cin >> id >> strength;
		it = facer.lower_bound(strength);

		if (it != facer.begin()) {
			it1 = it;
			it1--;
			if (strength - it1->first <= it->first - strength)
				cout << id << " " << it1->second << endl;
			else
				cout << id << " " << it->second << endl;
			facer[strength] = id;
		}
		else
			cout << id << " " << it->second << endl;

		facer[strength] = id;  //只有map容器可以这样用，multimap不行
	}

	return 0;
}

/* equal_range 用法：
pair<multimap<int, int>::iterator, multimap<int, int>::iterator> range;
range = facer.equal_range(strength);
range.first 相当于 facer.lower_bound(strength);
range.second 相当于 facer.upper_bound(strength);
*/