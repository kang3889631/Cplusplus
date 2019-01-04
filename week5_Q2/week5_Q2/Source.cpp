#include <string>
class MyString
{
	char *str;
	int size;
public:
	MyString(const char* s);
	MyString() { str = new char[1]; size = 0; str[0] = '\0'; }
	MyString(const MyString & rstr);
	~MyString() { delete str; }
	//
	bool operator>(MyString & ms2);
	bool operator<(MyString & ms2);
	bool operator==(MyString & ms2);
	MyString & operator=(MyString source);
	MyString operator+(MyString source);
	void operator+=(MyString s);
	char & operator[](int index);
	string operator()(int s, int l);

	//
	friend MyString operator+(const char*s1, MyString s2);
	friend ostream & operator<<(ostream & os, MyString &ms);
};
MyString::MyString(const char* s)
{
	size = strlen(s);
	str = new char[size + 1];
	strcpy(str, s);
}
MyString::MyString(const MyString & rstr)
{
	size = strlen(rstr.str);
	str = new char[size + 1];
	strcpy(str, rstr.str);
}
bool MyString::operator>(MyString & ms2)
{
	return strcmp(str, ms2.str)>0;
}
bool MyString::operator<(MyString & ms2)
{
	return ms2>*this;
}
bool MyString::operator==(MyString & ms2)
{
	return strcmp(ms2.str, str) == 0;
}
MyString& MyString::operator=(MyString source)
{
	if (*this == source)
		return *this;
	delete str;
	size = strlen(source.str);
	str = new char[size + 1];
	strcpy(str, source.str);
	return *this;
}
MyString MyString::operator+(MyString source)
{
	MyString temp;
	delete temp.str;
	temp.size = size + source.size;
	temp.str = new char[temp.size + 1];
	strcpy(temp.str, str);
	strcat(temp.str, source.str);
	return temp;
}
MyString operator+(const char* s1, MyString s2)
{
	MyString temp;
	delete temp.str;
	temp.size = strlen(s1) + s2.size;
	temp.str = new char[temp.size + 1];
	strcpy(temp.str, s1);
	strcat(temp.str, s2.str);
	return temp;
}
void MyString::operator+=(MyString s)
{
	size += s.size;
	char *pt = new char[size + 1];
	strcpy(pt, str);
	strcat(pt, s.str);
	delete str;
	str = pt;
}
char & MyString::operator[](int index)
{
	return str[index];
}
string MyString::operator()(int s, int l)
{
	string autostr = str;
	return autostr.substr(s, l);
}
ostream & operator<<(ostream & os, MyString &ms)
{
	os << ms.str;
	return os;
}