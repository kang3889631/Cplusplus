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
	int i = 4;
public:
	Red(int d, int n, int i, int l, int w) :m_dragon(d), m_ninja(n), m_iceman(i), m_lion(l), m_wolf(w) {}
	static void setm(int n);
	static void print();
	static int dragon;
	static int ninja;
	static int iceman;
	static int lion;
	static int wolf;
	static int m;

	void printf();
	void build_warrior(int i);
};

int Red::dragon = 0;
int Red::ninja = 0;
int Red::iceman = 0;
int Red::lion = 0;
int Red::wolf = 0;
int Red::m = 0;

void Red::setm(int n) {
	m = n;
}
void Red::print() {
	cout << "m= " << m << endl;
}
void Red::printf() {
	cout << m_dragon << " " << m_ninja << " " << m_iceman << " " << m_lion << " " << m_wolf << endl;
}
void Red::build_warrior(int i) {
	
	switch (i) {
	case 0: 
			iceman++;
			m -= m_iceman;
			count++;
			cout << setfill('0') << setw(3) << count - 1 << " ";
			cout << "red iceman " << count << " born with strenth " << m_iceman << "," << iceman << " iceman in red headquarter" << endl;
			break;

	case 1:
			lion++;
			m -= m_lion;
			count++;
			cout << setfill('0') << setw(3) << count - 1 << " ";
			cout << "lion " << count << " born with strenth " << m_lion << "," << lion << " lion in red headquarter" << endl;
			break;

	case 2:
			wolf++;
			m -= m_wolf;
			count++;
			cout << setfill('0') << setw(3) << count - 1 << " ";
			cout << "wolf " << count << " born with strenth " << m_wolf << "," << wolf << " wolf in red headquarter" << endl;
			break;

	case 3:
			ninja++;
			m -= m_ninja;
			count++;
			cout << setfill('0') << setw(3) << count - 1 << " ";
			cout << "ninja " << count << " born with strenth " << m_ninja << "," << ninja << " ninja in red headquarter" << endl;
			break;

	case 4:
			dragon++;
			m -= m_dragon;
			count++;
			cout << setfill('0') << setw(3) << count - 1 << " ";
			cout << "dragon " << count << " born with strenth " << m_dragon << "," << dragon << " dragon in red headquarter" << endl;
			break;
	}
}
int main() {
	int ca, n, i = 0; //ca:case number| n is health
	int l[5] = {};
	cin >> ca;
	while (ca-- != 0) {
		cin >> n >> l[0] >> l[1] >> l[2] >> l[3] >> l[4];
		Red red(l[0], l[1], l[2], l[3], l[4]);
		red.setm(n);
		red.build_warrior(i);
		//red.print();
		//red.printf();
	}
}