#include <iostream>
#include <math.h>
using namespace std;

int dim;  /*Space dimension*/

class matrix;

class vector
{
	double *vec = new double[dim];

public:
	vector()  /*Constructor*/
	{
		for (int i = 0; i < dim; i++)
			vec[i] = 0.0;
	};

	~vector() /*Destructor*/
	{
			delete[] vec;
	};

	friend vector MxV(matrix m, vector v);  /*Friendly matrix-vector multiplication function*/

	double len()  /*vector length |v|(orthonormal basis)*/
	{
		double l = 0;
		for (int i = 0; i < dim; i++)
			l += sqrt(vec[i] * vec[i]);
		return l;
	}


	vector operator+(const vector& v)  /*Sum v1 + v2*/
	{
		vector res;
		for (int i = 0; i < dim; i++)
			res.vec[i] = v.vec[i] + vec[i];
		return res;
	}

	vector operator-(const vector& v)  /*Diff v1 - v2*/
	{
		vector res;
		for (int i = 0; i < dim; i++)
			res.vec[i] = vec[i] - v.vec[i];
		return res;
	}

	double operator*(const vector& v)  /*dot product of vectors v1 * v2 (orthonormal basis)*/
	{
		double res = 0;
		for (int i = 0; i < dim; i++)
			res = res + vec[i] * v.vec[i];
		return res;
	}

	bool operator==(vector v)  /*Comparison of vector modules |v1| == |v2|*/
	{
		if (v.len() == this->len())
			return true;
		else
			return false;
	}

	bool operator>(vector v)  /*Comparison of vector modules |v1| > |v2|*/
	{
		if (v.len() > this->len())
			return true;
		else
			return false;
	}

	bool operator<(vector v)  /*Comparison of vector modules |v1| < |v2|*/
	{
		if (v.len() < this->len())
			return true;
		else
			return false;
	}

	friend ostream &operator <<(ostream &stream, vector v)  /*Output*/
	{
		for (int i = 0; i < dim; i++)
			stream << v.vec[i] << " ";
		return stream;
	}

	friend istream &operator >>(istream &stream, vector &v)  /*Input*/
	{
		for (int i = 0; i < dim; i++)
			stream >> v.vec[i];
		return stream;
	}
};
/*-------------------------------------------------------------------------------------------------------------------------------*/

class matrix
{
	int **mat = new int*[dim];

public:
	matrix()                          /* Constructor */
	{
		mat = new int*[dim];
		for (int i = 0; i < dim; i++)
			mat[i] = new int[dim];
	}

	~matrix()                         /*Destructor*/
	{
		for (int i = 0; i < dim; i++)
			delete[] mat[i];
		delete[] mat;
		cout << "Matrix deleted" << endl;
	}

	friend vector MxV(matrix m, vector v);  /*Friendly matrix-vector multiplication function*/

	matrix T()  /*Matrix transpose*/
	{
		matrix m2;
		for (int i = 0; i < dim; i++)
		{
			for (int k = 0; k < dim; k++)
				m2.mat[i][k] = this->mat[k][i];
		}
		return m2;
	}


	matrix operator+(const matrix &m)  /*Sum m1 + m2*/
	{
		matrix res;
		for (int i = 0; i < dim; i++)
		{
			for (int k = 0; k < dim; k++)
				res.mat[i][k] = m.mat[i][k] + this->mat[i][k];
		}
		return res;
	}

	matrix operator-(const matrix& m)  /*Diff m1 - m2*/
	{
		matrix res;
		for (int i = 0; i < dim; i++)
		{
			for (int k = 0; k < dim; k++)
				res.mat[i][k] = this->mat[i][k] - m.mat[i][k];
		}
		return res;
	}

	matrix operator*(const matrix& m)  /*Times m1 * m2*/
	{
		matrix res;
		double x;

		for (int i = 0; i < dim; i++)
		{
			for (int k = 0; k < dim; k++)
			{
				x = 0;
				for (int g = 0; g < dim; g++)
					x = x + m.mat[i][g] * this->mat[g][k];
				res.mat[i][k] = x;
			}
		}
		return res;
	}

	friend ostream &operator <<(ostream &stream, matrix m)  /*Output*/
	{
		for (int i = 0; i < dim; i++)
		{
			for (int k = 0; k < dim; k++)
				stream << m.mat[i][k] << " ";
			cout << endl;
		}
		return stream;
	}

