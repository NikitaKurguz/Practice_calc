#include "fraction.h"
#include <stdio.h>
#include <stdlib.h>

static int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
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
Fraction create_fraction(int num, int den) {
    if (den == 0) {
        den = 1;
    }

    int common_divisor = gcd(abs(num), abs(den));
    Fraction f;
    f.numerator = num / common_divisor;
    f.denominator = den / common_divisor;

    if (f.denominator < 0) {
        f.numerator = -f.numerator;
        f.denominator = -f.denominator;
    }

    return f;
}

Fraction add_fractions(Fraction a, Fraction b) {
    Fraction result;
    result.numerator = a.numerator * b.denominator + b.numerator * a.denominator;
    result.denominator = a.denominator * b.denominator;
    return create_fraction(result.numerator, result.denominator);
}

Fraction subtract_fractions(Fraction a, Fraction b) {
    Fraction result;
    result.numerator = a.numerator * b.denominator - b.numerator * a.denominator;
    result.denominator = a.denominator * b.denominator;
    return create_fraction(result.numerator, result.denominator);
}

Fraction multiply_fractions(Fraction a, Fraction b) {
    Fraction result;
    result.numerator = a.numerator * b.numerator;
    result.denominator = a.denominator * b.denominator;
    return create_fraction(result.numerator, result.denominator);
}

Fraction divide_fractions(Fraction a, Fraction b) {
    Fraction result;
    result.numerator = a.numerator * b.denominator;
    result.denominator = a.denominator * b.numerator;
    return create_fraction(result.numerator, result.denominator);
}

int compare_fractions(Fraction a, Fraction b) {
    int left = a.numerator * b.denominator;
    int right = b.numerator * a.denominator;

    if (left < right) {
        return -1;
    }
    if (left > right) {
        return 1;
    }
    return 0;
}


double fraction_to_decimal(Fraction f) {
    return (double)f.numerator / f.denominator;
}

void print_fraction(Fraction f) {
    printf("%d/%d", f.numerator, f.denominator);
}

int input_fraction(Fraction* f) {
    int num, den;
    printf("Введите дробь (числитель знаменатель): ");
    if (scanf_s("%d %d", &num, &den) != 2 || den == 0) {
        printf("Ошибка ввода! Знаменатель не может быть нулем.\n");
        while (getchar() != '\n');
        return 0;
    }
    *f = create_fraction(num, den);
    return 1;
}

void fraction_calculator_run() {
    int choice;

    do {
        printf("\n=== Калькулятор дробей ===\n");
        printf("1. Сложение дробей\n");
        printf("2. Вычитание дробей\n");
        printf("3. Умножение\n");
        printf("4. Деление\n");
        printf("5. Сравнение\n");
        printf("6. Десятичное представление\n");
        printf("0. Выход\n");
        printf("Выберите операцию: ");

        if (scanf_s("%d", &choice) != 1) {
            printf("Неверный ввод! Попробуйте снова.\n");
            while (getchar() != '\n');
            continue;
        }

        Fraction a, b, result;
        int cmp;
        double decimal;

        switch (choice) {
        case 1:
            if (input_fraction(&a) && input_fraction(&b)) {
                result = add_fractions(a, b);
                printf("Результат: ");
                print_fraction(a); printf(" + "); print_fraction(b);
                printf(" = "); print_fraction(result);
                printf(" (примерно %.3f)\n", fraction_to_decimal(result));
            }
            break;

        case 2:
            if (input_fraction(&a) && input_fraction(&b)) {
                result = subtract_fractions(a, b);
                printf("Результат: ");
                print_fraction(a); printf(" - "); print_fraction(b);
                printf(" = "); print_fraction(result);
                printf(" (примерно %.3f)\n", fraction_to_decimal(result));
            }
            break;

        case 3:
            if (input_fraction(&a) && input_fraction(&b)) {
                result = multiply_fractions(a, b);
                printf("Результат: ");
                print_fraction(a); printf(" * "); print_fraction(b);
                printf(" = "); print_fraction(result);
                printf(" (примерно %.3f)\n", fraction_to_decimal(result));
            }
            break;

        case 4:
            if (input_fraction(&a) && input_fraction(&b)) {
                if (b.numerator == 0) {
                    printf("Ошибка: деление на ноль!\n");
                    break;
                }
                result = divide_fractions(a, b);
                printf("Результат: ");
                print_fraction(a); printf(" / "); print_fraction(b);
                printf(" = "); print_fraction(result);
                printf(" (примерно %.3f)\n", fraction_to_decimal(result));
            }
            break;

        case 5:
            if (input_fraction(&a) && input_fraction(&b)) {
                cmp = compare_fractions(a, b);
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
                print_fraction(b); printf("\n");
            }
            break;

        case 6:
            if (input_fraction(&a)) {
                decimal = fraction_to_decimal(a);
                printf("Десятичная форма: %.3f\n", decimal);
            }
            break;

        case 0:
            break;

        default:
            printf("Неверный выбор! Попробуйте снова.\n");
        }

    } while (choice != 0);
}