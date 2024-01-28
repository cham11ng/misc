"""Module: Day 6 Exercise 2: Python - Sagar Chamling Rai"""

import os

os.system("clear")


def print_factorial():
    """Program to print factorial of a given number."""

    number_rg = int(input("Enter number to calculate factorial: "))
    factorial = 1

    for i in range(1, number_rg + 1):
        factorial *= i

    print(f"The factorial of {number_rg} is {factorial}")


def fibonacci_series():
    """Return fibonacci series."""
    # 1 1 2 3 5

    previous_number = 0
    next_number = 1

    print("The first 10 Fibonacci series are:", end=" ")

    while next_number <= 10:
        print(next_number, end=" ")
        total_sum = previous_number + next_number
        previous_number = next_number
        next_number = total_sum

    print("")


def calculate_sum():
    """Calculate sum till the range."""
    number_rg = int(input("Enter range number to sum up: "))

    sum_rg = 0
    for i in range(1, number_rg + 1):
        sum_rg += i

    print(f"Total sum of given range number {number_rg} is {sum_rg}.")


def reverse_range():
    """Display -10 to -1"""

    for i in range(-10, 0):
        print(i)


def run_pattern_loop(start, end, step):
    """Run pattern loop"""
    border = f"#{'='* 16}#"
    for line in range(start, end, step):
        if line == 0 and step == 1:   # Top Border
            print(border)

        spaces = " " * (6 - (2 * line))
        dots = "." * (line * 4)
        print(f"|{spaces}<>{dots}<>{spaces}|")

        if line == 0 and step == -1:  # Bottom Border
            print(border)


def mirror_lecture():
    """
    #================# space-(2*line)   dot+(4*line)   line
    |      <><>      |      6               0           0
    |    <>....<>    |      4               4           1
    |  <>........<>  |      2               8           2
    |<>............<>|      0               12          3
    |<>............<>|      0               12          3
    |  <>........<>  |      2               8           2
    |    <>....<>    |      4               4           1
    |      <><>      |      6               0           0
    #================#
    """
    run_pattern_loop(0, 4, 1)
    run_pattern_loop(3, -1, -1)


if __name__ == "__main__":
    print_factorial()                 # Call function calculate rainfall program.
    fibonacci_series()                # Call function check armstrong program.
    calculate_sum()                   # Call function check palindrome program.
    reverse_range()                   # Call function generate output.
    mirror_lecture()                  # Call function mirror lecture.
