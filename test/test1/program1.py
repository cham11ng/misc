"""
Module: Test 1: Program 1 Classwork - Sagar Chamling Rai
Write a Python program using if-elif-else approach for the following problem.

Display the following messages and get inputs from the user:

Enter the month in the numeric form.
Enter the day in numeric form.
Enter the year in two numeric digits (for example: 98, 20, 21).
In case of an invalid user input for day, month, or year, print the following messages:

Month: “Error: Invalid Month Input”
Day: “Error: Invalid Day Input”
Year: “Error: Invalid Year Input”
Check that you have been given an appropriate day input for a particular month.
For example, the 48th of a month or the 30th of February are not valid.
For simplicity’s sake, you can assume that any 4th year has a 29th of February
rather than do the full calculation. If the day is not appropriate,
print the following message: “Error: There is no such date in the calendar.”

For all valid inputs from the user, print the date with all three inputs
in a date format along with the following message:

“Success: Congratulations! You entered a correct date.”
"""

import os

os.system("clear")


def run():
    """
    Run program.
    """
    month = input("Enter the month in the numeric form: ")
    day = input("Enter the day in numeric form: ")
    year = input("Enter the year in two numeric digits (for example: 98, 20, 21): ")

    if (not month.isdigit() or not day.isdigit() or not year.isdigit()):  # Conditionally check if all inputs are integer or not
        print("Error: The input are not in numeric form.")
        return

    if len(year) != 2 or int(year) < 0 or int(year) > 99:                 # Checking if year are between 0-99 or not.
        print("Error: Invalid Year Input")
        return

    if int(month) < 1 or int(month) > 12:                                 # Checking valid month range between 1-12 or not.
        print("Month: Error: Invalid Month Input")
    else:
        actual_year = int(year)
        is_leap_year = True if (actual_year % 400 or actual_year % 100 != 0) and actual_year % 4 == 0 else False
        max_days = 31

        if int(month) == 2:
            if is_leap_year:                                              # Conditionally setting max number of days in case of leap year in Feb month.
                max_days = 29
            else:
                max_days = 28

    if int(day) < 1 or int(day) > max_days:                               # Checking if day are between 1-31 or not.
        print("Error: Invalid Day Input")
        return
    else:                                                                 # Valid case
        print("Success: Congratulations! You entered a correct date.")
        print(f"Date: {month}/{day}/20{year}")


if __name__ == "__main__":
    run()                                                                 # Calls run function.
