#include <stdio.h>
#include <math.h>

double func(double a) {
    if(a>=0 && a<=1.000001) return cos(a)*exp(-pow(a,2));
    else if(a>1.000001 && a<=2) return log(a+1)-sqrt(4-pow(a,2));
    else return 0.0;
}

double runge(double a, double b) { 
    return (a-b)/3;
}
int main() {
    double eps;
    printf("Print innacuracy max rate -> ");
    scanf("%lf", &eps);
    double x=0, I1=0, I2=0;
    for(int i=0;i<=30;i++){
        long int n=pow(2,i);
        double h = 2./n;
        for(int i=0;i<=n;i++) {
            I1+=func(x+i*h/2);
        }
        for(int i=0;i<=n*2;i++) {
            I2+=func(x+i*(h/4));
        }
        I1*=h; I2*=h/2;
        printf("if n = %ld, runge innacuracy = %.7lf\n", n,  runge(I1,I2));
        if(runge(I1,I2)<eps) return 0;
    }
    return 0;
}
