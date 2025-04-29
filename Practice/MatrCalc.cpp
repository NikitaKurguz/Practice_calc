#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
double** dynMatr(int stroki, int stolbci) {
    int i;
    double** matr = (double**)malloc(stroki * sizeof(double*));
    for (i = 0; i < stroki; i++) {
        matr[i] = (double*)malloc(stolbci * sizeof(double));
    }
    return matr;
}
void freeMatr(double** matr, int stroki) {
    int i;
    for (i = 0; i < stroki; i++) {
        free(matr[i]);
    }
    free(matr);
}
int proverkaVvoda() {
    int chislo2;
    while (scanf("%d", &chislo2) != 1) {
        while (getchar() != '\n');
        printf("вы ввели не число, повторите попытку: ");
    }
    return chislo2;
}
double proverkaVvoda1() {
    double chislo2;
    while (scanf("%lf", &chislo2) != 1) {
        while (getchar() != '\n');
        printf("вы ввели не число, повторите попытку: ");
    }
    return chislo2;
}
double** vvodElementov(int stroki, int stolbci) {
    int i, j;
    double** matr = dynMatr(stroki, stolbci);
    for (i = 0; i < stroki; i++) {
        for (j = 0; j < stolbci; j++) {
            printf("элемент [%d][%d]: ", i, j);
            matr[i][j] = proverkaVvoda1();
        }
    }
    return matr;
}
void vivodMatr(double** matr, int stroki, int stolbci) {
    int i, j;
    printf("матрица:\n");
    for (i = 0; i < stroki; i++) {
        for (j = 0; j < stolbci; j++) {
            printf("%.2lf ", matr[i][j]);
        }
        printf("\n");
    }
}
void slojenieMatr(double** matr1, double** matr2, int stolbci, int stroki, int stroki1, int stolbci1) {
    int i, j;

    printf("вследствие сложения матриц получим результат:\n");
    for (i = 0; i < stroki; i++) {
        for (j = 0; j < stolbci; j++) {
            printf("%.2lf ", matr1[i][j] + matr2[i][j]);
        }
        printf("\n");
    }
}
void vichitanieMatr(double** matr1, double** matr2, int stolbci, int stroki) {
    int i, j;
    printf("вследствие вычитания матриц получим результат:\n");
    for (i = 0; i < stroki; i++) {
        for (j = 0; j < stolbci; j++) {
            printf("%.2lf ", matr1[i][j] - matr2[i][j]);
        }
        printf("\n");
    }
}
void umnojenieMatr(double** matr1, double** matr2, int stroki1, int stolbci1, int stroki2, int stolbci2) {
    int i, j, s;
    double** resultatUmnojeniya = dynMatr(stroki1, stolbci2);
    for (i = 0; i < stroki1; i++) {
        for (j = 0; j < stolbci2; j++) {
            for (s = 0; s < stolbci1; s++) {
                resultatUmnojeniya[i][j] = resultatUmnojeniya[i][j] + (matr1[i][s] * matr2[s][j]);
            }
        }
    }
    vivodMatr(resultatUmnojeniya, stroki1, stolbci2);
    freeMatr(resultatUmnojeniya, stroki1);
}
void umnojenieMatrNaChislo(double** matr, int stroki, int stolbci) {
    double chislo;
    int i, j;
    printf("введите число, на которое необходимо умножить матрицу:\n");
    chislo = proverkaVvoda();
    double** resultatUmnojeniyaNaChislo = dynMatr(stroki, stolbci);
    for (i = 0; i < stroki; i++) {
        for (j = 0; j < stolbci; j++) {
            resultatUmnojeniyaNaChislo[i][j] = resultatUmnojeniyaNaChislo[i][j] + (matr[i][j] * chislo);
        }
    }
    vivodMatr(resultatUmnojeniyaNaChislo, stroki, stolbci);
    freeMatr(resultatUmnojeniyaNaChislo, stroki);
}
void slojenieMatrSChislom(double** matr, int stroki, int stolbci) {
    double chislo;
    int i, j;
    printf("введите число, которое необходимо прибаавить к матрице:\n");
    chislo = proverkaVvoda();
    double** resultatSlojeniyaSChislom = dynMatr(stroki, stolbci);
    for (i = 0; i < stroki; i++) {
        for (j = 0; j < stolbci; j++) {
            resultatSlojeniyaSChislom[i][j] = resultatSlojeniyaSChislom[i][j] + matr[i][j] + chislo;
        }
    }
    vivodMatr(resultatSlojeniyaSChislom, stroki, stolbci);
    freeMatr(resultatSlojeniyaSChislom, stroki);
}
void vichitanieMatrSChislom(double** matr, int stroki, int stolbci) {
    double chislo;
    int i, j;
    printf("введите число, на которое мы будем вычитать матрицу:\n");
    chislo = proverkaVvoda();
    double** resultatVichitaniyaSChislom = dynMatr(stroki, stolbci);
    for (i = 0; i < stroki; i++) {
        for (j = 0; j < stolbci; j++) {
            resultatVichitaniyaSChislom[i][j] = resultatVichitaniyaSChislom[i][j] + matr[i][j] - chislo;
        }
    }
    vivodMatr(resultatVichitaniyaSChislom, stroki, stolbci);
    freeMatr(resultatVichitaniyaSChislom, stroki);
}
void transponirovanieMatr(double** matr, int stroki, int stolbci) {
    int i, j;
    printf("вследствие транспонирования матрицы, получим следующий результат:\n");
    for (i = 0; i < stolbci; i++) {
        for (j = 0; j < stroki; j++) {
            printf("%.2lf ", matr[j][i]);
        }
        printf("\n");
    }
}
void opredelitelMatrOdinNaOdin(double** matr, int stroki, int stolbci) {
    printf("определитель матрицы 1х1 = %.1lf ", matr[0][0]);
}
void opredelitelMatrDvaNaDva(double** matr, int stroki, int stolbci) {
    double res;
    res = matr[0][0] * matr[1][1] - matr[0][1] * matr[1][0];
    printf("определитель матрицы 2х2 = %.1lf ", res);
}
void opredelitelMatrTriNaTri(double** matr, int stroki, int stolbci) {
    double res;
    res = (matr[0][0] * matr[1][1] * matr[2][2] + matr[0][1] * matr[1][2] * matr[2][0]) + (matr[0][2] * matr[1][0] * matr[2][1]) - (matr[0][2] * matr[1][1] * matr[2][0]) - (matr[0][0] * matr[1][2] * matr[2][1]) - (matr[0][1] * matr[1][0] * matr[2][2]);
    printf("определитель матрицы 3х3 = %.1lf ", res);
}
void opredelitelMatrChetireNaChetire(double** matr, int stroki, int stolbci) {
    double res;
    res = matr[0][0] * ((matr[1][1] * matr[2][2] * matr[3][3]) + (matr[2][1] * matr[3][2] * matr[1][3]) + (matr[1][2] * matr[2][3] * matr[3][1]) - (matr[1][3] * matr[2][2] * matr[3][1]) - (matr[3][2] * matr[2][3] * matr[1][1]) - (matr[2][1] * matr[1][2] * matr[3][3])) - matr[0][1] * ((matr[1][0] * matr[2][2] * matr[3][3]) + (matr[2][0] * matr[3][2] * matr[1][3]) + (matr[1][2] * matr[2][3] * matr[3][0]) - (matr[1][3] * matr[2][2] * matr[3][0]) - (matr[2][3] * matr[3][2] * matr[1][0]) - (matr[2][0] * matr[1][2] * matr[3][3])) + matr[0][2] * ((matr[1][0] * matr[2][1] * matr[3][3]) + (matr[1][1] * matr[2][3] * matr[3][0]) + (matr[2][0] * matr[3][1] * matr[1][3]) - (matr[1][3] * matr[2][1] * matr[3][0]) - (matr[3][1] * matr[2][3] * matr[1][0]) - (matr[2][0] * matr[1][1] * matr[3][3])) - matr[0][3] * ((matr[1][0] * matr[2][1] * matr[3][2]) + (matr[2][0] * matr[3][1] * matr[1][2]) + (matr[1][1] * matr[2][2] * matr[3][0]) - (matr[1][2] * matr[2][1] * matr[3][0]) - (matr[3][1] * matr[2][2] * matr[1][0]) - (matr[2][0] * matr[1][1] * matr[3][2]));
    printf("опредлдеитлеь 4х4 = %.1lf", res);
}
void obratnayaMatrDvaNaDva(double** matr, int stroki, int stolbci) {
    double res, algebraicheskieDopolneniya1[100][100];
    int i, j;

    do {
        res = matr[0][0] * matr[1][1] - matr[0][1] * matr[1][0];
        if (res == 0) {
            printf("определитель = 0 следовательно матрицы вырожденная и обраитной не существует\n");
            printf("ввод матрицы заново:\n");
            matr = vvodElementov(stroki, stolbci);
        }
    } while (res == 0);
    algebraicheskieDopolneniya1[0][0] = matr[1][1];
    algebraicheskieDopolneniya1[0][1] = -matr[1][0];
    algebraicheskieDopolneniya1[1][0] = -matr[0][1];
    algebraicheskieDopolneniya1[1][1] = matr[0][0];
    printf("обратная матрица:\n");
    for (i = 0; i < stolbci; i++) {
        for (j = 0; j < stroki; j++) {
            printf("%.2lf ", algebraicheskieDopolneniya1[j][i] / res);
        }
        printf("\n");
    }
}

