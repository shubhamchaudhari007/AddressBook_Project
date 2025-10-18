Address Book — Simple C Contact Manager

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

Overview

This small C project is a beginner-friendly, menu-driven contact manager. It stores contacts (name, phone, email) in memory while the program runs and can save/load them from a CSV file so your data persists between runs.

Why this project

- Good for learning basic C: structs, arrays, file I/O, string handling, and simple user interfaces.
- Small, self-contained, and easy to extend.

Features

- Create, search, edit, and delete contacts.
- List all contacts with simple sorting options.
- Save contacts to a CSV file and load them on program start.
- Basic validation to avoid duplicate phone numbers and emails.

Files in this folder

- `main.c` — The program entry, menu, and user interaction.
- `contact.h` / `contact.c` — Core contact logic (data types, add/search/edit/delete, validation).
- `searchsort.c` — Utility functions for searching and sorting contacts.
- `file.h` / `file.c` — Save/load contacts to/from `contacts.csv`.
- `contacts.csv` — Example data file used by the program.

Data format (contacts.csv)

The CSV file stores contacts like this:

First line: number of contacts (N)
Then N lines, each with: Name,Phone,Email

Example:

31
Ajay Dubey,9901234589,ajay.dubey@email.com
... (more lines)

Build and run

1. Open a terminal in `AddressBook-NewDesign`.
2. Compile with:

   gcc *.c -o address_book

3. Run:

   ./address_book

How to use

- The menu is numbered. Enter the number for the action you want.
- When adding a contact, the program validates phone and email uniqueness.
- Use "Save contacts" in the menu to write all contacts to `contacts.csv`.
- On next run the program will automatically load contacts from `contacts.csv`.

Notes for beginners

- The project uses fixed-size arrays for simplicity — names are limited to 50 chars, phone numbers to 20, email to 50.
- Validation is simple and intended for learning, not production use.
- To extend: add fields (address, birthday), use dynamic memory, or improve email/phone validation.

Contributing

- If you want to add features, please follow the same file structure and update `README.md` with your changes.
- Keep changes small and test by compiling locally before pushing to GitHub.

License

Use this project for learning and personal use. You can publish it on GitHub and modify it as you like.
