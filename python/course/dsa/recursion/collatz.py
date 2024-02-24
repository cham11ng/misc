"""
Module: collatz conjecture applies to positive integers and
speculates that it is always possible to get "back to 1"
"""

import os

os.system("clear")


def collatz(position):
    """Recursive collatz conjecture function"""
    print(int(position), end="")

    if position <= 1:
        return 0

    print(end=" -> ")
    if position % 2 == 0:
        return 1 + collatz(position / 2)
    else:
        return 1 + collatz(3 * position + 1)


if __name__ == "__main__":
    for i in range(1, 11):
        collatz(i)
        print()
