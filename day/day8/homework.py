"""Module: Day 8 Homework: Python - Sagar Chamling Rai"""

import os

os.system("clear")

MENU = """
Select from given menu:
    1) Add an item
    2) Delete an item
    3) Search an item
    4) Update an item
    5) Display item in table
    6) Quit

Total items: {total}
"""


def take_input():
    """Take input from user and return name, code and price of item."""
    name = input("Enter item name: ")
    code = input("Enter item code: ")
    while True:
        price = input("Enter item price: ")

        if price.isdigit():
            price = int(price)

            return (name.upper(), code, price)

        print("Please enter a valid price.")


def display_table(cart):
    """Display items in a cart in table format."""

    i = 1
    print(f"\n{'S.N.':<5} {'Name':<15} {'Code':<15} {'Price':<15}")  # Header of table
    print(f"{'-'*5:<5} {'-'*15:<15} {'-'*15:<15} {'-'*15:<15}")  # Boarder of table

    for value in cart.values():
        print(f"{i:<5} {value['name']:<15} {value['code']:<15} ${value['price']:<15}")  # Data of table
        i += 1


def run_shopping_cart():
    """Run shopping cart program"""
    i = 1
    cart = {}
    MAX = 4

    while True:
        os.system("clear")

        print(MENU.format(total=len(cart)))
        choice = input("Your choice: ")

        print()

        if choice == "1":
            if len(cart) == MAX:
                print(f"Application supports maximum {MAX} items.")
                display_table(cart)
            else:
                (name, code, price) = take_input()

                item = {"name": name, "code": code, "price": price}
                cart[i] = item
                i += 1

                display_table({name: item})

        elif choice == "2":
            name = input("Enter item name to remove: ")
            found = False

            for key, value in cart.items():
                if value["name"] == name.upper():
                    found = True
                    display_table({key: value})
                    del cart[key]

                    print("\nItem removed.")
                    break

            if not found:
                print(f"\nItem not found named '{name}'.")

        elif choice == "3":
            name = input("Enter item name to search: ")
            found = False

            for key, value in cart.items():
                if value["name"] == name.upper():
                    found = True
                    display_table({key: value})

            if not found:
                print(f"\nItem not found named '{name}'.")

        elif choice == "4":
            name = input("Enter item name to update: ")
            found = False

            for key, value in cart.items():
                if value["name"] == name.upper():
                    found = True
                    display_table({key: value})
                    print()
                    (name, code, price) = take_input()

                    item = {"name": name, "code": code, "price": price}
                    cart[key] = item
                    print("\nItem updated.")
                    break;

            if not found:
                print(f"\nItem not found named '{name}'.")
            else:
                display_table({name: item})

        elif choice == "5":
            print("Item list:")
            display_table(cart)

        elif choice == "6":
            print("See you again!")
            break

        else:
            print("Please enter a valid input:")

        input("\nPress any key to continue...")


if __name__ == "__main__":
    run_shopping_cart()
