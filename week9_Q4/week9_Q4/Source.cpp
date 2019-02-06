/**********************
����n���ַ�������1��ʼ��ţ���ÿ���ַ����е��ַ�λ�ô�0��ʼ��ţ�����Ϊ1-500�������������ɲ�����
copy N X L��ȡ����N���ַ�����X���ַ���ʼ�ĳ���ΪL���ַ�����
add S1 S2���ж�S1��S2�Ƿ�Ϊ0-99999֮�����������������ת��Ϊ�������ӷ��������ǣ������ַ����ӷ������ص�ֵΪһ�ַ�����
find S N���ڵ�N���ַ����д���ʼ��ѰS�ַ������������һ�γ��ֵ�λ�ã���û���ҵ��������ַ����ĳ��ȡ�
rfind S N���ڵ�N���ַ����д��ҿ�ʼ��ѰS�ַ������������һ�γ��ֵ�λ�ã���û���ҵ��������ַ����ĳ��ȡ�
insert S N X���ڵ�N���ַ����ĵ�X���ַ�λ���в���S�ַ�����
reset S N������N���ַ�����ΪS��
print N����ӡ�����N���ַ�����
printall����ӡ��������ַ�����
over������������
����N��X��L����find��rfind��������ʽ���ɣ�S��S1��S2����copy��add��������ʽ���ɡ�
***********************/

/**********************
�����ĵ�
S1 S2���ܴ���99999
N X L ����С��0
ʹ�ù��캯����Ҫ���ܵ���ţ��Ӱ�� ����ֱ�ӵ��ú��������ˡ��� �������Ƚϸ߼�������ʵ�е��鷳
**********************/

#include <iostream>
#include <string>

//#include <stdio.h>
//#include <stdlib.h>

using namespace std;

string str[22];
string commend;
int N;
inline string MyCopy(); // copy N X L��ȡ����N���ַ�����X���ַ���ʼ�ĳ���ΪL���ַ�����
inline string MyAdd();  // add S1 S2���ж�S1��S2�Ƿ�Ϊ0-99999֮�����������������ת��Ϊ�������ӷ��������ǣ������ַ����ӷ������ص�ֵΪһ�ַ�����
inline int MyFind();    // find S N���ڵ�N���ַ����д���ʼ��ѰS�ַ������������һ�γ��ֵ�λ�ã���û���ҵ��������ַ����ĳ��ȡ�
inline int MyRfind();   // rfind S N���ڵ�N���ַ����д��ҿ�ʼ��ѰS�ַ������������һ�γ��ֵ�λ�ã���û���ҵ��������ַ����ĳ��ȡ�
inline void MyInsert(); // insert S N X���ڵ�N���ַ����ĵ�X���ַ�λ���в���S�ַ�����
inline void MyReset();  // reset S N������N���ַ�����ΪS��
struct GETS
{
	GETS(string &s) // �ݹ���������s��
	{
		cin >> s;
		if (s == "copy")
			s = MyCopy();
		else if (s == "add")
			s = MyAdd();
	}
};

struct GETINT
{
	string Commend;
	GETINT(int &n)  // �ݹ���������int n
	{
		cin >> Commend;
		if (Commend == "find")
			n = MyFind();
		else if (Commend == "rfind")
			n = MyRfind();
		else
			n = atoi(Commend.c_str());
	}
};

struct GETSTRING
{
	GETSTRING(int &m, string &s)    // �ݹ���������s�� ���ж����Ƿ�Ϊ����
	{
		GETS Gets(s);
		int i = 0;
		for (m = 0; i<s.length(); i++)
			if ((s.at(i) >= '0') && (s.at(i) <= '9'))
				m = m * 10 + s.at(i) - '0';
			else
				break;
		if ((i != s.length()) || (m>99999))
			m = -1;
	}
};

int wmain()
{
	cin >> N;
	for (int i = 0; i<N; i++)
		cin >> str[i + 1];
	while (cin >> commend)
	{
		if (commend == "over")
			break;
		switch (commend.at(1))
		{
		case 'n':   MyInsert(); break;
		case 'e':   MyReset(); break;
		case 'r':   if (commend == "print")
		{
			int n;
			cin >> n;
			cout << str[n] << endl;
		}
					else
					{
						for (int j = 1; j <= N; j++)
							cout << str[j] << endl;
					}
					break;
		}
	}
	return 0;
}

inline string MyCopy()
{
	int n, x, l;
	GETINT getintn(n);
	GETINT getintx(x);
	GETINT getintl(l);
	return (str[n].substr(x, l));
}

inline string MyAdd()   // add S1 S2���ж�S1��S2�Ƿ�Ϊ0-99999֮�����������������ת��Ϊ�������ӷ��������ǣ������ַ����ӷ������ص�ֵΪһ�ַ�����
{
	string s1, s2;
	int m = -1, n = -1;
	GETSTRING getstringms1(m, s1);
	GETSTRING getstringns2(n, s2);
	if ((m == -1) || (n == -1))
		return (s1 + s2);
	else
	{
		m += n;
		char chars[8];
		//_itoa(m, chars, 10);
		_itoa_s(m, chars, 10);
		//sprintf(m, chars, 10);
		return string(chars);
	}
}


inline int MyFind() // find S N���ڵ�N���ַ����д���ʼ��ѰS�ַ������������һ�γ��ֵ�λ�ã���û���ҵ������� ?? �ĸ� ���� �ַ����ĳ��ȡ�
{
	string s;
	int n, value;
	cin >> s;
	GETINT getintn(n);
	value = str[n].find(s);
	if (value == string::npos)
		value = str[n].length();
	return value;
}

inline int MyRfind()    // rfind S N���ڵ�N���ַ����д��ҿ�ʼ��ѰS�ַ������������һ�γ��ֵ�λ�ã���û���ҵ��������ַ����ĳ��ȡ�
{
	string s;
	int n, value;
	cin >> s;
	GETINT getintn(n);
	value = str[n].rfind(s);
	if (value == string::npos)
		value = str[n].length();
	return value;
}

inline void MyInsert()  // insert S N X���ڵ�N���ַ����ĵ�X���ַ�λ���в���S�ַ�����
{
	string s;
	int n, x;
	GETS Gets(s);
	GETINT getintn(n);
	GETINT getintx(x);
	str[n].insert(x, s);
}

inline void MyReset()   // reset S N������N���ַ�����ΪS��
{
	string s;
	int n;
	GETS Gets(s);
	GETINT getintn(n);
	str[n].assign(s);
}