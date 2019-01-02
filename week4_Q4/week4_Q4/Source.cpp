#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>
using namespace std;

class Bigint {
private:
	string values;
	bool flag;
	inline int compare(string s1, string s2) {
		if (s1.size() < s2.size())
			return -1;
		else if (s1.size() > s2.size())
			return 1;
		else
			return s1.compare(s2);
	}
public:
	Bigint() :values("0"), flag(true) {};
	Bigint(string str) {
		values = str;
		flag = true;
	}
	friend ostream& operator << (ostream& os, const Bigint& bigint);
	friend istream& operator >> (istream& is, Bigint& bigint);
	Bigint operator+ (const Bigint& rhs);
	Bigint operator- (const Bigint& rhs);
	Bigint operator* (const Bigint& rhs);
	Bigint operator/ (const Bigint& rhs);
};
ostream& operator << (ostream& os, const Bigint& bigint) {
	if (!bigint.flag)
		os << '-';
	os << bigint.values;
	return os;
}
istream& operator >> (istream& is, Bigint& bigint) {
	string str;
	is >> str;
	bigint.flag = true;
	bigint.values = str;
	return is;
}
Bigint Bigint::operator+ (const Bigint& rhs) {
	Bigint ret;
	ret.flag = true;
	string lvalues(values), rvalues(rhs.values);
	if (lvalues == "0") {
		ret.values = rvalues;
		return ret;
	}
	if (rvalues == "0") {
		ret.values = lvalues;
		return ret;
	}
	unsigned int i, lsize, rsize;
	lsize = lvalues.size();
	rsize = rvalues.size();
	if (lsize < rsize) {
		for (i = 0; i < rsize - lsize; i++) {
			lvalues = "0" + lvalues;
		}
	}
	else {
		for (i = 0; i < lsize - rsize; i++) {
			rvalues = "0" + rvalues;
		}
	}
	int n1, n2;
	n2 = 0;
	lsize = lvalues.size();
	string res = "";
	reverse(lvalues.begin(), lvalues.end());
	reverse(rvalues.begin(), rvalues.end());
	for (i = 0; i < lsize; i++) {
		n1 = (lvalues[i] - '0' + rvalues[i] - '0' + n2) % 10;
		n2 = (lvalues[i] - '0' + rvalues[i] - '0' + n2) / 10;
		res = res + char(n1 + '0');
	}
	if (n2 == 1) {
		res = res + "1";
	}
	reverse(res.begin(), res.end());
	ret.values = res;
	return ret;
}
Bigint Bigint::operator- (const Bigint& rhs) {
	Bigint ret;
	string lvalues(values), rvalues(rhs.values);
	if (rvalues == "0") {
		ret.values = lvalues;
		ret.flag = true;
		return ret;
	}
	if (lvalues == "0") {
		ret.values = rvalues;
		ret.flag = false;
		return ret;
	}
	unsigned int i, lsize, rsize;
	lsize = lvalues.size();
	rsize = rvalues.size();
	if (lsize < rsize)
	{
		for (i = 0; i < rsize - lsize; i++)
		{
			lvalues = "0" + lvalues;
		}
	}
	else
	{
		for (i = 0; i < lsize - rsize; i++)
		{
			rvalues = "0" + rvalues;
		}
	}
	int t = lvalues.compare(rvalues);
	if (t < 0) {
		ret.flag = false;
		string tmp = lvalues;
		lvalues = rvalues;
		rvalues = tmp;
	}
	else if (t == 0) {
		ret.values = "0";
		ret.flag = true;
		return ret;
	}
	else {
		ret.flag = true;
	}
	unsigned int j;
	lsize = lvalues.size();
	string res = "";
	reverse(lvalues.begin(), lvalues.end());
	reverse(rvalues.begin(), rvalues.end());
	for (i = 0; i < lsize; i++) {
		if (lvalues[i] < rvalues[i]) {
			j = 1;
			while (lvalues[i + j] == '0') {
				lvalues[i + j] = '9';
			}
			lvalues[i + j] -= 1;
			res = res + char(lvalues[i] + ':' - rvalues[i]);
		}
		else {
			res = res + char(lvalues[i] - rvalues[i] + '0');
		}
	}
	reverse(res.begin(), res.end());
	res.erase(0, res.find_first_not_of('0'));
	ret.values = res;
	return ret;
}

Bigint Bigint::operator* (const Bigint& rhs) {
	Bigint ret;
	string lvalues(values), rvalues(rhs.values);
	if (lvalues == "0" || rvalues == "0")
	{
		ret.values = "0";
		ret.flag = true;
		return ret;
	}

	unsigned int lsize, rsize;
	lsize = lvalues.size();
	rsize = rvalues.size();
	string temp;
	Bigint res, itemp;
	if (lvalues < rvalues) {
		temp = lvalues;
		lvalues = rvalues;
		rvalues = temp;
		lsize = lvalues.size();
		rsize = rvalues.size();
	}
	int i, j, n1, n2, n3, t;
	reverse(lvalues.begin(), lvalues.end());
	reverse(rvalues.begin(), rvalues.end());
	for (i = 0; i < rsize; i++) {
		temp = "";
		n1 = n2 = n3 = 0;
		for (j = 0; j < i; j++) {
			temp = temp + "0";
		}
		n3 = rvalues[i] - '0';
		for (j = 0; j < lsize; j++) {
			t = (n3*(lvalues[j] - '0') + n2);
			n1 = t % 10;
			n2 = t / 10;
			temp = temp + char(n1 + '0');
		}
		if (n2) {
			temp = temp + char(n2 + '0');
		}
		reverse(temp.begin(), temp.end());
		itemp.values = temp;
		res = res + itemp;
	}
	ret = res;
	return ret;
}
Bigint Bigint::operator/ (const Bigint& rhs) {
	Bigint ret;
	string lvalues(values), rvalues(rhs.values);
	string quotient;
	if (rvalues == "0")
	{
		ret.values = "error";
		ret.flag = true;
		return ret;
	}
	if (lvalues == "0")
	{
		ret.values = "0";
		ret.flag = true;
		return ret;
	}
	if (compare(lvalues, rvalues) < 0)
	{
		ret.values = "0";
		ret.flag = true;
		return ret;
	}
	else if (compare(lvalues, rvalues) == 0)
	{
		ret.values = "1";
		ret.flag = true;
		return ret;
	}
	else {
		string temp;
		unsigned int lsize, rsize;
		lsize = lvalues.size();
		rsize = rvalues.size();
		int i;
		if (rsize > 1) temp.append(lvalues, 0, rsize - 1);
		for (i = rsize - 1; i < lsize; i++) {
			temp = temp + lvalues[i];
			for (char c = '9'; c >= '0'; c--) {
				Bigint t = (Bigint)rvalues*(Bigint)string(i, c);
				Bigint s = (Bigint)temp - t;

				if (s.flag == true) {
					temp = s.values;
					quotient = s.values + c;
					break;
				}
			}
		}
	}
	quotient.erase(0, quotient.find_first_not_of('0'));
	ret.values = quotient;
	ret.flag = true;
	return ret;
}
int main()
{
	Bigint a, b, result;
	char op;
	cin >> a >> op >> b;
	switch (op)
	{
	case '+':result = a + b; break;
	case '-':result = a - b; break;
	case '*':result = a * b; break;
	case '/':result = a / b; break;
	default:break;
	}
	cout << result << endl;
	return 0;
}