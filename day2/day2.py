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

# Program 2 to result  based on the given weekday value.

week_day_number = int(input("Please enter weekday integer value (1-7): "))

if week_day_number == 1:                            # If else condition for weekdays
    print(week_day_number, 'is Sunday')
elif week_day_number == 2:
    print(week_day_number, 'is Monday')
elif week_day_number == 3:
    print(week_day_number, 'is Tuesday')
elif week_day_number == 4:
    print(week_day_number, 'is Wednesday')
elif week_day_number == 5:
    print(week_day_number, 'is Thursday')
elif week_day_number == 6:
    print(week_day_number, 'is Friday')
elif week_day_number == 7:
    print(week_day_number, 'is Saturday')
else:
    print('Invalid entry, should be between 1 and 7.')

if week_day_number == 1 or week_day_number == 7:     # Checking for weekend.
    print("It is a Weekend")
else:
    if week_day_number > 1 and week_day_number < 7:   # Checking for weekday.
        print("It is a Weekday")


# Program 3 to take three numbers as input and result based on equal values.

x = int(input("Enter a first number: "))
y = int(input("Enter a second number: "))
z = int(input("Enter a third number: "))

if x == y == z:                         # Chained comparison for same values
    print("Total:", (x + y + z) * 3)
elif x == y or y == z or z == x:        # Comparison for at-least two same values
    print("Total:", (x + y + z) * 2)
else:                                   # All values are different
    print("Total", x + y + z)

# Program 4 to perform conditional action based on given integer number.

n = int(input('Enter integer value n: '))

if (n % 2) != 0:            # Condition for Range A odd integer comparison
    print('Range A')
elif n >= 2 and n <= 5:     # Even number Range B comparison between 2 and 5
    print('Range B')
elif n >= 6 and n <= 20:    # Even number Range C comparison between 6 and 20
    print('Range C')
elif n >= 20:               # Even number Range D comparison above 20
    print('Range D')
else:                       # Condition for negative values and other invalid entries.
    print('Undefined Range.')
