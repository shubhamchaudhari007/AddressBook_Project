#include <stdio.h>
#include "file.h"

// Saves all contacts from the address book to the file "contacts.csv" in CSV format.
void saveContactsToFile(AddressBook *addressBook)
{
    // Open the file in write mode (creates or overwrites contacts.csv)
    FILE *fptr;
    fptr = fopen("contacts.csv", "w+");

    // Write the number of contacts as the first line
    fprintf(fptr, "%d\n", addressBook->contactCount);

    // Write each contact's details in CSV format
    for (int i = 0; i < addressBook->contactCount; i++)
    {
        fprintf(fptr, "%s,%s,%s\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
    }
    // Close the file after writing
    fclose(fptr);
}

// Loads all contacts from the file "contacts.csv" into the address book.
void loadContactsFromFile(AddressBook *addressBook)
{

    // Open the file in read mode (reads contacts.csv)
    FILE *fptr;
    fptr = fopen("contacts.csv", "r+");

    // Read the number of contacts from the first line
    fscanf(fptr, "%d", &addressBook->contactCount);

    // Read each contact's details from the file
    for (int i = 0; i < addressBook->contactCount; i++)
    {
        fscanf(fptr, " %[^,],%[^,],%[^\n]", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
    }
    // Close the file after reading
    fclose(fptr);
}
