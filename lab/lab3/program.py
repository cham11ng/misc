"""
Module: Lab 3 Classwork: Python - Sagar Chamling Rai
Write a menu-driven program to add or delete products from a shopping cart.
You should use dictionary to store the product and its brand.

WELCOME TO THE AMANDO SHOPPING SITE

Add a product to the cart.
Search for a product.
Delete a product from the cart.
Display the contents of the cart.
Purchase items.
Quit.
Take an empty dictionary with the name “shoppingCart.” The dictionary should always
store “product-name”, “product-price”, and “brand” as key-value pairs.

Based on the user’s input in response to the main menu, do the following:

The user can add a new product to the shopping cart. A maximum of five products
can be entered. If the count is exceeded, then display the following message: “Cart is full.”
Search for a product by its name. If the name is found, then display the results.
If not, display the following message: “No product exists with this name.”
Delete an existing product. If the cart is empty then display the message:
“Cart is empty, no item is found.” If the product is not in the cart, display
the message: “Product not found in cart.”
Display the items in the cart. If there are no items in the cart, then
display the message: “Cart is empty.”
Purchasing items should total up the product prices for the products in
the cart and display the total along with a message: “Complete purchase (Y/N)?”
If the user answers “Y” or “y” then display the message: “Thank you for your business.”
and empty the cart. If the user answers “N” or “n” then display the message:
“Please continue shopping.” If the user answers anything else, display
the message: “Please answer either Y or N.” and repeat this process.
NOTE: If the user tries to purchase an empty cart, display the message:
“Cart is empty, please select an item before completing purchase.”
On entering the sixth option, user exits from the whole program.
"""

import os

MAX_CART_SIZE = 5
shoppingCart = {}
MENU = """
WELCOME TO THE AMANDO SHOPPING SITE:
    1. Add a product to the cart
    2. Search for a product
    3. Delete a product from the cart
    4. Display the contents of the cart
    5. Purchase items
    6. Quit

Total items in cart: {total}
"""


def display_products(cart):
    """Display items in a cart in table format."""

    print(f"\n{'Name':<15} {'Brand':<15} {'Price':<15}")                                          # Header of table
    print(f"{'-'*15:<15} {'-'*15:<15} {'-'*15:<15}")                                              # Boarder of table

    for value in cart.values():
        print(f"{value['product-name']:<15} {value['brand']:<15} ${value['product-price']:<15}")  # Data of table


def take_input():
    """Take input from user and return ."""
    product_name = input("Enter product name: ")
    product_brand = input("Enter product brand: ")
    product_price = float(input("Enter product price: "))

    return (product_name.upper(), product_brand, product_price)


def add_product():
    """Add a product to the cart."""
    if len(shoppingCart) >= MAX_CART_SIZE:                                                        # Compare with Max cart size.
        print("Cart is full.")
    else:
        (product_name, product_brand, product_price) = take_input()                               # Call take input function and store it in tuple variable.

        shoppingCart[product_name] = {                                                            # Add product to shopping cart dictionary.
            "product-name": product_name,
            "brand": product_brand,
            "product-price": product_price,
        }

        print(f"\n{product_name} has been added to the cart.")


def search_product():
    """Search for a product by its name."""
    if not shoppingCart:
        print("Cart is empty.")
    else:
        product_name = input("Enter product name to search: ")
        found = False

        for key, value in shoppingCart.items():
            if value["product-name"] == product_name.upper():                                     # Compare user product name with product name of items in shopping cart.
                found = True
                display_products({key: value})
                break

        if not found:
            print("\nNo product exists with this name.")


def complete_purchase():
    """Complete the purchase."""
    if not shoppingCart:
        print("Cart is empty, please select an item before completing purchase.")
        return

    total_price = 0

    for value in shoppingCart.values():
        total_price += value["product-price"]

    print(f"Total Price: ${total_price}")

    while True:                                                                                   # Asking user to complete purchase or not. Run loop infinitely unless valid input is given to break statement.
        choice = input("\nComplete purchase (Y/N)? ")

        if choice.upper() == "Y":
            print("\nThank you for your business.")
            shoppingCart.clear()                                                                  # Clearing shopping cart after purchase.

            break

        elif choice.upper() == "N":
            break

        else:
            print("\nPlease answer either Y or N.")


def delete_product():
    """Remove a product from the cart."""
    if not shoppingCart:
        print("Cart is empty, no item is found.")
    else:
        product_name = input("Enter product name to delete: ")
        found = False

        for key, value in shoppingCart.items():
            if value["product-name"] == product_name.upper():
                found = True
                display_products({key: value})

                del shoppingCart[key]                                                             # Deleting item using it's key from shopping cart dictionary.

                print("\nProduct removed.")
                break

        if not found:
            print("\nProduct not found in cart")


def run_shopping_cart():
    """Run shopping cart program"""
    while True:
        os.system("clear")

        print(MENU.format(total=len(shoppingCart)))
        choice = input("Your choice: ")

        print()

        if choice == "1":
            add_product()

        elif choice == "2":
            search_product()

        elif choice == "3":
            delete_product()

        elif choice == "4":
            display_products(shoppingCart)

        elif choice == "5":
            complete_purchase()

        elif choice == "6":
            print("See you again!")
            break

        else:
            print("Please enter a valid input:")

        input("\nPress any key to continue...")


if __name__ == "__main__":
    run_shopping_cart()
