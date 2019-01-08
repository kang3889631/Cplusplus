#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
// 在此处补充你的代码
int myStrlen(const char *str);
char *mystrcat(char *dest, char *src1, char *src2);
char *mystrcpy(char *dest, char *src)
{
	char *start = dest;
	while (*src!='\0') *dest++ = *src++;
	*dest++ = '\0';
	return start;
}
char *mystrcat(char *dest, char *src1, char *src2)
{
	char *start = dest;
	while (*src1 != '\0') *dest++ = *src1++;
	while (*src2 != '\0') *dest++ = *src2++;
	*dest++ = '\0';
	return start;
}
char *mysubstr(char *dest, char *src, int location, int length)
{
	char *start = dest;
	while (location-- != 0) {
		*src++;
	}
	while (*src != '\0'&&length-->0) { 
		*dest++ = *src++;
	}
	*dest++ = '\0';
	return start;
}

int myStrlen(const char *str) {
	int len = 0;
	while (str[len] != '\0') {
		len++;
	}
	return len;
}
class MyString {
private:
	char *str;
	int size;
public:
	MyString(char *s){
		size = myStrlen(s);
		//cout << "size: " << size << endl;
		str = new char[size+1];
		mystrcpy(str, s);
	};
	MyString() { str = new char[1]; size = 0; str[0] = '\0'; }
	MyString(const MyString &s) {
		size = myStrlen(s.str);
		str = new char[size+1];
		mystrcpy(str, s.str);
	};
	~MyString() {
		if(str!=NULL)
		delete str; 
	}
	MyString& operator=(const MyString &s);
	MyString operator+(const MyString &s);
	char & operator[](int index);
	void operator+=(const MyString &s);
	bool operator>(MyString & s);
	bool operator<(MyString & s);
	bool operator==(MyString & s);
	char* operator()(int location, int length);
	friend MyString operator+(char*s1, MyString s2);
	friend ostream & operator<<(ostream & os, MyString &ms);
};
ostream & operator<<(ostream & os, MyString &s)
{
	if (s.str != NULL)
		os << s.str;
	return os;
}
MyString operator+(char* s1, MyString s2)
{
	MyString temp;
	if(temp.str!=NULL)
		delete temp.str;
	temp.size = myStrlen(s1) + s2.size;
	temp.str = new char[temp.size + 1];
	mystrcat(temp.str, s1, s2.str);
	return temp;
}
bool MyString::operator>(MyString &s)
{
	return memcmp(str, s.str,sizeof(str))>0;
}
bool MyString::operator<(MyString &s)
{
	return memcmp(str, s.str, sizeof(str))<0;
}
bool MyString::operator==(MyString &s)
{
	return memcmp(str, s.str, sizeof(str))==0;
}
MyString MyString::operator+(const MyString &s)
{
	MyString My;
	if (My.str != NULL)
		delete My.str;
	My.size = size + myStrlen(s.str);
	My.str = new char[My.size + 1];
	mystrcat(My.str, str, s.str);
	return My;
}
MyString& MyString::operator=(const MyString &s)
{
	if (str == s.str)
		return *this;
	delete str;
	size = myStrlen(s.str);
	str = new char[size + 1];
	mystrcpy(str, s.str);
	return *this;
}
char & MyString::operator[](int index)
{
	return str[index];
}
void MyString::operator+=(const MyString &s)
{
	size += s.size;
	char *pt = new char[size + 1];
	mystrcat(pt, str, s.str);
	delete str;
	str = pt;
}
char* MyString::operator()(int location, int length) {
	char *p = new char[length + 1];
	mysubstr(p, str, location, length);
	return p;
}

int CompareString(const void * e1, const void * e2) {
	MyString * s1 = (MyString *)e1;
	MyString * s2 = (MyString *)e2;
	if (*s1 < *s2) return -1;
	else if (*s1 == *s2) return 0;
	else if (*s1 > *s2) return 1;
}

int main() {
	MyString s1("abcd-"), s2, s3("efgh-"), s4(s1);
	MyString SArray[4] = { "big","me","about","take" };
	cout << "1. " << s1 << s2 << s3 << s4 << endl;
	s4 = s3; s3 = s1 + s3;
	cout << "2. " << s1 << endl;
	cout << "3. " << s2 << endl;
	cout << "4. " << s3 << endl;
	cout << "5. " << s4 << endl;
	cout << "6. " << s1[2] << endl;
	s2 = s1; s1 = "ijkl-";
	s1[2] = 'A';
	cout << "7. " << s2 << endl;
	cout << "8. " << s1 << endl;
	s1 += "mnop";
	cout << "9. " << s1 << endl;
	s4 = "qrst-" + s2;
	cout << "10. " << s4 << endl;
	s1 = s2 + s4 + " uvw " + "xyz";
	cout << "11. " << s1 << endl;
	qsort(SArray, 4, sizeof(MyString), CompareString);
	for (int i = 0; i < 4; ++i)
		cout << SArray[i] << endl;
	//输出s1从下标0开始长度为4的子串
	cout << s1(0, 4) << endl;
	//输出s1从下标为5开始长度为10的子串
	cout << s1(5, 10) << endl;
	return 0;
}
