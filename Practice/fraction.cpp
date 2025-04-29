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
    printf("\n=== ������� ���� ===\n");
    printf("1. ����������� ������������ ������\n");
    printf("2. ��������� �����������\n");
    printf("3. ������ ������������ � ���.����������\n");
    printf("4. ����������� �������������\n");
    printf("5. ����������� �����������\n");
    printf("6. ������ � ���������\n");
    printf("0. �����\n");
    printf("�������� �����: ");
}

int input_fraction(Fraction* f) {
    int num, den;
    printf("������� ����� � ������� ��������� �����������: ");
    if (scanf("%d %d", &num, &den) != 2 || den == 0) {
        printf("������: ������������ ����!\n");
        while (getchar() != '\n');
        return 0;
    }
    *f = create_fraction(num, den);
    return 1;
}

void fraction_calculator_run() {
    int running = 1;
    while (running) {
        printf("\n=== ����������� ������ ===\n");
        printf("1. ��������\n");
        printf("2. ���������\n");
        printf("3. ���������\n");
        printf("4. �������\n");
        printf("5. ���������\n");
        printf("6. ���������� �����\n");
        printf("7. ���������� �������������\n");
        printf("0. ����� � ������� ����\n");
        printf("�������� ��������: ");

        int choice;
        if (scanf("%d", &choice) != 1) {
            printf("������: ������� �����!\n");
            while (getchar() != '\n');
            continue;
        }

        Fraction a, b;
        switch (choice) {
        case 1:  // ��������
            if (input_fraction(&a) && input_fraction(&b)) {
                Fraction res = add_fractions(a, b);
                printf("���������: ");
                print_fraction(res);
                printf(" (? %.3f)\n", to_decimal(res));
            }
            break;
        case 2:  // ���������
            if (input_fraction(&a) && input_fraction(&b)) {
                Fraction res = subtract_fractions(a, b);
                printf("���������: ");
                print_fraction(res);
                printf(" (? %.3f)\n", to_decimal(res));
            }
            break;
        case 3:  // ���������
            if (input_fraction(&a) && input_fraction(&b)) {
                Fraction res = multiply_fractions(a, b);
                printf("���������: ");
                print_fraction(res);
                printf(" (? %.3f)\n", to_decimal(res));
            }
            break;
        case 4:  // �������
            if (input_fraction(&a) && input_fraction(&b)) {
                if (b.numerator == 0) {
                    printf("������: ������� �� ����!\n");
                    break;
                }
                Fraction res = divide_fractions(a, b);
                printf("���������: ");
                print_fraction(res);
                printf(" (? %.3f)\n", to_decimal(res));
            }
            break;
        case 5:  // ���������
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
        case 6:  // ����������
            if (input_fraction(&a)) {
                Fraction res = simplify_fraction(a);
                printf("����������� �����: ");
                print_fraction(res);
                printf("\n");
            }
            break;
        case 7:  // ���������� �������������
            if (input_fraction(&a)) {
                printf("���������� �����: %.3f\n", to_decimal(a));
            }
            break;
        case 0:
            running = 0;
            break;
        default:
            printf("�������� �����!\n");
        }
    }
}