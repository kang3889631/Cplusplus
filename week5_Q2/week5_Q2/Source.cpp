#include <iostream>
#include <iomanip>
using namespace std;

class Warrior {
	int m_dragon = 0;
	int m_ninja = 0;
	int m_iceman = 0;
	int m_lion = 0;
	int m_wolf = 0;

public:
	Warrior(int d, int n, int i, int l, int w, int k) :m_dragon(d), m_ninja(n), m_iceman(i), m_lion(l), m_wolf(w), m(k) {}
	int count = 0;
	int m = 0;
	int dragon = 0;
	int ninja = 0;
	int iceman = 0;
	int lion = 0;
	int wolf = 0;

	int build_warrior(int i);
	int build_warrior_blue(int i);
	void weapon(int &m, int &m_w, char c);
};

void Warrior::weapon(int &m, int &m_w, char c){
	if (c == 'd') {
		int weapon = count % 3;
		float morale = (float)m / m_w;
		cout << "It has a ";
		if (weapon == 0)
			cout << "sword";
		else if (weapon == 1)
			cout << "bomb";
		else
			cout << "arrow";
		cout << ",and it's morale is " << fixed << setprecision(2) << morale << endl;
	}
	else if (c == 'n') {
		cout << "It has a ";
		int weapon1 = count % 3; 
		if (weapon1 == 0)
			cout << "sword";
		else if (weapon1 == 1)
			cout << "bomb";
		else
			cout << "arrow";
		cout << " and a ";
		int weapon2 = (count + 1) % 3;
		if (weapon2 == 0)
			cout << "sword";
		else if (weapon2 == 1)
			cout << "bomb";
		else
			cout << "arrow";
		cout << endl;
	}
	else if (c == 'i') {
		int weapon = count % 3;
		cout << "It has a ";
		if (weapon == 0)
			cout << "sword";
		else if (weapon == 1)
			cout << "bomb";
		else
			cout << "arrow";
		cout << endl;
	}
	else if (c == 'l') {
		cout << "It's loyalty is " << m << endl;
	}
	else {
	}
}
int Warrior::build_warrior(int i) {
	int a = 0;
	switch (i) {
	case 0:
		if (m < m_iceman) {
			return build_warrior(1);
		}
		iceman++;
		m -= m_iceman;
		count++;
		cout << "red iceman " << count << " born with strength " << m_iceman << "," << iceman << " iceman in red headquarter" << endl;
		weapon(m, m_iceman, 'i');
		a = 1;
		break;

	case 1:
		if (m < m_lion) {
			return build_warrior(2);
		}
		lion++;
		m -= m_lion;
		count++;
		cout << "red lion " << count << " born with strength " << m_lion << "," << lion << " lion in red headquarter" << endl;
		weapon(m, m_lion, 'l');
		a = 2;
		break;

	case 2:
		if (m < m_wolf) {
			return build_warrior(3);
		}
		wolf++;
		m -= m_wolf;
		count++;
		cout << "red wolf " << count << " born with strength " << m_wolf << "," << wolf << " wolf in red headquarter" << endl;
		a = 3;
		break;

	case 3:
		if (m < m_ninja) {
			return build_warrior(4);
		}
		ninja++;
		m -= m_ninja;
		count++;
		cout << "red ninja " << count << " born with strength " << m_ninja << "," << ninja << " ninja in red headquarter" << endl;
		weapon(m, m_ninja, 'n');
		a = 4;
		break;

	case 4:
		if (m < m_dragon) {
			return build_warrior(0);
		}
		dragon++;
		m -= m_dragon;
		count++;
		cout << "red dragon " << count << " born with strength " << m_dragon << "," << dragon << " dragon in red headquarter" << endl;
		weapon(m, m_dragon, 'd');
		a = 0;
		break;
	}
	return a;
}
int Warrior::build_warrior_blue(int i) {
	int a = 0;
	switch (i) {
	case 0:
		if (m < m_lion) {
			return build_warrior_blue(1);
		}
		lion++;
		m -= m_lion;
		count++;
		cout << "blue lion " << count << " born with strength " << m_lion << "," << lion << " lion in blue headquarter" << endl;
		weapon(m, m_lion, 'l');
		a = 1;
		break;

	case 1:
		if (m < m_dragon) {
			return build_warrior_blue(2);
		}
		dragon++;
		m -= m_dragon;
		count++;
		cout << "blue dragon " << count << " born with strength " << m_dragon << "," << dragon << " dragon in blue headquarter" << endl;
		weapon(m,m_dragon,'d');
		a = 2;
		break;

	case 2:
		if (m < m_ninja) {
			return build_warrior_blue(3);
		}
		ninja++;
		m -= m_ninja;
		count++;
		cout << "blue ninja " << count << " born with strength " << m_ninja << "," << ninja << " ninja in blue headquarter" << endl;
		weapon(m, m_ninja, 'n');
		a = 3;
		break;

	case 3:
		if (m < m_iceman) {
			return build_warrior_blue(4);
		}
		iceman++;
		m -= m_iceman;
		count++;
		cout << "blue iceman " << count << " born with strength " << m_iceman << "," << iceman << " iceman in blue headquarter" << endl;
		weapon(m, m_iceman, 'i');
		a = 4;
		break;

	case 4:
		if (m < m_wolf) {
			return build_warrior_blue(0);
		}
		wolf++;
		m -= m_wolf;
		count++;
		cout << "blue wolf " << count << " born with strength " << m_wolf << "," << wolf << " wolf in blue headquarter" << endl;
		a = 0;
		break;

	}
	return a;
}
int min(int d, int n, int i, int l, int w) {
	int a = d;
	if (n < a)
		a = n;
	if (i < a)
		a = i;
	if (l < a)
		a = l;
	if (w < a)
		a = w;
	return a;
}
int main() {
	int ca, n = 0, count = 1; //ca:case number| n is health
	int l[5] = {};

	cin >> ca;
	while (ca >= count) {
		cin >> n >> l[0] >> l[1] >> l[2] >> l[3] >> l[4];
		cout << "Case:" << count << endl;
		Warrior red(l[0], l[1], l[2], l[3], l[4], n);
		Warrior blue(l[0], l[1], l[2], l[3], l[4], n);
		int r = 0, b = 0, time = 0;
		bool red_finish_printed = false;
		bool blue_finish_printed = false;
		int m = min(l[0], l[1], l[2], l[3], l[4]);
		if (red.m < m && blue.m < m) {
			cout << setfill('0') << setw(3) << time << " ";
			cout << "red headquarter stops making warriors" << endl;
			cout << setfill('0') << setw(3) << time << " ";
			cout << "blue headquarter stops making warriors" << endl;
		}
		while (red.m >= m || blue.m >= m) {
			if (red_finish_printed == false && red.m < m) {
				cout << setfill('0') << setw(3) << time << " ";
				cout << "red headquarter stops making warriors" << endl;
				red_finish_printed = true;
			}
			else if (red.m >= m) {
				cout << setfill('0') << setw(3) << time << " ";
				r = red.build_warrior(r);
			}

			if (blue_finish_printed == false && blue.m < m) {
				cout << setfill('0') << setw(3) << time << " ";
				cout << "blue headquarter stops making warriors" << endl;
				blue_finish_printed = true;
			}
			else if (blue.m >= m) {
				cout << setfill('0') << setw(3) << time << " ";
				b = blue.build_warrior_blue(b);
			}
			time++;
			if (red_finish_printed == true && blue.m < m) {
				cout << setfill('0') << setw(3) << time << " ";
				cout << "blue headquarter stops making warriors" << endl;
			}
			if (blue_finish_printed == true && red.m < m) {
				cout << setfill('0') << setw(3) << time << " ";
				cout << "red headquarter stops making warriors" << endl;
			}
			if (red.m < m&&red_finish_printed == false && blue_finish_printed == false && blue.m < m) {
				cout << setfill('0') << setw(3) << time << " ";
				cout << "red headquarter stops making warriors" << endl;
				cout << setfill('0') << setw(3) << time << " ";
				cout << "blue headquarter stops making warriors" << endl;
			}
		}
		count++;
	}
}