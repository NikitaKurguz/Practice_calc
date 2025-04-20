#include <iostream>
#include <string>
#include "mnogochleni.h"
#include <malloc.h>
#include <cmath>
#include <limits>
using namespace std;
int Input_n() 
{
    int n;
    while (1) 
    {
        cout << "Введите степень многочлена (от 0 до 20): ";
        if (cin >> n) 
        {
            if (n >= 0 && n <= 20) break;
            else cout << "Ошибка! Степень должна быть от 0 до 20. Попробуйте снова." << endl;
        }
        else 
        {
            cout << "Ошибка ввода! Пожалуйста, введите целое число." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    return n;
}
double* Input_mnog(int n) {
    double* kefs = (double*)malloc((n + 1) * sizeof(double));
    cout << "Введите коэффициенты многочлена, начиная со старшей степени:" << endl;

    for (int i = n; i >= 0; i--) 
    {
        while (1) 
        {
            if (i > 1) cout << "Коэффициент при x^" << i << ": ";
            if (i == 0) cout << "Свободный коэффициент: ";
            if (i == 1) cout << "Коэффициент при x: ";

            if (cin >> kefs[i]) break;
            else 
            {
                cout << "Ошибка ввода! Пожалуйста, введите число." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
    }
    return kefs;
}

double Input_a() 
{
    double a;
    while (true) 
    {
        cout << "Введите число умножения: ";
        if (cin >> a) break;
        else 
        {
            cout << "Ошибка ввода! Пожалуйста, введите число." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
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
        if (a < 0) cout << " - ";
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
    for (int i = st1; i >= 0; i--) kefs1[i] *= a;
    return kefs1;
}
double* type4(int& st1, double* kefs1)
{
    if (st1 == 0)
    {
        double* n_kefs = (double*)malloc(sizeof(double));
        n_kefs[0] = 0.0;
        st1 = 0;
        return n_kefs;
    }
    double* n_kefs = (double*)malloc(st1 * sizeof(double));
    for (int i = 0; i < st1; ++i) n_kefs[i] = kefs1[i + 1] * (i + 1);
    st1--;
    return n_kefs;
}

Del_mnog type5(double* kefs1, int st1, double* kefs2, int st2)
{
    Del_mnog res;
    bool is_zero_poly = true;
    for (int i = 0; i <= st2; i++)
    {
        if (fabs(kefs2[i]) > 1e-10)
        {
            is_zero_poly = false;
            break;
        }
    }

    if (is_zero_poly)
    {
        cerr << "Ошибка: деление на нулевой многочлен!" << endl;
        exit(EXIT_FAILURE);
    }
    int real_st2 = st2;
    while (real_st2 >= 0 && fabs(kefs2[real_st2]) < 1e-10) real_st2--;

    if (real_st2 < 0)
    {
        cerr << "Ошибка: деление на нулевой многочлен!" << endl;
        exit(EXIT_FAILURE);
    }

    if (real_st2 == 0)
    {
        res.st_z = st1;
        res.kefs_z = (double*)malloc((st1 + 1) * sizeof(double));
        for (int i = 0; i <= st1; i++)
            res.kefs_z[i] = kefs1[i] / kefs2[0];
        res.st_ost = 0;
        res.kefs_ost = (double*)malloc(sizeof(double));
        res.kefs_ost[0] = 0.0;
        return res;
    }
    if (real_st2 > st1)
    {
        res.st_z = 0;
        res.kefs_z = (double*)calloc(1, sizeof(double));
        res.st_ost = st1;
        res.kefs_ost = (double*)malloc((st1 + 1) * sizeof(double));
        for (int i = 0; i <= st1; i++) res.kefs_ost[i] = kefs1[i];
        return res;
    }

    res.st_z = st1 - real_st2;
    res.st_ost = real_st2 - 1;
    res.kefs_z = (double*)calloc(res.st_z + 1, sizeof(double));
    res.kefs_ost = (double*)malloc((st1 + 1) * sizeof(double));

    for (int i = 0; i <= st1; i++) res.kefs_ost[i] = kefs1[i];
    for (int i = res.st_z; i >= 0; i--)
    {
        if (fabs(res.kefs_ost[i + real_st2]) > 1e-10)
        {
            double coeff = res.kefs_ost[i + real_st2] / kefs2[real_st2];
            res.kefs_z[i] = coeff;

            for (int j = 0; j <= real_st2; j++)
                res.kefs_ost[i + j] -= coeff * kefs2[j];
        }
    }
    return res;
}
void run_calc()
{
    while (1)
    {
        int n, st1, st2;
        double* kefs1, * kefs2, * res;
        int a;
        cout << "Калькулятор многочленов." << endl;
        cout << "1 - сложение многочленов" << endl;
        cout << "2 - вычитание многочленов" << endl;
        cout << "3 - умножение многочлена на число" << endl;
        cout << "4 - вычисление производной от многочлена" << endl;
        cout << "5 - деление многочленов в столбик" << endl;
        cout << "другая - возврат в главное меню" << endl;
        cout << "Выберите режим калькулятора: "; cin >> n;
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
            cout << "2 многочлен:" << endl;
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
            cout << "2 многочлен:" << endl;
            Output_mnog(kefs2, st2);
            res = type2(st1, st2, kefs1, kefs2);
            cout << "Результат после вычитания: " << endl;
            Output_mnog(res, max(st1, st2));
        }; break;
        case 3:
        {
            st1 = Input_n();
            kefs1 = Input_mnog(st1);
            cout << "Ваш многочлен:" << endl;
            Output_mnog(kefs1, st1);
            a = Input_a();
            kefs2 = type3(st1, kefs1, a);
            cout << "Результат после умножения многочлена на число: " << endl;
            Output_mnog(kefs2, st1);
        }; break;
        case 4:
        {
            st1 = Input_n();
            kefs1 = Input_mnog(st1);
            cout << "Ваш многочлен:" << endl;
            Output_mnog(kefs1, st1);
            kefs2 = type4(st1, kefs1);
            cout << "Производная многочлена: " << endl;
            Output_mnog(kefs2, st1);
        }; break;
        case 5:
        {
            st1 = Input_n();
            kefs1 = Input_mnog(st1);
            cout << "1 многочлен:" << endl;
            Output_mnog(kefs1, st1);
            st2 = Input_n();
            kefs2 = Input_mnog(st2);
            cout << "2 многочлен:" << endl;
            Output_mnog(kefs2, st2);
            Del_mnog Data = type5(kefs1, st1, kefs2, st2);
            cout << "Целая часть: ";
            Output_mnog(Data.kefs_z, Data.st_z);
            cout << "Остаток: ";
            Output_mnog(Data.kefs_ost, Data.st_ost);
        }; break;
        default: cout << "Возврат в главное меню..." << endl; return; break;
        }
        cout << "\n----------------------------------------------------\n";
    }
}