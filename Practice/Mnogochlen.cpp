#include <iostream>
#include <string>
#include "mnogochleni.h"
#include <malloc.h>
#include <cmath>
using namespace std;
int Input_n()
{
    int n;
    while (1)
    {
        cout << "������� ������� ���������� (�� ����� 20): "; cin >> n;
        if (n > 0 && n <= 20) break;
    }
    return n;
}
double* Input_mnog(int n) 
{
    double* kefs = (double*)malloc((n + 1) * sizeof(double));
    cout << "������� ������������ ����������, ������� �� ������� �������:" << endl;
    for (int i = n; i >= 0; i--)
    {
        if (i > 1) cout << "����������� ��� x^" << i << ": ";
        if (i == 0) cout << "��������� �����������: "; 
        if (i == 1) cout << "����������� ��� x: ";
        cin >> kefs[i];
    }
    return kefs;
}
void Output_mnog(double* kefs, int n)
{
    cout << "P(" << n << ") = ";
    int fl = 1;

    for (int i = n; i >= 0; i--)
    {
        double a = kefs[i];
        if (a == 0) { cout << " "; continue; }

        if (fl == 0)
        {
            if (a > 0) cout << " + ";
        }
        if (a < 0) cout << "-";
        if (fabs(a) != 1 || i == 0) cout << fabs(a);

        if (i > 1) cout << "x^" << i;
        if (i == 1) cout << "x";
        fl = 0;
    }
    if (fl == 1) cout << "0";
    cout << endl;
}
double* type1(int st1, int st2, double* kefs1, double* kefs2)
{
    int m_st;
    m_st = max(st1, st2);
    double* result_kefs = (double*)calloc(m_st + 1, sizeof(double));
    for (int i = 0; i <= st1; i++) result_kefs[i] += kefs1[i];

    for (int i = 0; i <= st2; i++) result_kefs[i] += kefs2[i];
    return result_kefs;
}
void run_calc()
{
	int n, st1, st2;
    double* kefs1, *kefs2, *res;
	cout << "����������� �����������." << endl;
	while (1)
	{
		cout << "'b' - ������� � ������� ����" << endl;
		cout << "1 - �������� �����������" << endl;
		cout << "2 - ��������� �����������" << endl;
		cout << "3 - ��������� ���������� �� �����" << endl;
		cout << "4 - ���������� ����������� �� ����������" << endl;
		cout << "5 - ������� ����������� � �������" << endl;
		cout << "�������� ����� ������������: "; cin >> n;
		if (n > 0 && n <= 5) break;
	}
    switch (n)
    {
    case 1:
    {
        st1 = Input_n();
        kefs1 = Input_mnog(st1);
        cout << "1 ���������:" << endl;
        Output_mnog(kefs1, st1);
        st2 = Input_n();
        kefs2 = Input_mnog(st2);
        cout << "������ ���������:" << endl;
        Output_mnog(kefs2, st2);
        res = type1(st1, st2, kefs1, kefs2);
        cout << "��������� ����� ��������: " << endl;
        Output_mnog(res, max(st1, st2));
    }
    case 2:
    {

    }
    }
}