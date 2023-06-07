#include <stdio.h>
#include <math.h>

double func(double a) {
    return cos(a*M_PI/180)*exp(-pow(a,2));
}

double func1(double a) {
    return log(a+1)-sqrt(4-pow(a,2));
}

int main() {
    double h=0;
    int count = 0;
    printf("shag X h=");
    scanf("%lf", &h);
    printf("\n   x          f(x)\n");
    printf("--------------------\n");

    while(count<=(1/h)) {
        printf("%.6lf   %.6lf\n",count*h, func(count*h));
        count++;
    }

    for(count; count<=(2/h);count++) {
        printf("%.6lf   %.6lf\n", count*h, func1(count*h));
    }
    return 0;
}
