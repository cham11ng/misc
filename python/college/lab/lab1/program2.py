"""Module: Day 3 Program 2 Classwork: Python - Sagar Chamling Rai"""

import os

os.system("clear")


def takeInput():
    """
    Program to take two numbers and the operator from the user
    """
    number1 = int(input("Enter the first number: "))
    number2 = int(input("Enter the second number: "))
    operation_operator = input("Enter an operator (+, -, *, /): ")

    return number1, number2, operation_operator


def displayResult(num1, num2, operator):
    """
    Function to perform calculations and display the result
    """
    if operator == "+":                          # Condition to match + and perform an operation
        result = num1 + num2
    elif operator == "-":                        # Condition to match - and perform an operation
        result = num1 - num2
    elif operator == "*":                        # Condition to match * and perform an operation
        result = num1 * num2
    elif operator == "/":                        # Condition to match / and perform an operation
        if num2 == 0:
            print("Error: Division by zero is not possible.")

            return

        result = num1 / num2
    else:
        print("Error: Invalid input operator.")

        return

    print(f"Formula: {num1} {operator} {num2}")  # Display the formula
    print(f"Result: {result}")                   # Display the result


num1, num2, operator = takeInput()               # Calling function to takeInput and setting the return value in num1, numb2 and operator
displayResult(num1, num2, operator)              # Calling a function to display result.
