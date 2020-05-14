#include <cstdlib>
#include <iostream>
#include <malloc.h>
#include <time.h>

#include "Vector.h"
#include "Vector.doing.h"
#include "Matrix.h"
#include "Matrix.doing.h"
#include <iostream>
#include <clocale>
#include <vector>
using namespace std;

int main()
{
	setlocale(LC_CTYPE, "Russian");
	Vector<int> v1, v2;
	v1.Set(3, 4, 41);
	v2.Set(3, 1, 54);
	Vector<int> v3(v1);
	cout << "�������� ������ ������� Set, ��������� ���������� ������ � ��������� �����������:" << "v1=" << v1 << endl << "v2=" << v2 << endl << "v3=" << v3 << endl;
	cin >> v3;
	cout << "�������� ������ ��������� ���������� �����:" << "v3=" << v3 << endl;
	v3 = v1 + v2;
	cout << "�������� ������ ��������� ����� � ��������� ������������:" << "v3=" << v3 << endl;
	v3 = v1 - v2;
	cout << "�������� ������ ��������� ��������:" << "v3=" << v3 << endl;
	v3 = v1 * v2;
	cout << "�������� ������ ��������� ��������� ������� �� ������:" << "v3=" << v3 << endl;
	cout << "���������� ��������� ��:" << BubbleSort(v1) << "������" << endl << "v1=" << v1 << endl;
	cout << "���������� ���������� ��:" << InsertionSort(v2) << "������" << endl << "v2=" << v2 << endl;
	cout << "���������� ��������� ��:" << QuickSort(v3, 0, v3.GetSize()) << "������" << endl << "v3=" << v3 << endl;
	Matrix<int> m1, m2, m4;
	m1.Set(3, 2, 1, 84);
	m2.Set(3, 2, 41, 150);
	m4.Set(2, 3, 41, 150);
	Matrix<int> m3(m1);
	cout << "�������� ������ ������� Set, ��������� ���������� ������ � ��������� �����������:" << "m1=" << m1 << endl << "m2=" << m2 << endl << "m3=" << m3 << endl;
	cin >> m3;
	cout << "�������� ������ ��������� ���������� �����:" << "m3=" << m3 << endl;
	m3 = m1 + m2;
	cout << "�������� ������ ��������� ����� � ��������� ������������:" << "m3=" << m3 << endl;
	m3 = m1 - m2;
	cout << "�������� ������ ��������� ��������:" << "m3=" << m3 << endl;
	m3 = m1 * m4;
	cout << "�������� ������ ��������� ��������� ������� �� �������:" << "m3=" << m3 << endl;
	v3 = v1 * m1;
	cout << "�������� ������ ��������� ��������� ������� �� �������:" << "v3=" << v3 << endl;
	v3 = m4 * v1;
	cout << "�������� ������ ��������� ��������� ������� �� ������:" << "v3=" << v3 << endl;
	return 0;
}