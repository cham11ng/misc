"""Module: Day 6 Exercise 1: Python - Sagar Chamling Rai"""

import os

os.system("clear")

MONTHS = [
    "Jan",
    "Feb",
    "Mar",
    "Apr",
    "May",
    "Jun",
    "July",
    "Aug",
    "Sept",
    "Oct",
    "Nov",
    "Dec",
]


def calculate_rainfall():
    """
    Write average rainfall in millimeter using python user has to input all twelve months rainfall (mm).
    Please include number of years user has to enter.
    """
    count = 0
    total_temperature = 0
    total_months = len(MONTHS)
    total_years = int(input("Enter total number of years: "))

    for i in range(total_years):
        for j in range(total_months):
            temperature = float(input(f"Enter year {i + 1}, rainfall value in (mm) on {MONTHS[j]}: "))

            total_temperature += temperature
            count += 1

    average = total_temperature / total_months
    print(f"The average rainfall (mm) for {total_years} year(s): {round(average, 2)}")


def check_armstrong():
    """Check given number is armstrong or not."""
    total_sum = 0
    number_str = input("Enter number to check it is armstrong or not: ")
    total_digits = len(number_str)

    for digit in number_str:                     # Loop for each digits.
        total_sum += int(digit) ** total_digits  # Applying armstrong logic.

    if total_sum == int(number_str):             # Comparing total sum with given input.
        print(f"The number {number_str} is armstrong number.")
    else:
        print(f"The number {number_str} is not armstrong number.")


def check_palindrome():
    """Check given number is palindrome or not."""
    number_str = input("Enter number to check it is palindrome or not: ")
    total_digits = len(number_str)

    reverse_str = ""
    for i in range(total_digits, 0, -1):
        reverse_str += number_str[i - 1]         # Calculating reverse string.

    if number_str == reverse_str:                # Comparing input and reversed input string.
        print(f"The number {number_str} is palindrome number.")
    else:
        print(f"The number {number_str} is not palindrome number.")


def generate_output():
    """
    1 ---- 99
    2 ---- 98
    3 ---- 97
    ....
    98 ---- 2
    99 ---- 1
    """

    total = 100
    for i in range(1, total):
        print(i, "----", total - i)


if __name__ == "__main__":
    calculate_rainfall()                         # Call function calculate rainfall program.
    check_armstrong()                            # Call function check armstrong program.
    check_palindrome()                           # Call function check palindrome program.
    generate_output()                            # Call function generate output.
