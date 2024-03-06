"""
Module: Python - Sagar Chamling Rai
Generate the largest number from the given list of numbers.
"""

import os

os.system("clear")


def find_largest_number(numbers):
    """
    Finds the largest number from a list of numbers.
    """
    largest_numbers = ""

    # repeat while there are digits in the list
    while len(numbers) > 0:
        # find max digit index
        largest_index = 0

        for i, number in enumerate(numbers):
            if number > numbers[largest_index]:
                largest_index = i

        # append it to the number
        largest_numbers += str(numbers[largest_index])

        # remove it from the list of digits
        del numbers[largest_index]

    return largest_numbers


if __name__ == "__main__":
    nums = [51, 6, 1, 9]
    print(find_largest_number(nums))
