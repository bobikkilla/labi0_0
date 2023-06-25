#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fill(int n,int m, int *A) {
    for(int i=0;i<n*m;i++) {
        *(A+i) = rand() % 200 - 99;
    }
}

int main() {
    srand(time(NULL));
    int n=0,m=0;
    printf("Введите размер массива NxM -> ");
    scanf("%d %d", &n, &m);
    int *A = malloc(n*m*sizeof(int));
    if(!A) {
        printf("Memory fail\n");
        return 0;
    }
    fill(n,m,A); //zapoln massiv

    for(int i=0;i<n;i++) {
        for(int k=0;k<m;k++) {
            printf("%4d", *(A+i*m+k));
        }
        printf("\n"); }  // vivod massiva
    if(n==m) {
        int sled = 0;
        for(int i=0;i<n;i++) {  //ch sled
            sled += *(A+i*n+i);
        }
        printf("Частное следа квадратной матрицы = %d\n",sled);

        int *summ = malloc(n*sizeof(int)); // massiv s summami
        if(!summ) {
            printf("Memory fail\n");
            return 0;
        }
        int m_summ = 0; //indx sum
        for(int i=0;i<n;i++) { //sum skal proizv
            int sum = 0;
            for(int k=0;k<n;k++) {
                sum += *(A+i*m+k) * *(A+k*m+i);
            }
            *(summ+m_summ) = sum; //summa v massiv
            m_summ++;
        }

        printf("Суммы скалярных произведений соответствующих столбцов и строк матрицы равны:\n");
        for(int i=0;i<n;i++) {
            printf("%d  ", *(summ+i));
        }
        printf("\n");
        free(summ);
    }
    free(A);
    return 0;
}