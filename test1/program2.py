"""
Module: Test 1: Program 2 - Sagar Chamling Rai
Write a Python program using if-elif-else and nested if-else for the following.

Note: The user must enter the colour in lowercase letters.

Declare the following global variables for the three colours with the following values:
RED = "red"
BLUE = "blue"
YELLOW = "yellow"

This program must prompt the user to input two different primary colours: “colour1” and “colour2.”
Consider the following situations:

If color1 is not a primary colour (RED, BLUE, or YELLOW),
    then print the error message: “Error: Invalid Colour1.”
If color2 is not a primary colour,
    then print the error message: “Error: Invalid Colour2.”
If colour1 and colour2 are the same,
    then print the error message: “Error: The two colours you entered are the same.”
Otherwise, if the inputs are valid, the program will report the secondary colour
    which is the mix of the two primary colours as follows:

When first colour is “RED”:
RED+BLUE=PURPLE
RED+YELLOW=ORANGE
When first colour is “BLUE”:
BLUE+RED=PURPLE
BLUE+YELLOW=GREEN
When first colour is “YELLOW”:
YELLOW+RED=ORANGE
YELLOW+BLUE=GREEN
"""

import os

os.system("clear")

RED = "red"
BLUE = "blue"
YELLOW = "yellow"


def run():
    """
    Run overall program.
    """
    print(f'Accepted Colours: {RED}, {BLUE}, {YELLOW}')
    colour1 = input("Enter the first primary colour in lowercase letters: ")
    colour2 = input("Enter the second primary colour in lowercase letters: ")

    if colour1 != RED and colour1 != BLUE and colour1 != YELLOW:      # Check if colour1 is a primary colour
        print("Error: Invalid Colour1.")
    else:
        if colour2 != RED and colour2 != BLUE and colour2 != YELLOW:  # Check if color2 is a primary colour
            print("Error: Invalid Colour2.")
        else:
            if colour1 == colour2:                                    # Check if color1 and color2 are the same
                print("Error: The two colours you entered are the same.")
            else:                                                     # Determine and print the secondary color
                if colour1 == RED:
                    if colour2 == BLUE:                               # Check condition for colour1 as RED and colour2 as BLUE
                        print("RED+BLUE=PURPLE")
                    elif colour2 == YELLOW:                           # Check condition for colour1 as RED and colour2 as YELLOW
                        print("RED+YELLOW=ORANGE")
                elif colour1 == BLUE:
                    if colour2 == RED:                                # Check condition for colour1 as BLUE and colour2 as RED
                        print("BLUE+RED=PURPLE")
                    elif colour2 == YELLOW:                           # Check condition for colour1 as BLUE and colour2 as YELLOW
                        print("BLUE+YELLOW=GREEN")
                elif colour1 == YELLOW:
                    if colour2 == RED:                                # Check condition for colour1 as YELLOW and colour2 as RED
                        print("YELLOW+RED=ORANGE")
                    elif colour2 == BLUE:                             # Check condition for colour1 as YELLOW and colour2 as GREEN
                        print("YELLOW+BLUE=GREEN")


if __name__ == "__main__":
    run()                                                             # Calls run function.
