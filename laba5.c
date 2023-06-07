#include <stdio.h>

int bobik(int num,int del) {
    if(del == 1) return 1;
    else {
        if (num % del == 0) return 0;
        else return bobik(num,del - 1);;
    }
}

int main() {
    int num;
    printf("Vvedite chislo -> ");
    scanf("%d", &num);

    if(num == 1) printf("Chislo ne prostoe(cycle,recurs)\n");
    else if(num == 2) printf("Chislo prostoe(cycle,recurs)\n");
    else if(num % 2 == 0) printf("Chislo ne prostoe(cycle,recurs)\n");
    else {
        int del = (num+1)/2-1;

        if(bobik(num,del) == 1) printf("Chislo prostoe(recurs)\n");
        else printf("Chislo ne prostoe(recurs)\n");

        for (int i = (num+1) / 2;i!=1;i--) {
            if(num % i == 0) {
                printf("Chislo ne prostoe(cycle)\n");
                return 0;
            }
            else continue;
        }
        printf("Chislo prostoe(cycle)\n");
    }
    return 0;
}