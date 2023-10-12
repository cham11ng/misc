"""Module: Test 2: Python - Sagar Chamling Rai
Write a Python script for the following scenario:

Develop a Phone Directory Management System Python program using dictionaries.
Create a dictionary with name "phoneDirectory." The dictionary should be empty at the initial stages.
Display a menu as demonstrated below with multiple choices, so that the user can select one for
performing various actions. After completing the relevant actions (except for Quit), the menu is displayed again.

Sample menu:

WELCOME TO THE GRANN'S PHONE DIRECTORY

Add a record
Search a record
Update a record
Sort the record alphabetically
Delete a record
Quit
Enter your choice:

The dictionary should always store names and phone numbers as a key-value pair.
Based on the user's input in response to the main menu, add a new name and phone number,
search a person's phone number, change an existing phone number, display the stored records in sorted form,
or delete an existing name and phone number. On entering the sixth option (Quit),
the user will exit from the whole program.

Sample input and action:
Enter your choice: 1
Enter name: Jessica
Enter your 10-digit phone number: 4387677890
Record added
[The menu is displayed again]

Sample input and action:
Enter your choice: 1
Enter name: Ammy
Enter your 10-digit phone number: 4297400000
Record added
[The menu is displayed again]

Sample input and action:
Enter your choice: 2
Enter name to search: Jessica
Jessica: 4387677890
[The menu is displayed again]

Sample input and action:
Enter your choice: 3
Enter name: Jessica
Enter new 10-digit phone number: 4382121212
Record updated
[The menu is displayed again]

Sample input and action:
Enter your choice: 4
Sorted Record is : Ammy-4297400000, Jessica-4382121212
[The menu is displayed again]

Sample input and action:
Enter your choice: 5
Enter name: Jessica
Record deleted
[The menu is displayed again]

Sample input and action:
Enter your choice: 6
[Exit from the whole program]
"""

import os

os.system("clear")


MENU = """
WELCOME TO THE GRANN'S PHONE DIRECTORY:

    1. Add record
    2. Search a record
    3. Update a record
    4: Sort the record alphabetically
    5: Delete a record
    6. Quit

Total Contacts in Phone Directory: {total}
"""                                                                   # Menu with total phoneDirectory length as placeholder.

phoneDirectory = {}                                                   # Empty dictionary to store phone book items.

# Messages
msg_input_search = "Enter your name to search: "
msg_input_option = "Enter your choice: "
msg_input_name = "Enter name: "
msg_input_phone = "Enter your 10-digit phone number: "
msg_input_new_phone = "Enter new 10-digit phone number: "
msg_input_any_key = "Press any key to continue..."

msg_success_add = "Record added."
msg_success_delete = "Record deleted."
msg_success_update = "Record updated."
msg_success_quit = "Thank you for using the phone directory."

msg_err_invalid_option = "Invalid option. Please try again."
msg_err_invalid_number = "Invalid, should be 10-digit number. Please try again."
msg_err_not_found = "Phone number not found. Please try again."
msg_err_name_exists = "Name already exists. Please try again."


def add_record():
    """Add record to phone book."""
    global phoneDirectory                                             # To access global variable.

    name = input(msg_input_name)

    while True:                                                       # Loop until valid phone number is entered.
        phone = input(msg_input_phone)

        if name in phoneDirectory:                                    # Check if name already exists.
            print(msg_err_name_exists)
            continue

        if len(phone) != 10 or not phone.isdigit() or phone[0] == 0:  # Check if phone number is valid. Length should be 10 and should not start with 0.
            print(msg_err_invalid_number)
            continue

        phoneDirectory[name] = phone                                  # Add name and phone number to phoneDirectory dictionary. In dictionary, name is key and phone number is value.
        print(msg_success_add)

        return


def search_record():
    """Search record from phone book."""
    global phoneDirectory                                             # To access global variable.

    name = input(msg_input_search)

    if name not in phoneDirectory:                                    # Check if name exists in phoneDirectory dictionary.
        print(msg_err_not_found)
    else:                                                             # If name exists, print name and phone number.
        print(f"{name}: {phoneDirectory[name]}")


def update_record():
    """Update record from phone book."""
    global phoneDirectory                                             # To access global variable.

    name = input(msg_input_name)

    if name not in phoneDirectory:                                    # Check if name exists in phoneDirectory dictionary.
        print(msg_err_not_found)
    else:                                                             # If name exists, update phone number.
        phone = input(msg_input_new_phone)

        if len(phone) != 10 or not phone.isdigit() or phone[0] == 0:  # Check if phone number is valid. Length should be 10 and should not start with 0.
            print(msg_err_invalid_number)
        else:                                                         # If phone number is valid, update phone number.
            phoneDirectory[name] = phone                              # Update phone number in phoneDirectory dictionary.
            print(msg_success_update)


def sort_record():
    """Sort record from phone book."""
    global phoneDirectory                                             # To access global variable.

    sorted_phoneDirectory = sorted(phoneDirectory.items())            # Sort phoneDirectory dictionary by key.

    print("Sorted Record is : ", end="")

    for name, phone in sorted_phoneDirectory:                         # Print sorted phoneDirectory dictionary.
        print(f"{name}-{phone}", end=", ")                            # Print name and phone number separated by hyphen and comma.


def delete_record():
    """Delete record from phone book."""
    global phoneDirectory                                             # To access global variable.

    name = input(msg_input_name)

    if name not in phoneDirectory:                                    # Check if name exists in phoneDirectory dictionary.
        print(msg_err_not_found)
        return

    del phoneDirectory[name]                                          # Delete name and phone number from phoneDirectory dictionary.
    print(msg_success_delete)


def run_phone_book():
    """Run phone book."""
    while True:
        os.system("clear")
        print(MENU.format(total=len(phoneDirectory)))                 # Print menu with total phoneDirectory length as placeholder.
        option = input(msg_input_option)

        if option == "1":                                             # Option switch to add_record function.
            add_record()
        elif option == "2":                                           # Option switch to search_record function.
            search_record()
        elif option == "3":                                           # Option switch to update_record function.
            update_record()
        elif option == "4":                                           # Option switch to sort_record function.
            sort_record()
        elif option == "5":                                           # Option switch to delete_record function.
            delete_record()
        elif option == "6":                                           # Option switch to quit.
            print(msg_success_quit)
            break
        else:                                                         # Option switch to invalid option.
            print(msg_err_invalid_option)

        print()
        input(msg_input_any_key)                                      # Wait for user to press any key.


if __name__ == "__main__":
    run_phone_book()                                                  # Calls run_phone_book function.
