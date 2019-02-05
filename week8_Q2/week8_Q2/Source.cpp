#include <iostream>
#include <list>
#include <string>
#include <vector>
using namespace std;
class MyList {
public:
	int id;
	list <int> lst;
	MyList(int t)
	{
		id = t;
	}
	void PrintList()
	{
		lst.sort();
		list<int>::iterator it;
		for (it = lst.begin(); it != lst.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	static MyList & _Find(vector<MyList> & v, int t)
	{
		vector<MyList>::iterator i;
		i = v.begin();
		return *(i + t - 1);
	}
};
int main()
{
	int n;
	cin >> n;
	vector<MyList > v;
	while (n--)
	{
		string s;
		cin >> s;
		if (s == "new")
		{
			int t;
			cin >> t;
			v.push_back(MyList(t));
		}
		if (s == "add")
		{
			int t1, t2;
			cin >> t1 >> t2;
			MyList& p1 = MyList::_Find(v, t1);
			p1.lst.push_back(t2);
		}
		if (s == "out")
		{
			int t1;
			cin >> t1;
			MyList& p1 = MyList::_Find(v, t1);
			p1.PrintList();
		}
		if (s == "merge")
		{
			int t1, t2;
			cin >> t1 >> t2;
			MyList& p1 = MyList::_Find(v, t1);
			MyList& p2 = MyList::_Find(v, t2);
			p1.lst.merge(p2.lst);
		}
		if (s == "unique")
		{
			int t1;
			cin >> t1;
			MyList& p1 = MyList::_Find(v, t1);
			p1.lst.sort();
			p1.lst.unique();
		}
	}
}