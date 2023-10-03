"""
Module: Practice 1: Python - Sagar Chamling Rai
Write a Python code using If-else approach to take date as input (MM/DD/YY) from the user
and print it on screen in below format:

Enter date in MM/DD/YY format à  01/17/2023 (incorrect entry will prompt with appropriate error message)
You have entered January 17, 2023, as the date.
"""

import os
from datetime import datetime

os.system("clear")


def input_date():
    """
    Input date and convert into the string.

    :return: Date input
    :rtype: datetime
    """
    date_str = input("Please enter the date in given format (MM/DD/YYYY): ")

    return datetime.strptime(date_str, "%m/%d/%Y")


def format_date(date_object):
    """
    Format date. eg. January 17, 2023.

    :param date_object: Date object to be formatted
    :type date_object: datetime
    :return: Date string in formatted.
    :rtype: datetime
    """
    return date_object.strftime("%B %d, %Y")


if __name__ == "__main__":
    try:
        given_date = input_date()
        formatted_date = format_date(given_date)

        print("You have entered", formatted_date)
    except ValueError as ex:
        print("Error: Invalid Entry:", ex)
