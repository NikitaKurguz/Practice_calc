#include <iostream>
#include <limits> 
#include "Combs.h"
#include <cmath>
using namespace std;
void input_n(int n)
{
    while (1)
    {
        cout << "n = "; cin >> n;
        if (n > 0) { cout << "n > 0"; break; }
    }
}
void input_k(int k)
{
    while (1)
    {
        cout << "k = "; cin >> k;
        if (k > 0) { cout << "k > 0"; break; }
    }
}
unsigned long long fact(int n)
{
    if (n == 0 || n == 1) return 1;
    unsigned long long fact = 1;
    for (int i = 2; i <= n; i++) fact *= i;
    return fact;
}

unsigned long long t1(int n, int k) 
{ 
    return pow(n, k); 
}
unsigned long long t2(int n, int k) 
{ 
    return fact(n) / fact(n - k); 
}
unsigned long long t3(int n, int k) 
{ 
    return fact(n + k - 1) / (fact(k) * fact(n - 1)); 
}
unsigned long long t4(int n, int k) 
{ 
    return fact(n) / (fact(k) * fact(n - k)); 
}
unsigned long long t5(int n) 
{ 
    return fact(n); 
}

void Menu()
{
    cout << "Калькулятор формул комбинаторики" << endl;
    cout << "1 - Размещение с повторением: n^k" << endl;
    cout << "2 - Размещение без повторений: n! / (n-k)!" << endl;
    cout << "3 - Сочетание с повторением: (n+k-1)! / (k! * (n-1)!)" << endl;
    cout << "4 - Сочетание без повторений: n! / (k! * (n-k)!)" << endl;
    cout << "5 - Перестановки: n!" << endl;
    cout << "0 - Вернуться в главное меню" << endl;
    cout << "Выберите пункт меню: ";
}

bool safeInput(int& value) {
    cin >> value;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }
    return true;
}
int menu_comb()
{
    int m;
    do
    {
        Menu();
        if (!safeInput(m)) {
            cout << "Ошибка ввода. Возврат в главное меню." << endl;
            return 0;
        }

        int n, k;
        switch (m)
        {
        case 1:
            cout << "Формула: n^k" << endl;
            cout << "Введите n = ";
            if (!safeInput(n)) return 0;
            cout << "Введите k = ";
            if (!safeInput(k)) return 0;
            cout << "Результат: " << t1(n, k) << endl;
            break;
        case 2:
            cout << "Формула: n! / (n-k)!" << endl;
            cout << "Введите n = ";
            if (!safeInput(n)) return 0;
            cout << "Введите k = ";
            if (!safeInput(k)) return 0;
            cout << "Результат: " << t2(n, k) << endl;
            break;
        case 3:
            cout << "Формула: (n+k-1)! / (k! * (n-1)!)" << endl;
            cout << "Введите n = ";
            if (!safeInput(n)) return 0;
            cout << "Введите k = ";
            if (!safeInput(k)) return 0;
            cout << "Результат: " << t3(n, k) << endl;
            break;
        case 4:
            cout << "Формула: n! / (k! * (n-k)!)" << endl;
            cout << "Введите n = ";
            if (!safeInput(n)) return 0;
            cout << "Введите k = ";
            if (!safeInput(k)) return 0;
            cout << "Результат: " << t4(n, k) << endl;
            break;
        case 5:
            cout << "Формула: n!" << endl;
            cout << "Введите n = ";
            if (!safeInput(n)) return 0;
            cout << "Результат: " << t5(n) << endl;
            break;
        default:
            cout << "Неверный выбор. Возврат в главное меню." << endl;
            return 0;
        }
        cout << endl;
    } while (1);
}
