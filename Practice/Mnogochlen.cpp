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
        cout << "Введите степень многочлена (не более 20): "; cin >> n;
        if (n > 0 && n <= 20) break;
    }
    return n;
}
double* Input_mnog(int n) 
{
    double* kefs = (double*)malloc((n + 1) * sizeof(double));
    cout << "Введите коэффициенты многочлена, начиная со старшей степени:" << endl;
    for (int i = n; i >= 0; i--)
    {
        if (i > 1) cout << "Коэффициент при x^" << i << ": ";
        if (i == 0) cout << "Свободный коэффициент: "; 
        if (i == 1) cout << "Коэффициент при x: ";
        cin >> kefs[i];
    }
    return kefs;
}
double Input_a()
{
    double a;
    cout << "Введите число умножения: "; cin >> a;
    return a;
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
double* type2(int st1, int st2, double* kefs1, double* kefs2) 
{
    double* result = (double*)calloc(max(st1, st2) + 1, sizeof(double));
    for (int i = 0; i <= st1; i++) result[i] += kefs1[i];
    for (int i = 0; i <= st2; i++)  result[i] -= kefs2[i];
    return result;
}
double* type3(int st1, double* kefs1, double a)
{
    for (int i = st1; i << st1 >= 0; i--) kefs1[i] *= a;
    return kefs1;
}
void run_calc()
{
	int n, st1, st2;
    double* kefs1, *kefs2, *res;
    int a;
	cout << "Калькулятор многочленов." << endl;
	while (1)
	{
		cout << "'b' - возврат в главное меню" << endl;
		cout << "1 - сложение многочленов" << endl;
		cout << "2 - вычитание многочленов" << endl;
		cout << "3 - умножение многочлена на число" << endl;
		cout << "4 - вычисление производной от многочлена" << endl;
		cout << "5 - деление многочленов в столбик" << endl;
		cout << "Выберите режим калькулятора: "; cin >> n;
		if (n > 0 && n <= 5) break;
	}
    switch (n)
    {
    case 1:
    {
        st1 = Input_n();
        kefs1 = Input_mnog(st1);
        cout << "1 многочлен:" << endl;
        Output_mnog(kefs1, st1);
        st2 = Input_n();
        kefs2 = Input_mnog(st2);
        cout << "Второй многочлен:" << endl;
        Output_mnog(kefs2, st2);
        res = type1(st1, st2, kefs1, kefs2);
        cout << "Результат после сложения: " << endl;
        Output_mnog(res, max(st1, st2));
    }; break;
    case 2:
    {
        st1 = Input_n();
        kefs1 = Input_mnog(st1);
        cout << "1 многочлен:" << endl;
        Output_mnog(kefs1, st1);
        st2 = Input_n();
        kefs2 = Input_mnog(st2);
        cout << "Второй многочлен:" << endl;
        Output_mnog(kefs2, st2);
        res = type2(st1, st2, kefs1, kefs2);
        cout << "Результат после вычитания: " << endl;
        Output_mnog(res, max(st1, st2));
    }; break;
    case 3:
    {
        st1 = Input_n();
        kefs1 = Input_mnog(st1);
        cout << "1 многочлен:" << endl;
        Output_mnog(kefs1, st1);
        a = Input_a();
        kefs2 = type3(st1, kefs1, a);
        cout << "Результат после умножения многочлена на число: " << endl;
        Output_mnog(kefs2, st1);
    }; break;
    }
}