#include <stdio.h>
void vvodMatr(double matr[100][100],int *stolbci,int *stroki){
    int i,j;
    printf("введите количество строк матрицы: ");
    do{
        scanf("%d",stroki);
    }while (*stroki<1);
    printf("введите количество столбцов матрицы: ");
    do{
        scanf("%d",stolbci);
    }while (*stolbci<1);
    printf("введите элементы матрицы:\n");
    for (i=0;i<*stroki;i++){
        for (j=0;j<*stolbci;j++){
            printf("элементы [%d][%d]",i,j);
            scanf("%lf",&matr[i][j]);
        }
    }
}
void vvodMatr1(double matr1[100][100],int *stolbci,int *stroki){
    int i,j;
    printf("введите количество строк матрицы(1): ");
    do{
        scanf("%d",stroki);
    }while (*stroki<1);
    printf("введите количество столбцов матрицы(1): ");
    do{
        scanf("%d",stolbci);
    }while (*stolbci<1);
    printf("введите элементы матрицы(1):\n");
    for (i=0;i<*stroki;i++){
        for (j=0;j<*stolbci;j++){
            printf("элементы матрицы(1)[%d][%d]",i,j);
            scanf("%lf",&matr1[i][j]);
        }
    }
}
void vvodMatr2(double matr2[100][100],int *stolbci,int *stroki){
    int i,j;
    printf("введите количество строк матрицы(2): ");
    do{
        scanf("%d",stroki);
    }while (*stroki<1);
    printf("введите количество столбцов матрицы(2): ");
    do{
        scanf("%d",stolbci);
    }while (*stolbci<1);
    printf("введите элементы матрицы(2):\n");
    for (i=0;i<*stroki;i++){
        for (j=0;j<*stolbci;j++){
            printf("элементы матрицы(2)[%d][%d]",i,j);
            scanf("%lf",&matr2[i][j]);
        }
    }
}
void vivodMatr(double matr[100][100],int stolbci,int stroki){
    int i,j;
    printf("матрица:\n");
    for (i=0;i<stroki;i++){
        for (j=0;j<stolbci;j++){
            printf("%lf\t",matr[i][j]);
        }
    }
}
void slojenieMatr(double matr1[100][100],double matr2[100][100],int stolbci,int stroki,int stroki1,int stolbci1){
    int i,j;
    if (stroki!=stroki1 || stolbci!=stolbci1){
        printf("введите одинаковые размеры:");
    }
    printf("вследствие сложения матриц получим результат:");
    for (i=0;i<stroki;i++){
        for (j=0;j<stolbci;j++){
            printf("%lf\t",matr1[i][j]+matr2[i][j]);
        }
        printf("\n");
    }
}
void vichitanieMatr(double matr1[100][100],double matr2[100][100],int stolbci,int stroki){
    int i,j;
    printf("вследствие вычитания матриц получим результат:");
    for (i=0;i<stroki;i++){
        for (j=0;j<stolbci;j++){
            printf("%lf\t",matr1[i][j]-matr2[i][j]);
        }
        printf("\n");
    }
}
void umnojenieMatr(double matr1[100][100],double matr2[100][100],int stroki,int stolbci,int stolbci1){
    int i,j,s;
    double resultatUmnojeniya[100][100]={0};
    for (i=0;i<stroki;i++){
        for (j=0;j<stolbci1;j++){
            for (s=0;s<stolbci;s++){
                resultatUmnojeniya[i][j]=resultatUmnojeniya[i][j]+(matr1[i][s]*matr2[s][j]);
            }
        }
    }
    vivodMatr(resultatUmnojeniya,stolbci1,stroki);
}
void umnojenieMatrNaChislo(double matr[100][100],int stroki,int stolbci){
    double resultatUmnojeniyaNaChislo[100][100]={0},chislo;
    int i,j;
    printf("введите число, на которое необходимо умножить матрицу:\n");
    scanf("%lf",&chislo);
    for (i=0;i<stroki;i++){
        for (j=0;j<stolbci;j++){
            resultatUmnojeniyaNaChislo[i][j]=resultatUmnojeniyaNaChislo[i][j]+(matr[i][j]*chislo);
        }
    }
    vivodMatr(resultatUmnojeniyaNaChislo, stolbci, stroki);
}
void slojenieMatrSChislom(double matr[100][100],int stroki,int stolbci){
    double resultatSlojeniyaSChislom[100][100]={0},chislo;
    int i,j;
    printf("введите число, которое необходимо прибаавить к матрице:\n");
    scanf("%lf",&chislo);
    for (i=0;i<stroki;i++){
        for (j=0;j<stolbci;j++){
            resultatSlojeniyaSChislom[i][j]=resultatSlojeniyaSChislom[i][j]+matr[i][j]+chislo;
        }
    }
    vivodMatr(resultatSlojeniyaSChislom, stolbci, stroki);
}
void vichitanieMatrSChislom(double matr[100][100],int stroki,int stolbci){
    double resultatVichitaniyaSChislom[100][100]={0},chislo;
    int i,j;
    printf("введите число, на которое мы будем вычитать матрицу:\n");
    scanf("%lf",&chislo);
    for (i=0;i<stroki;i++){
        for (j=0;j<stolbci;j++){
            resultatVichitaniyaSChislom[i][j]=resultatVichitaniyaSChislom[i][j]+matr[i][j]-chislo;
        }
    }
    vivodMatr(resultatVichitaniyaSChislom, stolbci, stroki);
}
void transponirovanieMatr(double matr[100][100],int stroki,int stolbci){
    int i,j;
    printf("вследствие транспонирования матрицы, получим следующий результат:\n");
    for (i=0;i<stolbci;i++){
        for (j=0;j<stroki;j++){
            printf("%lf\t",matr[j][i]);
        }
        printf("\n");
    }
}
void menu(){
    double matr[100][100],matr1[100][100],matr2[100][100];
    int stroki,stolbci,stroki1,stolbci1,stroki2,stolbci2,n;
    do{
        printf("меню выбора действий над матрицей");
        printf("1.сложение двух матриц\n");
        printf("2.вычетание двух матриц\n");
        printf("3.умножение двух матриц\n");
        printf("4.умножение матриц на число\n");
        printf("5.прибавление числа к матрице\n");
        printf("6.вычистание числа из матрицы\n");
        printf("7.транспонирование матрицы\n");
        printf("0.выход\n");
        scanf("%d",&n);
        switch(n){
            case 1:
                printf("введите первую матрицу:\n");
                vvodMatr1(matr1,&stolbci,&stroki);
                printf("введите вторую матрицу:\n");
                vvodMatr2(matr2,&stolbci,&stroki);
                printf("результат сложения этих матриц:\n");
                slojenieMatr(matr1,matr2,stolbci,stroki,stroki1,stolbci1);
            break;
            case 2:
                printf("введите первую матрицу:\n");
                vvodMatr1(matr1,&stolbci,&stroki);
                printf("введите вторую матрицу:\n");
                vvodMatr2(matr2,&stolbci,&stroki);
                printf("результат вычитания этих матриц:\n");
                vichitanieMatr(matr1,matr2,stolbci,stroki);
            break;
            case 3:
                printf("введите первую матрицу:\n");
                vvodMatr1(matr1,&stolbci,&stroki);
                printf("введите вторую матрицу:\n");
                vvodMatr2(matr2,&stolbci1,&stroki);
                printf("результат умножения этих матриц:\n");
                umnojenieMatr(matr1,matr2,stroki,stolbci,stolbci1);
            break;
            case 4:
                printf("введите матрицу:\n");
                vvodMatr(matr,&stolbci,&stroki);
                printf("результат умножения матрицы на число:\n");
                umnojenieMatrNaChislo(matr,stroki,stolbci);
            break;
            case 5:
                printf("введите матрицу:\n");
                vvodMatr(matr,&stolbci,&stroki);
                printf("результат сложения матрицы с числом:\n");
                slojenieMatrSChislom(matr,stroki,stolbci);
            break;
            case 6:
                printf("введите матрицу:\n");
                vvodMatr(matr,&stolbci,&stroki);
                printf("результат вычитания числа из матрицы:\n");
                vichitanieMatrSChislom(matr,stroki,stolbci);
            break;
            case 7:
                printf("введите матрицу:\n");
                vvodMatr(matr,&stolbci,&stroki);
                printf("результат транспонирования матрицы:\n");
                transponirovanieMatr(matr,stroki,stolbci);
            break;
        }
    }while(n!=0);
}
    
