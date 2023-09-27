"""Module: Day 7 Classwork: Python - Sagar Chamling Rai"""

import os

os.system("clear")


def run_list_iterations():
    """Running iterations."""
    prime = [2, 3, 5, 7, 11, 13, 17, 19, 23]
    for i in prime:
        print(i, end=" ")

    print("")

    i = 0
    while i < len(prime):
        print(prime[i], end=" ")
        i += 1


def append_lists():
    """Appending vegetable or fruits"""
    items = ["cauliflower", "okra", "eggplant", "avocado", "dragon fruit", "kiwi"]

    while True:
        new_item = input("Enter new vegetable or fruit: ")

        if new_item not in items:
            items.append(new_item)

        more_input = input("Do you want to enter more: (y/N): ")

        if more_input != "y":
            break

    i = 0

    while i < len(items):
        print(items[i])
        i += 1


def run_shopping_cart():
    """Run shopping cart"""
    items = []

    while True:
        os.system("clear")

        print(
            f"""
            Select from given menu:
                1: Add new item
                2: Deleting an item
                3: Sort and print items in ascending order.
                4: Sort and print items in reverse order.
                5: Quit

            Total Items: {len(items)}
            """
        )
        user_input = input("Select one from given options: ")

        if user_input == "1":  # Option to add new item.
            while True:
                new_item = input("\nEnter new item: ")

                if new_item not in items:
                    items.append(new_item)
                    print(new_item, "item added.\n")
                else:
                    print(new_item, "item already in a list.\n")

                more_input = input("Do you want to enter more: (y/N): ")

                if more_input != "y":
                    break

        elif user_input == "2":  # Option to delete item.
            while True:
                remove_item = input("\nEnter item to remove: ")

                if remove_item not in items:
                    print(remove_item, "not in the list.\n")
                else:
                    items.remove(remove_item)

                    print(remove_item, "item deleted.\n")

                more_input = input("Do you want to remove more: (y/N): ")

                if more_input != "y":
                    break

        elif user_input == "3":  # Option to sort in ascending order
            items.sort()

            print("\nItem in sorted order:")

            for item in items:
                print(item)

        elif user_input == "4":  # Option to sort in reverse order
            items.reverse()

            print("\nItems in reverse order:")

            for item in items:
                print(item)

        elif user_input == "5":  # Option to quit.
            print("\nSee you again!")

            break

        else:  # Option to handle invalid input.
            print("\nPlease enter the valid option from the given menu.")

        input("\nPress any key to continue...")


def run_list_manipulation():
    """Running iterations."""
    items = [1, 2, 4, 5, 6, 7, 8, 10, 11, 12, 13, 5, 16, 17, 20, 30, 50, 100]

    print("\na) Printing list in different line.")

    for item in items:
        print(item)

    items.sort()
    print("\nb) Sorted items:", items)

    print("\nc) Largest number:", items[-1], "or", max(items))

    new_items = []
    for item in items:
        if item <= 20:
            new_items.append(item)

    print("\nd) Removed items greater than 20:", new_items)

    new_items.extend([200, 250])
    print("\ne) New list with added 200, 250:", new_items)

    new_items.pop()
    print("\nf) List after popping out 250:", new_items)

    position = len(new_items)
    print(f"\ng) {position}th number is:", new_items[position - 1])

    print("\nh) Total items in original list:", len(items))

    print("\ni) Reverse list", new_items.reverse())

    print("\nj) Largest", new_items[0])

    print("\nk) Total items in updated list:", len(new_items))

    new_items.clear()
    print("\nl) Clearing list", new_items)


if __name__ == "__main__":
    run_list_iterations()    # Calls run list iterations function.
    append_lists()           # Call run list veggies fruits
    run_shopping_cart()      # Call run shopping cart
    run_list_manipulation()  # Call run list manipulation
