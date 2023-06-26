#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char str[200];
    printf("Введите любые слова через пробел, завершить ввод нажатием ENTER: ");
    fgets(str, 200, stdin);
    char *leks = strtok(str, " ");
    int count = 0;
    while (leks != NULL) {
        int len = strlen(leks);
        for (int i = 0; i < len; i++) {
            if ((i == count) && (isalpha(leks[i]))) {
                printf("%c\n", leks[i]);
            }
        }
        leks = strtok(NULL, " ");
        count++;
    }
    return 0;
}
