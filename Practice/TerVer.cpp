#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "TerVer.h"
#include <stdlib.h>
int proverkaVvoda_() {
    int chislo2;
    while (scanf("%d", &chislo2) != 1) {
        while (getchar() != '\n');
        printf("�� ����� �� �����, ��������� �������: ");
    }
    return chislo2;
}
double proverkaVvoda1_() {
    double chislo2;
    char c;
    while (scanf("%lf%c", &chislo2, &c) != 2 || c != '\n') {
        while (getchar() != '\n');
        printf("�� ����� �� �����, ��������� �������: ");
    }
    return chislo2;
}
void mNaN(double m, double n) {
    double res;
    res = m / n;
    printf("��������� = %.3lf\n", res);
}
void matOjidaniye() {
    int i, n;
    double* p, * x, res = 0.0, sum = 0.0;
    printf("������� n\n");
    do {
        n = proverkaVvoda_();
        if (n <= 0) {
            printf("n ������ ���� > 0\n");
        }
    } while (n <= 0);
    x = (double*)malloc(n * sizeof(double));
    p = (double*)malloc(n * sizeof(double));
    for (i = 0; i < n; i++) {
        printf("������� x[%d]\n", i);
        x[i] = proverkaVvoda1_();
        do {
            printf("������� p[%d]\n", i);
            p[i] = proverkaVvoda1_();
            if (p[i] < 0 || p[i]>1) {
                printf("����������� ��������� 1 ��� �� ������ 0.��������� ����\n");
            }
        } while (p[i] > 1 || p[i] < 0);
        res = res + p[i];
    }
    if (res < 0.999999 || res>1.00001) {
        printf("����������� ������ ���� = 1\n");
        return;
    }
    for (i = 0; i < n; i++) {
        sum = sum + (x[i] * p[i]);
    }
    printf("�������������� �������� = %.2lf", sum);
    free(x);
    free(p);
}
void dispersiya() {
    int i, n;
    double* p, * x, res = 0.0, sum = 0.0, DISP = 0.0;
    printf("������� n\n");
    do {
        n = proverkaVvoda_();
        if (n <= 0) {
            printf("n ������ ���� > 0\n");
        }
    } while (n <= 0);
    x = (double*)malloc(n * sizeof(double));
    p = (double*)malloc(n * sizeof(double));
    for (i = 0; i < n; i++) {
        printf("������� x[%d]\n", i);
        x[i] = proverkaVvoda1_();
        do {
            printf("������� p[%d]\n", i);
            p[i] = proverkaVvoda1_();
            if (p[i] < 0 || p[i]>1) {
                printf("����������� ��������� 1.��������� ����\n");
            }
        } while (p[i] > 1 || p[i] < 0);
        res = res + p[i];
    }
    if (res < 0.999999 || res>1.00001) {
        printf("����������� ������ ���� = 1\n");
        return;
    }
    for (i = 0; i < n; i++) {
        sum = sum + (x[i] * p[i]);
    }
    for (i = 0; i < n; i++) {
        DISP = DISP + ((x[i] - sum) * (x[i] - sum)) * p[i];
    }
    printf("��������� = %.3lf", DISP);
    free(p);
    free(x);
}
void menu_terver() {
    double m, n;
    int o;
    do {
        printf("���� ������ ��� ������ �����������\n");
        printf("1.����������� m/n\n");
        printf("2.���.��������\n");
        printf("3.���������\n");
        printf("0.�����\n");
        o = proverkaVvoda_();
        switch (o) {
        case 1:
            do {
                printf("������� ����� ������������� �������(m)\n");
                m = proverkaVvoda1_();
                if (m < 0 || m == 0) {
                    printf("������ ������� �����������: m �� ����� ���� ������ 1,m �� ����� ���� = 0\n");
                }
            } while (m < 0 || m == 0);
            do {
                printf("������� ����� ���� �������(n)\n");
                n = proverkaVvoda1_();
                if (n == 0 || m > n || n < 0 || m < 0) {
                    printf("������ ������� �����������:n �� ����� ���� ������ m � n �� ����� ���� ������ 1\n");
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
            printf("��������� ���������\n");
            break;
        }
    } while (o != 0);
}

