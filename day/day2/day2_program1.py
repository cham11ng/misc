"""Module: Day 2 Classwork: Python - Sagar Chamling Rai"""

# Program 1 to compare two given numbers are equal or not

import os

os.system('clear')

a = int(input('Please enter first number: '))
b = int(input('Please enter second number: '))

if a == b:  # Conditional statement to check if a and b are equal or not equal
    print(a, "is equal to", b)
else:
    print(a, "is not equal to", b)
