#include <stdio.h>
#include <stdlib.h>
double** dynMatr(int stroki,int stolbci){
    int i;
    double** matr=(double**)malloc(stroki*sizeof(double*));
    for (i=0;i<stroki;i++){
        matr[i]=(double*)malloc(stolbci*sizeof(double));
    }
    return matr;
}
void freeMatr(double **matr, int stroki){
    int i;
    for (i=0;i<stroki;i++){
        free(matr[i]);
    }
    free(matr);
}
int proverkaVvoda(){
    int chislo2;
    while (scanf("%d",&chislo2)!=1){
        while (getchar()!='\n');
        printf("вы ввели не число, повторите попытку: ");
    }
    return chislo2;
}
double proverkaVvoda1(){
    double chislo2;
    while (scanf("%lf",&chislo2)!=1){
        while (getchar()!='\n');
        printf("вы ввели не число, повторите попытку: ");
    }
    return chislo2;
}
double **vvodMatr(int *stolbci,int *stroki){
    int i,j;
    printf("введите количество строк матрицы: ");
    do{
        *stroki=proverkaVvoda();
        if (*stroki<=0){
            printf("во-первых,строки должны быть положительными, во-вторых больше 0: ");
        }
    }while (*stroki<1);
    printf("введите количество столбцов матрицы: ");
    do{
        *stolbci=proverkaVvoda();
        if (*stolbci<=0){
            printf("во-первых,столбцы должны быть положительными, во-вторых больше 0: ");
        }
    }while (*stolbci<1);
    double **matr=dynMatr(*stroki,*stolbci);
    printf("введите элементы матрицы:\n");
    for (i=0;i<*stroki;i++){
        for (j=0;j<*stolbci;j++){
            printf("элементы [%d][%d]",i,j);
            matr[i][j]=proverkaVvoda1();
        }
    }
    return matr;
}

