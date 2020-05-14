#pragma once
#include "Vector.h"

template<class F>
Vector<F>::Vector()
{
	n = 0;
	arr = NULL;
}

template<class F>
Vector<F>::Vector(int size, F* other)
{
	arr = new F[size];

	for (int i = 0; i < size; i++)
		arr[i] = other[i];

}
template<class F>
Vector<F>::Vector(const Vector<F>& other)
{
	this->n = other.n;
	arr = new F[n];
	for (int i = 0; i < n; i++)
		arr[i] = other.arr[i];
}

template<class F>
Vector<F>::~Vector()
{
	if (arr != NULL)
	{
		delete[] arr;
		arr = NULL;
		n = 0;
	}
}

template<class F> const F& Vector<F>::operator[](int index) const
{
	if (index < 0 || index >= n)
		abort(); 
	return arr[index];
}

template<class F>
F Vector<F>::GetArr(int i)
{
	if ((i >= 0) || (i < n))
		return arr[i];
	else return arr[0];
}

template<class F>
int Vector<F>::GetSize()
{
	return n;
}

template<class F>
inline void Vector<F>::Set(int size, int min, int max)
{
	delete[] arr;
	n = size;
	float d;
	arr = new F[n];
	for (int i = 0; i < n; i++)
	{

		d = float(RAND_MAX - rand()) / RAND_MAX;
		arr[i] = min + F(d * (max - min));

	}
}
	
template<class F> Vector<F>& Vector<F>::operator=(const Vector<F>& other)
{
	if (this != &other)
	{
		if (n != other.n)
		{
			delete[] arr;
			n = other.n;
			arr = new F[n];
		}
		for (int i = 0; i < n; i++)
			arr[i] = other.arr[i];
	}
	return *this;
}
template<class F>
bool Vector<F>::operator==(const Vector<F>& other) const
{
	if (strcmp(arr, other.arr) < 0) return true;
	else return false;
}

template<class F>ostream& operator<<(ostream& vyvod, const Vector<F>& other)
{
	vyvod << "(";
	for (int i = 0; i < other.n; i++)
	{
		vyvod << other.arr[i];
		if (i < other.n)
			vyvod << " ";
	}
	vyvod << ")";
	return vyvod;
}

template<class F>istream& operator>>(istream& vvod, Vector<F>& other)
{
	int size;
	cout << "Введите размерность:";
	vvod >> size;
	if (other.n != size)
	{
		if (other.arr != NULL)
			delete[] other.arr;
		other.n = size;
		other.arr = new F[size];
	}
	for (int i = 0; i < other.n; i++)
	{
		cout << endl << "Введите значение: ";
		vvod >> other.arr[i];
	}
	return vvod;
}

template<class F> Vector<F> operator*(const Vector<F>& v1, const Vector<F>& v2)
{
	if (v2.n != v1.n)
	{
		cout << "Должна быть одинаковая размерность" << endl;
		break;
	}
	F res = 0;
	for (int i = 0; i < v1.n; i++)
		res += v1.arr[i] * v2.arr[i];
	return res;
}

template<class F> Vector<F> operator+(const Vector<F>& v1, const Vector<F>& v2)
{
	if (v2.n != v1.n)
	{
		cout << "Должна быть одинаковая размерность" << endl;
		break;
	}
	Vector<F> res(v1.n, 0);
	for (int i = 0; i < v1.n; i++)
		res.arr[i] = v1.arr[i] + v2.arr[i];
	return res;
}

template<class F> Vector<F> operator-(const Vector<F>& v1, const Vector<F>& v2)
{
	if (v2.n != v1.n)
	{
		cout << "Должна быть одинаковая размерность" << endl;
		break;
	}
	Vector<F> res(v1.n, 0);
	for (int i = 0; i < v1.n; i++)
		res.arr[i] = v1.arr[i] - v2.arr[i];
	return res;
}
template<class F>
Vector<F> operator*(const Vector<F>& v, const Matrix<F>& m)
{
	if (v.n != m.str)
	{
		cout << "Размерность вектора должна совпадать с числом строк в матрице" << endl;
		break;
	}
	F* res = new F[m.stlb];
	for (int i = 0; i < m.stlb; i++)
		for (int j = 0; j < v.n; j++)
			res[i] += v.arr[j] * m.arr[j][i];
	return res;
}
template<class F>
Vector<F> operator*(const Matrix<F>& m, const Vector<F>& v)
{
	if (v.n != m.stlb)
	{
		cout << "Размерность вектора должна совпадать с числом столбцов в матрице" << endl;
		break;
	}
	F* res = new F[m.str];
	for (int i = 0; i < m.str; i++)
		for (int j = 0; j < v.n; j++)
			res[i] += v.arr[j] * m.arr[i][j];
	return res;
}
template<class F>
clock_t BubbleSort(Vector<F>& other)
{
	clock_t start, finish;
	start = clock();
	F tmp = 0;
	int i, j = 0;
	start = clock();
	for (int i = 0; i < other.n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (other.GetArr(j) > other.GetArr(j + 1))
			{
				tmp = other.GetArr(j);
				other.GetArr(j) = other.GetArr(j + 1);
				other.GetArr(j + 1) = tmp;
			}
		}
	}
	finish = clock();
	return (finish - start);
}
template<class F>
clock_t InsertionSort(Vector<F>& other)
{
	clock_t start, finish;
	start = clock();
	F tmp;
	int location;

	for (int i = 1; i < other.n; i++)
	{
		tmp = other.GetArr(i);
		location = i - 1;
		while (location >= 0 && other.GetArr(location) > tmp)
		{
			other.GetArr(location + 1) = other.GetArr(location);
			location = location - 1;
		}
		other.GetArr(location + 1) = tmp;
	}
	finish = clock();
	return (finish - start);
}
template<class F>
clock_t QuickSort(Vector<F>& other, int first, int last)
{
	clock_t t1, t2, t3;
	t1 = clock();
	int i = first, j = last;
	F tmp;
	F x = other.GetArr((first + last) / 2);

	do {
		while (other.GetArr(i) < x)
			i++;
		while (other.GetArr(j) > x)
			j--;

		if (i <= j)
		{
			if (i < j)
			{
				tmp = other.GetArr(i);
				other.GetArr(i) = other.GetArr(j);
				other.GetArr(j) = tmp;
			}
			i++;
			j--;
		}
	} while (i <= j);

	if (i < last)
		t3 = QuickSort(other, i, last);
	if (first < j)
		t3 = QuickSort(other, first, j);
	t2 = clock();
	return t2 - t1;
}