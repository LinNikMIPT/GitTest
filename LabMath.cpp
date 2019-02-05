#include <iostream>
#include <math.h>
using namespace std;

int dim;  /*Space dimension*/

class matrix;

class vector  
{
public:
	double *vec = new double[dim];

	vector()  /*Constructor*/
	{
		for (int i = 0; i < dim; i++)
			vec[i] = 0.0;
	};

	~vector() /*Destructor*/
	{
		//delete[] vec;              /*????????????*/
	};

	friend vector MxV(matrix m, vector v);  /*Friendly matrix-vector multiplication function*/

	double len(vector v)  /*vector length |v|(orthonormal basis)*/
	{
		double len = 0;
		for (int i = 0; i < dim; i++)
			len = len + sqrt(v.vec[i] * v.vec[i]);
		return len;
	}
};
/*OPERATOR OVERLOAD FOR VECTOR-------------------------------------------------------------------------------------------------*/
vector operator+(const vector& v1, const vector& v2)  /*Sum v1 + v2*/
{
	vector res;
	for (int i = 0; i < dim; i++)
		res.vec[i] = v1.vec[i] + v2.vec[i];
	return res;
}

vector operator-(const vector& v1, const vector& v2)  /*Diff v1 - v2*/
{
	vector res;
	for (int i = 0; i < dim; i++)
		res.vec[i] = v1.vec[i] - v2.vec[i];
	return res;
}

double operator*(const vector& v1, const vector& v2)  /*dot product of vectors v1 * v2 (orthonormal basis)*/
{
	double res = 0;
	for (int i = 0; i < dim; i++)
		res = res + v1.vec[i] * v2.vec[i];
	return res;
}

bool operator==(const vector& v1, const vector& v2)  /*Comparison of vector modules |v1| == |v2|*/
{
	vector v;
	if (v.len(v1) == v.len(v2))
		return true;
	else
		return false;
}

bool operator>(const vector& v1, const vector& v2)  /*Comparison of vector modules |v1| > |v2|*/
{
	vector v;
	if (v.len(v1) > v.len(v2))
		return true;
	else
		return false;
}

bool operator<(const vector& v1, const vector& v2)  /*Comparison of vector modules |v1| < |v2|*/
{
	vector v;
	if (v.len(v1) < v.len(v2))
		return true;
	else
		return false;
}

ostream &operator <<(ostream &stream, vector v)  /*Output*/
{
	for (int i = 0; i < dim; i++)
		stream << v.vec[i] << " ";
	return stream;
}

istream &operator >>(istream &stream, vector &v)  /*Input*/
{
	for (int i = 0; i < dim; i++)
		stream >> v.vec[i];
	return stream;
}
/*-------------------------------------------------------------------------------------------------------------------------------*/

class matrix 
{
public:

	int **mat = new int*[dim];
	matrix()
	{
		mat = new int*[dim];
		for (int i = 0; i < dim; i++)
			mat[i] = new int[dim];
	}

	~matrix()
	{
		for (int i = 0; i < dim; i++)
			delete[] mat[i];
		delete[] mat;
		cout << "Matrix deleted" << endl;
	}

	//	matrix()  /*Constructor*/   /*??????????????????/*/
	//{
	//	for (int i = 0; i < dim; i++)
	//		mat[i] = new int[dim];
	//}

	//~matrix()  /*Destructor*/   /*??????????????????/*/
	//{
	//	//for (int i = 0; i < dim; i++)
	//	//	delete[] mat[i];
	//	//delete[] mat;
	//};

	

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
};
/*OPERATOR OVERLOAD FOR MATRIX -------------------------------------------------------------------------------------------------------*/
matrix operator+(const matrix& m1, const matrix& m2)  /*Sum m1 + m2*/
{
	matrix res;
	for (int i = 0; i < dim; i++)
	{
		for (int k = 0; k < dim; k++)
			res.mat[i][k] = m1.mat[i][k] + m2.mat[i][k];
	}
	return res;
}

