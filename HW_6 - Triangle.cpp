#include <iostream>
using namespace std;

struct Point
{
private:
	int x, y;

public:
	Point() {};

	Point(int x_, int y_) {
		x = x_;
		y = y_;
	}

	void Set(int x_, int y_) {
		x = x_;
		y = y_;
	}

	friend ostream &operator <<(ostream &stream, Point &p)
	{
		stream << p.x << " " << p.y;
		return stream;
	}

	~Point() {};
};

class Triangle {
	Point x1, x2, x3;
	double len12, len23, len31;

public:
	Triangle() {};

	Triangle(int X1, int Y1, int X2, int Y2, int X3, int Y3) {
		x1.Set(X1, Y1);
		x2.Set(X2, Y2);
		x3.Set(X3, Y3);

		if (Y1 != Y2 && Y2 != Y3) {
			if (((X1 - X2) / (Y1 - Y2)) * ((X1 - X2) / (Y1 - Y2)) == ((X3 - X2) / (Y3 - Y2)) * ((X3 - X2) / (Y3 - Y2))) {
				cout << "The triangle is degenerated!" << endl;
			}
			else {
				cout << "The triangle isn't degenerated!" << endl;
			}
		}
		else {
			cout << "The triangle isn't degenerated!" << endl;
		}
	}

	void print() {
		cout << x1 << " " << x2 << " "  << x3;
	}

	~Triangle() {};
};

class MathEx {
public:
	MathEx() {};

	~MathEx() {};

	virtual void perr() = 0;
};


class  DiaEx {
	int a, b;

public:
	DiaEx() {};
	DiaEx(int a_, int b_) {
		a = a_;
		b = b_;
	}

	~DiaEx() {};
};


int main()
{
	system("pause");
	return 0;
}