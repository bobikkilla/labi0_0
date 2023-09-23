#include <stdio.h>
#include <string.h>

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
Friend friends[20];

void read_from_file() {
    FILE *file = fopen("friends.txt", "r");
    if (file == NULL) {
        printf("Empty\n");
        return;
    }
    while (fscanf(file, "%s %s %s %d %d %d %s %s",
           friends[num_friends].surname,
           friends[num_friends].name,
           friends[num_friends].otch,
           &friends[num_friends].day,
           &friends[num_friends].month,
           &friends[num_friends].year,
           friends[num_friends].address,
           friends[num_friends].phone) == 8) {
        num_friends++;
    }
    fclose(file);
}

void write_to_file() {
    FILE *file = fopen("friends.txt", "w");
    for (int i = 0; i < num_friends; i++) {
        fprintf(file, "%s %s %s %d %d %d %s %s\n",
                friends[i].surname,
                friends[i].name,
                friends[i].otch,
                friends[i].day,
                friends[i].month,
                friends[i].year,
                friends[i].address,
                friends[i].phone);
    }
    fclose(file);
}

void add_friend() {
    if (num_friends >= 20) {
        printf("List is full\n");
        return;
    }
    Friend friend;
    printf("Surname -> ");
    scanf("%s", friend.surname);
    printf("Name -> ");
    scanf("%s", friend.name);
    printf("Patronymic-> ");
    scanf("%s", friend.otch);

    printf("Birth day -> ");        // correct day
    while(1) {
        scanf("%d", &friend.day);
        if(friend.day <=31 && friend.day >= 1) break;
        else {
            printf("Incorrect day! Try again!\n");
            printf("Birth day -> ");
        }
    }

    printf("Birth month -> ");      // correct month
    while(1) {
        scanf("%d", &friend.month);
        if(friend.month<=12 && friend.month>=1) {
            break;
        }
        else { printf("Incorrect month! Try again!\n");
        printf("Birth month -> ");
        }
    }

    printf("Birth year -> ");       // correct year
    while(1) {
        scanf("%d", &friend.year);
        if(friend.year <= 2008 && friend.year >= 1900) break;
        else { printf("Incorrect year! Try again!\n");
            printf("Birth year -> ");
        }
    }

    printf("Address ->");
    while (getchar() != '\n');
    fgets(friend.address, sizeof(friend.address), stdin);
    friend.address[strcspn(friend.address, "\n")] = '\0';
    printf("Phone number -> ");
    scanf("%s", friend.phone);
    friends[num_friends++] = friend;
    write_to_file();
    printf("Friend added!\n");
}

void remove_friend() {
    char name[50];
    printf("Enter friend's name to delete -> ");
    scanf("%s", name);
    int i;
    for (i = 0; i < num_friends; i++) {
        if (strcmp(friends[i].name, name) == 0) {
            break;
        }
    }
    if (i == num_friends) {
        printf("No matches\n");
        return;
    }
    for (int j = i; j < num_friends - 1; j++) {
        friends[j] = friends[j + 1];
    }
    num_friends--;
    write_to_file();
    printf("Deleted\n");
}

void list_friends() {
    if (num_friends == 0) {
        printf("Empty\n");
        return;
    }
    printf("Friend's list:\n");
    for (int i = 0; i < num_friends; i++) {
        printf("%s %s %s, %d.%d.%d, %s, %s\n",
               friends[i].surname,
               friends[i].name,
               friends[i].otch,
               friends[i].day,
               friends[i].month,
               friends[i].year,
               friends[i].address,
               friends[i].phone);
    }
}

void find_friends_by_month(int month) {
    if (month <= 0 || month >= 13) {
        printf("Month is wrong!\n");
        return;
    }
    int found_friends = 0;
    printf("Friends born in month %d:\n", month);
    for (int i = 0; i < num_friends; i++) {
        if (friends[i].month == month) {
            printf("%s %s %s, %d.%d.%d, %s, %s\n",
                   friends[i].surname,
                   friends[i].name,
                   friends[i].otch,
                   friends[i].day,
                   friends[i].month,
                   friends[i].year,
                   friends[i].address,
                   friends[i].phone);
            found_friends++;
        }
    }
    if (found_friends == 0) {
        printf("Not found\n");
    }
}

int main() {
    read_from_file();

    while (1) {
        int choice, month;
        printf("1. List all friends\n");
        printf("2. Add a friend\n");
        printf("3. Remove a friend\n");
        printf("4. Find friends by month\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                list_friends();
                break;
            case 2:
                add_friend();
                break;
            case 3:
                remove_friend();
                break;
            case 4:
                printf("Enter a month: ");
                scanf("%d", &month);
                find_friends_by_month(month);
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice\n");
        }
        printf("\n");
    }
}
