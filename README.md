# 📒 Address Book in C

![Language](https://img.shields.io/badge/Language-C-blue)
![Status](https://img.shields.io/badge/Project%20Type-Console%20App-brightgreen)
![License](https://img.shields.io/badge/License-Open%20Source-yellow)
![Made With ❤️](https://img.shields.io/badge/Made%20With-%E2%9D%A4-red)

---

## 🧠 Overview
A **simple and interactive C program** to manage your personal or professional contacts.  
This project helps users store, search, edit, and delete contact details efficiently from a terminal interface.  
Contacts are stored in memory and can be saved to a file for future use.  

> 💡 A great beginner project to learn **file handling, structures, arrays, and modular programming in C**.

---

## 🎯 Project Overview
- Manage a digital address book with **Name**, **Phone**, and **Email**.
- Contacts are maintained in memory and can be **saved/loaded** from a CSV file.
- Fully **menu-driven** with clean console interaction.

---

## ✨ Features
✅ **Add New Contact** – Add contacts with unique phone and email validation.  
🔍 **Search Contact** – Find contacts by name, phone, or email.  
✏️ **Edit Contact** – Update existing contact details.  
🗑️ **Delete Contact** – Remove a contact safely.  
📋 **List All Contacts** – Display all contacts in a formatted table.  
💾 **Save Contacts** – Save your address book to a file (`contacts.csv`).  
🚪 **Exit** – Quit the program safely while ensuring all changes are saved.  

---

## 🧩 File Structure
📁 AddressBook-NewDesign
│
├── main.c # Main program and menu interface
├── contact.h/.c # Core contact logic (add, search, edit, delete, validation)
├── searchsort.c # Searching and sorting functions
├── file.h/.c # File handling (save/load contacts)
└── contacts.csv # Example data file

---

## 🧱 Data Format (contacts.csv)
Each line of the file contains:
Name,Phone,Email

Example:
3
Ajay Dubey,9901234589,ajay.dubey@email.com
Riya Sharma,9823456712,riya.sharma@email.com
Rohan Patil,9765432189,rohan.patil@email.com


---

## ⚙️ Build and Run

### 🧮 Compile
```bash
gcc *.c -o address_book
▶️ Run
bash

./address_book
💻 Usage Guide
When you run the program, you’ll see a menu like this:

markdown

===== ADDRESS BOOK MENU =====
1. Add New Contact
2. Search Contact
3. Edit Contact
4. Delete Contact
5. List All Contacts
6. Save Contacts
7. Exit
=============================
Enter your choice:

🧾 Tips:

Use numbers (1–7) to navigate options.

Ensure each contact has a unique phone number and email.

Always use the Save Contacts option before exiting to retain data.

On next launch, the program automatically loads existing contacts.
---

###🧠 Notes for Beginners
Uses fixed-size arrays for simplicity:

Name → 50 chars

Phone → 20 chars

Email → 50 chars

Input validation is basic but educational.

Ideal for understanding:

🧩 struct

💾 File I/O

🔄 Loops & Menus

📂 Modular design with multiple .c and .h files

## 🔧 Extensibility
You can enhance this project by adding:

🏠 Address or birthday fields

📤 Import/export to .txt or .json

🧮 Sorting by name or phone

🔐 Password protection

🖥️ GUI version using GTK or web-based interface

🧰 Suitable For
🎓 Students learning C programming and file handling

🧑‍💻 Developers building simple data management applications

🧠 Learners who want hands-on practice with structs and arrays

## 🧩 Why This Project?
Simple yet powerful C application

Demonstrates real-world concepts of data storage and searching

Teaches modular design and code reusability

Fully terminal-based — perfect for beginners

## 🤝 Contributing
Want to improve this project?
Here’s how you can contribute:

Fork the repository

Add new features or fix bugs

Update this README.md with your changes

Submit a pull request 🚀

🧾 License
This project is open for learning and personal use.
You are free to use, modify, and publish it under your own repository.
