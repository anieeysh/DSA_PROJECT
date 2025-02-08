#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char name[100];
    int age;
    char address[100];
    int phone;
    char bloodgroup[100];
    int reg;
    int priority;
    struct node *next;
};

struct node *start = NULL;

struct node *insert(struct node *);
struct node *deleteRecord(struct node *);
void display(struct node *);
void table();

int main() {
    int option;
    do {
        printf("\t\t\t-------------------------------\n");
        printf("\t\t\t WELCOME TO CURE HOSPITAL!\n");
        printf("\t\t\t-------------------------------\n");
        printf("\t\t\t1. ADD A PATIENT\n");
        printf("\t\t\t2. DELETE A RECORD\n");
        printf("\t\t\t3. DISPLAY ALL APPOINTMENTS\n");
        printf("\t\t\t4. EXIT\n");
        printf("\t\t\tEnter your choice: ");
        scanf("%d", &option);
        getchar(); // Consume newline left in buffer

        switch (option) {
            case 1:
                start = insert(start);
                break;
            case 2:
                start = deleteRecord(start);
                break;
            case 3:
                display(start);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (option != 4);
}

struct node *insert(struct node *start) {
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    
    printf("Enter patient Name: ");
    scanf("%99s", ptr->name);

    printf("Enter the patient's age: ");
    scanf("%d", &ptr->age);
    getchar();

    printf("Enter your home address: ");
    fgets(ptr->address, 100, stdin);
    strtok(ptr->address, "\n"); // Remove newline character

    printf("Enter your phone number: ");
    scanf("%d", &ptr->phone);
    getchar();

    printf("Enter the blood group of Patient: ");
    scanf("%99s", ptr->bloodgroup);

    printf("Enter the reg no: ");
    scanf("%d", &ptr->reg);

    printf("Enter your disease Number:\n");
    table();
    scanf("%d", &ptr->priority);
    
    ptr->next = NULL;

    if (start == NULL || ptr->priority < start->priority) {
        ptr->next = start;
        start = ptr;
    } else {
        struct node *p = start;
        while (p->next != NULL && p->next->priority <= ptr->priority)
            p = p->next;
        ptr->next = p->next;
        p->next = ptr;
    }
    return start;
}

struct node *deleteRecord(struct node *start) {
    if (start == NULL) {
        printf("\n NO PATIENT RECORD TO DELETE\n");
        return start;
    } else {
        struct node *ptr = start;
        printf("\n Deleted Record is : %d\n", ptr->reg);
        start = start->next;
        free(ptr);
    }
    return start;
}

void display(struct node *start) {
    if (start == NULL) {
        printf("\nTHERE IS NO PATIENT\n");
    } else {
        printf("\nPriority wise appointments are:\n");
        struct node *ptr = start;
        while (ptr != NULL) {
            printf("The name of patient is: %s\n", ptr->name);
            printf("The age of patient is: %d\n", ptr->age);
            printf("The address of patient is: %s\n", ptr->address);
            printf("Phone Number: %d\n", ptr->phone);
            printf("The blood group of patient is: %s\n", ptr->bloodgroup);
            printf("---------------------------------------------------\n");
            ptr = ptr->next;
        }
    }
}

void table() {
    printf("\t\tPlease Refer to this Table for your disease!\n");
    printf("1. Heart attack\n");
    printf("2. Severe wound/Bleeding\n");
    printf("3. Cancer\n");
    printf("4. Chest pain\n");
    printf("5. Fracture\n");
    printf("6. Diabetes Checkup\n");
    printf("7. Infection\n");
    printf("8. Viral Fever\n");
    printf("9. Common Cold/Headache\n");
}
