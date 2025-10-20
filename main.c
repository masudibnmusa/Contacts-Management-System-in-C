#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CONTACTS 100
#define MAX_LENGTH 100
#define FILE_NAME "contacts.txt"

typedef struct {
    char name[MAX_LENGTH];
    char phone[MAX_LENGTH];
    char street[MAX_LENGTH];
    char email[MAX_LENGTH];
} Contact;

void clearScreen() {
    // Windows
    system("cls");
    // For Linux/macOS, uncomment the next line and comment the above:
    // system("clear");
}

void saveContacts(Contact contacts[], int count) {
    FILE *fp = fopen(FILE_NAME, "w");
    if (fp == NULL) {
        printf("Error opening file for writing!\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(fp, "%s\n%s\n%s\n%s\n",
                contacts[i].name,
                contacts[i].phone,
                contacts[i].street,
                contacts[i].email);
    }

    fclose(fp);
}

int loadContacts(Contact contacts[]) {
    FILE *fp = fopen(FILE_NAME, "r");
    if (fp == NULL) {
        // No file exists yet, so 0 contacts loaded
        return 0;
    }

    int count = 0;
    while (count < MAX_CONTACTS &&
           fgets(contacts[count].name, MAX_LENGTH, fp) != NULL &&
           fgets(contacts[count].phone, MAX_LENGTH, fp) != NULL &&
           fgets(contacts[count].street, MAX_LENGTH, fp) != NULL &&
           fgets(contacts[count].email, MAX_LENGTH, fp) != NULL) {

        // Remove trailing newline characters
        contacts[count].name[strcspn(contacts[count].name, "\n")] = 0;
        contacts[count].phone[strcspn(contacts[count].phone, "\n")] = 0;
        contacts[count].street[strcspn(contacts[count].street, "\n")] = 0;
        contacts[count].email[strcspn(contacts[count].email, "\n")] = 0;

        count++;
    }

    fclose(fp);
    return count;
}

void addContact(Contact contacts[], int *count) {
    if (*count >= MAX_CONTACTS) {
        printf("Contact list full!\n");
        return;
    }

    printf("Enter name: ");
    fgets(contacts[*count].name, MAX_LENGTH, stdin);
    contacts[*count].name[strcspn(contacts[*count].name, "\n")] = 0;

    printf("Enter phone number: ");
    fgets(contacts[*count].phone, MAX_LENGTH, stdin);
    contacts[*count].phone[strcspn(contacts[*count].phone, "\n")] = 0;

    printf("Enter street address: ");
    fgets(contacts[*count].street, MAX_LENGTH, stdin);
    contacts[*count].street[strcspn(contacts[*count].street, "\n")] = 0;

    printf("Enter email address: ");
    fgets(contacts[*count].email, MAX_LENGTH, stdin);
    contacts[*count].email[strcspn(contacts[*count].email, "\n")] = 0;

    (*count)++;
    saveContacts(contacts, *count); // Save after adding new contact

    printf("Contact added successfully!\n\n");
}

void displayContacts(Contact contacts[], int count) {
    if (count == 0) {
        printf("No contacts to display.\n\n");
        return;
    }

    printf("\n----- Contacts List -----\n");
    for (int i = 0; i < count; i++) {
        printf("Contact %d:\n", i + 1);
        printf("Name: %s\n", contacts[i].name);
        printf("Phone: %s\n", contacts[i].phone);
        printf("Street: %s\n", contacts[i].street);
        printf("Email: %s\n\n", contacts[i].email);
    }
}

int main() {
    Contact contacts[MAX_CONTACTS];
    int count = 0;
    int choice;

    count = loadContacts(contacts); // Load contacts from file at startup

    while (1) {
        clearScreen();
        printf("Contacts Management System\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);
        getchar();  // consume newline

        clearScreen();

        switch (choice) {
            case 1:
                addContact(contacts, &count);
                break;
            case 2:
                displayContacts(contacts, count);
                printf("Press Enter to continue...");
                getchar();
                break;
            case 3:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice! Please enter 1, 2, or 3.\n");
                printf("Press Enter to continue...");
                getchar();
        }
    }

    return 0;
}

