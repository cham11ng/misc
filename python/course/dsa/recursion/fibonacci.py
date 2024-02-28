"""
Module: Fibonacci series
"""

import os

os.system("clear")


def fibonacci_slow(position):
    """Recursive fibonacci function"""
    if position <= 1:
        return position

    response = fibonacci_slow(position - 1) + fibonacci_slow(position - 2)

    return response


memo = []


def fibonacci_memoized(position):
    """Memoized approach of fibonacci function"""
    if position <= 1:
        return position

    if position in memo:
        return memo[position]

    return fibonacci_memoized(position - 1) + fibonacci_memoized(position - 2)


def fibonacci_bottom_up(n):
    """Bottom up approach of Fibonacci"""
    prev = 0
    nxt = 1
    count = 0

    while count < n:
        print(nxt, end=" ")

        total = prev + nxt
        prev, nxt = nxt, total

        count += 1


def fibonacci_dynamic(n):
    """
    Dynamic programming approach of fibonacci function.
    => Memoization + Bottom-up
    """
    series = [0, 1]

    for position in range(2, n + 1):
        series.append(series[position - 1] + series[position - 2])

    return series


if __name__ == "__main__":
    TOTAL_SIZE = 10

    print("Fibonacci Slow - O(2^n)")
    for i in range(1, TOTAL_SIZE + 1):
        res = fibonacci_slow(i)
        print(res, end=" ")

    print("\nFibonacci Memoized - O(n)")
    for i in range(1, TOTAL_SIZE + 1):
        res = fibonacci_memoized(i)
        print(res, end=" ")

    print("\nFibonacci Bottom-up - O(n)")
    fibonacci_bottom_up(TOTAL_SIZE)

    print("\nFibonacci Dynamic - O(n)")
    output = fibonacci_dynamic(TOTAL_SIZE)
    print(output)
