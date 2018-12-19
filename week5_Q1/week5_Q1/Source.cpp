#include <iostream>
#include <string>
using namespace std;
class CStudent {
private:
	string name;
	string id;
	char gender;
	int age;
public:
	void PrintInfo();
	void SetInfor(const string&name_, const string &id_, int age_, char gender_);
	string GetName() { return name; }
};

class CUndergraduateStudent :public CStudent {
private:
	string department;
public:
	void QualifiedForBaoYan() {
		cout << "qualified for baoyan" << endl;
	}
	void PrintInfo() {
		CStudent::PrintInfo();
		cout << "Department:" << department << endl;
	}
	void SetInfor(const string&name_, const string&id_, int age_, char gender_, const string & deparment_) {
		CStudent::SetInfor(name_, id_, age_, gender_);
		department = deparment_;
	}
};
void CStudent::PrintInfo() {
	cout << "Name:" << name << endl;
	cout << "ID" << id << endl;
	cout << "Age:" << age << endl;
	cout << "Gender:" << gender << endl;
}
void CStudent::SetInfor(const string&name_, const string & id_, int age_, char gender_) {
	name = name_;
	id = id_;
	age = age_;
	gender = gender_;
}
int main() {
	CUndergraduateStudent s2;
	s2.SetInfor("Harry Potter", "118829212", 19, 'M', "Computer Science");
	cout << s2.GetName() << " ";
	s2.QualifiedForBaoYan();
	s2.PrintInfo();
	return 0;
}