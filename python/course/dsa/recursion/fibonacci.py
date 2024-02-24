"""
Module: Fibonacci series
"""

import os

os.system("clear")


def fibonacci(position):
    """Recursive fibonacci function"""
    if position <= 1:
        return 0

    if position == 2:
        return 1

    response = fibonacci(position - 1) + fibonacci(position - 2)

    return response


if __name__ == "__main__":
    for i in range(1, 11):
        res = fibonacci(i)
        print(res, end=" ")
