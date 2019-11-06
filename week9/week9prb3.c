#include <stdio.h>
#include <stdlib.h>

double df1(double);
double f1(double);
double df2(double);
double f2(double);
double newton_method(double, double (*fp)(double), double (*dfp)(double));

int a, b, c, d;

int main() {
    double x01, x02;
    double root1, root2;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    scanf("%lf %lf", &x01, &x02);
    root1 = newton_method(x01, f1, df1);
    root2 = newton_method(x02, f2, df2);
    printf("%lf\n%lf\n", root1, root2);
    return 0;
}

double newton_method(double x0, double (*fp)(double), double (*dfp)(double)){
    return fp(x0)/dfp(x0)>=-0.000001&&fp(x0)/dfp(x0)<=0.000001?x0-fp(x0)/dfp(x0):newton_method(x0-fp(x0)/dfp(x0), fp, dfp);
}

double f1(double x){
    return a*x*x*x + b*x*x + c*x +d;
}

double df1(double x){
    return 3*a*x*x + 2*b*x + c;
}

double f2(double x){
    return b*x*x*x + a*x*x + c*x +d;
}

double df2(double x){
    return 3*b*x*x + 2*a*x + c;
}