double **vvodMatr1(int *stolbci,int *stroki){
    int i,j;
    printf("введите количество строк матрицы: ");
    do{
        *stroki=proverkaVvoda();
        if (*stroki<=0){
            printf("во-первых,строки должны быть положительными, во-вторых больше 0: ");
        }
    }while (*stroki<1);
    printf("введите количество столбцов матрицы: ");
    do{
        *stolbci=proverkaVvoda();
        if (*stolbci<=0){
            printf("во-первых,столбцы должны быть положительными, во-вторых больше 0: ");
        }
    }while (*stolbci<1);
    double **matr=dynMatr(*stroki,*stolbci);
    printf("введите элементы матрицы:\n");
    for (i=0;i<*stroki;i++){
        for (j=0;j<*stolbci;j++){
            printf("элементы [%d][%d]",i,j);
            matr[i][j]=proverkaVvoda1();
        }
    }
    return matr;
}
double **vvodMatr2(int *stolbci1,int *stroki1){
    int i,j;
    printf("введите количество строк матрицы: ");
    do{
        *stroki1=proverkaVvoda();
        if (*stroki1<=0){
            printf("во-первых,строки должны быть положительными, во-вторых больше 0: ");
        }
    }while (*stroki1<1);
    printf("введите количество столбцов матрицы: ");
    do{
        *stolbci1=proverkaVvoda();
        if (*stolbci1<=0){
            printf("во-первых,столбцы должны быть положительными, во-вторых больше 0: ");
        }
    }while (*stolbci1<1);
    double **matr=dynMatr(*stroki1,*stolbci1);
    printf("введите элементы матрицы:\n");
    for (i=0;i<*stroki1;i++){
        for (j=0;j<*stolbci1;j++){
            printf("элементы [%d][%d]",i,j);
            matr[i][j]=proverkaVvoda1();
        }
    }
    return matr;
}
void vivodMatr(double **matr,int stroki,int stolbci){
    int i,j;
    printf("матрица:\n");
    for (i=0;i<stroki;i++){
        for (j=0;j<stolbci;j++){
            printf("%.1lf\t",matr[i][j]);
        }
        printf("\n");
    }
}
void slojenieMatr(double **matr1,double **matr2,int stolbci,int stroki,int stroki1,int stolbci1){
    int i,j;
    
    printf("вследствие сложения матриц получим результат:\n");
    for (i=0;i<stroki;i++){
        for (j=0;j<stolbci;j++){
            printf("%.1lf\t",matr1[i][j]+matr2[i][j]);
        }
        printf("\n");
    }
}
void vichitanieMatr(double **matr1,double **matr2,int stolbci,int stroki){
    int i,j;
    printf("вследствие вычитания матриц получим результат:\n");
    for (i=0;i<stroki;i++){
        for (j=0;j<stolbci;j++){
            printf("%.1lf\t ",matr1[i][j]-matr2[i][j]);
        }
        printf("\n");
    }
}
void umnojenieMatr(double **matr1,double **matr2,int stroki1,int stolbci1,int stroki2,int stolbci2){
    int i,j,s;
    double **resultatUmnojeniya=dynMatr(stroki1,stolbci2);
    for (i=0;i<stroki1;i++){
        for (j=0;j<stolbci2;j++){
            for (s=0;s<stolbci1;s++){
                resultatUmnojeniya[i][j]=resultatUmnojeniya[i][j]+(matr1[i][s]*matr2[s][j]);
            }
        }
    }
    vivodMatr(resultatUmnojeniya,stroki1,stolbci1);
    freeMatr(resultatUmnojeniya,stroki1);
}
void umnojenieMatrNaChislo(double **matr,int stroki,int stolbci){
    double chislo;
    int i,j;
    printf("введите число, на которое необходимо умножить матрицу:\n");
    chislo=proverkaVvoda();
    double **resultatUmnojeniyaNaChislo=dynMatr(stroki,stolbci);
    for (i=0;i<stroki;i++){
        for (j=0;j<stolbci;j++){
            resultatUmnojeniyaNaChislo[i][j]=resultatUmnojeniyaNaChislo[i][j]+(matr[i][j]*chislo);
        }
    }
    vivodMatr(resultatUmnojeniyaNaChislo,stroki,stolbci);
    freeMatr(resultatUmnojeniyaNaChislo,stroki);
}
void slojenieMatrSChislom(double **matr,int stroki,int stolbci){
    double chislo;
    int i,j;
    printf("введите число, которое необходимо прибаавить к матрице:\n");
    chislo=proverkaVvoda();
    double **resultatSlojeniyaSChislom=dynMatr(stroki,stolbci);
    for (i=0;i<stroki;i++){
        for (j=0;j<stolbci;j++){
            resultatSlojeniyaSChislom[i][j]=resultatSlojeniyaSChislom[i][j]+matr[i][j]+chislo;
        }
    }
    vivodMatr(resultatSlojeniyaSChislom,stroki,stolbci);
    freeMatr(resultatSlojeniyaSChislom,stroki);
}
void vichitanieMatrSChislom(double **matr,int stroki,int stolbci){
    double chislo;
    int i,j;
    printf("введите число, на которое мы будем вычитать матрицу:\n");
    chislo=proverkaVvoda();
    double **resultatVichitaniyaSChislom=dynMatr(stroki,stolbci);
    for (i=0;i<stroki;i++){
        for (j=0;j<stolbci;j++){
            resultatVichitaniyaSChislom[i][j]=resultatVichitaniyaSChislom[i][j]+matr[i][j]-chislo;
        }
    }
    vivodMatr(resultatVichitaniyaSChislom,stroki,stolbci);
    freeMatr(resultatVichitaniyaSChislom,stroki);
}
void transponirovanieMatr(double **matr,int stroki,int stolbci){
    int i,j;
    printf("вследствие транспонирования матрицы, получим следующий результат:\n");
    for (i=0;i<stolbci;i++){
        for (j=0;j<stroki;j++){
            printf("%.1lf\t",matr[j][i]);
        }
        printf("\n");
    }
}
void opredelitelMatrOdinNaOdin(double **matr,int stroki,int stolbci){
    printf("определитель матрицы 1х1 = %.1lf",matr[0][0]);
}
void opredelitelMatrDvaNaDva(double **matr,int stroki,int stolbci){
    double res;
    res=matr[0][0]*matr[1][1]-matr[0][1]*matr[1][0];
    printf("определитель матрицы 2х2 = %.1lf",res);
}
void opredelitelMatrTriNaTri(double **matr,int stroki,int stolbci){
    double res;
    res=(matr[0][0]*matr[1][1]*matr[2][2]+matr[0][1]*matr[1][2]*matr[2][0])+(matr[0][2]*matr[1][0]*matr[2][1])-(matr[0][2]*matr[1][1]*matr[2][0])-(matr[0][0]*matr[1][2]*matr[2][1])-(matr[0][1]*matr[1][0]*matr[2][2]);
    printf("определитель матрицы 3х3 = %.1lf",res);
}
void opredelitelMatrChetireNaChetire(double **matr,int stroki,int stolbci){
    double res;
    res=matr[0][0]*((matr[1][1]*matr[2][2]*matr[3][3])+(matr[2][1]*matr[3][2]*matr[1][3])+(matr[1][2]*matr[2][3]*matr[3][1])-(matr[1][3]*matr[2][2]*matr[3][1])-(matr[3][2]*matr[2][3]*matr[1][1])-(matr[2][1]*matr[1][2]*matr[3][3]))-matr[0][1]*((matr[1][0]*matr[2][2]*matr[3][3])+(matr[2][0]*matr[3][2]*matr[1][3])+(matr[1][2]*matr[2][3]*matr[3][0])-(matr[1][3]*matr[2][2]*matr[3][0])-(matr[2][3]*matr[3][2]*matr[1][0])-(matr[2][0]*matr[1][2]*matr[3][2]))+matr[0][2]*((matr[1][0]*matr[2][1]*matr[3][3])+(matr[1][1]*matr[2][3]*matr[3][0])+(matr[2][0]*matr[3][1]*matr[1][3])-(matr[1][3]*matr[2][1]*matr[3][0])-(matr[3][1]*matr[2][3]*matr[1][0])-(matr[2][0]*matr[1][1]*matr[3][3]))-matr[0][3]*((matr[1][0]*matr[2][1]*matr[3][3])+(matr[2][0]*matr[3][1]*matr[1][2])+(matr[1][1]*matr[2][2]*matr[3][0])-(matr[1][2]*matr[2][1]*matr[3][0])-(matr[3][1]*matr[2][2]*matr[1][0])-(matr[2][0]*matr[1][1]*matr[3][3]));
    printf("опредлдеитлеь 4х4 = %.1lf",res);
}
void obratnayaMatrDvaNaDva(double **matr,int stroki,int stolbci){
    double res;
    int i,j;
    res=matr[0][0]*matr[1][1]-matr[0][1]*matr[1][0];
    if (res==0){
        printf("определитель = 0 следовательно матрицы вырожденная и обраитной не существует\n");
    }
    double **algebraicheskieDopolneniya=dynMatr(stroki,stolbci);
        algebraicheskieDopolneniya[0][0]=matr[1][1];
        algebraicheskieDopolneniya[0][1]=-matr[1][0];
        algebraicheskieDopolneniya[1][0]=-matr[0][1];
        algebraicheskieDopolneniya[1][1]=matr[0][0];
        printf("обратная матрица:\n");
        for(i=0;i<stolbci;i++){
            for(j=0;j<stroki;j++){
                printf("%.2lf ",algebraicheskieDopolneniya[j][i]/res);
            }
            printf("\n");
        }
    freeMatr(algebraicheskieDopolneniya,stroki);
    }

