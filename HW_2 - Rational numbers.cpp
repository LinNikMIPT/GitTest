#include <iostream>
#include <map>
#include <string>

using namespace std;

int GCD(int a, int b) {      //greatest common divisor
	int t;
	while (b != 0) {
		t = b;
		b = a % b;
		a = t;
	}
	return a;
}

class Q {
	int p, q;

public:
	Q(int p_ = 0, int q_ = 1) {
		if (q_ != 0) {
			int p1;
			if (GCD(p_, q_) != 1) {
				p1 = p_;
				p_ = p_ / GCD(p_, q_);
				q_ = q_ / GCD(p1, q_);
			}
			p = p_;
			q = q_;
		}
		else
			cout << "Incorect input!" << endl;
	}

	int Get_q() {
		return q;
	}

	int Get_p() {
		return p;
	}

	Q Set(int p, int q) {
		Q q1(p, q);
		return q1;
	}

	~Q() {};

	Q operator*(const Q& n)
	{
		Q ans;
		ans.p = p * n.p;
		ans.q = q * n.q;
		return ans;
	}

	Q operator/(const Q& n)
	{
		return Q(p * n.q, q * n.p);
	}

	Q operator+(const Q& n)
	{
		return Q(p * n.q + q * n.p, q * n.q);
	}

	Q operator-(const Q& n)
	{
		return Q(p * n.q - q * n.p, q * n.q);
	}

	bool operator==(const Q& n)
	{
		if (p * n.q == q * n.p)
			return true;
		else
			return false;
	}

	friend ostream &operator <<(ostream &stream, Q n)
	{
		if (n.q < 0) {
			n.p = -n.p;
			n.q = -n.q;
		}
		stream << n.p << " " << n.q;
		return stream;
	}

	friend istream &operator >>(istream &stream, Q &n)  
	{
		int p_, q_;
		stream >> p_ >> q_;
		n.p = p_;
		n.q = q_;
		return stream;
	}

	friend Q norm(const Q& x) {
		Q ans = x;
		if (GCD(x.p, x.q) != 1) {
			ans.p = x.p / GCD(x.p, x.q);
			ans.q = x.q / GCD(x.p, x.q);
		}
		return ans;
	}
};

int main() {
	Q q1, q2, q(1, 2), ans;
	map <Q, string> m1 = {{q, "One half"}};  

	cout << "Enter Q1:" << endl;
	cin >> q1;
	cout << "Enter Q2:" << endl;
	cin >> q2;
	cout << endl;


	cout << "Q1 + Q2:" << endl;
	ans = q1 + q2;
	cout << norm(ans) << endl;

	cout << "Q1 - Q2:" << endl;
	ans = q1 - q2;
	cout << norm(ans) << endl;

	cout << "Q1 * Q2:" << endl;
	ans = q1 * q2;
	cout << norm(ans) << endl;

	cout << "Q1 / Q2:" << endl;
	ans = q1 / q2;
	cout << norm(ans) << endl;
	
	if (q1 == q2)
		cout << "Q1 == Q2" << endl;
	else
		cout << "Q1 != Q2" << endl;

	cout << q << " is " << m1[q] << endl;

	system("pause");
	return 0;
}