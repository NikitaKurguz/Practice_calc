#include <stdio.h>
#include <locale.h>
//#include "kal1.h" // Калькулятор дробей     
#include "MatrCalc.h" // Матричный калькулятор
#include "TerVer.h" // Теория вероятностей
#include "Combs.h" // Комбинаторика     
#include "mnogochleni.h" // Многочлены
//#include "kal6.h" // Работа с функциями

int main() {
    setlocale(LC_ALL, "");
    int choice;
    int running = 1;

    while (running) {
        //display_main_menu();

        if (scanf_s("%d", &choice) != 1) {
            printf("Ошибка ввода! Пожалуйста, введите число.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
        case 1:
            //kal1_run(); // Калькулятор дробей   
            break;
        case 2:
            menu(); // Матричный калькулятор
            break;
        case 3:
            //menu_terver(); // Теория вероятностей
            break;
        case 4:
            menu_comb(); // Комбинаторика 
            break;
        case 5:
            run_calc(); // Многочлены
            break;
        case 6:
            //kal6_run(); // Работа с функциями
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