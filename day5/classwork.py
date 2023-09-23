"""Module: Day 5 Classwork: Python - Sagar Chamling Rai"""

import os

os.system("clear")


def run_loop_basic():
    """Main function."""
    i = 1

    # Program to print numbers.

    while i < 6:
        print(i)
        i += 1

    # Program to print even number only.

    i = 1
    while i <= 30:
        if i % 2 == 0:
            print(i)

        i += 1

    # Program to print odd number only.

    i = 1
    while i <= 30:
        if i % 2 != 0:
            print(i)

        i += 1

    # Program to take input as score.

    score = 0
    scores = 0
    course_count = 1

    while score != -1:  # Sentinel loop
        input_text = "Enter your scores from last semester course " + str(course_count) + " (-1) to terminate: "
        score = int(input(input_text))
        scores += score
        course_count += 1

    print("Total Score:", scores)

    # Program to take valid age until user hits the age in correct range.

    age = int(input("Enter your valid age: "))

    while not 1 < age < 100:
        if age == 0 or age == -1:
            print("You have entered the invalid input.")

        age = int(input("Enter your valid age: "))

    print("Finally, your age is", age)

    # Program to print average temperature of the year.

    months = [
        "Sept 1, 2022",
        "Oct 1, 2022",
        "Nov 1, 2022",
        "Dec 1, 2022",
        "Jan 1, 2023",
        "Feb 1, 2023",
        "Mar 1, 2023",
        "Apr 1, 2023",
        "May 1, 2023",
        "Jun 1, 2023",
        "July 1, 2023",
        "Aug 1, 2023",
        "Sept 1, 2023",
    ]
    count = 0
    total_temperature = 0
    total_months = len(months)

    while count < total_months:
        temperature = float(input(f"Enter temperature in (°C) on {months[count]}: "))

        total_temperature += temperature
        count += 1

    average = total_temperature / total_months
    print("The average temperature  (°C) for 12 months :", round(average, 2))


def run_nested_loop():
    """Run nested loop"""
    # Program using for loop.

    for i in range(2, 4):
        for j in range(1, 2):
            print(i, j)

    # Program for patterns.

    # *
    # **
    # ***
    # ****
    # *****
    for i in range(1, 6):          # Range 1 to 5
        for j in range(1, i + 1):  # Range 1 to i+1
            print("*", end="")     # By default end is new line ('\n') so overwriting with nothing as end

        print("")                  # Printing it for new line

    # 1
    # 22
    # 333
    # 4444
    # 55555
    # 666666
    # 7777777
    for i in range(1, 8):
        for j in range(1, i + 1):
            print(i, end="")

        print("")

    # 1
    # 23
    # 345
    # 4567
    # 56789
    for i in range(1, 6):
        for j in range(i, i + i):
            print(j, end="")

        print("")

    # 54321
    # 4321
    # 321
    # 21
    # 1
    for i in range(5, 0, -1):
        for j in range(i, 0, -1):
            print(j, end="")

        print("")

    # *
    # * *
    # *   *
    # *     *
    # *       *
    # *         *
    # *           *
    # *             *
    # *               *
    total = 9

    for i in range(1, total + 1):    # Range 1 to total
        for j in range(1, i + 1):    # Range 1 to i+1
            if j == 1 or i == j:     # Condition to match for borders.
                print("* ", end="")  # By default end is new line ('\n') so overwriting with nothing as end.
            else:
                print("  ", end="")  # Print empty for ether case.

        print("")                    # Printing it for new line


if __name__ == "__main__":
    run_loop_basic()                 # Calls loop basic.
    run_nested_loop()                # RUn nested loop.
