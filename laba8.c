#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <ctype.h>

int mygetch()
{
    struct termios oldt, newt;
    int c;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    c = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return c;
}

int main() {
    int count=0;
    while (1 == 1) {
        char a = mygetch();
        if(isalpha(a)) {
            printf("%c", a);
            count++;
            continue;
        }
        else if (a == 27) { //esc
            a = getchar(); // 2 symb
            if (a == '[') { //skobka na klave
                a = getchar(); // 3 symb
                if (a == '5') { // 3 symb = 5
                    break; // eto pageup
                }
                else {
                    ungetc(a, stdin);
                }
            }
            else {
                ungetc(a, stdin);
            }
        }
        else continue;
    }
    printf("\n");
    printf("kolichestvo vvedennih bukv %d\n", count);
    return 0;
}
