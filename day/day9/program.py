"""Module: Day 9 Classwork: Python - Sagar Chamling Rai

Build a phone directory with python code.

There will be 4 options
1. Add Phone Number
2. Delete Phone Number
3. Search Phone Number
4. Update Phone Number
5. Quit

If user input more than 5 phone numbers then it will stop the program and display all the phone numbers.
The phone number digit should be exactly 10 digit.
If user input more than 10 digit or less than 10 digit, display error and Continue to options again.
This has to be done by dictionary.
"""

import os

MAX_PHONE_NUMBER = 5
MENU = """
Welcome to Phone Book Portal:

    1. Add Phone Number
    2. Delete Phone Number
    3. Search Phone Number
    4: Update Phone Number
    5: Display Phone Book
    6. Quit

Total PhoneBook Contacts: {total}
"""

i = 1  # Define global variable for indexing dictionary.
phone_book = {}  # Empty dictionary variable for phone_book.


msg_input_search = "Enter your name or phone number to search: "
msg_input_option = "Enter your choice: "
msg_input_name = "Enter name: "
msg_input_phone = "Enter phone number: "
msg_input_any_key = "Press any key to continue..."

msg_success_add = "Phone number added successfully."
msg_success_delete = "Phone number deleted successfully."
msg_success_update = "Phone number updated successfully."
msg_success_quit = "Thank you for using the phone book."

msg_err_invalid_option = "Invalid option. Please try again."
msg_err_invalid_number = "You have entered the invalid phone number."
msg_err_not_found = "Phone number not found. Please try again."
msg_err_maximum_limit = "You've already reached the maximum limit."


def take_input():
    """Take input to phone number."""
    name = input(msg_input_name)

    while True:
        phone_number = input(msg_input_phone)

        if phone_number.isdigit() and len(phone_number) == 10 and phone_number[0] != "0":
            return (name, phone_number)
        else:
            print(msg_err_invalid_number)


def add_phone_number():
    """Add phone number. Check the number (shall not start with 0 and length should be 10)."""
    global i

    if len(phone_book) == MAX_PHONE_NUMBER:
        print(msg_err_maximum_limit)

        return

    (name, phone_number) = take_input()

    phone_book[i] = {"name": name, "phone_number": phone_number}
    i += 1  # Increase the global index value by 1 after adding.

    print(msg_success_add)


def delete_phone_number():
    """Add delete phone number."""
    found = False
    search_input = input(msg_input_search)

    for key, value in phone_book.items():
        if search_input.lower() == value["name"].lower() or search_input == value["phone_number"]:
            found = True

            del phone_book[key]
            print(msg_success_delete)

            break

    if not found:
        print(msg_err_not_found)


def search_phone_number():
    """Add search phone number."""
    found = False
    search_input = input(msg_input_search)

    for key, value in phone_book.items():
        if search_input.lower() == value["name"].lower() or search_input == value["phone_number"]:
            found = True

            print("Name:", value["name"])
            print("Phone number:", value["phone_number"])

            break

    if not found:
        print(msg_err_not_found)


def update_phone_number():
    """Update phone number detail, search by phone number or name."""
    search_input = input(msg_input_search)
    found = False

    for key, value in phone_book.items():
        if search_input.lower() == value["name"].lower() or search_input == value["phone_number"]:
            found = True

            (name, phone_number) = take_input()

            phone_book[key] = {"name": name, "phone_number": phone_number}

            break

    if not found:
        print(msg_err_not_found)


def display_phone_book():
    """Display items in a cart in table format."""

    print()  # Extra line
    print(f"{'Name':<15} {'Phone Number':<15}")  # Header of table
    print(f"{'-'*15:<15} {'-'*15:<15}")  # Boarder of table

    for value in phone_book.values():
        print(f"{value['name']:<15} {value['phone_number']:<15}")  # Data of table


def run_phone_book():
    """Run phone book."""
    i = 1  # Global variable index

    while True:
        os.system("clear")
        print(MENU.format(total=len(phone_book)))  # Printing menu with total phone_book length as placeholder

        user_input = input(msg_input_option)

        print()  # Extra line in output.

        if user_input == "1":
            add_phone_number()
        elif user_input == "2":
            delete_phone_number()
        elif user_input == "3":
            search_phone_number()
        elif user_input == "4":
            update_phone_number()
        elif user_input == "5":
            display_phone_book()
        elif user_input == "6":
            print(msg_success_quit)

            break
        else:
            print(msg_err_invalid_option)

        print()  # Extra line in output.

        input(msg_input_any_key)


if __name__ == "__main__":
    run_phone_book()  # Calls run_phone_book function.
