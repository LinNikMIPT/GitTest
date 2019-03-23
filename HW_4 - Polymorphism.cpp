#include <iostream>
#include <vector>
using namespace std;

class Num { // The main base class
public:
	Num() {};

	virtual void shownumQ() = 0; // Virtual function 

	~Num() {};
};

class outhex : public Num { // The hexadecimal numbering system
	vector <int> num16;
	vector <char> Anum16;

public:
	outhex(int number) {
		int b, c;
		b = number / 16;
		c = number % 16;
		num16.push_back(c);
		number = b;

		while (b >= 16)
		{
			b = number / 16;
			c = number % 16;
			num16.push_back(c);
			number = b;
		}
		num16.push_back(b);

		for (int i = 0; i < size(num16); i++) {
			if (num16[i] < 10) {
				char ch = (char)(((int)'0') + num16[i]);
				Anum16.push_back(ch);
			}
			if (num16[i] == 10)
				Anum16.push_back('A');
			if (num16[i] == 11)
				Anum16.push_back('B');
			if (num16[i] == 12)
				Anum16.push_back('C');
			if (num16[i] == 13)
				Anum16.push_back('D');
			if (num16[i] == 14)
				Anum16.push_back('E');
			if (num16[i] == 15)
				Anum16.push_back('F');
		}
	};

	virtual void shownumQ() {
		for (int i = 0; i < size(Anum16); i++)
			cout << Anum16[size(Anum16) - i - 1];
		cout << endl;
	}

	~outhex() {};
};

class outoct : public Num { // The octal number system
	vector <int> num8;

public:
	outoct(int number) {
		if (number == 8) {
			num8.push_back(0);
			num8.push_back(1);
		}
		if (number == 16) {
			num8.push_back(0);
			num8.push_back(2);
		}
		if (number == 32) {
			num8.push_back(0);
			num8.push_back(4);
		}
		if (number == 48) {
			num8.push_back(0);
			num8.push_back(6);
		}
		if (number != 8 && number != 16 && number != 32 && number != 48) {
			int b, c, n = number;
			b = n / 8;
			while (b >= 8)
			{
				b = n / 8;
				c = n % 8;
				num8.push_back(c);
				n = b;
			}
			num8.push_back(b);
		}
	};

	virtual void shownumQ() {
		for (int i = 0; i < size(num8); i++)
			cout << num8[size(num8) - i - 1];
		cout << endl;
	}

	~outoct() {};
};


int main()
{
	int n;
	cin >> n;

	outhex number1(n);
	number1.shownumQ();

	outoct number2(n);
	number2.shownumQ();

	system("pause");
	return 0;
}