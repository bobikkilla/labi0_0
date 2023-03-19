#include <stdio.h>

int main() {
    int a, b, c, x;
    printf("Enter a -> "); scanf("%d", &a);
    printf("Enter b -> "); scanf("%d", &b);
    printf("Enter c -> "); scanf("%d", &c);
    printf("Enter x -> "); scanf("%d", &x);
    int min = a;
   
    if(b <= c && min >= b) {
        min = b;
        if ((min <= x) && ((min % 7) == 0)) {
            printf("%d\n", min);
            }
        printf("%.2lf", (float)min/((float)b+(float)c));
        return 0;
        }
       
    else if (b >= c && min >= c) {
        min = c;
        if ((min <= x) && ((min % 7) == 0)) {
            printf("%d\n", min);
            }
        printf("%.3lf ", (float)min/((float)b+(float)c));
        return 0;
        }
   
    if ((min <= x) && ((min % 7) == 0)) {
        printf("%d\n", min);
        }
        printf("%.2lf", (float)min/((float)b+(float)c));
    return 0;
}