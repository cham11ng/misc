"""Module: Day 9 Classwork: Python - Sagar Chamling Rai

Build a phone directory with python code.

There will be 4 options
1. Add Phone Number
2. Delete Phone Number
3. Search Phone Number
4. Quit

If user input more than 5 phone numbers then it will stop the program and display all the phone numbers.
The phone number digit should be exactly 10 digit.
If user input more than 10 digit or less than 10 digit, display error and Continue to options again.
This has to be done by dictionary.
"""

import os

MENU = """
Welcome to Phone Book Center:

    1. Add Phone Number
    2. Delete Phone Number
    3. Search Phone Number
    4. Quit

Total PhoneBook: {total}
"""


phone_book = {}
MAX_PHONE_NUMBER = 5


def add_phone_number(phone_book):
    """Add phone number."""
    while True:
        phone_number = input("Enter your phone number: ")
        if len(phone_number) == 10:
            name = input("Enter your name: ")
            phone_book[phone_number] = name
            print("Phone number added successfully.")
            break
        else:
            print("Invalid phone number. Please try again.")


def delete_phone_number(phone_book):
    """Add delete phone number."""
    while True:
        phone_number = input("Enter your phone number to delete: ")
        if phone_number in phone_book:
            del phone_book[phone_number]
            print("Phone number deleted successfully.")
            break
        else:
            print("Phone number not found. Please try again.")


def search_phone_number(phone_book):
    """Add search phone number."""
    while True:
        phone_number = input("Enter your phone number to search: ")
        if phone_number in phone_book:
            print(f"Phone number found: {phone_book[phone_number]}")
            break
        else:
            print("Phone number not found. Please try again.")


def run_phone_book():
    """Run phone book."""
    while True:
        os.system("clear")
        print(MENU.format(total=len(phone_book)))

        user_input = input("Enter your choice: ")

        print()

        if user_input == "1":
            add_phone_number(phone_book)
        elif user_input == "2":
            delete_phone_number(phone_book)
        elif user_input == "3":
            search_phone_number(phone_book)
        elif user_input == "4":
            print("Thank you for using the phone book.")
            break
        else:
            print("Invalid input. Please try again.")

        input("\nPress enter to continue...")


if __name__ == "__main__":
    run_phone_book()  # Calls _ function.