matrix operator-(const matrix& m1, const matrix& m2)  /*Diff m1 - m2*/
{
	matrix res;
	for (int i = 0; i < dim; i++)
	{
		for (int k = 0; k < dim; k++)
			res.mat[i][k] = m1.mat[i][k] - m2.mat[i][k];
	}
	return res;
}

matrix operator*(const matrix& m1, const matrix& m2)  /*Times m1 * m2*/
{
	matrix res;
	double x;

	for (int i = 0; i < dim; i++)
	{
		for (int k = 0; k < dim; k++)
		{
			x = 0;
			for (int g = 0; g < dim; g++)
				x = x + m1.mat[i][g] * m2.mat[g][k];
			res.mat[i][k] = x;
		}
	}
	return res;
}

ostream &operator <<(ostream &stream, matrix m)  /*Output*/
{
	for (int i = 0; i < dim; i++)
	{
		for (int k = 0; k < dim; k++)
			stream << m.mat[i][k] << " ";
		cout << endl;
	}
	return stream;
}

istream &operator >>(istream &stream, matrix &m)  /*Input*/
{
	for (int i = 0; i < dim; i++)
	{
		for (int k = 0; k < dim; k++)
			stream >> m.mat[i][k];
	}
	return stream;
}
/*-----------------------------------------------------------------------------------------------------------------------------------*/

class complex 
{
public:
	double re, im;
	complex()  /* Constructor */
	{
		re = 0;
		im = 0;
	}

	~complex() {};  /*Destructor*/

	double abs(complex z)  /*Complex number module |z|*/
	{
		double mod;
		mod = sqrt(z.re * z.im + z.im * z.im);
		return mod;
	}
};
/*OPERATOR OVERLOAD FOR COMPLEX NUMBERS ------------------------------------------------------------------------------------------------*/
complex operator+(const complex& z1, const complex& z2)  /*Sum z1 + z2*/
{
	complex res;
	res.re = z1.re + z2.re;
	res.im = z1.im + z2.im;
	return res;
}

complex operator-(const complex& z1, const complex& z2)  /*Diff z1 - z2*/
{
	complex res;
	res.re = z1.re - z2.re;
	res.im = z1.im - z2.im;
	return res;
}

complex operator*(const complex& z1, const complex& z2)  /*Times z1 * z2*/
{
	complex res;
	res.re = z1.re * z2.re - z1.im * z2.im;
	res.im = z1.re * z2.im + z2.re * z1.im;
	return res;
}

complex operator/(const complex& z1, const complex& z2)  /*Division z1 / z2*/
{
	complex res;
	res.re = (z1.re * z2.re + z1.im * z2.im) / (z2.re * z2.re + z2.im * z2.im);
	res.im = (z2.re * z1.im - z1.re * z2.im) / (z2.re * z2.re + z2.im * z2.im);
	return res;
}

bool operator==(const complex& z1, const complex& z2)  /*Comparison of complex numbers modules |z1| == |z2|*/
{	
	complex z;
	if (z.abs(z1) == z.abs(z2))
		return true;
	else
		return false;
}

bool operator<(const complex& z1, const complex& z2)  /*Comparison of complex numbers modules |z1| < |z2|*/
{
	complex z;
	if (z.abs(z1) < z.abs(z2))
		return true;
	else
		return false;
}

bool operator>(const complex& z1, const complex& z2)  /*Comparison of complex numbers modules |z1| < |z2|*/
{
	complex z;
	if (z.abs(z1) > z.abs(z2))
		return true;
	else
		return false;
}

ostream &operator <<(ostream &stream, complex z)  /*Output*/
{
	if (z.im >= 0)
		stream << z.re << "+" << z.im << "i";
	else
		stream << z.re << z.im << "i";
	return stream;
}

istream &operator >>(istream &stream, complex &z)  /*Input*/
{
	stream >> z.re >> z.im;
	return stream;
}
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
	if (z2.re == 0 && z2.im == 0)
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