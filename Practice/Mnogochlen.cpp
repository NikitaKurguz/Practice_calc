#include <iostream>
#include <string>
#include "mnogochleni.h"
#include <malloc.h>
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
void run_calc()
{
	int n, st;
    double* kefs;
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
        st = Input_n();
        kefs = Input_mnog(st);
        Output_mnog(kefs, st);
    }

    }
}