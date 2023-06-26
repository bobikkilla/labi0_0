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
    double eps=0;
    printf("Print innacuracy max rate -> ");
    scanf("%lf", &eps);

    double x=0, I1=0, I2=0,i=0;
    do {
        long int n = pow(2,i);
        double h = 2./n;
        for(int i=0;i<=n*2;i++) {
            if(i<=n) I1+=func(x+i*h/2);
            I2+=func(x+i*(h/4));
        }
        I1*=h; I2*=h/2; i++;
        printf("if n = %ld, runge innacuracy = %.7lf, I= %.7lf\n", n,  runge(I1,I2),I2);
    } while(runge(I1,I2)>eps);
    return 0;
}
