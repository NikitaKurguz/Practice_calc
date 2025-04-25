#include <iostream>
#include "Comb.h"
using namespace std;
#include <cmath>

unsigned long long factorial(int n) {
    if (n == 0 || n == 1) return 1;
    unsigned long long fact = 1;
    for (int i = 2; i <= n; ++i) {
        fact *= i;
    }
    return fact;
}

unsigned long long placementWithRepetition(int n, int k) {
    return pow(n, k);
}

unsigned long long placementWithoutRepetition(int n, int k) {
    return factorial(n) / factorial(n - k);
}

unsigned long long combinationWithRepetition(int n, int k) {
    return factorial(n + k - 1) / (factorial(k) * factorial(n - 1));
}

unsigned long long combinationWithoutRepetition(int n, int k) {
    return factorial(n) / (factorial(k) * factorial(n - k));
}

unsigned long long permutation(int n) {
    return factorial(n);
}

void showMenu() 
{
    cout << "=== Калькулятор формул комбинаторики ===" << endl;
    cout << "1. Размещение с повторением" << endl;
    cout << "2. Размещение без повторений" << endl;
    cout << "3. Сочетание с повторением" << endl;
    cout << "4. Сочетание без повторений" << endl;
    cout << "5. Перестановки" << endl;
    cout << "0. Выход" << endl;
    cout << "Выберите пункт меню: ";
}

int menu_comb() 
{
    int choice;
    do {
        showMenu();
        cin >> choice;

        int n, k;
        switch (choice) {
        case 1:
            cout << "Введите n и k: ";
            cin >> n >> k;
            cout << "Результат: " << placementWithRepetition(n, k) << endl;
            break;
        case 2:
            cout << "Введите n и k: ";
            cin >> n >> k;
            cout << "Результат: " << placementWithoutRepetition(n, k) << endl;
            break;
        case 3:
            cout << "Введите n и k: ";
            cin >> n >> k;
            cout << "Результат: " << combinationWithRepetition(n, k) << endl;
            break;
        case 4:
            cout << "Введите n и k: ";
            cin >> n >> k;
            cout << "Результат: " << combinationWithoutRepetition(n, k) << endl;
            break;
        case 5:
            cout << "Введите n: ";
            cin >> n;
            cout << "Результат: " << permutation(n) << endl;
            break;
        case 0:
            cout << "Выход из программы." << endl;
            break;
        default:
            cout << "Неверный выбор. Повторите попытку." << endl;
        }
        cout << endl;
    } while (choice != 0);

    return 0;
}

