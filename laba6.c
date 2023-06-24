#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fill(int n, int A[]) { //func zapoln massiva
    int i;
    for (i = 0; i < n; i++)
        A[i] = rand () % 101 - 50;
}

int main() {
    srand(time(NULL));
    int n;
    printf("n (n>=3) -> ");
    scanf("%d", &n);
    if(n<3) {   // uslovie raboti programmi
        printf("error 228\n");
        return 0;
    }
    int mass[n];  // init massiva
    fill(n, mass);
    int i;
    for (i = 0; i < n; i++)  //vivod massiva
        printf("%4d", mass[i]);
    printf("\n");

    int max1=-51, max2=-51, max3=-51;
    for (i = 0; i < n; i++) {  //nahodim idx max elementov massiva
        if (mass[i] > max1) {
            max3 = max2;
            max2 = max1;
            max1 = i;
        } else if (mass[i] > max2) {
            max3 = max2;
            max2 = i;
        } else if (mass[i] > max3) {
            max3 = i;
        }
    }
    printf("max elements: %4d %4d %4d\n", max1,max2,max3);  // index max elemov

    int sum=mass[max1]+mass[max2]+mass[max3], prod=mass[max1]*mass[max2]*mass[max3];  //последние вычисления
    printf("Summa = %d, proizvedenie = %d, raznost prod & sum = %d\n", sum, prod, prod-sum);
    printf("суммa их индексов по модулю %d = %d\n", n, (max1+max2+max3)%n);
    return 0;
}