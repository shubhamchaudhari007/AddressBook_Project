#include <stdio.h>
#include "contact.h"

/*

Name : Shubham Sanjay Chaudhari
Date : 17_09_2025
Batch Id: 25021C_306
language : C programming
Project :

  Address Book Project
  --------------------
  A simple and interactive C program to manage your personal or professional contacts.
 
  Project Overview:
    - This application allows users to store, search, edit, and delete contact information.
    - Each contact consists of a name, phone number, and email address.
    - All contacts are stored in memory and can be saved to a file for future use.
 
  Main Features:
    1. Create Contact: Add a new contact with validation for unique phone and email.
    2. Search Contact: Find contacts by name, phone, or email with flexible matching.
    3. Edit Contact: Update the name, phone, or email of an existing contact.
    4. Delete Contact: Remove a contact from the address book.
    5. List All Contacts: Display all saved contacts in a formatted table.
    6. Save Contacts: Write all contacts to a file for persistence.
    7. Exit: Quit the program safely.
 
  Usage Instructions:
    - Run the program and follow the on-screen menu.
    - Input is validated to prevent duplicate phone numbers and emails.
    - Data is saved to a file so you can retrieve your contacts later.
 
  File Structure:
    - main.c: Contains the main menu and program loop.
    - contact.c/h: Core logic for contact management (create, edit, delete, validate).
    - searchsort.c: Functions for searching and sorting contacts.
    - file.c/h: Handles saving and loading contacts from a file.
 
  Extensibility:
    - The code is modular and can be extended to support more fields (e.g., address, birthday).
    - Additional features like import/export, group contacts, or UI enhancements can be added.
 
  Suitable For:
    - Students learning C programming and file handling.
    - Anyone needing a basic, menu-driven contact manager.
  
 */
int main()
{
    int choice;
    AddressBook addressBook;
    initialize(&addressBook); // Initialize the address book

    do
    {
        printf("\nAddress Book Menu:\n");
        printf("1. Create contact\n");
        printf("2. Search contact\n");
        printf("3. Edit contact\n");
        printf("4. Delete contact\n");
        printf("5. List all contacts\n");
        printf("6. Save contacts\n");
        printf("7. Exit\n");
        printf("Enter your choice (1-8): ");
        scanf("%d", &choice);
        while(getchar() != '\n');
        switch (choice)
        {
        case 1:
            createContact(&addressBook);
            break;
        case 2:
            searchContact(&addressBook);
            break;
        case 3:
            editContact(&addressBook);
            break;
        case 4:
            deleteContact(&addressBook);
            break;
        case 5:
            listContacts(&addressBook);
            break;
        case 6:
            printf("Saving...\n");
            saveContactsToFile(&addressBook);
            break;
        case 7:
            break;
        default:
            printf("❌Invalid choice. Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}
