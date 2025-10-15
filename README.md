
# Contacts Management System in C

A simple command-line **Contacts Management System** written in C that allows you to store and manage contacts with the following details:

- Name
- Phone Number
- Street Address
- Email Address

Contacts are saved persistently in a file (`contacts.txt`), so they are retained between program runs.

---

## Features

- Add new contacts
- Display all saved contacts
- Persistent storage using file I/O (`contacts.txt`)
- Clears the console screen between operations for better user experience
- Handles up to 100 contacts

---

## How to Use

1. **Compile the program**

```bash
gcc contacts.c -o contacts
