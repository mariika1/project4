#pragma once
#include "Matrix.h"

template<class F> Matrix<F>::Matrix()

{
	stlb = 0;
	str = 0;
	arr = NULL;
}
template<class F> Matrix<F>::Matrix(int str_, int stlb_, F** other)
{
	arr = new F[str_][stlb_];
	for (int i = 0; i < str_; i++)
		for (int j = 0; j < stlb_; j++)
			arr[i][j] = other[i][j];
}
template<class F> Matrix<F>::Matrix(const Matrix<F>& other)
{
	this->str = other.str;
	this->stlb = other.stlb;
	F** arr = new F * [str];
	for (int i = 0; i < str; i++)
	{
		arr[i] = new int[stlb];
	}
	for (int i = 0; i < str; i++)
		for (int j = 0; j < stlb; j++)
			arr[i][j] = other.arr[i][j];
}
template<class F> Matrix<F>::~Matrix()
{
	if (arr != NULL)
	{
		for (int i = 0; i < stlb; i++)
		{
			delete[]arr[i];
		}
		delete[]arr;
		arr = NULL;
		str = 0;
		stlb = 0;
	}
}


template<class F>
int Matrix<F>::GetStr()
{
	return str;
}

template<class F>
int Matrix<F>::GetStlb()
{
	return stlb;
}
template<class F>
F Matrix<F>::GetArr(int i, int j)
{
	if (i >= 0 || i < str || j >= 0 || j < stlb)
		return arr[i][j];
	else return arr[0][0];
}
template<class F>
inline void Matrix<F>::Set(int _str, int _stlb, int min, int max)
{
	for (int i = 0; i < stlb; i++)
	{
		delete[]arr[i];
	}
	delete[]arr;
	str = _str;
	stlb = _stlb;
	float d;
	F** arr = new F * [str];
	for (int i = 0; i < str; i++)
	{
		arr[i] = new int[stlb];
	}
	for (int i = 0; i < str; i++)
		for (int j = 0; j < stlb; j++)
		{

			d = float(RAND_MAX - rand()) / RAND_MAX;
			arr[i][j] = min + F(d * (max - min));

		}
}
template<class F>
const F& Matrix<F>::operator()(int str_, int stlb_) const
{
	if (str_ < 0 || str_ >= str || stlb_ < 0 || stlb_ >= stlb)
		abort(); 
	return arr[str_][stlb_];
}

	
template<class F> Matrix<F>& Matrix<F>::operator=(const Matrix<F>& other)
{
	if (this != &other)
	{
		if (str != other.str || stlb != other.stlb)
		{
			for (int i = 0; i < stlb; i++)
			{
				delete[]arr[i];
			}
			delete[]arr;
			str = other.str;
			stlb = other.stlb;
			F** arr = new F * [str];
			for (int i = 0; i < str; i++)
			{
				arr[i] = new int[stlb];
			}
		}
		for (int i = 0; i < other.str; i++)
			for (int j = 0; j < other.stlb; j++)
				arr[i][j] = other.arr[i][j];
	}
	return *this;
}
template<class F>
bool Matrix<F>::operator==(const Matrix<F>& other) const
{
	if (str != other.str || stlb != other.stlb)
	{
		return false;
		break;
	}
	for (int i = 0; i < other.str; i++)
		for (int j = 0; j < other.stlb; j++)
			if (arr[i][j] = other.arr[i][j])
			{
				return false;
				break;
			}
	return true;
}
template<class F>
inline F** Matrix<F>::InitArray(F** other, int str, int stlb, F minVal, F maxVal)
{
	float d;
	for (int i = 0; i < str; i++)
		for (int j = 0; j < stlb; j++)
		{
			d = float(RAND_MAX - rand()) / RAND_MAX;
			other[i][j] = minVal + F(d * (maxVal - minVal));
		}
	return other;
}
template<class
	F>ostream& operator<<(ostream& vyvod, const Matrix<F>& other)
{


	for (int i = 0; i < other.str; i++)
	{
		vyvod << "(";
		for (int j = 0; j < other.stlb; j++)
			vyvod << other.arr[i][j] << " ";
		vyvod << ")" << endl;
	}
	vyvod << endl;
	return vyvod;
}

template<class
	F>istream& operator>>(istream& vvod, Matrix<F>& other)
{
	int str_;
	int stlb_;
	cout << "Введите количество строк:";
	vvod >> str_;
	cout << endl << "Введите количество строк:";
	vvod >> stlb_;
	if (other.str != str_ || other.stlb != stlb_)
	{
		if (other.arr != NULL)
			for (int i = 0; i < stlb; i++)
			{
				delete[] other.arr[i];
			}
		delete[] other.arr;
		other.str = str_;
		other.stlb = stlb_;
		other.arr = new F[str_][stlb_];
	}
	for (int i = 0; i < other.str; i++)
		for (int j = 0; j < other.stlb; j++)
		{
			cout << endl << "Введите значение:";
			vvod >> other.arr[i][j];
		}
	return vvod;
}

template<class F> Matrix<F> operator*(const Matrix<F>& m1, const Matrix<F>& m2)
{
	if (m1.str != m2.stlb || m1.stlb != m2.str)
	{
		cout << "Число столбцов m1 должно совпадать с числом строк m2, а число строк m1 должно совпадать с числом столбцов m2" << endl;
		break;
	}
	F** res = new F[m1.str][m2.stlb];
	for (int i = 0; i < m1.str; i++)
		for (int j = 0; j < m2.stlb; j++)
			for (int k = 0; k < m1.stlb; k++)
				res[i][j] += m1.arr[i][k] * m2.arr[k][j];
	return res;
}

template<class F> Matrix<F> operator+(const Matrix<F>& m1, const Matrix<F>& m2)
{
	if (m1.str != m2.str || m1.stlb != m2.stlb)
	{
		cout << "Должна быть одинаковая размерность" << endl;
		break;
	}
	F** res = new F[m1.str][m1.stlb];
	for (int i = 0; i < m1.str; i++)
		for (int j = 0; j < m1.stlb; j++)
			res.arr[i][j] = m1.arr[i][j] + m2.arr[i][j];
	return res;
}

template<class F> Matrix<F> operator-(const Matrix<F>& m1, const Matrix<F>& m2)
{
	if (m1.str != m2.str || m1.stlb != m2.stlb)
	{
		cout << "Должна быть одинаковая размерность" << endl;
		break;
	}
	F** res = new F[m1.str][m1.stlb];
	for (int i = 0; i < m1.str; i++)
		for (int j = 0; j < m1.stlb; j++)
			res.arr[i][j] = m1.arr[i][j] - m2.arr[i][j];
	return res;
}
