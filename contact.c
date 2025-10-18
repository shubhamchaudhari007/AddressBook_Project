#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"

extern int contactindex[20];

// Check if the phone number already exists in the address book (returns 0 if duplicate, 1 if unique)
int duplicatephone(char *phone, AddressBook *addressBook)
{
    // Index for iterating contacts
    int i = 0;
    while (i < addressBook->contactCount)
    {
        // Compare phone numbers
        if (!strcmp(phone, addressBook->contacts[i].phone))
        {
            return 0;
        }
        i++;
    }
    // No duplicate found
    return 1;
}

// Check if the email already exists in the address book (returns 0 if duplicate, 1 if unique)
int duplicateEmail(char *email, AddressBook *addressBook)
{
    // Index for iterating contacts
    int i = 0;
    while (i < addressBook->contactCount)
    {
        // Compare emails
        if (!strcmp(email, addressBook->contacts[i].email))
        {
            return 0;
        }
        i++;
    }
    // No duplicate found
    return 1;
}

// Check if the string contains only lowercase letters, digits, '@', or '.'
int islowerstr(char *str)
{
    // Index for iterating string
    int i = 0;
    int flag;
    while (str[i] != '\0')
    {
        flag = 0;
        // Valid character check
        if ((str[i] >= 97 && str[i] <= 122) || (str[i] >= 48 && str[i] <= 57) || str[i] == '@' || str[i] == '.')
        {
            flag = 1;
        }
        else
        {
            break; // Invalid character found
        }
        i++;
    }
    // Returns 1 if all valid, 0 otherwise
    return flag;
}

