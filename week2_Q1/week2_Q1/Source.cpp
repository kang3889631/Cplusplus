#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Student {

private:
	string name;
	int age = 0;
	string id;
	int mark1 = 0;
	int mark2 = 0;
	int mark3 = 0;
	int mark4 = 0;
public:
	void getname(string s);
	void getage(int p);
	void getid(string p);
	void getmark(int p1, int p2, int p3, int p4);
	int ave(void);
	void print(void);
};
int Student::ave(void) {
	return (mark1 + mark2 + mark3 + mark4) / 4;
}
void Student::print(void) {
	cout << name << "," << age << "," << id << "," << ave() << endl;
}
void Student::getname(string s) {
	name = s;
}
void Student::getage(int p) {
	age = p;
}
void Student::getid(string p) {
	id = p;
}
void Student::getmark(int p1,int p2,int p3,int p4) {
	mark1 = p1;
	mark2 = p2;
	mark3 = p3;
	mark4 = p4;
}
int main()
{
	Student st;
	string name;
	string age;
	string id;
	string mark1;
	string mark2;
	string mark3;
	string mark4;

	getline(cin, name, ',');
	getline(cin, age, ',');
	getline(cin, id, ',');
	getline(cin, mark1, ',');
	getline(cin, mark2, ',');
	getline(cin, mark3, ',');
	getline(cin, mark4);
	
	int temp = 0;
	st.getname(name);
	stringstream geek(age);
	geek >> temp;
	st.getage(temp);
	st.getid(id);
	int x1, x2, x3, x4 = 0;
	stringstream m1(mark1);
	m1 >> x1;
	stringstream m2(mark2);
	m2 >> x2;
	stringstream m3(mark3);
	m3 >> x3;
	stringstream m4(mark4);
	m4 >> x4;
	st.getmark(x1, x2, x3, x4);
	st.print();
	return 0;
}