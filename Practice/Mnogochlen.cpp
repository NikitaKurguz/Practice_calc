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
        if (i != 0) cout << "Коэффициент при x^" << i << ": ";
        else cout << "Свободный коэффициент: "; 
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
    bool first_term = true; // Флаг для первого слагаемого

    for (int i = n; i >= 0; i--) {
        if (kefs[i] == 0) continue; // Пропускаем нулевые коэффициенты

        // Обработка знака
        if (!first_term) {
            cout << (kefs[i] > 0 ? " + " : " - ");
        }
        else if (kefs[i] < 0) {
            cout << "-";
        }

        // Вывод коэффициента (если он не 1 или -1, или это свободный член)
        double abs_coef = abs(kefs[i]);
        if (abs_coef != 1 || i == 0) {
            cout << abs_coef;
        }

        // Вывод переменной x и степени
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
        st = Input_n();
        Input_mnog(st);
    }

    }
}