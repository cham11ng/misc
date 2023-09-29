"""
Module: Lab 2 - Program 3 Classwork: Python - Sagar Chamling Rai
Write a Python program using nested for loop to print the following pattern:
"""

import os

os.system("clear")


def run_pattern():
    """Run pattern."""
    for i in range(1, 8):             # Range 1 to total
        for j in range(0, i + 1):     # Range 1 to i+1
            if j == 0 or i == j:      # Condition to match for borders.
                print("#", end="")    # By default end is new line ('\n') so overwriting with nothing as end.
            else:
                print(" ", end="")    # Print empty for ether case.

        print("")                     # Printing it for new line


if __name__ == "__main__":
    run_pattern()  # Calls run_pattern function.
