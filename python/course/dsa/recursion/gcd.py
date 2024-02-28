"""
Module: to find greatest common divisor (GCD)
- each step is reduces the size of numbers by factor of 2
- takes -> log(ab)
- euclidean algorithm
- application cryptography
"""

import os

os.system("clear")


def find_gcd(numerator, denominator):
    """Function to find greatest common divisor"""
    print(f"gcd({numerator}, {denominator})")

    if denominator == 0:
        return numerator

    reminder = numerator % denominator

    return find_gcd(denominator, reminder)


if __name__ == "__main__":
    print(find_gcd(34, 12))
    print(find_gcd(357, 234))
    print(find_gcd(3918848, 1653264))
