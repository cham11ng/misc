"""Module: Day 2 Classwork: Python - Sagar Chamling Rai"""

number1 = int(input("Enter a first number: "))
number2 = int(input("Enter a second number: "))
number3 = int(input("Enter a third number: "))

if number1 == number2 == number3:
    print("Total:", (number1 + number2 + number3) * 3)
elif number1 == number2 or number2 == number3 or number3 == number1:
    print("Total:", (number1 + number2 + number3) * 2)
else:
    print("Total", number1 + number2 + number3)
