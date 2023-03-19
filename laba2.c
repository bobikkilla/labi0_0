#include <stdio.h>
#include <math.h>

int main() {
    double x,y,z;
    scanf("%lf", &x);
        if(log2(2.-sqrt(3))<=x && x<=log2(2.+sqrt(3))) {
            y = (pow(2,x)+pow(2,-x))/2.;
            z = sqrt(2+y-pow(y,2));
            printf("x = %lf\n", x);
            printf("y(x) = %lf\n", y);
            printf("z(y) = %lf\n", z);
        }
        else {
            printf("x value is incorrect!\n");
        }
    return 0;
}
