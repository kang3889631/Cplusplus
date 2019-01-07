#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
// 在此处补充你的代码
void stringcat(char *str1, char*str2) {
	while (*str1)
		str1++;
	while (*str2)
		*str1++ = *str2++;
}
class MyString
{
char *str;
int size;
public:
MyString(const char* s);
MyString(){str=new char[1];size=0;str[0]='\0';}
MyString(const MyString & rstr);
~MyString(){delete str;}
//
bool operator>(MyString & ms2);
bool operator<(MyString & ms2);
bool operator==(MyString & ms2);
MyString & operator=(MyString source);
MyString operator+(MyString source);
void operator+=(MyString s);
char & operator[](int index);
string operator()(int s,int l);
//
friend MyString operator+(const char*s1,MyString s2);
friend ostream & operator<<(ostream & os,MyString &ms);
};
MyString::MyString(const char* s)
{
size=strlen(s);
str=new char [size+1];
memcpy(str,s,strlen(s)+1);
}
MyString::MyString(const MyString & rstr)
{
size=strlen(rstr.str);
str=new char[size+1];
memcpy(str,rstr.str,strlen(rstr.str)+1);
}
bool MyString::operator>(MyString & ms2)
{
return memcmp(str,ms2.str,sizeof(str))>0;
}
bool MyString::operator<(MyString & ms2)
{
return ms2>*this;
}
bool MyString::operator==(MyString & ms2)
{
return memcmp(ms2.str,str,sizeof(ms2.str))==0;
}

MyString& MyString::operator=(MyString source)
{
if(*this==source) 
return *this;
delete str;
size=strlen(source.str);
str=new char[size+1];
memcpy(str,source.str,strlen(str)+1);
return *this;
}
MyString MyString::operator+(MyString source)
{
MyString temp;
delete temp.str;
temp.size=size+source.size;
temp.str=new char[temp.size+1];
memcpy(temp.str,str,strlen(str)+1);
stringcat(temp.str,source.str);

return temp;
}
MyString operator+(const char* s1,MyString s2)
{
MyString temp;
delete temp.str;
temp.size=strlen(s1)+s2.size;
temp.str=new char [temp.size+1];
memcpy(temp.str,s1,strlen(s1)+1);
stringcat(temp.str,s2.str);
return temp;
}
void MyString::operator+=(MyString s)
{
size+=s.size;
char *pt=new char[size+1];
memcpy(pt,str,strlen(str)+1);
stringcat(pt,s.str);
delete str;
str=pt;
}
char & MyString::operator[](int index)
{
return str[index];
}
string MyString::operator()(int s,int l)
{
string autostr=str;
return autostr.substr(s,l);
}
ostream & operator<<(ostream & os,MyString &ms)
{
os<<ms.str;
return os;
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
	//cout << s1(0, 4) << endl;
	////输出s1从下标为5开始长度为10的子串
	//cout << s1(5, 10) << endl;
	return 0;
}