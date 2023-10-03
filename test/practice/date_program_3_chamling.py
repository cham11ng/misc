"""
Module: Practice 3: Python - Sagar Chamling Rai
Write a Python code using If-elif-else and nested if-else approach for following:

Define three global variables:
First item = Rice
Second item = Bread
Third item = Curry

The user is prompt to enter two different items from above three.
For all invalid inputs an error message would appear that “Invalid items entry.”

If Rice and Curry entered, then it prints LUNCH items
If Bread and Curry entered, then it prints DINNER items
If Rice and Bread entered, then it prints NO PROPER LUNCH OR DINNER items

Output will be as follows:
Enter the first item: Rice
Enter the second item: Curry

You have entered Lunch Items
"""

import os

os.system("clear")

RICE = "rice"
BREAD = "bread"
CURRY = "curry"


def input_items():
    """
    Input date.
    """
    print("Please enter two item from given list. (Rice, Bread, Curry)")

    first_item = input("Enter your first item: ")
    second_item = input("Enter your second item: ")

    return first_item.lower(), second_item.lower()


def run_user_interaction():
    """
    Recursively ask for input for invalid input and return items in list.
    """
    first_item, second_item = input_items()
    items = (RICE, BREAD, CURRY)

    if first_item in items and second_item in items:          # Conditionally validate items with accepted list.
        return first_item, second_item

    print("Invalid items entry.\n")

    return run_user_interaction()                             # Recursive call for failed condition to re-enter the inputs.


def evaluate_item(first_item, second_item):
    """
    Evaluate items based on inputs.
    """
    if (first_item == RICE and second_item == CURRY) or (     # Comparing Lunch items.
        first_item == CURRY and second_item == RICE
    ):
        print("You have entered LUNCH items")
    elif (first_item == BREAD and second_item == CURRY) or (  # Comparing Dinner items.
        first_item == CURRY and second_item == BREAD
    ):
        print("You have entered DINNER items")
    else:
        print("NO PROPER LAUNCH OR DINNER items")


def main():
    """
    Main function.
    """
    first_item, second_item = run_user_interaction()          # Calls run_user_interaction function

    evaluate_item(first_item, second_item)                    # Calls evaluate_item function


if __name__ == "__main__":
    main()                                                    # Calls main function.
