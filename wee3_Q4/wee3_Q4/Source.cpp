#include <iostream>
#include <iomanip>
using namespace std;

class Red {
	int m_dragon = 0;
	int m_ninja = 0;
	int m_iceman = 0;
	int m_lion = 0;
	int m_wolf = 0;
	int count = 0;

public:
	Red(int d, int n, int i, int l, int w, int k) :m_dragon(d), m_ninja(n), m_iceman(i), m_lion(l), m_wolf(w),m(k) {}
	int m = 0;
	static int dragon;
	static int ninja;
	static int iceman;
	static int lion;
	static int wolf;

	int build_warrior(int i);
};

int Red::dragon = 0;
int Red::ninja = 0;
int Red::iceman = 0;
int Red::lion = 0;
int Red::wolf = 0;

int Red::build_warrior(int i) {
	int a = 0;
	switch (i) {
	case 0: 
		if (m < m_iceman){
			build_warrior(1);
		}
			iceman++;
			m -= m_iceman;
			count++;
			cout << setfill('0') << setw(3) << count - 1 << " ";
			cout << "red iceman " << count << " born with strenth " << m_iceman << "," << iceman << " iceman in red headquarter" << endl;
			a = 1;
			break;

	case 1:
		if (m < m_lion) {
			build_warrior(2);
		}
			lion++;
			m -= m_lion;
			count++;
			cout << setfill('0') << setw(3) << count - 1 << " ";
			cout << "lion " << count << " born with strenth " << m_lion << "," << lion << " lion in red headquarter" << endl;
			a = 2;
			break;

	case 2:
		if (m < m_wolf) {
			build_warrior(3);
		}
			wolf++;
			m -= m_wolf;
			count++;
			cout << setfill('0') << setw(3) << count - 1 << " ";
			cout << "wolf " << count << " born with strenth " << m_wolf << "," << wolf << " wolf in red headquarter" << endl;
			a = 3;
			break;

	case 3:
		if (m < m_ninja) {
			build_warrior(4);
		}
			ninja++;
			m -= m_ninja;
			count++;
			cout << setfill('0') << setw(3) << count - 1 << " ";
			cout << "ninja " << count << " born with strenth " << m_ninja << "," << ninja << " ninja in red headquarter" << endl;
			a = 4;
			break;

	case 4:
		if (m < m_dragon) {
			build_warrior(0);
		}
			dragon++;
			m -= m_dragon;
			count++;
			cout << setfill('0') << setw(3) << count - 1 << " ";
			cout << "dragon " << count << " born with strenth " << m_dragon << "," << dragon << " dragon in red headquarter" << endl;
			a = 0;
			break;
	case 5:
			build_warrior(5);
			count++;
			cout << setfill('0') << setw(3) << count - 1 << " ";
			cout << "red headquater stops making warriors" << endl;
			break;
			
	}
	return a;
}
int main() {
	int ca, n = 0; //ca:case number| n is health
	int l[5] = {};
	cin >> ca;
	while (ca!= 0) {
		cin >> n >> l[0] >> l[1] >> l[2] >> l[3] >> l[4];
		
		cout << "Case:" << ca << endl;
		Red red(l[0], l[1], l[2], l[3], l[4], n);
		int temp = 0;
		while (red.m > 0) {
			temp = red.build_warrior(temp);
		}
		ca--;
	}
}