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
        if((c > 0x3A && c <= 0x53) && (c!=0x49))  return '\0';
    return c;
}

int main() {
    int count = 0;
    while (1) {
        char a = mygetch();
        if (isalpha(a)) {
            printf("%c", a);
            count++;
        }
        else if (a == 27) { // esc
            a = mygetch(); // 2 символ
            if (a == '[') { // скобка на клаве
                a = mygetch(); // 3 символ
                if (a == '5') { // 3 символ = 5
                    printf("\n");
                    printf("Количество введенных букв: %d\n", count);
                    return 0; // это PageUp
                }
                else {
                    ungetc(a, stdin);
                }
            }
            else {
                ungetc(a, stdin);
            }
        }
    }
    return 0;
}
