#include <stdio.h>
#include <string.h>

#define MAX_FRIENDS 100

typedef struct {
    char surname[50];
    char name[50];
    char otch[50];
    int day;
    int month;
    int year;
    char address[100];
    char phone[20];
} Friend;

int num_friends = 0;
Friend friends[MAX_FRIENDS];

void add_friend() {
    if (num_friends >= MAX_FRIENDS) {
        printf("Список друзей полон\n");
        return;
    }
    Friend friend;
    printf("Введите фамилию друга -> ");
    scanf("%s", friend.surname);
    printf("Введите имя друга -> ");
    scanf("%s", friend.name);
    printf("Введите отчество друга -> ");
    scanf("%s", friend.otch);
    printf("Введите день рождения -> ");
    scanf("%d", &friend.day);
    printf("Введите месяц рождения -> ");
    scanf("%d", &friend.month);
    printf("Введите год рождения -> ");
    scanf("%d", &friend.year);
    printf("Введите адрес друга -> ");
    scanf("%s", friend.address);
    printf("Введите телефон друга -> ");
    scanf("%s", friend.phone);
    friends[num_friends++] = friend;
    FILE *file = fopen("friends.txt", "a");
    fprintf(file, "%s %s %s %d %d %d %s %s\n", friend.surname, friend.name, friend.otch,
            friend.day, friend.month, friend.year, friend.address, friend.phone);
    fclose(file);
    printf("Друг добавлен в список\n");
}

void remove_friend() {
    char name[50];
    printf("Введите имя друга для удаления -> ");
    scanf("%s", name);
    int i;
    for (i = 0; i < num_friends; i++) {
        if (strcmp(friends[i].name, name) == 0) {
            break;
        }
    }
    if (i == num_friends) {
        printf("Друг не найден в списке\n");
        return;
    }
    for (int j = i; j < num_friends - 1; j++) {
        friends[j] = friends[j + 1];
    }
    num_friends--;
    FILE *file = fopen("friends.txt", "w");
    for (int j = 0; j < num_friends; j++) {
        Friend friend = friends[j];
        fprintf(file, "%s %s %s %d %d %d %s %s\n", friend.surname, friend.name, friend.otch, friend.day, friend.month, friend.year, friend.address, friend.phone);
    }
    fclose(file);
    printf("Друг удален из списка\n");
}

void list_friends() {
    FILE *file = fopen("friends.txt", "r");
    if (file == NULL) {
        printf("Список друзей пуст\n");
        return;
    }
    char surname[50], name[50], otch[50], address[100], phone[20];
    int day, month, year;
    printf("Список друзей:\n");
    while (fscanf(file, "%s %s %s %d %d %d %s %s", surname, name, otch, &day, &month, &year, address, phone) == 8) {
        printf("%s %s %s, %d.%d.%d, %s, %s\n", surname, name, otch, day, month, year, address, phone);
    }
    fclose(file);
    if (num_friends == 0) {
        printf("Список друзей пуст\n");
    }
}

void find_friends_by_month(int month) {
    FILE *file = fopen("friends.txt", "r");
    if (file == NULL) {
        printf("Список друзей пуст\n");
        return;
    }
    if (month <= 0 || month >= 13) {
        printf("Номер месяца введён неверно.\n");
        fclose(file);
        return;
    }
    char mon_str[3];
    sprintf(mon_str, "%02d", month);  // переводим номер месяца в строку
    char surname[50], name[50], otch[50], address[100], phone[20];
    int day, m, year;
    int found_friends = 0;
    while (fscanf(file, "%s %s %s %d %d %d %s %s", surname, name, otch, &day, &m, &year, address, phone) == 8) {
        if (m == month) {
            printf("%s %s %s, %d.%d.%d, %s, %s\n", surname, name, otch, day, m, year, address, phone);
            found_friends++;
        }
    }
    fclose(file);
    if (found_friends == 0) {
        printf("Друзья, родившиеся в этом месяце, не найдены\n");
    }
}

int main() {
    int act;
        printf("1 - Добавить друга\n");
        printf("2 - Удалить друга\n");
        printf("3 - Список друзей\n");
        printf("4 - Поиск друзей по месяцу рождения\n");
        printf("Выберите действие -> ");
        scanf("%d", &act);
        switch (act) {
            case 1: add_friend(); break;
            case 2: remove_friend(); break;
            case 3: list_friends(); break;
            case 4:
                int month;
                printf("Введите номер месяца для поиска(в формате 1,2,3...11,12) -> ");
                scanf("%d", &month);
                find_friends_by_month(month);
                break;
            default:
                printf("Неверный выбор\n");
        }
    return 0;
}
