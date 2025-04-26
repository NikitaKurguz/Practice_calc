double vvodMatr(int stroki,int stolbci);
double vvodMatr1(int *stolbci,int *stroki);
double vvodMatr2(int *stolbci1,int *stroki1);
void freeMatr(double **matr, int stroki);
void proverkaVvoda();
double proverkaVvoda1();
void vivodMatr(double **matr,int stroki,int stolbci);
void slojenieMatr(double **matr1,double **matr2,int stolbci,int stroki,int stroki1,int stolbci1);
void vichitanieMatr(double **matr1,double **matr2,int stolbci,int stroki);
void umnojenieMatr(double **matr1,double **matr2,int stroki1,int stolbci1,int stroki2,int stolbci2);
void umnojenieMatrNaChislo(double **matr,int stroki,int stolbci,int chislo);
void slojenieMatrSChislom(double **matr,int stroki,int stolbci);
void vichitanieMatrSChislom(double **matr,int stroki,int stolbci);
void transponirovanieMatr(double **matr,int stroki,int stolbci);
void opredelitelMatrOdinNaOdin(double **matr,int stroki,int stolbci);
void opredelitelMatrDvaNaDva(double **matr,int stroki,int stolbci);
void opredelitelMatrTriNaTri(double **matr,int stroki,int stolbci);
void opredelitelMatrChetireNaChetire(double **matr,int stroki,int stolbci);
void obrtnayaMatrOdinNaOdin(double **matr,int stroki,int stolbci);
void obratnayaMatrDvaNaDva(double **matr,int stroki,int stolbci);
void obratnayaMatrTriNaTri(double **matr,int stroki,int stolbci);
void menu();



