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
        printf("�� ����� �� �����, ��������� �������: ");
    }
    return chislo2;
}
double proverkaVvoda1() {
    double chislo2;
    while (scanf("%lf", &chislo2) != 1) {
        while (getchar() != '\n');
        printf("�� ����� �� �����, ��������� �������: ");
    }
    return chislo2;
}
double** vvodElementov(int stroki, int stolbci) {
    int i, j;
    double** matr = dynMatr(stroki, stolbci);
    for (i = 0; i < stroki; i++) {
        for (j = 0; j < stolbci; j++) {
            printf("������� [%d][%d]: ", i, j);
            matr[i][j] = proverkaVvoda1();
        }
    }
    return matr;
}
void vivodMatr(double** matr, int stroki, int stolbci) {
    int i, j;
    printf("�������:\n");
    for (i = 0; i < stroki; i++) {
        for (j = 0; j < stolbci; j++) {
            printf("%.2lf ", matr[i][j]);
        }
        printf("\n");
    }
}
void slojenieMatr(double** matr1, double** matr2, int stolbci, int stroki, int stroki1, int stolbci1) {
    int i, j;

    printf("���������� �������� ������ ������� ���������:\n");
    for (i = 0; i < stroki; i++) {
        for (j = 0; j < stolbci; j++) {
            printf("%.2lf ", matr1[i][j] + matr2[i][j]);
        }
        printf("\n");
    }
}
void vichitanieMatr(double** matr1, double** matr2, int stolbci, int stroki) {
    int i, j;
    printf("���������� ��������� ������ ������� ���������:\n");
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
    printf("������� �����, �� ������� ���������� �������� �������:\n");
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
    printf("������� �����, ������� ���������� ���������� � �������:\n");
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
    printf("������� �����, �� ������� �� ����� �������� �������:\n");
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
    printf("���������� ���������������� �������, ������� ��������� ���������:\n");
    for (i = 0; i < stolbci; i++) {
        for (j = 0; j < stroki; j++) {
            printf("%.2lf ", matr[j][i]);
        }
        printf("\n");
    }
}
void opredelitelMatrOdinNaOdin(double** matr, int stroki, int stolbci) {
    printf("������������ ������� 1�1 = %.1lf ", matr[0][0]);
}
void opredelitelMatrDvaNaDva(double** matr, int stroki, int stolbci) {
    double res;
    res = matr[0][0] * matr[1][1] - matr[0][1] * matr[1][0];
    printf("������������ ������� 2�2 = %.1lf ", res);
}
void opredelitelMatrTriNaTri(double** matr, int stroki, int stolbci) {
    double res;
    res = (matr[0][0] * matr[1][1] * matr[2][2] + matr[0][1] * matr[1][2] * matr[2][0]) + (matr[0][2] * matr[1][0] * matr[2][1]) - (matr[0][2] * matr[1][1] * matr[2][0]) - (matr[0][0] * matr[1][2] * matr[2][1]) - (matr[0][1] * matr[1][0] * matr[2][2]);
    printf("������������ ������� 3�3 = %.1lf ", res);
}
void opredelitelMatrChetireNaChetire(double** matr, int stroki, int stolbci) {
    double res;
    res = matr[0][0] * ((matr[1][1] * matr[2][2] * matr[3][3]) + (matr[2][1] * matr[3][2] * matr[1][3]) + (matr[1][2] * matr[2][3] * matr[3][1]) - (matr[1][3] * matr[2][2] * matr[3][1]) - (matr[3][2] * matr[2][3] * matr[1][1]) - (matr[2][1] * matr[1][2] * matr[3][3])) - matr[0][1] * ((matr[1][0] * matr[2][2] * matr[3][3]) + (matr[2][0] * matr[3][2] * matr[1][3]) + (matr[1][2] * matr[2][3] * matr[3][0]) - (matr[1][3] * matr[2][2] * matr[3][0]) - (matr[2][3] * matr[3][2] * matr[1][0]) - (matr[2][0] * matr[1][2] * matr[3][3])) + matr[0][2] * ((matr[1][0] * matr[2][1] * matr[3][3]) + (matr[1][1] * matr[2][3] * matr[3][0]) + (matr[2][0] * matr[3][1] * matr[1][3]) - (matr[1][3] * matr[2][1] * matr[3][0]) - (matr[3][1] * matr[2][3] * matr[1][0]) - (matr[2][0] * matr[1][1] * matr[3][3])) - matr[0][3] * ((matr[1][0] * matr[2][1] * matr[3][2]) + (matr[2][0] * matr[3][1] * matr[1][2]) + (matr[1][1] * matr[2][2] * matr[3][0]) - (matr[1][2] * matr[2][1] * matr[3][0]) - (matr[3][1] * matr[2][2] * matr[1][0]) - (matr[2][0] * matr[1][1] * matr[3][2]));
    printf("������������� 4�4 = %.1lf", res);
}
void obratnayaMatrDvaNaDva(double** matr, int stroki, int stolbci) {
    double res, algebraicheskieDopolneniya1[100][100];
    int i, j;

    do {
        res = matr[0][0] * matr[1][1] - matr[0][1] * matr[1][0];
        if (res == 0) {
            printf("������������ = 0 ������������� ������� ����������� � ��������� �� ����������\n");
            printf("���� ������� ������:\n");
            matr = vvodElementov(stroki, stolbci);
        }
    } while (res == 0);
    algebraicheskieDopolneniya1[0][0] = matr[1][1];
    algebraicheskieDopolneniya1[0][1] = -matr[1][0];
    algebraicheskieDopolneniya1[1][0] = -matr[0][1];
    algebraicheskieDopolneniya1[1][1] = matr[0][0];
    printf("�������� �������:\n");
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
            printf("������������ = 0 ������������� ������� ����������� � �������� �� ����������\n");
            printf("���� ������� ������:\n");
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
    printf("�������� �������:\n");
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
            printf("������������ = 0 ������������� ������� ����������� � �������� �� ����������\n");
            printf("���� ������� ������:\n");
            matr = vvodElementov(stroki, stolbci);
        }
    } while (res == 0);
    printf("�������� �������:\n");
    printf("%.2lf ", res);
}
void menu() {
    double** matr, ** matr1, ** matr2;
    int stroki, stolbci, stroki1, stolbci1, stroki2, stolbci2, n, n1, n2;
    do {
        printf("���� ������ �������� ��� ��������\n");
        printf("1.�������� ���� ������\n");
        printf("2.��������� ���� ������\n");
        printf("3.��������� ���� ������\n");
        printf("4.��������� ������ �� �����\n");
        printf("5.����������� ����� � �������\n");
        printf("6.��������� ����� �� �������\n");
        printf("7.���������������� �������\n");
        printf("8.������������ ������\n");
        printf("9.�������� �������\n");
        printf("0.�����\n");
        n = proverkaVvoda();
        switch (n) {
        case 1:
            do {
                printf("������� ��� �� ����� ��� ������ �������:\n");
                do {
                    stroki = proverkaVvoda();
                    if (stroki <= 0) {
                        printf("��-������,������ ������ ���� ��������������, ��-������ ������ 0\n");
                    }
                } while (stroki < 1);
                printf("������� ��� �� �������� ��� ������ �������:\n");
                do {
                    stolbci = proverkaVvoda();
                    if (stolbci <= 0) {
                        printf("��-������,������ ������ ���� ��������������, ��-������ ������ 0\n");
                    }
                } while (stolbci < 1);
                printf("������� ��� �� ����� ��� ������ �������:\n");
                do {
                    stroki1 = proverkaVvoda();
                    if (stroki1 <= 0) {
                        printf("��-������,������ ������ ���� ��������������, ��-������ ������ 0\n");
                    }
                } while (stroki1 < 1);
                printf("������� ��� �� �������� ��� ������ �������:\n");
                do {
                    stolbci1 = proverkaVvoda();
                    if (stolbci1 <= 0) {
                        printf("��-������,������ ������ ���� ��������������, ��-������ ������ 0\n");
                    }
                } while (stolbci1 < 1);
                if (stroki1 != stroki || stolbci1 != stolbci) {
                    printf("������� ������������:\n");
                }
            } while (stroki1 != stroki || stolbci1 != stolbci);
            printf("������� �������� ��� 1�� �������:\n");
            matr1 = vvodElementov(stroki, stolbci);
            printf("������� �������� ��� 2�� �������:\n");
            matr2 = vvodElementov(stroki, stolbci);
            printf("��������� �������� ���� ������:\n");
            slojenieMatr(matr1, matr2, stolbci, stroki, stroki1, stolbci1);
            freeMatr(matr1, stroki);
            freeMatr(matr2, stroki);
            break;
        case 2:
            do {
                printf("������� ��� �� ����� ��� ������ �������:\n");
                do {
                    stroki = proverkaVvoda();
                    if (stroki <= 0) {
                        printf("��-������,������ ������ ���� ��������������, ��-������ ������ 0\n");
                    }
                } while (stroki < 1);
                printf("������� ��� �� �������� ��� ������ �������:\n");
                do {
                    stolbci = proverkaVvoda();
                    if (stolbci <= 0) {
                        printf("��-������,������ ������ ���� ��������������, ��-������ ������ 0\n");
                    }
                } while (stolbci < 1);
                printf("������� ��� �� ����� ��� ������ �������:\n");
                do {
                    stroki1 = proverkaVvoda();
                    if (stroki1 <= 0) {
                        printf("��-������,������ ������ ���� ��������������, ��-������ ������ 0\n");
                    }
                } while (stroki1 < 1);
                printf("������� ��� �� �������� ��� ������ �������:\n");
                do {
                    stolbci1 = proverkaVvoda();
                    if (stolbci1 <= 0) {
                        printf("��-������,������ ������ ���� ��������������, ��-������ ������ 0\n");
                    }
                } while (stolbci1 < 1);
                if (stroki1 != stroki || stolbci1 != stolbci) {
                    printf("������� ������������:\n");
                }
            } while (stroki1 != stroki || stolbci1 != stolbci);
            printf("������� �������� ��� 1�� �������:\n");
            matr1 = vvodElementov(stroki, stolbci);
            printf("������� �������� ��� 2�� �������:\n");
            matr2 = vvodElementov(stolbci, stroki);
            vichitanieMatr(matr1, matr2, stolbci, stroki);
            freeMatr(matr1, stroki1);
            freeMatr(matr2, stroki);
            break;
        case 3:
            do {
                printf("������� ��� �� ����� ��� ������ �������:\n");
                do {
                    stroki1 = proverkaVvoda();
                    if (stroki1 <= 0) {
                        printf("��-������,������ ������ ���� ��������������, ��-������ ������ 0\n");
                    }
                } while (stroki1 < 1);
                printf("������� ��� �� �������� ��� ������ �������:\n");
                do {
                    stolbci1 = proverkaVvoda();
                    if (stolbci1 <= 0) {
                        printf("��-������,������ ������ ���� ��������������, ��-������ ������ 0\n");
                    }
                } while (stolbci1 < 1);
                printf("������� ��� �� ����� ��� ������ �������:\n");
                do {
                    stroki2 = proverkaVvoda();
                    if (stroki2 <= 0) {
                        printf("��-������,������ ������ ���� ��������������, ��-������ ������ 0\n");
                    }
                } while (stroki2 < 1);
                printf("������� ��� �� �������� ��� ������ �������:\n");
                do {
                    stolbci2 = proverkaVvoda();
                    if (stolbci2 <= 0) {
                        printf("��-������,������ ������ ���� ��������������, ��-������ ������ 0\n");
                    }
                } while (stolbci2 < 1);
                if (stroki1 != stroki2) {
                    printf("������� ������������:\n");
                }
            } while (stolbci1 != stroki2);
            printf("������� �������� ��� 1�� �������:\n");
            matr1 = vvodElementov(stroki1, stolbci1);
            printf("������� �������� ��� 2�� �������:\n");
            matr2 = vvodElementov(stroki2, stolbci2);
            umnojenieMatr(matr1, matr2, stroki1, stolbci1, stroki2, stolbci2);
            freeMatr(matr1, stroki1);
            freeMatr(matr2, stroki2);
            break;
        case 4:
            printf("������� �������:\n");
            printf("������� ��� �� ����� ��� �������:\n");
            do {
                stroki = proverkaVvoda();
                if (stroki <= 0) {
                    printf("��-������,������ ������ ���� ��������������, ��-������ ������ 0\n");
                }
            } while (stroki < 1);
            printf("������� ��� �� �������� ���  �������:\n");
            do {
                stolbci = proverkaVvoda();
                if (stolbci <= 0) {
                    printf("��-������,������ ������ ���� ��������������, ��-������ ������ 0\n");
                }
            } while (stolbci < 1);
            matr = vvodElementov(stroki, stolbci);
            printf("��������� ��������� ������� �� �����:\n");
            umnojenieMatrNaChislo(matr, stroki, stolbci);
            freeMatr(matr, stroki);
            break;
        case 5:
            printf("������� �������:\n");
            printf("������� ��� �� ����� ��� �������:\n");
            do {
                stroki = proverkaVvoda();
                if (stroki <= 0) {
                    printf("��-������,������ ������ ���� ��������������, ��-������ ������ 0\n");
                }
            } while (stroki < 1);
            printf("������� ��� �� �������� ���  �������:\n");
            do {
                stolbci = proverkaVvoda();
                if (stolbci <= 0) {
                    printf("��-������,������ ������ ���� ��������������, ��-������ ������ 0\n");
                }
            } while (stolbci < 1);
            matr = vvodElementov(stroki, stolbci);
            printf("��������� �������� ������� � ������:\n");
            slojenieMatrSChislom(matr, stroki, stolbci);
            freeMatr(matr, stroki);
            break;
        case 6:
            printf("������� �������:\n");
            printf("������� ��� �� ����� ��� �������:\n");
            do {
                stroki = proverkaVvoda();
                if (stroki <= 0) {
                    printf("��-������,������ ������ ���� ��������������, ��-������ ������ 0\n");
                }
            } while (stroki < 1);
            printf("������� ��� �� �������� ���  �������:\n");
            do {
                stolbci = proverkaVvoda();
                if (stolbci <= 0) {
                    printf("��-������,������ ������ ���� ��������������, ��-������ ������ 0\n");
                }
            } while (stolbci < 1);
            matr = vvodElementov(stroki, stolbci);
            printf("��������� ��������� ����� �� �������:\n");
            vichitanieMatrSChislom(matr, stroki, stolbci);
            freeMatr(matr, stroki);
            break;
        case 7:
            printf("������� �������:\n");
            printf("������� ��� �� ����� ��� �������:\n");
            do {
                stroki = proverkaVvoda();
                if (stroki <= 0) {
                    printf("��-������,������ ������ ���� ��������������, ��-������ ������ 0\n");
                }
            } while (stroki < 1);
            printf("������� ��� �� �������� ���  �������:\n");
            do {
                stolbci = proverkaVvoda();
                if (stolbci <= 0) {
                    printf("��-������,������ ������ ���� ��������������, ��-������ ������ 0\n");
                }
            } while (stolbci < 1);
            matr = vvodElementov(stroki, stolbci);
            printf("��������� ���������������� �������:\n");
            transponirovanieMatr(matr, stroki, stolbci);
            freeMatr(matr, stroki);
            break;
        case 8:
            printf("��������, ������ ������� ������� �� ������ ����� ������������?\n");
            printf("1.������� 1�1\n");
            printf("2.������� 2�2\n");
            printf("3.������� 3�3\n");
            printf("4.������� 4�4\n");
            n1 = proverkaVvoda();
            switch (n1) {
            case 1:
                do {
                    printf("������� �������:\n");
                    printf("������� ��� �� ����� ��� �������:\n");
                    do {
                        stroki = proverkaVvoda();
                        if (stroki <= 0) {
                            printf("��-������,������ ������ ���� ��������������, ��-������ ������ 0\n");
                        }
                    } while (stroki < 1);
                    printf("������� ��� �� �������� ���  �������:\n");
                    do {
                        stolbci = proverkaVvoda();
                        if (stolbci <= 0) {
                            printf("��-������,������ ������ ���� ��������������, ��-������ ������ 0\n");
                        }
                    } while (stolbci < 1);
                    if (stroki != 1 || stolbci != 1) {
                        printf("������� �� ���������");
                    }
                    else {
                        break;
                    }
                } while (stroki != 1 || stolbci != 1);
                printf("������� �������� �������:\n");
                matr = vvodElementov(stroki, stolbci);
                opredelitelMatrOdinNaOdin(matr, stroki, stolbci);
                break;
            case 2:
                do {
                    printf("������� �������:\n");
                    printf("������� ��� �� ����� ��� �������:\n");
                    do {
                        stroki = proverkaVvoda();
                        if (stroki <= 0) {
                            printf("��-������,������ ������ ���� ��������������, ��-������ ������ 0\n");
                        }
                    } while (stroki < 1);
                    printf("������� ��� �� �������� ���  �������: ");
                    do {
                        stolbci = proverkaVvoda();
                        if (stolbci <= 0) {
                            printf("��-������,������ ������ ���� ��������������, ��-������ ������ 0\n");
                        }
                    } while (stolbci < 1);
                    if (stroki != 2 || stolbci != 2) {
                        printf("������� �� ���������\n");
                    }
                    else {
                        break;
                    }
                } while (stroki != 2 || stolbci != 2);
                printf("������� �������� �������:\n");
                matr = vvodElementov(stroki, stolbci);
                opredelitelMatrDvaNaDva(matr, stroki, stolbci);
                break;
            case 3:
                do {
                    printf("������� �������:\n");
                    printf("������� ��� �� ����� ��� �������:\n");
                    do {
                        stroki = proverkaVvoda();
                        if (stroki <= 0) {
                            printf("��-������,������ ������ ���� ��������������, ��-������ ������ 0\n");
                        }
                    } while (stroki < 1);
                    printf("������� ��� �� �������� ���  �������:\n");
                    do {
                        stolbci = proverkaVvoda();
                        if (stolbci <= 0) {
                            printf("��-������,������ ������ ���� ��������������, ��-������ ������ 0\n");
                        }
                    } while (stolbci < 1);
                    if (stroki != 3 || stolbci != 3) {
                        printf("������� �� ���������\n");
                    }
                    else {
                        break;
                    }
                } while (stroki != 3 || stolbci != 3);
                printf("������� �������� �������:\n");
                matr = vvodElementov(stroki, stolbci);
                opredelitelMatrTriNaTri(matr, stroki, stolbci);
                break;
            case 4:
                do {
                    printf("������� �������:\n");
                    printf("������� ��� �� ����� ��� �������:\n");
                    do {
                        stroki = proverkaVvoda();
                        if (stroki <= 0) {
                            printf("��-������,������ ������ ���� ��������������, ��-������ ������ 0\n");
                        }
                    } while (stroki < 1);
                    printf("������� ��� �� �������� ���  �������:\n");
                    do {
                        stolbci = proverkaVvoda();
                        if (stolbci <= 0) {
                            printf("��-������,������ ������ ���� ��������������, ��-������ ������ 0\n");
                        }
                    } while (stolbci < 1);
                    if (stroki != 4 || stolbci != 4) {
                        printf("������� �� ���������\n");
                    }
                    else {
                        break;
                    }
                } while (stroki != 4 || stolbci != 4);
                printf("������� �������� �������:\n");
                matr = vvodElementov(stroki, stolbci);
                opredelitelMatrChetireNaChetire(matr, stroki, stolbci);
                freeMatr(matr, stroki);
                break;
            default:
                printf("������������ ����\n");
            }break;
        case 9:
            printf("��������, ��� ����� ������� �� ������ ����� ��������?\n");
            printf("1.������� 1�1\n");
            printf("2.������� 2�2\n");
            printf("3.������� 3�3\n");
            n2 = proverkaVvoda();
            switch (n2) {
            case 1:
                do {
                    printf("������� �������:\n");
                    printf("������� ��� �� ����� ��� �������:\n");
                    do {
                        stroki = proverkaVvoda();
                        if (stroki <= 0) {
                            printf("��-������,������ ������ ���� ��������������, ��-������ ������ 0\n");
                        }
                    } while (stroki < 1);
                    printf("������� ��� �� �������� ���  �������:\n");
                    do {
                        stolbci = proverkaVvoda();
                        if (stolbci <= 0) {
                            printf("��-������,������ ������ ���� ��������������, ��-������ ������ 0\n");
                        }
                    } while (stolbci < 1);
                    if (stroki != 1 || stolbci != 1) {
                        printf("������� �� ���������\n");
                    }
                    else {
                        break;
                    }
                } while (stroki != 1 || stolbci != 1);
                printf("������� �������� �������:\n");
                matr = vvodElementov(stroki, stolbci);
                obratnayaMatrOdinNaOdin(matr, stroki, stolbci);
                freeMatr(matr, stroki);
                break;
            case 2:
                do {
                    printf("������� �������:\n");
                    printf("������� ��� �� ����� ��� �������\n");
                    do {
                        stroki = proverkaVvoda();
                        if (stroki <= 0) {
                            printf("��-������,������ ������ ���� ��������������, ��-������ ������ 0\n");
                        }
                    } while (stroki < 1);
                    printf("������� ��� �� �������� ���  �������:\n");
                    do {
                        stolbci = proverkaVvoda();
                        if (stolbci <= 0) {
                            printf("��-������,������ ������ ���� ��������������, ��-������ ������ 0\n");
                        }
                    } while (stolbci < 1);
                    if (stroki != 2 || stolbci != 2) {
                        printf("������� �� ���������\n");
                    }
                    else {
                        break;
                    }
                } while (stroki != 2 || stolbci != 2);
                printf("������� �������� �������:\n");
                matr = vvodElementov(stroki, stolbci);
                obratnayaMatrDvaNaDva(matr, stroki, stolbci);
                freeMatr(matr, stroki);
                break;
            case 3:
                do {
                    printf("������� �������:\n");
                    printf("������� ��� �� ����� ��� �������:\n");
                    do {
                        stroki = proverkaVvoda();
                        if (stroki <= 0) {
                            printf("��-������,������ ������ ���� ��������������, ��-������ ������ 0\n");
                        }
                    } while (stroki < 1);
                    printf("������� ��� �� �������� ���  �������:\n");
                    do {
                        stolbci = proverkaVvoda();
                        if (stolbci <= 0) {
                            printf("��-������,������ ������ ���� ��������������, ��-������ ������ 0\n");
                        }
                    } while (stolbci < 1);
                    if (stroki != 3 || stolbci != 3) {
                        printf("������� �� ���������\n");
                    }
                    else {
                        break;
                    }
                } while (stroki != 3 || stolbci != 3);
                printf("������� �������� �������:\n");
                matr = vvodElementov(stroki, stolbci);
                obratnayaMatrTriNaTri(matr, stroki, stolbci);
                freeMatr(matr, stroki);
                break;
            default:
                printf("������������ ����\n");
            }break;
        }
    } while (n != 0);
}





