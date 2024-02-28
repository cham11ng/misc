"""Find max pairwise product"""

import sys


def max_pairwise_product():
    """Find max pairwise product."""
    second_largest = 1
    largest = 1

    for value in sys.argv[1:]:
        if largest < int(value):
            second_largest = largest
            largest = int(value)

        elif second_largest < int(value):
            second_largest = int(value)

    print(second_largest, largest)

    print("Maximum pairwise product:", second_largest * largest)


max_pairwise_product()
