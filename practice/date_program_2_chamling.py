"""
Module: Practice 2: Python - Sagar Chamling Rai
Write a Python code using if-elif-else approach to take date as three inputs
    [one for each – month, date, & year] (MM/DD/YY) from the user
    and print it on screen in below format:

Enter date in numeric format DD: _ _ (03)
Enter month in numeric format MM: _ _ (07)
Enter year in numeric format YY: _ _ (22)

Output will be:

You have entered July 3, 2022, as the date.
For all incorrect inputs it should show an error message, e.g., if DD = 32 or 0
    or negative number it displays a message that “You have entered a wrong date”
For all incorrect inputs it should show an error message, e.g., if MM = 13
    or 0 it displays a message that “You have entered a wrong month.”

[Hint: Check what can be done if entered date is February 29, 2022?]
"""

import os

os.system("clear")


def input_date():
    """
    Input date.
    """
    day = input("Enter date in numeric format DD: ")
    month = input("Enter month in numeric format MM: ")
    year = input("Enter year in numeric format YY: ")

    return day, month, year


def validate_input(day, month, year):
    """
    Validate input and return the date in list.
    """
    if (
        not month.isdigit() or not day.isdigit() or not year.isdigit()
    ):                                           # Conditionally check if all inputs are integer or not
        print("Invalid date format. Should be (MM/DD/YY)")
        return False
    if int(month) < 1 or int(month) > 12:        # Checking if month are between 1-12 or not.
        print("You have entered a wrong month.")
        return False
    if int(day) < 1 or int(day) > 31:            # Checking if day are between 1-31 or not.
        print("You have entered a wrong day.")
        return False
    if int(year) < 0 or int(year) > 99:          # Checking if year are between 0-99 or not.
        print("You have entered a wrong year.")
        return False

    actual_year = int(f"20{year}")
    is_leap_year = True if (actual_year % 400 or actual_year % 100 != 0) and actual_year % 4 == 0 else False

    if int(month) != 2:
        return True
    elif is_leap_year:
        if int(month) == 2 and int(day) <= 29:   # Checking february month highest day value in leap year.
            return True
        else:
            print("You have entered a wrong month and day")
            return False
    else:
        if int(month) == 2 and int(day) <= 28:   # Checking february month highest day value in non leap year.
            return True
        else:
            print("You have entered a wrong month and day")
            return False


def format_date(day, month, year):
    """
    Mapping month and format date in human readable form. eg. January 17, 2023.
    """
    month_str = ""

    if month == "01":
        month_str = "January"
    elif month == "02":
        month_str = "February"
    elif month == "03":
        month_str = "March"
    elif month == "04":
        month_str = "April"
    elif month == "05":
        month_str = "May"
    elif month == "06":
        month_str = "June"
    elif month == "07":
        month_str = "July"
    elif month == "08":
        month_str = "August"
    elif month == "09":
        month_str = "September"
    elif month == "10":
        month_str = "October"
    elif month == "11":
        month_str = "November"
    elif month == "12":
        month_str = "December"
    else:
        print("You have entered a wrong month,", month)

        return

    print(f"You have entered {month_str} {int(day)}, 20{year} as the date.")


def main():
    """
    Main function.
    """
    day, month, year = input_date()              # Calling function to take inputs
    response = validate_input(day, month, year)  # Calling function to validate the input values

    if not response:                             # Condition to skip formatting if validation fails.
        return

    format_date(day, month, year)                # Calling function to format date and display result.


if __name__ == "__main__":
    main()
