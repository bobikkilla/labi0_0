#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fill(int n,int m, int A[][m]) { //zapolnenie
    for(int i=0;i<n;i++) {
        for(int k=0;k<m;k++) {
            A[i][k] = rand () % 200- 99;
        }
    }
}

int main() {
    srand(time(NULL));
    int n=0,m=0;
    printf("Введите размер массива NxM -> ");
    scanf("%d %d", &n, &m);
    int A[n][m];
    fill(n,m,A); //init massiva

    for(int i=0;i<n;i++) {
        for(int k=0;k<m;k++) {
            printf("%4d", A[i][k]);
        }
        printf("\n");
    } //vivod massiva
    if(n!=m) return 0;
    else {
        int sled = 0;
        for(int i=0;i<n;i++) {  //chastnoe sleda
            sled+=A[i][i];
        }
        printf("Частное следа квадратной матрицы = %d\n",sled);

        int summ[n];
        for(int i=0;i<n;i++) {  //summa skal proizvedenii
            for(int m=0;m<n;m++) {
                summ[m] = 0;
                summ[m]+=A[i][m]*A[m][i];
            }
        }

        printf("Cуммы скалярных произведений соответствующих столбцов и строк матрицы равны:\n");
        for(int i=0;i<n;i++) {
            printf("%d  ", summ[i]);
        }
        printf("\n"); //не уверен насчёт постановки задачи, но скалярные произведения строк и столбцов матрицы
    }                        //будут представлены в виде матриц[n][1]. А если матрица, где n!=m, то задание невыполнимо
    return 0;
}