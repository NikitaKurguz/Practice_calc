#define _CRT_SECURE_NO_WARNINGS
#define SDL_MAIN_HANDLED
#include <stdio.h>
#include <locale.h>
#include <iostream>
#include "MatrCalc.h" 
#include "TerVer.h" 
#include "Combs.h"      
#include "mnogochleni.h" 
#include "Func.h"
#include "fraction.h"
using namespace std;
int main() 
{
    setlocale(LC_ALL, "Russian");
    int choice;
    int running = 1;
    while (running) 
    {
        display_main_menu();
        if (!(cin >> choice))
        {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) 
        {
        case 1:
            fraction_calculator_run(); // Калькулятор дробей   
            break;
        case 2:
            menu_matr(); // Матричный калькулятор
            break;
        case 3:
            menu_terver(); // Теория вероятностей
            break;
        case 4:
            menu_comb(); // Комбинаторика 
            break;
        case 5:
            run_calc(); // Многочлены
            break;
        case 6:
            menu_function();
            break;
        case 0:
            running = 0;
            break;
        default:
            cout << "Error!" << endl;;
        }
    }

    return 0;
}
