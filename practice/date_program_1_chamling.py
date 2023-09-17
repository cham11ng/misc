"""
Module: Practice 1: Python - Sagar Chamling Rai
Write a Python code using If-else approach to take date as input (MM/DD/YY) from the user
and print it on screen in below format:

Enter date in MM/DD/YY format à  01/17/2023 (incorrect entry will prompt with appropriate error message)
You have entered January 17, 2023, as the date.
"""

import os

os.system("clear")


def input_date():
    """
    Input date.
    """
    date_str = input("Please enter the date in given format (MM/DD/YY): ")

    return date_str


def validate_input(raw_date):
    """
    Validate input and return the date in list.
    """
    date_list = raw_date.split("/")

    if len(raw_date) == 3:
        print('Error: Invalid date format. (MM/DD/YY)')
        return False

    month, day, year = date_list

    if not month.isdigit() or not day.isdigit() or not year.isdigit():
        print("Error: Date should be all in integer.")
        return False

    return date_list


def format_date(date_list):
    """
    Format date. eg. January 17, 2023.
    """
    month, day, year = date_list
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
        print("Error: Invalid month input, ", month)

        return

    print(f"You have entered {month_str} {int(day)}, 20{year} as the date.")


def main():
    """
    Main function.
    """
    given_date = input_date()

    response = validate_input(given_date)

    if not response:
        return

    format_date(response)


if __name__ == "__main__":
    main()
