#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "TerVer.h"
#include <stdlib.h>
int proverkaVvoda_() {
    int chislo2;
    while (scanf("%d", &chislo2) != 1) {
        while (getchar() != '\n');
        printf("вы ввели не число, повторите попытку: ");
    }
    return chislo2;
}
double proverkaVvoda1_() {
    double chislo2;
    char c;
    while (scanf("%lf%c", &chislo2, &c) != 2 || c != '\n') {
        while (getchar() != '\n');
        printf("вы ввели не число, повторите попытку: ");
    }
    return chislo2;
}
void mNaN(double m, double n) {
    double res;
    res = m / n;
    printf("результат = %.3lf\n", res);
}
void matOjidaniye() {
    int i, n;
    double* p, * x, res = 0.0, sum = 0.0;
    printf("введите n\n");
    do {
        n = proverkaVvoda_();
        if (n <= 0) {
            printf("n должно быть > 0\n");
        }
    } while (n <= 0);
    x = (double*)malloc(n * sizeof(double));
    p = (double*)malloc(n * sizeof(double));
    for (i = 0; i < n; i++) {
        printf("введите x[%d]\n", i);
        x[i] = proverkaVvoda1_();
        do {
            printf("введите p[%d]\n", i);
            p[i] = proverkaVvoda1_();
            if (p[i] < 0 || p[i]>1) {
                printf("вероятность превышает 1 или же меньше 0.повторите ввод\n");
            }
        } while (p[i] > 1 || p[i] < 0);
        res = res + p[i];
    }
    if (res < 0.999999 || res>1.00001) {
        printf("вероятность должна быть = 1\n");
        return;
    }
    for (i = 0; i < n; i++) {
        sum = sum + (x[i] * p[i]);
    }
    printf("математическое ожидание = %.2lf", sum);
    free(x);
    free(p);
}
void dispersiya() {
    int i, n;
    double* p, * x, res = 0.0, sum = 0.0, DISP = 0.0;
    printf("введите n\n");
    do {
        n = proverkaVvoda_();
        if (n <= 0) {
            printf("n должно быть > 0\n");
        }
    } while (n <= 0);
    x = (double*)malloc(n * sizeof(double));
    p = (double*)malloc(n * sizeof(double));
    for (i = 0; i < n; i++) {
        printf("введите x[%d]\n", i);
        x[i] = proverkaVvoda1_();
        do {
            printf("введите p[%d]\n", i);
            p[i] = proverkaVvoda1_();
            if (p[i] < 0 || p[i]>1) {
                printf("вероятность превышает 1.повторите ввод\n");
            }
        } while (p[i] > 1 || p[i] < 0);
        res = res + p[i];
    }
    if (res < 0.999999 || res>1.00001) {
        printf("вероятность должна быть = 1\n");
        return;
    }
    for (i = 0; i < n; i++) {
        sum = sum + (x[i] * p[i]);
    }
    for (i = 0; i < n; i++) {
        DISP = DISP + ((x[i] - sum) * (x[i] - sum)) * p[i];
    }
    printf("дисперсия = %.3lf", DISP);
    free(p);
    free(x);
}
void menu_terver() {
    double m, n;
    int o;
    do {
        printf("меню выбора для теории вероятности\n");
        printf("1.вероятность m/n\n");
        printf("2.мат.ожидание\n");
        printf("3.дисперсия\n");
        printf("0.выход\n");
        o = proverkaVvoda_();
        switch (o) {
        case 1:
            do {
                printf("введите число благоприятных исходов(m)\n");
                m = proverkaVvoda1_();
                if (m < 0 || m == 0) {
                    printf("данные введены некорректно: m не может быть меньше 1,m не может быть = 0\n");
                }
            } while (m < 0 || m == 0);
            do {
                printf("введите число всех исходов(n)\n");
                n = proverkaVvoda1_();
                if (n == 0 || m > n || n < 0 || m < 0) {
                    printf("данные введены некорректно:n не может быть меньше m и n не может быть меньше 1\n");
                }
            } while (n == 0 || m > n || n < 0 || m < 0);
            mNaN(m, n);
            break;
        case 2:
            matOjidaniye();
            break;
        case 3:
            dispersiya();
            break;
        case 0:
            printf("программа завершена\n");
            break;
        }
    } while (o != 0);
}

