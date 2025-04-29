#define _CRT_SECURE_NO_WARNINGS
#define SDL_MAIN_HANDLED
#include <stdio.h>
#include <locale.h>   
#include "MatrCalc.h" 
#include "TerVer.h" 
#include "Combs.h"      
#include "mnogochleni.h" 
#include "Func.h"
#include "fraction.h"
#include <iostream>
using namespace std;
int main() 
{
    setlocale(LC_ALL, "");
    int choice;
    int running = 1;

    while (running) {
        display_main_menu();

        if (scanf_s("%d", &choice) != 1) {
            printf("Ошибка ввода! Пожалуйста, введите число.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
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
            printf("Программа завершена.\n");
            break;
        default:
            printf("Неверный выбор! Пожалуйста, выберите существующий вариант.\n");
        }
    }

    return 0;
}
