#include <stdio.h>
#include <math.h>

double func(double a) {
    return cos(a*M_PI/180)*exp(pow(-a,2));
}

double func1(double a) {
    return log(a+1)-sqrt(4-pow(a,2));
}

int main() {
    double h=0, x=0;
    printf("shag X h=");
    scanf("%lf", &h);
    printf("\n   x          f(x)\n");
    printf("--------------------\n");
    
    while(x<=1) {
        printf("%.6lf   %.6lf\n",x, func(x));
        x+=h;
    }
    
    for(double i=x;i<=2;i+=h) {
        printf("%.6lf   %.6lf\n", i, func1(i));
    }
    printf("%.6lf   %.6lf\n", 2.000000, func1(2));
  
    return 0;
}
