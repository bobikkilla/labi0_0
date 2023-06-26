#include <stdio.h>
#include "string.h"

struct friend {
    char surname[50];       // Фамилия
    char name[50];          // Имя
    char otchestvo[50];    // Отчество
    char birthday[15];      // Дата рождения
    char address[100];      // Адрес
    char phone[20];         // Телефон
};

int main() {
    struct friend nick  = {"wazowski", "nick", "nickovich", "23.01.2002", "prospekt lenina", "+79682054141"};
    struct friend fedya = {"pushkin", "fedya", "vasilevich", "05.04.2004", "mayakovskogo street", "+79682052288"};
    struct friend katya = {"sushina", "katya", "alekseevna", "14.08.2004", "mayakovskogo street", "+79682054629"};
    struct friend vitya = {"wazowski", "vitya", "nickovich", "05.01.2002", "prospekt leninskii", "+79682054141"};
    struct friend petya = {"pushkin", "petya", "vasilevich", "30.04.2004", "mayakovskogo street", "+79682052288"};
    struct friend anya  = {"sushina", "anya", "alekseevna", "08.08.2004", "mayakovskogo street", "+79682054629"};
    printf("Введите номер месяц для поиска(в формате 1,2,3...11,12) -> ");
    int month;
    scanf("%d",&month);
    if(month<=0 || month >=13) {
        printf("Номер месяца введён неверно.\n"); // ошибка
        return 0;
    }
    char mon_str[3];
    sprintf(mon_str, "%02d", month);  // переводим номер месяца в строку
    printf("\n");
    struct friend friends[] = {nick, fedya, katya, vitya, petya, anya};
    for(int i=0; i<6; i++) {  //поиск друзей по месяцу
        char birthday_copy[15];
        strcpy(birthday_copy, friends[i].birthday);
        char *birth_month_str = strtok(birthday_copy, ".");
        birth_month_str = strtok(NULL, ".");
        if (strcmp(birth_month_str, mon_str) == 0) {
            printf("Фамилия: %s\n", friends[i].surname);
            printf("Имя: %s\n", friends[i].name);
            printf("Отчество: %s\n", friends[i].otchestvo);
            printf("Дата рождения: %s\n", friends[i].birthday);
            printf("Адрес: %s\n", friends[i].address);
            printf("Телефон: %s\n", friends[i].phone);
            printf("\n");
        }
    }
    return 0;
}