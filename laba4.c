#include <stdio.h>
#include <math.h>

double func(double a) {
    if(a>=0 && a<=1) return cos(a)*exp(-pow(a,2));
    else if(a>1 && a<=2) return log(a+1)-sqrt(4-pow(a,2));
    else return 0.0;
}

double runge(double a, double b) { 
    return (a-b)/3;
}
int main() {
    double x=0, I1=0, I2=0;
    int n=pow(2,10);
    double h = 2./n;
    for(int i=0;i<=n;i++) {
        I1+=func(x+i*h/2);
    }
    for(int i=0;i<=n*2;i++) {
        I2+=func(x+i*(h/4));
    }
    I1*=h; I2*=h/2;
    printf("%lf\t%lf", I1, I2);
    return 0;
}
