# Program 4: Function to calculate taxi fare

import os

os.system("clear")

HST = 18
TAXI_FARE = 1.5


def calculate_taxi_fare(kilometers):                                     # Function Definition
    """
    Calculate the taxi fare

    :param km: Kilometer value
    :type km: float
    :return: Mile value
    :rtype: float
    """

    taxable_taxi_fare = kilometers * TAXI_FARE                           # Calculating taxable fare

    output = taxable_taxi_fare + (HST / 100 * taxable_taxi_fare)         # Adding 18% HST

    return output                                                        # Returning value


km = float(input("Enter total distance traveled in KM: "))               # Taking input

if km == 0:                                                              # Comparing 0 km distance.
    print("Not enough distance covered. Total Fare: $0")
elif km < 0:                                                             # Comparing less than 0 km distance.
    print("Invalid Input. Please enter the valid distanced in KM.")
else:                                                                    # Function Call
    result = calculate_taxi_fare(km)                                     # Rounding to 2 decimal value only
    rounded_result = round(result, 2)

    print("Total Fare: $", rounded_result)                               # Print value.
