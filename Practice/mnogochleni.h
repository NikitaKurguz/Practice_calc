#ifndef MNOGOCHLENI_H
#define MNOGOCHLENI_H
struct Del_mnog
{
    double* kefs_z;
    double* kefs_ost;
    int st_z;
    int st_ost;
};
void run_calc();
int Input_n();
double Input_a();
void Output_mnog(double* kefs, int n);
double* Input_mnog(int n);
double* type1(int st1, int st2, double* kefs1, double* kefs2);
double* type2(int st1, int st2, double* kefs1, double* kefs2);
double* type3(int st1, double* kefs1, double a);
double* type4(int& st1, double* kefs1);
Del_mnog type5(double* kefs1, int st1, double* kefs2, int st2);
#endif //MNOGOCHLENI_H