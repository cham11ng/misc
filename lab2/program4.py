"""
Module: Lab 2 - Program 4 Classwork: Python - Sagar Chamling Rai
Write a Python program for the following scenario by using lists, functions, and loops.

Instructions:

Declare and initialize a 9-integer list with the name “myNumbers.”
During the initialization of this list, store the following numbers in it: 4,6,9,12,17,22,27,33,44.
By using the concept of loops, iterate through the elements of the list one by one and print them on the console.
Sort the list as follows:
First, move through the list and find the largest number left in the list.
Swap that number for the last element in the unsorted list.
Reduce the range of the list you are sorting by 1 and repeat steps a and b until there is only 1
element left to consider.
Print the sorted list.
"""

import os

os.system("clear")


def print_list(given_list):
    """Print given list using for loop."""
    for value in given_list:                             # Looping until the given_list.
        print(value, end=" ")

    print()


def sort_list(given_lists):
    """Sort list."""
    length = len(given_lists)                            # Evaluating length of given_lists.

    for i in range(length - 1):                          # Loop from 1 to length - 1. Last number is not required for iteration.
        max_index = i                                    # Initially setting max_index first one.

        for j in range(i + 1, length):                   # Loop to traverse through other numbers in list
            if given_lists[j] > given_lists[max_index]:  # Compare with largest number.
                max_index = j                            # Set largest number as its max_index for latter swapping.

        given_lists[i], given_lists[max_index] = (
            given_lists[max_index],
            given_lists[i],
        )                                                # Swap the largest in current position i.


def run_list():
    """Running lists."""
    myNumbers = [4, 6, 9, 12, 17, 22, 27, 33, 44]

    print("Given Lists:", end=" ")
    print_list(myNumbers)                                # Call print_list function to print the list

    sort_list(myNumbers)                                 # Call sort_list function with given list.

    print("Sorted Lists:", end=" ")
    print_list(myNumbers)                                # Since the list is passed by reference value, it print the mutated list.


if __name__ == "__main__":
    run_list()  # Calls run_list function.
