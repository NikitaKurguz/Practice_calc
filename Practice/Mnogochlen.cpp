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
        if (i != 0) cout << "����������� ��� x^" << i << ": ";
        else cout << "��������� �����������: "; 
        cin >> kefs[i];
    }
    return kefs;
}
void Output_mnog(double* kefs)
{
    
    int n = 0;
    for (int i = 20; i >= 0; i--) {
        if (kefs[i] != 0) {
            n = i;
            break;
        }
    }

    cout << "P(x) = ";
    bool first_term = true; // ���� ��� ������� ����������

    for (int i = n; i >= 0; i--) {
        if (kefs[i] == 0) continue; // ���������� ������� ������������

        // ��������� �����
        if (!first_term) {
            cout << (kefs[i] > 0 ? " + " : " - ");
        }
        else if (kefs[i] < 0) {
            cout << "-";
        }

        // ����� ������������ (���� �� �� 1 ��� -1, ��� ��� ��������� ����)
        double abs_coef = abs(kefs[i]);
        if (abs_coef != 1 || i == 0) {
            cout << abs_coef;
        }

        // ����� ���������� x � �������
        if (i > 0) {
            cout << "x";
            if (i > 1) {
                cout << "^" << i;
            }
        }

        first_term = false;
    }
    if (first_term) {
        cout << "0";
    }

    cout << endl;
}
void run_calc()
{
	int n, st;
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
        Input_mnog(st);
    }

    }
}