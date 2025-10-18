#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "contact.h"
#include "file.h"

int contactindex[20] = {-1};

// Searches for contacts by name in the address book and displays matching results.
void searchbyname(AddressBook *addressBook)
{
    // Store total number of contacts
    int temp = addressBook->contactCount;
    // Variable to store the name entered by user
    char Name[50];
    printf("\nEnter name : ");
    scanf(" %[^\n]", Name);
    getchar();
    // flag: found or not, j: index for contactindex
    // flag: 1 if not found, 0 if found; j: index for contactindex array
    int flag = 1, j = 0;
    // sleep();
    printf("\nSearching");
    // Simulate searching animation
    for (int i = 0; i < 3; i++)
    {
        fflush(stdout); // Flush output buffer for immediate print
        sleep(1);       // Simulate delay for searching animation
        printf(".");    // Print dot for animation
    }
    // If name is valid (contains only alphabets)
    if (!isalpha1(Name))
    {
        // Index for iterating contacts
        // i: index for iterating through contacts
        int i = 0;
        printf("\n--------- Searched Contacts -----------\n");
        printf("\n");
        printf("%-10s %-15s %-15s %-15s\n", "Sr.No", "Name", "Phone", "Email");
        printf("------------------------------------------------------------------------\n");
        while (i < temp)
        {
            // Check for exact match or substring match in name
            if ((!strcasecmp(Name, addressBook->contacts[i].name)) || strstr(addressBook->contacts[i].name, Name) != NULL)
            {
                flag = 0;            // Mark as found
                contactindex[j] = i; // Store found index
                printf("%-10d %-15s %-15s %-15s\n", j + 1, addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
                j++; // Increment found index
            }
            i++; // Next contact
        }

        if (flag)
        {
            contactindex[j] = -1; // Mark as not found
            printf("\n❌Error : Entered Name Contact not found\n");
        }
    }
    else
    {
        printf("\n❌Enter valid name ! IT MUST ONLY CONTAINS ALPHABETS\n");
    }
    printf("------------------------------------------------------------------------\n");
}

// Searches for a contact by phone number in the address book and displays the result.
void searchbyphone(AddressBook *addressBook)
{
    // Store total number of contacts
    int temp = addressBook->contactCount;
    // Variable to store the phone number entered by user
    char Phone[20];
    printf("\nEnter phone : ");
    scanf("%s", Phone);
    getchar();
    // flag: 1 if not found, 0 if found
    int flag = 1;
    printf("Searching");
    // Simulate searching animation
    for (int i = 0; i < 3; i++)
    {
        fflush(stdout);
        sleep(1);
        printf(".");
    }
    if (!phonevalid(Phone))
    {
        // i: index for iterating, j: index for contactindex array
        int i = 0, j = 0;
        printf("\n--------- Searched Contact -----------\n");
        printf("\n");
        printf("%-10s %-15s %-15s %-15s\n", "Sr.No", "Name", "Phone", "Email");
        printf("------------------------------------------------------------------------\n");
        while (i < temp)
        {
            if (!strcmp(Phone, addressBook->contacts[i].phone))
            {
                flag = 0;
                contactindex[j] = i;
                printf("%-10d %-15s %-15s %-15s\n", 1, addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
                j++;
                break;
            }
            i++;
        }
        if (flag)
        {
            contactindex[j] = -1;
            printf("\n❌Error : Entered Phone No. not found\n");
            // printf("--------------------------------------\n");
        }
    }
    else
    {
        printf("\n❌Enter valid Phone number!!\n");
    }
    printf("------------------------------------------------------------------------\n");
}

// Searches for a contact by email in the address book and displays the result.
void searchbyemail(AddressBook *addressBook)
{
    char Email[50];
    printf("\nEnter Email : ");
    scanf("%s", Email);
    getchar();
    // Store total number of contacts
    int temp = addressBook->contactCount;
    // flag: 1 if not found, 0 if found; j: index for contactindex array
    int flag = 1, j = 0;
    printf("Searching");
    // Simulate searching animation
    for (int i = 0; i < 3; i++)
    {
        fflush(stdout);
        sleep(1);
        printf(".");
    }
    if (islowerstr(Email) && charpresent(Email) && checkemail(Email))
    {
        // i: index for iterating through contacts
        int i = 0;
        printf("\n--------- Searched Contact -----------\n");
        printf("\n");
        printf("%-10s %-15s %-15s %-15s\n", "Sr.No", "Name", "Phone", "Email");
        printf("------------------------------------------------------------------------\n");
        while (i < temp)
        {
            flag = 0;
            if (!strcmp(Email, addressBook->contacts[i].email))
            {
                contactindex[j] = i;
                printf("%-10d %-15s %-15s %-15s\n", 1, addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
                j++;
                break;
            }
            i++;
        }
        if (flag)
        {
            contactindex[j] = -1;
            printf("\n❌Error : Entered Email not found !!\n");
            // printf("--------------------------------\n");
        }
    }
    else
    {
        printf("\n❌Enter Valid Email !!\n");
    }
    printf("------------------------------------------------------------------------\n");
}

// Sorts the contacts in the address book alphabetically by name.
void sortbyname(AddressBook *addressBook)
{
    // Temporary variable for swapping contacts
    Contact temp1;
    // Store total number of contacts
    int temp = addressBook->contactCount;
    for (int i = 0; i < temp; i++)
    {
        for (int j = 0; j < temp - i - 1; j++)
        {
            if (strcasecmp(addressBook->contacts[j].name, addressBook->contacts[j + 1].name) > 0)
            {
                temp1 = addressBook->contacts[j];
                addressBook->contacts[j] = addressBook->contacts[j + 1];
                addressBook->contacts[j + 1] = temp1;
            }
        }
    }
}

// Sorts the contacts in the address book numerically by phone number.
void sortbyphone(AddressBook *addressBook)
{
    // Temporary variable for swapping contacts
    Contact temp1;
    // Store total number of contacts
    int temp = addressBook->contactCount;
    for (int i = 0; i < temp; i++)
    {
        for (int j = 0; j < temp - i - 1; j++)
        {
            if (strcmp(addressBook->contacts[j].phone, addressBook->contacts[j + 1].phone) > 0)
            {
                temp1 = addressBook->contacts[j];
                addressBook->contacts[j] = addressBook->contacts[j + 1];
                addressBook->contacts[j + 1] = temp1;
            }
        }
    }
}

// Sorts the contacts in the address book alphabetically by email address.
void sortbyemail(AddressBook *addressBook)
{
    // Temporary variable for swapping contacts
    Contact temp1;
    // Store total number of contacts
    int temp = addressBook->contactCount;
    for (int i = 0; i < temp; i++)
    {
        for (int j = 0; j < temp - i - 1; j++)
        {
            if (strcmp(addressBook->contacts[j].email, addressBook->contacts[j + 1].email) > 0)
            {
                temp1 = addressBook->contacts[j];
                addressBook->contacts[j] = addressBook->contacts[j + 1];
                addressBook->contacts[j + 1] = temp1;
            }
        }
    }
}

// Displays all contacts in the address book in a formatted table.
void display(AddressBook *addressBook)
{
    // i: index for iterating through contacts
    int i = 0;
    // Store total number of contacts
    int temp = addressBook->contactCount;
    if (temp == 0)
    {
        printf("\n-------------------------\n");
        printf("    No Contacts Present     \n");
        printf("--------------------------\n");
        return;
    }
    printf("\nAll Contacts : \n");
    // printf("-----------------------------------------\n");
    printf("\n");
    printf("%-10s %-15s %-15s %-15s\n", "Sr.No", "Name", "Phone", "Email");
    printf("------------------------------------------------------------------------\n");
    while (i < temp)
    {
        printf("%-10d %-15s %-15s %-15s\n", i + 1, addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
        i++;
    }
    printf("------------------------------------------------------------------------\n");
}

// Edits the name of a selected contact from the search results.
void EditName(AddressBook *addressBook)
{
    // searchContact(addressBook);
    // ind: index of contact to edit
    int ind;
    // str: variable to store new name
    char str[50];
    if (contactindex[0] == -1)
    {
        printf("\nNo previous search result found \nPlease Search again!!\n");
        return;
    }
    printf("Enter Sr.No From above to edit : ");
    scanf("%d", &ind);
    // flag: 1 if valid, 0 if not
    int flag;
    do
    {
        printf("Enter New Name : ");
        scanf(" %[^\n]", str);
        flag = 0;
        if (!isalpha1(str))
        {
            flag = 1;
            strcpy(addressBook->contacts[contactindex[ind - 1]].name, str);
            printf("\n✅Name Edited Successfully !!\n");
        }
        else
        {
            printf("\n❌Enter Valid name !!\n");
        }
    } while (flag != 1);
}

// Edits the phone number of a selected contact from the search results.
void EditPhone(AddressBook *addressBook)
{
    // searchContact(addressBook);
    // printf("You Dont Want to Edit(y/n) ");
    // phone: variable to store new phone number
    char phone[20];
    // flag: 1 if valid, 0 if not; ind: index of contact to edit
    int flag, ind;
    if (contactindex[0] == -1)
    {
        printf("\nNo previous search result found \nPlease Search again!!\n");
        return;
    }
    printf("Enter Sr.No From above to edit : ");
    scanf("%d", &ind);
    do
    {
        printf("Enter New Phone : ");
        scanf(" %[^\n]", phone);
        flag = 0;
        if (!phonevalid(phone))
        {
            if (duplicatephone(phone, addressBook))
            {
                flag = 1;
                strcpy(addressBook->contacts[contactindex[ind - 1]].phone, phone);
                printf("\n✅Phone Edited Successfully !!\n");
            }
            else
            {
                printf("\n❌Entered Phone No is already present !! \n");
            }
        }
        else
        {
            printf("\n❌Enter Valid Phone No !! \n");
        }
    } while (flag != 1);
}

// Edits the email address of a selected contact from the search results.
void EditEmail(AddressBook *addressBook)
{
    // searchContact(addressBook);
    // email: variable to store new email
    char email[50];
    // flag: 1 if valid, 0 if not; ind: index of contact to edit
    int flag, ind;
    if (contactindex[0] == -1)
    {
        printf("\nNo previous search result found \nPlease Search again!!\n");
        return;
    }
    printf("\nEnter Sr.No From above to edit : ");
    scanf("%d", &ind);
    do
    {
        printf("\nEnter New Email : ");
        scanf(" %[^\n]", email);
        flag = 0;
        if (islowerstr(email) && charpresent(email) && checkemail(email))
        {
            if (duplicateEmail(email, addressBook))
            {
                flag = 1;
                strcpy(addressBook->contacts[contactindex[0]].email, email);
                printf("\n✅Email Edited Successfully !!\n");
            }
            else
            {
                printf("\n❌Entered Email Address already present !! \n");
            }
        }
        else
        {
            printf("\n❌Enter Valid Email Address !!\n");
        }
    } while (flag != 1);
}