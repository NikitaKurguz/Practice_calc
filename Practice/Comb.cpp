#include <iostream>
#include <limits>
#include "Combs.h"
#include <cmath>
using namespace std;

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
void input_n(int& n) 
{
    while (1) 
    {
        cout << "n = ";
        if (cin >> n) 
        {
            if (n > 0) break;
            else cout << "Ошибка: n должно быть больше 0." << endl;
        }
        else 
        {
            cout << "Ошибка ввода! Пожалуйста, введите число." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

void input_k(int& k) 
{
    while (true) 
    {
        cout << "k = ";
        if (cin >> k) 
        {
            if (k > 0) break;
            else cout << "Ошибка: k должно быть больше 0." << endl;
        }
        else 
        {
            cout << "Ошибка ввода! Пожалуйста, введите число." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}
void Menu()
{
    cout << "-------------------------------------" << endl;
    cout << "Калькулятор формул комбинаторики" << endl;
    cout << "1 - Размещение с повторением: n^k" << endl;
    cout << "2 - Размещение без повторений: n! / (n-k)!" << endl;
    cout << "3 - Сочетание с повторением: (n+k-1)! / (k! * (n-1)!)" << endl;
    cout << "4 - Сочетание без повторений: n! / (k! * (n-k)!)" << endl;
    cout << "5 - Перестановки: n!" << endl;
    cout << "Любая другая клавиша - вернуться в главное меню" << endl;
    cout << "Выберите пункт меню: ";
}
void menu_comb()
{
    int m;
    do
    {
        Menu();
        while (true) {
            cin >> m;
            if (cin.fail()) {
                cin.clear(); 
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                return; 
            }
            else {
                break; 
            }
        }

        int n, k;
        switch (m)
        {
        case 1:
            cout << "Формула: n^k" << endl;
            input_n(n);
            input_k(k);
            cout << "Размещение " << k << " элементов по " << n << " с повторениями: " << t1(n, k) << endl;
            break;

        case 2:
            cout << "Формула: n! / (n-k)!" << endl;
            input_n(n);
            while (true)
            {
                input_k(k);
                if (n < k)
                    cout << "Ошибка: n должно быть больше или равно k." << endl;
                else break;
            }
            cout << "Размещение " << k << " элементов по " << n << " без повторений: " << t2(n, k) << endl;
            break;

        case 3:
            cout << "Формула: (n+k-1)! / (k! * (n-1)!)" << endl;
            input_n(n);
            input_k(k);
            cout << "Сочетание " << k << " элементов из " << n << " с повторениями: " << t3(n, k) << endl;
            break;

        case 4:
            cout << "Формула: n! / (k! * (n-k)!)" << endl;
            input_n(n);
            while (true)
            {
                input_k(k);
                if (n < k)
                    cout << "Ошибка: n должно быть больше или равно k." << endl;
                else break;
            }
            cout << "Сочетание " << k << " элементов из " << n << " без повторений: " << t4(n, k) << endl;
            break;

        case 5:
            cout << "Формула: n!" << endl;
            input_n(n);
            cout << "Перестановки из " << n << " элементов: " << t5(n) << endl;
            break;

        default:
            cout << "Возврат в главное меню." << endl;
            return;
        }
        cout << endl;
    } while (1);
}