void obratnayaMatrTriNaTri(double **matr,int stroki,int stolbci){
    double res,algebraicheskieDopolneniya1[100][100];
    int i,j;
    do{
        res=(matr[0][0]*matr[1][1]*matr[2][2]+matr[0][1]*matr[1][2]*matr[2][0])+(matr[0][2]*matr[1][0]*matr[2][1])-(matr[0][2]*matr[1][1]*matr[2][0])-(matr[0][0]*matr[1][2]*matr[2][1])-(matr[0][1]*matr[1][0]*matr[2][2]);
        if (res==0){
            printf("определитель = 0 следовательно матрицы вырожденная и обраитной не существует\n");
            printf("ввод матрицы заново:\n");
            matr=vvodMatr(&stolbci,&stroki);
        }
    }while (res==0);
    
    double **algebraicheskieDopolneniya=dynMatr(stroki,stolbci);
        algebraicheskieDopolneniya1[0][0]=matr[1][1]*matr[2][2]-matr[1][2]*matr[2][1];
        algebraicheskieDopolneniya1[0][1]=-(matr[1][0]*matr[2][2]-matr[1][2]*matr[2][0]);
        algebraicheskieDopolneniya1[0][2]=matr[1][0]*matr[2][1]-matr[1][1]*matr[2][0];
        algebraicheskieDopolneniya1[1][0]=-(matr[0][1]*matr[2][2]-matr[0][2]*matr[2][1]);
        algebraicheskieDopolneniya1[1][1]=matr[0][0]*matr[2][2]-matr[0][2]*matr[2][0];
        algebraicheskieDopolneniya1[1][2]=-(matr[0][0]*matr[2][1]-matr[0][1]*matr[2][0]);
        algebraicheskieDopolneniya1[2][0]=matr[0][1]*matr[1][2]-matr[0][2]*matr[1][1];
        algebraicheskieDopolneniya1[2][1]=-(matr[0][0]*matr[1][2]-matr[0][2]*matr[1][0]);
        algebraicheskieDopolneniya1[2][2]=matr[0][0]*matr[1][1]-matr[0][1]*matr[1][0];
        printf("обратная матрица:\n");
        for(i=0;i<stolbci;i++){
            for(j=0;j<stroki;j++){
                printf("%.2lf ",algebraicheskieDopolneniya1[j][i]/res);
            }
            printf("\n");
        }
    freeMatr(algebraicheskieDopolneniya,stroki);
    }
