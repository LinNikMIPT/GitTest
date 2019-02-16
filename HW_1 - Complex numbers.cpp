#include <iostream>
#include <math.h>
using namespace std;

const double pi = 3.1415;

class complex
{
	double re, im;

public:
	complex()  /* Constructor */
	{
		re = 0;
		im = 0;
	}

	void Set(double re_, double im_)
	{
		re = re_;
		im = im_;
	}

	double Get_re()
	{
		return re;
	}

	double Get_im()
	{
		return im;
	}

	double abs()  /*Complex number module |z|*/
	{
		double mod;
		mod = sqrt(re * re + im * im);
		return mod;
	}

	complex operator+(const complex& z)  /*Sum z1 + z2*/
	{
		complex res;
		res.re = re + z.re;
		res.im = im + z.im;
		return res;
	}

	complex operator-(const complex& z)  /*Diff z1 - z2*/
	{
		complex res;
		res.re = re - z.re;
		res.im = im - z.im;
		return res;
	}

	complex operator*(const complex& z)  /*Times z1 * z2*/
	{
		complex res;
		res.re = z.re * re - z.im * im;
		res.im = z.re * im + re * z.im;
		return res;
	}

	complex operator/(const complex& z)  /*Division z1 / z2*/
	{
		complex res;
		if (z.re * z.re + z.im + z.im != 0) {
			res.re = (z.re * re + z.im * im) / (z.re * z.re + z.im + z.im);
			res.im = (- re * z.im + z.re * im) / (z.re * z.re + z.im + z.im);
		}
		else {
			res.re = NAN;
			res.im = NAN;
		}
		return res;
	}

	bool operator==(const complex& z)  /*Comparison of complex numbers modules |z1| == |z2|*/
	{

		if (z.re * z.re + z.im * z.im == re * re + im * im)
			return true;
		else
			return false;
	}

	bool operator<(const complex& z)  /*Comparison of complex numbers modules |z1| < |z2|*/
	{
		if (z.re * z.re + z.im * z.im < re * re + im * im)
			return true;
		else
			return false;
	}

	bool operator>(const complex& z)  /*Comparison of complex numbers modules |z1| > |z2|*/
	{
		if (z.re * z.re + z.im * z.im > re * re + im * im)
			return true;
		else
			return false;
	}

	friend ostream &operator <<(ostream &stream, complex z)  /*Output*/
	{
		if (z.im >= 0)
			stream << z.re << "+" << z.im << "i";
		else
			stream << z.re << z.im << "i";
		return stream;
	}

	friend istream &operator >>(istream &stream, complex &z)  /*Input*/
	{
		double re, im;
		stream >> re >> im;
		z.re = re;
		z.im = im;
		return stream;
	}

	~complex() {};  /*Destructor*/
};

complex power(complex z, int n)
{
	complex ans;
	double fi;

	if (z.Get_re() != 0)
		fi = atan(z.Get_im() / z.Get_re());
	else
	{
		if (z.Get_im() >= 0)
			fi = pi / 2;
		else
			fi = -pi / 2;
	}

	ans.Set(pow(z.abs(), n)*cos(n*fi), pow(z.abs(), n)*sin(n*fi));
	return ans;
}

void root(complex z, int n)
{
	double fi;
	fi = atan(z.Get_im() / z.Get_re());

	for (int k = 0; k < n; k++)
	{
		if (sin((fi + 2 * pi * k) / n) >= 0)
			cout << pow(z.abs(), 1 / n)*cos((fi + 2 * pi * k) / n) << "+"
			<< pow(z.abs(), 1 / n)*sin((fi + 2 * pi * k) / n) << "i" << endl;
		else
			cout << pow(z.abs(), 1 / n)*cos((fi + 2 * pi * k) / n) << 
			pow(z.abs(), 1 / n)*sin((fi + 2 * pi * k) / n) << "i" << endl;
	}
}



int main()
{
	int n1, n2;
	complex z1, z2;
	cout << "Enter Complex_1:" << endl;
	cin >> z1;
	cout << "Enter Complex_2:" << endl;
	cin >> z2;
	cout << "Enter exponet:" << endl;
	cin >> n1;
	cout << "Enter degree of root:" << endl;
	cin >> n2;

	cout << endl;

	cout << "Complex_1 + Complex_2 is:" << endl;
	cout << z1 + z2 << endl;
	cout << "Complex_1 - Complex_2 is:" << endl;
	cout << z1 - z2 << endl;
	cout << "Complex_1 x Complex_2 is:" << endl;
	cout << z1 * z2 << endl;
	cout << "Complex_1 / Complex_2 is:" << endl;
	if (z2.Get_re() == 0 && z2.Get_im() == 0)
		cout << "It's impossible to divide Complex_1 by Comblex_2 cause Comblex_2 = 0" << endl;
	else
		cout << z1 / z2 << endl;

	if (z1 == z2)
		cout << "|Complex_1| = |Complex_2|" << endl;
	if (z1 > z2)
		cout << "|Complex_1| > |Complex_2|" << endl;
	if (z1 < z2)
		cout << "|Complex_1| < |Complex_2|" << endl;

	cout << "Complex_1 to the degree " << n1 << " is:" << endl;
	cout << power(z1, n1) << endl;

	cout << "Roots of degree " << n2 << " Complex_2 are:" << endl;
	root(z2, n2);

	cout << endl;

	system("pause");
	return 0;
}