	friend istream &operator >>(istream &stream, matrix m)  /*Input*/
	{
		for (int i = 0; i < dim; i++)
		{
			for (int k = 0; k < dim; k++)
				stream >> m.mat[i][k];
		}
		return stream;
	}
};
/*-----------------------------------------------------------------------------------------------------------------------------------*/

class complex
{
	double re, im;

public:
	complex(double re_ = 0, double im_ = 0)  /* Constructor */
	{
		re = re_;
		im = im_;
	}

	~complex() {};  /*Destructor*/

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

	double abs(complex z)  /*Complex number module |z|*/
	{
		double mod;
		mod = sqrt(z.re * z.im + z.im * z.im);
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
			res.im = (-re * z.im + z.re * im) / (z.re * z.re + z.im + z.im);
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
};
/*-----------------------------------------------------------------------------------------------------------------------------------------*/

vector MxV(matrix m, vector v)  /*Matrix-vector multiplication function*/
{
	vector res;
	double x;

	for (int i = 0; i < dim; i++)
	{
		x = 0;
		for (int j = 0; j < dim; j++)
			x = x + v.vec[i] * m.mat[j][i];
		res.vec[i] = x;
	}
	return res;
}

int main() 
{
	cout << "Enter space dimension:" << endl;
	cin >> dim;
	cout << endl;

	cout << "VECTOR---------------------------------------------------------------------------------------------------" << endl;
	vector v1, v2;
	cout << "Enter vector_1:" << endl;
	cin >> v1;
	cout << "Enter vector_2:" << endl;
	cin >> v2;
	cout << endl;

	cout << "Vector_1 + Vector_2 is: " << endl;
	cout << v1 + v2 << " " << endl;
	cout << "Vector_1 - Vector_2 is: " << endl;
	cout << v1 - v2 << endl;
	cout << "Vector_1 x Vector_2 is: " << endl;
	cout << v1 * v2 << endl;

	if (v1 == v2)
		cout << "|Vector_1| = |Vector_2|" << endl;
	if (v1 > v2)
		cout << "|Vector_1| > |Vector_2|" << endl;
	if (v1 < v2)
		cout << "|Vector_1| < |Vector_2|" << endl;

	cout << endl;

	cout << "MATRIX ---------------------------------------------------------------------------------------------------" << endl;
	matrix m1, m2;
	cout << "Enter matrix_1:" << endl;
	cin >> m1;
	cout << "Enter matrix_2:" << endl;
	cin >> m2;
	cout << endl;

	cout << "Matrix_1 + Matrix_2 is:" << endl;
	cout << m1 + m2 << endl;
	cout << "Matrix_1 - Matrix_2 is:" << endl;
	cout << m1 - m2 << endl;
	cout << "Matrix_1^T is:" << endl;
	cout << m1.T() << endl;
	cout << "Matrix_1 x Matrix_2 is:" << endl;
	cout << m1 * m2 << endl << endl;

	cout << "Matrix-vector multiplication function----------------------------------------------------------------------" << endl;
	cout << "Vector_1 x Matrix_1 is:" << endl;
	cout << MxV(m1, v1) << endl << endl;

	cout << "COMPLEX-----------------------------------------------------------------------------------------------------" << endl;
	complex z1, z2;
	cout << "Enter complex_1:" << endl;
	cin >> z1;
	cout << "Enter complex_2:" << endl;
	cin >> z2;
	cout << endl;

	cout << "Complex_1 + Complex_2 is:" << endl;
	cout << z1 + z2 << endl;
	cout << "Complex_1 - Complex_2 is:" << endl;
	cout << z1 - z2 << endl;
	cout << "Complex_1 x Complex_2 is:" << endl;
	cout << z1 * z2 << endl;
	cout << "Complex_1 / Complex_2 is:" << endl;
	if (z2.Get_re() == 0 && z2.Get_im() == 0)
		cout << "It's impossible to divide Complex_1 by Comblex_2" << endl;
	else
		cout << z1 / z2 << endl;

	if (z1 == z2)
		cout << "|Complex_1| = |Complex_2|" << endl;
	if (z1 > z2)
		cout << "|Complex_1| > |Complex_2|" << endl;
	if (z1 < z2)
		cout << "|Complex_1| < |Complex_2|" << endl;

	cout << endl;

	system("pause");
	return 0;
}

