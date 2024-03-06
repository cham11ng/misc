"""
Module: Python - Sagar Chamling Rai
Solve patient queue minimum time.
"""

import os
import math

os.system("clear")


def min_total_waiting_time(times):
    """Calculate min total waiting time."""
    total_waiting_time = 0
    n = len(times)

    for i in range(1, n):
        minimum_time = math.inf
        minimum_time_index = i - 1

        for j, time in enumerate(times):
            if time is not None and time < minimum_time:
                minimum_time = time
                minimum_time_index = j

        total_waiting_time += (n - i) * minimum_time
        print("+", times[minimum_time_index])
        times[minimum_time_index] = None

    print("------")
    return total_waiting_time


if __name__ == "__main__":
    print("=", min_total_waiting_time([20, 15, 10, 25, 5, 30]))
    print("-------------")
    print("=", min_total_waiting_time([15, 20, 10]))
