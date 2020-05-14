#pragma once
#include <clocale>
#include <iomanip>
#include <iostream>
#include "Matrix.h"
using namespace std;

template<class F>
class Vector :public Matrix<F>
{
public:
	Vector();
	Vector(int size, F* other);
	Vector(const Vector& other);
	~Vector();
	const F& operator[](int index) const;
	F GetArr(int i);
	int GetSize();
	void Set(int size, int min, int max);
	Vector& operator=(const Vector& other);
	template<class F>
	friend ostream& operator<<(ostream& vyvod, const Vector<F>& other);
	template<class F>
	friend istream& operator>>(istream& vvod, Vector<F>& other);
	bool operator == (const Vector<F>& other) const;
	friend Vector<F> operator*(const Vector<F>& v1, const Vector<F>& v2);
	friend Vector<F> operator+(const Vector<F>& v1, const Vector<F>& v2);
	friend Vector<F> operator-(const Vector<F>& v1, const Vector<F>& v2);
	friend Vector<F> operator*(const Vector<F>& v, const Matrix<F>& m);
	friend Vector<F> operator*(const Matrix<F>& m, const Vector<F>& v);
	friend clock_t BubbleSort(Vector<F>& other);
	friend clock_t InsertionSort(Vector<F>& other);
	friend clock_t QuickSort(Vector<F>& other, int first, int last);
private:
	F* arr;
	int n;

};