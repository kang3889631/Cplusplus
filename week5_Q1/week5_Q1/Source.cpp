#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
// 在此处补充你的代码
class MyString {
	char *str;
public:
	MyString(char *s) {
		str = new char[sizeof(s)];
		memcpy(str, s, sizeof(s));
	}; 
	MyString():str(NULL){};
	MyString(const MyString&mystring) {
		str = new char[sizeof(mystring.str)];
		memcpy(str, mystring.str, sizeof(mystring.str));
	};
	friend ostream& operator<<(ostream&os, const MyString&mystring);
	MyString operator=(const MyString&mystring) {
		this->str = new char[sizeof(mystring.str)];
		memcpy(this->str, mystring.str, sizeof(mystring.str));
		return *this;
	}

	MyString operator+(const MyString&mystring) {
		MyString s;
		if (mystring.str == NULL) {
			return *this;
		}
		char *a = this->str;
		char *b = mystring.str;
		char tmp[30] = {};
		int size = sizeof(this->str) / 2 + 1;
		for (int i = 0; i < size; i++) {
			tmp[i] = *a++;
		}
		cout << tmp << endl;
		for (int i = 0; i < sizeof(mystring.str) / 2 + 1; i++) {
			tmp[i+size] = *b++;
		}
		cout << tmp << endl;
		
		return s;
	}

};
ostream& operator<<(ostream&os, const MyString&mystring) {
	if (mystring.str == NULL) {
		return os;
	}
	os << mystring.str;
	return os;
}
//ostream& operator<<(ostream&os, const MyString&mystring) {
//}
//int CompareString(const void * e1, const void * e2) {
//	MyString * s1 = (MyString *)e1;
//	MyString * s2 = (MyString *)e2;
//	if (*s1 < *s2) return -1;
//	else if (*s1 == *s2) return 0;
//	else if (*s1 > *s2) return 1;
//}
int main() {

	MyString s1("abcd-"), s2, s3("efgh-"), s4(s1);
	//MyString SArray[4] = { "big","me","about","take" };
	cout << "1. " << s1 << s2 << s3 << s4 << endl;
	s4 = s3; s3 = s1 + s3;
	cout << "2. " << s1 << endl;
	cout << "3. " << s2 << endl;
	cout << "4. " << s3 << endl;
	cout << "5. " << s4 << endl;
	//cout << "6. " << s1[2] << endl;
	//s2 = s1; s1 = "ijkl-";
	//s1[2] = 'A';
	//cout << "7. " << s2 << endl;
	//cout << "8. " << s1 << endl;
	//s1 += "mnop";
	//cout << "9. " << s1 << endl;
	//s4 = "qrst-" + s2;
	//cout << "10. " << s4 << endl;
	//s1 = s2 + s4 + " uvw " + "xyz";
	//cout << "11. " << s1 << endl;
	//qsort(SArray, 4, sizeof(MyString), CompareString);
	//for (int i = 0; i < 4; ++i)
	//	cout << SArray[i] << endl;
	////输出s1从下标0开始长度为4的子串
	//cout << s1(0, 4) << endl;
	////输出s1从下标为5开始长度为10的子串
	//cout << s1(5, 10) << endl;
	//return 0;
}