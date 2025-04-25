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
    cout << "=== ����������� ������ ������������� ===" << endl;
    cout << "1. ���������� � �����������" << endl;
    cout << "2. ���������� ��� ����������" << endl;
    cout << "3. ��������� � �����������" << endl;
    cout << "4. ��������� ��� ����������" << endl;
    cout << "5. ������������" << endl;
    cout << "0. �����" << endl;
    cout << "�������� ����� ����: ";
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
            cout << "������� n � k: ";
            cin >> n >> k;
            cout << "���������: " << placementWithRepetition(n, k) << endl;
            break;
        case 2:
            cout << "������� n � k: ";
            cin >> n >> k;
            cout << "���������: " << placementWithoutRepetition(n, k) << endl;
            break;
        case 3:
            cout << "������� n � k: ";
            cin >> n >> k;
            cout << "���������: " << combinationWithRepetition(n, k) << endl;
            break;
        case 4:
            cout << "������� n � k: ";
            cin >> n >> k;
            cout << "���������: " << combinationWithoutRepetition(n, k) << endl;
            break;
        case 5:
            cout << "������� n: ";
            cin >> n;
            cout << "���������: " << permutation(n) << endl;
            break;
        case 0:
            cout << "����� �� ���������." << endl;
            break;
        default:
            cout << "�������� �����. ��������� �������." << endl;
        }
        cout << endl;
    } while (choice != 0);

    return 0;
}

