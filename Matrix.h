#pragma once
#include <iostream>
#include <clocale>
#include <iomanip>

using namespace std;
template<class F>
class Matrix {
public:
	Matrix();
	Matrix(int str_, int stlb_, F** other);
	Matrix(const Matrix& other);
	~Matrix();

	const F& operator()(int str_, int stlb_) const;
	F GetArr(int i, int j);
	void Set(int _str, int _stlb, int min, int max);

	int GetStr();
	int GetStlb();
	Matrix& operator=(const Matrix& other);
	friend ostream& operator<<(ostream& vyvod, const Matrix<F>& other);
	friend istream& operator>>(istream& vvod, Matrix<F>& other);
	bool operator == (const Matrix<F>& other) const;
	friend Matrix<F> operator*(const Matrix<F>& m1, const Matrix<F>& m2);
	friend Matrix<F> operator+(const Matrix<F>& m1, const Matrix<F>& m2);
	friend Matrix<F> operator-(const Matrix<F>& m1, const Matrix<F>& m2);
	F** InitArray(F** other, int str, int stlb, F minVal, F maxVal);
private:
	F** arr;
	int str;
	int stlb;
};