// Check if exactly one '@' is present and not at the start
int charpresent(char *str)
{
    // Only check up to before domain
    int len = strlen(str) - 5;
    int i = 0;
    int count = 0;
    while (i < len)
    {
        // Count '@' characters
        if (str[i] == '@')
        {
            count++;
        }
        i++;
    }
    if (count == 1 && str[0] != '@')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Check if the email ends with .com or .in
int checkemail(char *str)
{
    int len1 = strlen(str) - 4;
    int len2 = strlen(str) - 3;
    char str1[5] = ".com";
    // take 2nd array to check what if duplivate .com present or not
    char str2[50];
    strcpy(str2, str);
    str2[len1] = '\0';
    // char str2[5] = ".in";
    int flag = 0;
    // Check for .com or .in
    if (!(strcmp(&str[len1], str1)) && strstr(str2, str1) == NULL) // first compare .com with last 4 letters and another check what if it contains duplicate .com
    {
        flag = 1;
    }
    return flag;
}

// Check if the string contains only alphabets and spaces
int isalpha1(char *str)
{
    // Index for iterating string
    int i = 0;
    int flag;
    while (str[i] != '\0')
    {
        flag = 1;
        // Valid character check
        if ((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122) || str[i] == ' ')
        {
            flag = 0;
        }
        else
        {
            break; // Invalid character found
        }
        i++;
    }
    // Returns 0 if all valid, 1 otherwise
    return flag;
}

// Check if the phone number is valid (10 digits, not starting with 0)
int phonevalid(char *str)
{
    // Index for iterating string
    int i = 0;
    int flag;
    while (str[i] != '\0')
    {
        flag = 1;
        // Digit and length 10 and doesn't start with 0
        if ((str[i] >= 48 && str[i] <= 57) && (strlen(str) == 10) && (str[0] != '0'))
        {
            flag = 0;
        }
        else if (str[0] == '0')
        {
            flag = 1; // Invalid if starts with 0
        }
        else
        {
            break; // Invalid character found
        }
        i++;
    }
    // Returns 0 if valid, 1 otherwise
    return flag;
}

void listContacts(AddressBook *addressBook)
{
    // Sort contacts based on the chosen criteria
    int choice;
    // Loop until user chooses to go back
    do
    {
        printf("\nDisplay Contacts : \n");
        printf("1. Sort By Name\n");
        printf("2. Sort By Phone\n");
        printf("3. Sort by Email\n");
        printf("4. Back to Main Menu\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        // Handle user's menu choice
        switch (choice)
        {
        case 1:
            int i;
            sortbyname(addressBook);
            display(addressBook);
            printf("Press 1 to go back ");
            scanf("%d", &i);
            if (i == 1)
                break;
        case 2:
            int j;
            sortbyphone(addressBook);
            display(addressBook);
            printf("Press 1 to go back ");
            scanf("%d", &j);
            if (j == 1)
                break;
        case 3:
            int k;
            sortbyemail(addressBook);
            display(addressBook);
            printf("Press 1 to go back ");
            scanf("%d", &i);
            if (k == 1)
                break;
        case 4:
            break;
        default:
            printf("\n-- InValid Choice -- \n");
            break;
        }

    } while (choice != 4);
}

void initialize(AddressBook *addressBook)
{
    // Set initial contact count to zero
    addressBook->contactCount = 0;

    // Load contacts from file during initialization (After files)
    loadContactsFromFile(addressBook);
}

void saveAndExit(AddressBook *addressBook)
{
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS);              // Exit the program
}

void createContact(AddressBook *addressBook)
{
    // Index for new contact
    int temp = addressBook->contactCount;
    char Name[50];
    char Phone[20];
    char Email[50];
    int flag;
    // Loop until valid name is entered
    do
    {
        flag = 0;
        printf("\nEnter Name : ");
        scanf(" %[^\n]", Name);
        getchar();
        if (!isalpha1(Name))
        {
            flag = 1;
            strcpy(addressBook->contacts[temp].name, Name);
        }
        else
        {
            printf("❌ Enter valid name ! IT MUST ONLY CONTAINS ALPHABETS\n");
        }
    } while (flag != 1);

    // Loop until valid phone is entered
    do
    {
        flag = 0;
        printf("\nEnter Phone Number : ");
        scanf(" %[^\n]", Phone);
        getchar();

        if (phonevalid(Phone)) // calls phonevalid function and check if phone no is valid or not
        {
            printf("❌Please Enter Valid Phone Number!!\n");
        }
        else if (!duplicatephone(Phone, addressBook))
        {
            printf("❌Entered Phone Number Already Exists !\n");
            printf("Try with different \n");
        }
        else
        {
            flag = 1;
            strcpy(addressBook->contacts[temp].phone, Phone);
        }
    } while (flag != 1);

    // Loop until valid email is entered
    do
    {
        printf("\nEnter Email Address : ");
        scanf(" %[^\n]", Email);
        getchar();
        flag = 0;

        if (!(islowerstr(Email) && charpresent(Email) && checkemail(Email)))
        {
            printf("❌Enter Valid Email Address !!\n");
        }
        else if (!duplicateEmail(Email, addressBook))
        {
            printf("❌Entered Email Address Already Exists !\n");
            printf("Try with different \n");
        }
        else
        {

            flag = 1;
            strcpy(addressBook->contacts[temp].email, Email);
        }

    } while (flag != 1);

    // Increment contact count after adding new contact
    (addressBook->contactCount)++;
    printf("✅Contact Added Successfully !!\n");
}

void searchContact(AddressBook *addressBook)
{
    /* Define the logic for search */
    // User's menu choice
    int choice;
    do
    {
        printf("\nSearch contact Menu : \n");
        printf("1.Search By Name\n");
        printf("2.Search By Phone\n");
        printf("3.Search By Email\n");
        printf("4.Back to Menu\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        // Handle user's menu choice
        switch (choice)
        {
        case 1:
            int i;
            searchbyname(addressBook);
            break;
        case 2:
            int j;
            searchbyphone(addressBook);
            break;
        case 3:
            int k;
            searchbyemail(addressBook);
            break;
        case 4:
            break;
        default:
            printf("\n❌Invalid Choice! please try again\n");
        }
    } while (choice != 4);
}

void editContact(AddressBook *addressBook)
{
    // User's menu choice
    int choice;
    // First search for the contact to edit
    searchContact(addressBook);
    do
    {

        printf("\nEdit contact Menu : \n");
        printf("1.Edit Name\n");
        printf("2.Edit Phone\n");
        printf("3.Edit Email\n");
        printf("4.Back to Main Menu\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        // Handle user's menu choice
        switch (choice)
        {
        case 1:
            EditName(addressBook);
            //printf("\nName Edit Successful !!\n");
            break;
        case 2:
            EditPhone(addressBook);
            //printf("\nPhone Edited Successfully !!\n");
            break;
        case 3:
            EditEmail(addressBook);
            //printf("\nEmail Edited Successfully !!\n");
            break;
        case 4:
            break;
        default:
            printf("\n❌Invalid Choice! please try again\n");
        }
    } while (choice != 4);
}

void deleteContact(AddressBook *addressBook)
{
    // User's menu choice and index to delete
    int choice, index;
    // Store total number of contacts
    int temp = addressBook->contactCount;
    // First search for the contact to delete
    searchContact(addressBook);
    // No contact found to delete
    if (contactindex[0] == -1)
    {
        printf("\n❌contact is not present to delete\n");
        return;
    }
    printf("Enter Sr.No to delete contact : ");
    scanf("%d", &index);
    if (contactindex[index - 1] != -1)
    {
        // Shift contacts left to delete the selected contact
        for (int i = contactindex[index - 1]; i < temp; i++)
        {
            addressBook->contacts[i] = addressBook->contacts[i + 1];
        }
        printf("\n✅Contact Deleted Successfully !!\n");
        addressBook->contactCount--;
    }
    else
    {
        printf("\n❌Enter Valid Contact No !!\n");
    }
}
