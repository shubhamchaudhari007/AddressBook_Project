#ifndef CONTACT_H
#define CONTACT_H

#define MAX_CONTACTS 100

typedef struct
{
    char name[50];
    char phone[20];
    char email[50];
} Contact;

typedef struct
{
    int contactCount;
    Contact contacts[100];
} AddressBook;

void createContact(AddressBook *addressBook);
void searchContact(AddressBook *addressBook);
void editContact(AddressBook *addressBook);
void deleteContact(AddressBook *addressBook);
void listContacts(AddressBook *addressBook);
void initialize(AddressBook *addressBook);
void saveContactsToFile(AddressBook *addressBook);

int duplicatephone(char *phone,AddressBook *addressBook);
int duplicateEmail(char *email,AddressBook *addressBook);
int islowerstr(char *str);
int phonevalid(char *str);
int isalpha1(char *str);
int checkemail(char *str);
int charpresent(char *str);
void searchbyname(AddressBook *addressBook);
void searchbyphone(AddressBook *addressBook);
void searchbyemail(AddressBook *addressBook);

void sortbyname(AddressBook *addressBook);
void sortbyphone(AddressBook *addressBook);
void sortbyemail(AddressBook *addressBook);

void display(AddressBook *addressBook);
//void dispaycontact(AddressBook *addressBook,int i);

void EditName(AddressBook *addressBook);
void EditPhone(AddressBook *addressBook);
void EditEmail(AddressBook *addressBook);

#endif
