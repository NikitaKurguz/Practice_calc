#include <iostream>
#include "mnogochleni.h"
using namespace std;
void run_calc()
{
	int n;
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
}