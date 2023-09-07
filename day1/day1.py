"""Module: Day 1 Classwork: Python - Sagar Chamling Rai"""

# This program prints Hello, world!

print("Hello, world!")
print('437258xxxx')
print(2 + 2)
print("2 + 2\n")

# Program to input your name and print it.

name = input("Please enter your name: ")
print("Welcome", name, ", we hope you enjoy  CSD110-Python")

# This program ask for input and returns arithmetic operations of two numbers.

# Taking input
number1 = input('Enter number 1: ')
number2 = input('Enter number 2: ')

# String to integer type conversion
x = int(number1)
y = int(number2)

# Performing operation
sum_raw = number1 + number2
addition = x + y
multiply = x * y
divide = x / y
subtract = x - y
modulus = x % y
exponential = x**y
floor = x // y

# Formatting using horizontal tabs
print("\nConcatenation\t of", number1, "and", number2, ":", sum_raw)
print("Sum\t\t\t\t of", x, "and", y, ":", addition)
print("Multiplication\t of", x, "and", y, ":", multiply)
print("Division\t\t of", x, "and", y, ":", divide)
print("Subtraction\t\t of", x, "and", y, ":", subtract)
print("Modulus\t\t\t of", x, "and", y, ":", modulus)
print("Exponential\t\t of", x, "and", y, ":", exponential)
print("Floor division\t of", x, "and", y, ":", floor)

# Formatting and printing it using f-string and triple quotes.
print(f"""
Concatenation  of {x} and {y}: {sum_raw}
Sum            of {x} and {y}: {addition}
Subtract       of {x} and {y}: {subtract}
Multiplication of {x} and {y}: {multiply}
Division       of {x} and {y}: {divide}
Modulus        of {x} and {y}: {modulus}
Exponential    of {x} and {y}: {exponential}
Floor Division of {x} and {y}: {floor}
""")
