"""Module: Day 3 Program 1 Classwork: Python - Sagar Chamling Rai"""

import os

os.system("clear")

# Constant values.
PENNY_VALUE = 1
NICKEL_VALUE = 5
DIME_VALUE = 10
QUARTER_VALUE = 25
PENNIES_IN_DOLLAR = 100


def calculate_total_cents(pennies, nickels, dimes, quarters):
    """
    Function to calculate the total value in cents from given input
    """
    total_cents = (pennies * PENNY_VALUE) + (nickels * NICKEL_VALUE) + (dimes * DIME_VALUE) + (quarters * QUARTER_VALUE)

    return total_cents


def run_dollar_game():
    """
    Function to take input from user and return the result.
    """
    pennies = int(input("Enter the number in pennies: "))
    nickels = int(input("Enter the number in nickels: "))
    dimes = int(input("Enter the number in dimes: "))
    quarters = int(input("Enter the number in quarters: "))

    total_cent = calculate_total_cents(pennies, nickels, dimes, quarters)  # Calculating total value in cents
    total_dollars = total_cent / PENNIES_IN_DOLLAR                         # Calculating total value in dollars

    print("Total dollars: $", total_dollars)

    if total_dollars > 1:                                                  # Comparing total dollar value greater than 1
        print("Sorry, the amount you entered was more than one dollar.")
    elif total_dollars < 1:                                                # Comparing total dollar value less than 1
        print("Sorry, the amount you entered was less than one dollar.")
    else:                                                                  # Comparing total dollar value with exactly 1
        print("Congratulations!\nThe amount you entered was exactly one dollar!\nYou win the game!")


run_dollar_game()                                                          # Calling a function