void obratnayaMatrTriNaTri(double** matr, int stroki, int stolbci) {
    double res, algebraicheskieDopolneniya1[100][100];
    int i, j;
    do {
        res = (matr[0][0] * matr[1][1] * matr[2][2]) + (matr[0][1] * matr[1][2] * matr[2][0]) + (matr[0][2] * matr[1][0] * matr[2][1]) - (matr[0][2] * matr[1][1] * matr[2][0]) - (matr[0][0] * matr[1][2] * matr[2][1]) - (matr[0][1] * matr[1][0] * matr[2][2]);
        if (res == 0) {
            printf("определитель = 0 следовательно матрицы вырожденная и обратной не существует\n");
            printf("ввод матрицы заново:\n");
            matr = vvodElementov(stroki, stolbci);
        }
    } while (res == 0);
    algebraicheskieDopolneniya1[0][0] = (matr[1][1] * matr[2][2] - matr[1][2] * matr[2][1]);
    algebraicheskieDopolneniya1[0][1] = -(matr[1][0] * matr[2][2] - matr[1][2] * matr[2][0]);
    algebraicheskieDopolneniya1[0][2] = (matr[1][0] * matr[2][1] - matr[1][1] * matr[2][0]);
    algebraicheskieDopolneniya1[1][0] = -(matr[0][1] * matr[2][2] - matr[0][2] * matr[2][1]);
    algebraicheskieDopolneniya1[1][1] = (matr[0][0] * matr[2][2] - matr[0][2] * matr[2][0]);
    algebraicheskieDopolneniya1[1][2] = -(matr[0][0] * matr[2][1] - matr[0][1] * matr[2][0]);
    algebraicheskieDopolneniya1[2][0] = (matr[0][1] * matr[1][2] - matr[0][2] * matr[1][1]);
    algebraicheskieDopolneniya1[2][1] = -(matr[0][0] * matr[1][2] - matr[0][2] * matr[1][0]);
    algebraicheskieDopolneniya1[2][2] = (matr[0][0] * matr[1][1] - matr[0][1] * matr[1][0]);
    printf("обратная матрица:\n");
    for (i = 0; i < stolbci; i++) {
        for (j = 0; j < stroki; j++) {
            printf("%.2lf ", algebraicheskieDopolneniya1[j][i] / res);
        }
        printf("\n");
    }
}
void obratnayaMatrOdinNaOdin(double** matr, int stroki, int stolbci) {
    double res;
    do {
        res = matr[0][0];
        if (res == 0) {
            printf("определитель = 0 следовательно матрицы вырожденная и обратной не существует\n");
            printf("ввод матрицы заново:\n");
            matr = vvodElementov(stroki, stolbci);
        }
    } while (res == 0);
    printf("обратная матрица:\n");
    printf("%.2lf ", res);
}
void menu() {
    double** matr, ** matr1, ** matr2;
    int stroki, stolbci, stroki1, stolbci1, stroki2, stolbci2, n, n1, n2;
    do {
        printf("меню выбора действий над матрицей\n");
        printf("1.сложение двух матриц\n");
        printf("2.вычитание двух матриц\n");
        printf("3.умножение двух матриц\n");
        printf("4.умножение матриц на число\n");
        printf("5.прибавление числа к матрице\n");
        printf("6.вычитание числа из матрицы\n");
        printf("7.транспонирование матрицы\n");
        printf("8.определитель матриц\n");
        printf("9.обратные матрицы\n");
        printf("0.выход\n");
        n = proverkaVvoda();
        switch (n) {
        case 1:
            do {
                printf("введите кол во строк для первой матрицы:\n");
                do {
                    stroki = proverkaVvoda();
                    if (stroki <= 0) {
                        printf("во-первых,строки должны быть положительными, во-вторых больше 0\n");
                    }
                } while (stroki < 1);
                printf("введите кол во столбцов для первой матрицы:\n");
                do {
                    stolbci = proverkaVvoda();
                    if (stolbci <= 0) {
                        printf("во-первых,строки должны быть положительными, во-вторых больше 0\n");
                    }
                } while (stolbci < 1);
                printf("введите кол во строк для второй матрицы:\n");
                do {
                    stroki1 = proverkaVvoda();
                    if (stroki1 <= 0) {
                        printf("во-первых,строки должны быть положительными, во-вторых больше 0\n");
                    }
                } while (stroki1 < 1);
                printf("введите кол во столбцов для первой матрицы:\n");
                do {
                    stolbci1 = proverkaVvoda();
                    if (stolbci1 <= 0) {
                        printf("во-первых,строки должны быть положительными, во-вторых больше 0\n");
                    }
                } while (stolbci1 < 1);
                if (stroki1 != stroki || stolbci1 != stolbci) {
                    printf("размеры неправильные:\n");
                }
            } while (stroki1 != stroki || stolbci1 != stolbci);
            printf("введите элементы для 1ой матрицы:\n");
            matr1 = vvodElementov(stroki, stolbci);
            printf("введите элементы для 2ой матрицы:\n");
            matr2 = vvodElementov(stroki, stolbci);
            printf("результат сложения этих матриц:\n");
            slojenieMatr(matr1, matr2, stolbci, stroki, stroki1, stolbci1);
            freeMatr(matr1, stroki);
            freeMatr(matr2, stroki);
            break;
        case 2:
            do {
                printf("введите кол во строк для первой матрицы:\n");
                do {
                    stroki = proverkaVvoda();
                    if (stroki <= 0) {
                        printf("во-первых,строки должны быть положительными, во-вторых больше 0\n");
                    }
                } while (stroki < 1);
                printf("введите кол во столбцов для первой матрицы:\n");
                do {
                    stolbci = proverkaVvoda();
                    if (stolbci <= 0) {
                        printf("во-первых,строки должны быть положительными, во-вторых больше 0\n");
                    }
                } while (stolbci < 1);
                printf("введите кол во строк для второй матрицы:\n");
                do {
                    stroki1 = proverkaVvoda();
                    if (stroki1 <= 0) {
                        printf("во-первых,строки должны быть положительными, во-вторых больше 0\n");
                    }
                } while (stroki1 < 1);
                printf("введите кол во столбцов для первой матрицы:\n");
                do {
                    stolbci1 = proverkaVvoda();
                    if (stolbci1 <= 0) {
                        printf("во-первых,строки должны быть положительными, во-вторых больше 0\n");
                    }
                } while (stolbci1 < 1);
                if (stroki1 != stroki || stolbci1 != stolbci) {
                    printf("размеры неправильные:\n");
                }
            } while (stroki1 != stroki || stolbci1 != stolbci);
            printf("введите элементы для 1ой матрицы:\n");
            matr1 = vvodElementov(stroki, stolbci);
            printf("введите элементы для 2ой матрицы:\n");
            matr2 = vvodElementov(stolbci, stroki);
            vichitanieMatr(matr1, matr2, stolbci, stroki);
            freeMatr(matr1, stroki1);
            freeMatr(matr2, stroki);
            break;
        case 3:
            do {
                printf("введите кол во строк для первой матрицы:\n");
                do {
                    stroki1 = proverkaVvoda();
                    if (stroki1 <= 0) {
                        printf("во-первых,строки должны быть положительными, во-вторых больше 0\n");
                    }
                } while (stroki1 < 1);
                printf("введите кол во столбцов для первой матрицы:\n");
                do {
                    stolbci1 = proverkaVvoda();
                    if (stolbci1 <= 0) {
                        printf("во-первых,строки должны быть положительными, во-вторых больше 0\n");
                    }
                } while (stolbci1 < 1);
                printf("введите кол во строк для второй матрицы:\n");
                do {
                    stroki2 = proverkaVvoda();
                    if (stroki2 <= 0) {
                        printf("во-первых,строки должны быть положительными, во-вторых больше 0\n");
                    }
                } while (stroki2 < 1);
                printf("введите кол во столбцов для первой матрицы:\n");
                do {
                    stolbci2 = proverkaVvoda();
                    if (stolbci2 <= 0) {
                        printf("во-первых,строки должны быть положительными, во-вторых больше 0\n");
                    }
                } while (stolbci2 < 1);
                if (stroki1 != stroki2) {
                    printf("размеры неправильные:\n");
                }
            } while (stolbci1 != stroki2);
            printf("введите элементы для 1ой матрицы:\n");
            matr1 = vvodElementov(stroki1, stolbci1);
            printf("введите элементы для 2ой матрицы:\n");
            matr2 = vvodElementov(stroki2, stolbci2);
            umnojenieMatr(matr1, matr2, stroki1, stolbci1, stroki2, stolbci2);
            freeMatr(matr1, stroki1);
            freeMatr(matr2, stroki2);
            break;
        case 4:
            printf("введите матрицу:\n");
            printf("введите кол во строк для матрицы:\n");
            do {
                stroki = proverkaVvoda();
                if (stroki <= 0) {
                    printf("во-первых,строки должны быть положительными, во-вторых больше 0\n");
                }
            } while (stroki < 1);
            printf("введите кол во столбцов для  матрицы:\n");
            do {
                stolbci = proverkaVvoda();
                if (stolbci <= 0) {
                    printf("во-первых,строки должны быть положительными, во-вторых больше 0\n");
                }
            } while (stolbci < 1);
            matr = vvodElementov(stroki, stolbci);
            printf("результат умножения матрицы на число:\n");
            umnojenieMatrNaChislo(matr, stroki, stolbci);
            freeMatr(matr, stroki);
            break;
        case 5:
            printf("введите матрицу:\n");
            printf("введите кол во строк для матрицы:\n");
            do {
                stroki = proverkaVvoda();
                if (stroki <= 0) {
                    printf("во-первых,строки должны быть положительными, во-вторых больше 0\n");
                }
            } while (stroki < 1);
            printf("введите кол во столбцов для  матрицы:\n");
            do {
                stolbci = proverkaVvoda();
                if (stolbci <= 0) {
                    printf("во-первых,строки должны быть положительными, во-вторых больше 0\n");
                }
            } while (stolbci < 1);
            matr = vvodElementov(stroki, stolbci);
            printf("результат сложения матрицы с числом:\n");
            slojenieMatrSChislom(matr, stroki, stolbci);
            freeMatr(matr, stroki);
            break;
        case 6:
            printf("введите матрицу:\n");
            printf("введите кол во строк для матрицы:\n");
            do {
                stroki = proverkaVvoda();
                if (stroki <= 0) {
                    printf("во-первых,строки должны быть положительными, во-вторых больше 0\n");
                }
            } while (stroki < 1);
            printf("введите кол во столбцов для  матрицы:\n");
            do {
                stolbci = proverkaVvoda();
                if (stolbci <= 0) {
                    printf("во-первых,строки должны быть положительными, во-вторых больше 0\n");
                }
            } while (stolbci < 1);
            matr = vvodElementov(stroki, stolbci);
            printf("результат вычитания числа из матрицы:\n");
            vichitanieMatrSChislom(matr, stroki, stolbci);
            freeMatr(matr, stroki);
            break;
        case 7:
            printf("введите матрицу:\n");
            printf("введите кол во строк для матрицы:\n");
            do {
                stroki = proverkaVvoda();
                if (stroki <= 0) {
                    printf("во-первых,строки должны быть положительными, во-вторых больше 0\n");
                }
            } while (stroki < 1);
            printf("введите кол во столбцов для  матрицы:\n");
            do {
                stolbci = proverkaVvoda();
                if (stolbci <= 0) {
                    printf("во-первых,строки должны быть положительными, во-вторых больше 0\n");
                }
            } while (stolbci < 1);
            matr = vvodElementov(stroki, stolbci);
            printf("результат транспонирования матрицы:\n");
            transponirovanieMatr(matr, stroki, stolbci);
            freeMatr(matr, stroki);
            break;
        case 8:
            printf("выберите, какого размера матрицы вы хотите найти определитель?\n");
            printf("1.матрицы 1х1\n");
            printf("2.матрица 2х2\n");
            printf("3.матрица 3х3\n");
            printf("4.матрица 4х4\n");
            n1 = proverkaVvoda();
            switch (n1) {
            case 1:
                do {
                    printf("введите матрицу:\n");
                    printf("введите кол во строк для матрицы:\n");
                    do {
                        stroki = proverkaVvoda();
                        if (stroki <= 0) {
                            printf("во-первых,строки должны быть положительными, во-вторых больше 0\n");
                        }
                    } while (stroki < 1);
                    printf("введите кол во столбцов для  матрицы:\n");
                    do {
                        stolbci = proverkaVvoda();
                        if (stolbci <= 0) {
                            printf("во-первых,строки должны быть положительными, во-вторых больше 0\n");
                        }
                    } while (stolbci < 1);
                    if (stroki != 1 || stolbci != 1) {
                        printf("размеры не совпадают");
                    }
                    else {
                        break;
                    }
                } while (stroki != 1 || stolbci != 1);
                printf("введите элементы матрицы:\n");
                matr = vvodElementov(stroki, stolbci);
                opredelitelMatrOdinNaOdin(matr, stroki, stolbci);
                break;
            case 2:
                do {
                    printf("введите матрицу:\n");
                    printf("введите кол во строк для матрицы:\n");
                    do {
                        stroki = proverkaVvoda();
                        if (stroki <= 0) {
                            printf("во-первых,строки должны быть положительными, во-вторых больше 0\n");
                        }
                    } while (stroki < 1);
                    printf("введите кол во столбцов для  матрицы: ");
                    do {
                        stolbci = proverkaVvoda();
                        if (stolbci <= 0) {
                            printf("во-первых,строки должны быть положительными, во-вторых больше 0\n");
                        }
                    } while (stolbci < 1);
                    if (stroki != 2 || stolbci != 2) {
                        printf("размеры не совпадают\n");
                    }
                    else {
                        break;
                    }
                } while (stroki != 2 || stolbci != 2);
                printf("введите элементы матрицы:\n");
                matr = vvodElementov(stroki, stolbci);
                opredelitelMatrDvaNaDva(matr, stroki, stolbci);
                break;
            case 3:
                do {
                    printf("введите матрицу:\n");
                    printf("введите кол во строк для матрицы:\n");
                    do {
                        stroki = proverkaVvoda();
                        if (stroki <= 0) {
                            printf("во-первых,строки должны быть положительными, во-вторых больше 0\n");
                        }
                    } while (stroki < 1);
                    printf("введите кол во столбцов для  матрицы:\n");
                    do {
                        stolbci = proverkaVvoda();
                        if (stolbci <= 0) {
                            printf("во-первых,строки должны быть положительными, во-вторых больше 0\n");
                        }
                    } while (stolbci < 1);
                    if (stroki != 3 || stolbci != 3) {
                        printf("размеры не совпадают\n");
                    }
                    else {
                        break;
                    }
                } while (stroki != 3 || stolbci != 3);
                printf("введите элементы матрицы:\n");
                matr = vvodElementov(stroki, stolbci);
                opredelitelMatrTriNaTri(matr, stroki, stolbci);
                break;
            case 4:
                do {
                    printf("введите матрицу:\n");
                    printf("введите кол во строк для матрицы:\n");
                    do {
                        stroki = proverkaVvoda();
                        if (stroki <= 0) {
                            printf("во-первых,строки должны быть положительными, во-вторых больше 0\n");
                        }
                    } while (stroki < 1);
                    printf("введите кол во столбцов для  матрицы:\n");
                    do {
                        stolbci = proverkaVvoda();
                        if (stolbci <= 0) {
                            printf("во-первых,строки должны быть положительными, во-вторых больше 0\n");
                        }
                    } while (stolbci < 1);
                    if (stroki != 4 || stolbci != 4) {
                        printf("размеры не совпадают\n");
                    }
                    else {
                        break;
                    }
                } while (stroki != 4 || stolbci != 4);
                printf("введите элементы матрицы:\n");
                matr = vvodElementov(stroki, stolbci);
                opredelitelMatrChetireNaChetire(matr, stroki, stolbci);
                freeMatr(matr, stroki);
                break;
            default:
                printf("неправильный ввод\n");
            }break;
        case 9:
            printf("выберите, для какой матрицы вы хотите найти обратную?\n");
            printf("1.матрица 1х1\n");
            printf("2.матрица 2х2\n");
            printf("3.матрица 3х3\n");
            n2 = proverkaVvoda();
            switch (n2) {
            case 1:
                do {
                    printf("введите матрицу:\n");
                    printf("введите кол во строк для матрицы:\n");
                    do {
                        stroki = proverkaVvoda();
                        if (stroki <= 0) {
                            printf("во-первых,строки должны быть положительными, во-вторых больше 0\n");
                        }
                    } while (stroki < 1);
                    printf("введите кол во столбцов для  матрицы:\n");
                    do {
                        stolbci = proverkaVvoda();
                        if (stolbci <= 0) {
                            printf("во-первых,строки должны быть положительными, во-вторых больше 0\n");
                        }
                    } while (stolbci < 1);
                    if (stroki != 1 || stolbci != 1) {
                        printf("размеры не совпадают\n");
                    }
                    else {
                        break;
                    }
                } while (stroki != 1 || stolbci != 1);
                printf("введите элементы матрицы:\n");
                matr = vvodElementov(stroki, stolbci);
                obratnayaMatrOdinNaOdin(matr, stroki, stolbci);
                freeMatr(matr, stroki);
                break;
            case 2:
                do {
                    printf("введите матрицу:\n");
                    printf("введите кол во строк для матрицы\n");
                    do {
                        stroki = proverkaVvoda();
                        if (stroki <= 0) {
                            printf("во-первых,строки должны быть положительными, во-вторых больше 0\n");
                        }
                    } while (stroki < 1);
                    printf("введите кол во столбцов для  матрицы:\n");
                    do {
                        stolbci = proverkaVvoda();
                        if (stolbci <= 0) {
                            printf("во-первых,строки должны быть положительными, во-вторых больше 0\n");
                        }
                    } while (stolbci < 1);
                    if (stroki != 2 || stolbci != 2) {
                        printf("размеры не совпадают\n");
                    }
                    else {
                        break;
                    }
                } while (stroki != 2 || stolbci != 2);
                printf("введите элементы матрицы:\n");
                matr = vvodElementov(stroki, stolbci);
                obratnayaMatrDvaNaDva(matr, stroki, stolbci);
                freeMatr(matr, stroki);
                break;
            case 3:
                do {
                    printf("введите матрицу:\n");
                    printf("введите кол во строк для матрицы:\n");
                    do {
                        stroki = proverkaVvoda();
                        if (stroki <= 0) {
                            printf("во-первых,строки должны быть положительными, во-вторых больше 0\n");
                        }
                    } while (stroki < 1);
                    printf("введите кол во столбцов для  матрицы:\n");
                    do {
                        stolbci = proverkaVvoda();
                        if (stolbci <= 0) {
                            printf("во-первых,строки должны быть положительными, во-вторых больше 0\n");
                        }
                    } while (stolbci < 1);
                    if (stroki != 3 || stolbci != 3) {
                        printf("размеры не совпадают\n");
                    }
                    else {
                        break;
                    }
                } while (stroki != 3 || stolbci != 3);
                printf("введите элементы матрицы:\n");
                matr = vvodElementov(stroki, stolbci);
                obratnayaMatrTriNaTri(matr, stroki, stolbci);
                freeMatr(matr, stroki);
                break;
            default:
                printf("неправильный ввод\n");
            }break;
        }
    } while (n != 0);
}





