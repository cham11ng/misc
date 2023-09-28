"""
Module: Lab 2 - Program 2 Classwork: Python - Sagar Chamling Rai
Write a Python program for the following scenario using functions and for loop.

Instructions:

Let us suppose your doctor asks you to record your daily data intake of calories during a diet.
Note that every day, the number of calories should be increased by a certain small percentage.
Ask the user to enter the following:
Starting daily calorie intake.
Average daily percentage decrease.
The number of days.
The user must enter only positive values, otherwise an error will be printed on the console, and the user must be prompted to enter the values again.
If the values are positive, you must decrease by the percentage for the specified number of days to the start of the diet.
NOTE: If the diet decreases calories below 1200 then you must stop decreases and produce a note when the diet stabilized.
Note: Day 1 count will start from the original starting count.
Print the calories data on the daily basis.
"""

import os

os.system("clear")


def input_positive_float(prompt_message):
    """Input positive float"""
    while True:                                                            # Indefinite loop until the function is returned.
        value = float(input(prompt_message))
        if value <= 0:                                                     # Check if value is negative number.
            print("Invalid input, should be only positive number. Please enter again.\n")
        else:
            return value                                                   # Returning the value.


def diet_calculator():
    """Diet calculator"""
    starting_calories = input_positive_float("Enter starting daily calorie intake: ")
    percentage_decrease = input_positive_float("Enter average daily percentage decrease (e.g., 0.5 for 0.5%): ")
    num_days = int(input_positive_float("Enter the number of days: "))

    current_calories = starting_calories                                   # Setting starting_calories to current_calories

    for day in range(1, num_days + 1):                                     # Run loop till total number of days.
        print(f"Day {day}: {current_calories:.2f} calories")
        current_calories -= (percentage_decrease / 100) * current_calories # Subtracting percentage decrease in current_calories.

        if current_calories < 1200:                                        # Terminate loop if current_calories decreases less than 1200
            print("The diet has stabilized because calories dropped below 1200.")
            break


if __name__ == "__main__":
    diet_calculator()                                                      # Run diet calculator value
