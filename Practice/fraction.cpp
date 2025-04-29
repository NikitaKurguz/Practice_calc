#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "fraction.h"


static int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    else {
        return gcd(b, a % b);
    }
}

Fraction create_fraction(int num, int den) {
    if (den == 0) den = 1;
    Fraction f = { num, den };
    return simplify_fraction(f);
}

void display_main_menu() {
    printf("\n=== ГЛАВНОЕ МЕНЮ ===\n");
    printf("1. Калькулятор обыкновенных дробей\n");
    printf("2. Матричный калькулятор\n");
    printf("3. Теория вероятностей и мат.статистика\n");
    printf("4. Калькулятор комбинаторики\n");
    printf("5. Калькулятор многочленов\n");
    printf("6. Работа с функциями\n");
    printf("0. Выход\n");
    printf("Выберите опцию: ");
}

int input_fraction(Fraction* f) {
    int num, den;
    printf("Введите дробь в формате числитель знаменатель: ");
    if (scanf("%d %d", &num, &den) != 2 || den == 0) {
        printf("Ошибка: некорректный ввод!\n");
        while (getchar() != '\n');
        return 0;
    }
    *f = create_fraction(num, den);
    return 1;
}

void fraction_calculator_run() {
    int running = 1;
    while (running) {
        printf("\n=== Калькулятор дробей ===\n");
        printf("1. Сложение\n");
        printf("2. Вычитание\n");
        printf("3. Умножение\n");
        printf("4. Деление\n");
        printf("5. Сравнение\n");
        printf("6. Сокращение дроби\n");
        printf("7. Десятичное представление\n");
        printf("0. Назад в главное меню\n");
        printf("Выберите операцию: ");

        int choice;
        if (scanf("%d", &choice) != 1) {
            printf("Ошибка: введите число!\n");
            while (getchar() != '\n');
            continue;
        }

        Fraction a, b;
        switch (choice) {
        case 1:  // Сложение
            if (input_fraction(&a) && input_fraction(&b)) {
                Fraction res = add_fractions(a, b);
                printf("Результат: ");
                print_fraction(res);
                printf(" (? %.3f)\n", to_decimal(res));
            }
            break;
        case 2:  // Вычитание
            if (input_fraction(&a) && input_fraction(&b)) {
                Fraction res = subtract_fractions(a, b);
                printf("Результат: ");
                print_fraction(res);
                printf(" (? %.3f)\n", to_decimal(res));
            }
            break;
        case 3:  // Умножение
            if (input_fraction(&a) && input_fraction(&b)) {
                Fraction res = multiply_fractions(a, b);
                printf("Результат: ");
                print_fraction(res);
                printf(" (? %.3f)\n", to_decimal(res));
            }
            break;
        case 4:  // Деление
            if (input_fraction(&a) && input_fraction(&b)) {
                if (b.numerator == 0) {
                    printf("Ошибка: деление на ноль!\n");
                    break;
                }
                Fraction res = divide_fractions(a, b);
                printf("Результат: ");
                print_fraction(res);
                printf(" (? %.3f)\n", to_decimal(res));
            }
            break;
        case 5:  // Сравнение
            if (input_fraction(&a) && input_fraction(&b)) {
                int cmp = compare_fractions(a, b);
                print_fraction(a);
                if (cmp < 0) {
                    printf(" < ");
                }
                else if (cmp > 0) {
                    printf(" > ");
                }
                else {
                    printf(" == ");
                }
                print_fraction(b);
                printf("\n");
            }
            break;
        case 6:  // Сокращение
            if (input_fraction(&a)) {
                Fraction res = simplify_fraction(a);
                printf("Сокращённая дробь: ");
                print_fraction(res);
                printf("\n");
            }
            break;
        case 7:  // Десятичное представление
            if (input_fraction(&a)) {
                printf("Десятичная форма: %.3f\n", to_decimal(a));
            }
            break;
        case 0:
            running = 0;
            break;
        default:
            printf("Неверный выбор!\n");
        }
    }
}