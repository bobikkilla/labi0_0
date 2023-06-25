#include <stdio.h>
#include <string.h>
int main()
{
    char str[200];
    for(int i=0;i<200;i++) {
        scanf("%c", &str[i]);
        printf("%c", str[i]);
        if(str[i] == '\n') break;
    }
    char * leks = strtok(str, " ");
    int count = 0;
    while(leks != NULL) {
        printf("%c\n", leks[count]);
        count++;
        leks = strtok(NULL, " ");
    }
    return 0;
}