void obratnayaMatrOdinNaOdin(double **matr,int stroki,int stolbci){
    double res;
    do{
        res=matr[0][0];
        if (res==0){
            printf("определитель = 0 следовательно матрицы вырожденная и обраитной не существует\n");
            printf("ввод матрицы заново:\n");
            vvodMatr(stolbci,stroki);
        }
    }while (res==0);
    printf("обратная матрица:\n");
    printf("%.2lf",res);
}
void menu(){
    double **matr,**matr1,**matr2;
    int stroki,stolbci,stroki1,stolbci1,stroki2,stolbci2,n,n1,n2;
    do{
        printf("меню выбора действий над матрицей\n");
        printf("1.сложение двух матриц\n");
        printf("2.вычетание двух матриц\n");
        printf("3.умножение двух матриц\n");
        printf("4.умножение матриц на число\n");
        printf("5.прибавление числа к матрице\n");
        printf("6.вычистание числа из матрицы\n");
        printf("7.транспонирование матрицы\n");
        printf("8.определитель матриц\n");
        printf("9.обратные матрицы\n");
        printf("0.выход\n");
        n=proverkaVvoda();
        switch(n){
            case 1:
                do{
                    printf("введите первую матрицу:\n");
                    matr1=vvodMatr1(&stolbci,&stroki);
                    printf("введите вторую матрицу:\n");
                    matr2=vvodMatr2(&stolbci1,&stroki1);
                    if (stroki!=stroki1 || stolbci!=stolbci1){
                        printf("размеры матриц не совпадают\n");
                    }
                }while(stroki!=stroki1 || stolbci!=stolbci1);
                printf("результат сложения этих матриц:\n");
                slojenieMatr(matr1,matr2,stolbci,stroki,stroki1,stolbci1);
                freeMatr(matr1,stroki);
                freeMatr(matr2,stroki);
                break;
            case 2:
                do{
                    printf("введите кол во строк для первой матрицы: ");
                    stroki1=proverkaVvoda();
                    printf("введите кол во столбцов для первой матрицы: ");
                    stolbci1=proverkaVvoda();
                    printf("введите кол во строк для второй матрицы: ");
                    stroki2=proverkaVvoda();
                    printf("введите кол во столбоц для второй матрицы: ");
                    stolbci2=proverkaVvoda();
                    if (stroki1!=stroki2 || stolbci1!=stolbci2){
                        printf("размеры неправильные:\n");
                    }
                }while (stroki1!=stroki2 || stolbci1!=stolbci2);
                printf("введите элементы для 1ой матрицы:\n");
                matr1=vvodMatr(&stolbci1, &stroki1);
                printf("введите элементы для 2ой матрицы:\n");
                matr2=vvodMatr(&stolbci2,&stroki2);
                vichitanieMatr(matr1,matr2,stroki1,stolbci1);
                freeMatr(matr1,stroki1);
                freeMatr(matr2,stroki2);
                break;
            case 3:
                do{
                    printf("введите кол во строк для первой матрицы: ");
                    stroki1=proverkaVvoda();
                    printf("введите кол во столбцов для первой матрицы: ");
                    stolbci1=proverkaVvoda();
                    printf("введите кол во строк для второй матрицы: ");
                    stroki2=proverkaVvoda();
                    printf("введите кол во столбоц для второй матрицы: ");
                    stolbci2=proverkaVvoda();
                    if (stolbci1!=stroki2){
                        printf("столбцы из 1ой матр должны совпадать со строками из 2ой матр.\n");
                    }
                }while (stolbci1!=stroki2);
                printf("введите элементы для 1ой матрицы:\n");
                matr1=vvodMatr(&stolbci1, &stroki1);
                printf("введите элементы для 2ой матрицы:\n");
                matr2=vvodMatr(&stolbci2,&stroki2);
                umnojenieMatr(matr1,matr2,stroki1,stolbci1,stroki2,stolbci2);
                freeMatr(matr1, stroki1);
                freeMatr(matr2, stroki2);
                break;
            case 4:
                printf("введите матрицу:\n");
                matr=vvodMatr(&stolbci,&stroki);
                printf("результат умножения матрицы на число:\n");
                umnojenieMatrNaChislo(matr,stroki,stolbci);
                freeMatr(matr,stroki);
                break;
            case 5:
                printf("введите матрицу:\n");
                matr=vvodMatr(&stolbci,&stroki);
                printf("результат сложения матрицы с числом:\n");
                slojenieMatrSChislom(matr,stroki,stolbci);
                freeMatr(matr,stroki);
                break;
            case 6:
                printf("введите матрицу:\n");
                matr=vvodMatr(&stolbci,&stroki);
                printf("результат вычитания числа из матрицы:\n");
                vichitanieMatrSChislom(matr,stroki,stolbci);
                freeMatr(matr,stroki);
                break;
            case 7:
                printf("введите матрицу:\n");
                matr=vvodMatr(&stolbci,&stroki);
                printf("результат транспонирования матрицы:\n");
                transponirovanieMatr(matr,stroki,stolbci);
                freeMatr(matr,stroki);
                break;
            case 8:
                printf("выберите, какого размера матрицы вы хотите найти определитель?\n");
                printf("1.матрицы 1х1\n");
                printf("2.матрица 2х2\n");
                printf("3.матрица 3х3\n");
                printf("4.матрица 4х4\n");
                n1=proverkaVvoda();
                switch(n1){
                    case 1:
                        do{
                            printf("размеры матрицы:\n");
                            printf("Введите количество строк матрицы: ");
                            stroki=proverkaVvoda();
                            printf("Введите количество столбцов матрицы: ");
                            stolbci=proverkaVvoda();
                            if (stroki!=1 || stolbci!=1){
                                printf("размеры не совпадают");
                            }else{
                                break;
                            }
                            
                        }while(stroki!=1 || stolbci!=1);
                        printf("введите элементы матрицы:\n");
                        matr=vvodMatr(&stolbci,&stroki);
                        opredelitelMatrOdinNaOdin(matr,stroki,stolbci);
                        break;
                    case 2:
                        do{
                            printf("размеры матрицы:\n");
                            printf("Введите количество строк матрицы: ");
                            stroki=proverkaVvoda();
                            printf("Введите количество столбцов матрицы: ");
                            stolbci=proverkaVvoda();
                            if (stroki!=2 || stolbci!=2){
                                printf("размеры не совпадают");
                            }else{
                                break;
                            }
                        }while(stroki!=2 || stolbci!=2);
                        printf("введите элементы матрицы:\n");
                        matr=vvodMatr(&stolbci,&stroki);
                        opredelitelMatrDvaNaDva(matr,stroki,stolbci);
                        break;
                    case 3:
                        do{
                            printf("размеры матрицы:\n");
                            printf("Введите количество строк матрицы: ");
                            stroki=proverkaVvoda();
                            printf("Введите количество столбцов матрицы: ");
                            stolbci=proverkaVvoda();
                            if (stroki!=3 || stolbci!=3){
                                printf("размеры не совпадают");
                            }else{
                                break;
                            }
                        }while(stroki!=3 || stolbci!=3);
                        printf("введите элементы матрицы:\n");
                        matr=vvodMatr(&stolbci,&stroki);
                        opredelitelMatrTriNaTri(matr,stroki,stolbci);
                        break;
                    case 4:
                        do{
                            printf("размеры матрицы:\n");
                            printf("Введите количество строк матрицы: ");
                            stroki=proverkaVvoda();
                            printf("Введите количество столбцов матрицы: ");
                            stolbci=proverkaVvoda();
                            if (stroki!=4 || stolbci!=4){
                                printf("размеры не совпадают");
                            }else{
                                break;
                            }
                        }while(stroki!=4 || stolbci!=4 );
                        printf("введите элементы матрицы:\n");
                        matr=vvodMatr(&stolbci,&stroki);
                        opredelitelMatrChetireNaChetire(matr,stroki,stolbci);
                        freeMatr(matr,stroki);
                        break;
                }while(n1!=0);
            case 9:
                printf("выберите, для какой матрицы вы хотите найти обратную?\n");
                printf("1.матрица 1х1\n");
                printf("2.матрица 2х2\n");
                printf("3.матрица 3х3\n");
                n2=proverkaVvoda();
                switch(n2){
                    case 1:
                        do{
                            printf("размеры матрицы:\n");
                            printf("Введите количество строк матрицы: ");
                            stroki=proverkaVvoda();
                            printf("Введите количество столбцов матрицы: ");
                            stolbci=proverkaVvoda();
                            if (stroki!=1 || stolbci!=1){
                                printf("размеры не совпадают");
                            }else{
                                break;
                            }
                        }while(stroki!=1 || stolbci!=1);
                        printf("введите элементы матрицы:\n");
                        matr=vvodMatr(&stolbci,&stroki);
                        obratnayaMatrDvaNaDva(matr,stroki,stolbci);
                        freeMatr(matr,stroki);
                    break;
                    case 2:
                        do{
                            printf("размеры матрицы:\n");
                            printf("Введите количество строк матрицы: ");
                            stroki=proverkaVvoda();
                            printf("Введите количество столбцов матрицы: ");
                            stolbci=proverkaVvoda();
                            if (stroki!=2 || stolbci!=2){
                                printf("размеры не совпадают");
                            }else{
                                break;
                            }
                        }while(stroki!=2 || stolbci!=2);
                        printf("введите элементы матрицы:\n");
                        matr=vvodMatr(&stolbci,&stroki);
                        obratnayaMatrDvaNaDva(matr,stroki,stolbci);
                        freeMatr(matr,stroki);
                        break;
                    case 3:
                            do{
                                printf("размеры матрицы:\n");
                                printf("Введите количество строк матрицы: ");
                                stroki=proverkaVvoda();
                                printf("Введите количество столбцов матрицы: ");
                                stolbci=proverkaVvoda();
                                if (stroki!=3 || stolbci!=3){
                                    printf("размеры не совпадают");
                                }else{
                                    break;
                                }
                            }while(stroki!=3 || stolbci!=3);
                            printf("введите элементы матрицы:\n");
                            matr=vvodMatr(&stolbci,&stroki);
                            obratnayaMatrDvaNaDva(matr,stroki,stolbci);
                            freeMatr(matr,stroki);
                            break;
                    case 0:
                        break;
                    default:
                        printf("неправильный ввод\n");
                }while(n2!=0);
        }
    }while(n!=0);
}
    




