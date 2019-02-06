//#include <iostream>
//#include <string>
//using namespace std;
template <class T>
class CMyistream_iterator
{
public:
	CMyistream_iterator(istream &input) :is(input) {
		is >> a;
	}
	T operator *() {
		return a;
	}
	void operator ++(int) {
		is >> a;
	}
private:
	T a;
	istream & is;
};
//int main()
//{
//	CMyistream_iterator<int> inputInt(cin);
//	int n1, n2, n3;
//	n1 = *inputInt; 
//	int tmp = *inputInt;
//	cout << tmp << endl;
//	inputInt++;
//	n2 = *inputInt; 
//	inputInt++;
//	n3 = *inputInt; 
//	cout << n1 << "," << n2 << "," << n3 << endl;
//	CMyistream_iterator<string> inputStr(cin);
//	string s1, s2;
//	s1 = *inputStr;
//	inputStr++;
//	s2 = *inputStr;
//	cout << s1 << "," << s2 << endl;
//	return 0;
//}