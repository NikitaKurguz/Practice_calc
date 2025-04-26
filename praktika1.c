#include <stdio.h>
#include "praktika1.h"
#include <stdlib.h>
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
void mNaN(double m,double n){
    double res;
    if (m>n){
        printf("m не может быть > n");
    }
    if(n<0 || m<0){
        printf("не могут быть отрицательными");
    }
    if(n==0){
        printf("нельзя делить на ноль");
    }
    res=m/n;
    printf("результат = %.2lf",res);
}
void menu(){
    double m,n;
    int o;
    do{
        printf("меню выбора для теории вероятности\n");
        printf("1.вероятность m/n\n");
        printf("0.выход\n");
        o=proverkaVvoda();
        switch(o){
            case 1:
                do{
                    printf("введите число благоприятных исходов(m)\n");
                    m=proverkaVvoda1();
                    if (m<0 || m==0){
                        printf("данные введены некорректно\n");
                    }
                }while (m<0 || m==0);
                do{
                    printf("введите число всех исходов(n)\n");
                    n=proverkaVvoda1();
                    if (n==0 || m>n || n<0 ||m<0){
                        printf("данные введены некорректно\n");
                    }
                }while (n==0 || m>n || n<0 ||m<0);
                mNaN(m,n);
                break;
        }
    }while (o!=0);
}

