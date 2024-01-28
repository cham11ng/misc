"""Module: Day 3 Classwork: Python - Sagar Chamling Rai"""

import os

# Program 1 to say hello.


def say_hello():
    """
    Function to say hello world.
    """
    print("Hello, world!")


def hello_name(name):
    """
    Function to say hello and given parameter.

    :param name: Name of the user
    :type name: str
    """
    print("Hello,", name)


say_hello()
hello_name("Sagar")


# Program 2: Create function to convert temperature from celsius to fahrenheit.

os.system("clear")


def convert_celsius_to_fahrenheit(celsius):                   # Function definition.
    """
    Function to convert celsius to fahrenheit based on given parameter celsius.

    :param celsius: _description_
    :type celsius: float
    :return: Fahrenheit
    :rtype: float
    """
    fahrenheit = (celsius * 9 / 5) + 32                       # Formula to convert celsius to fahrenheit.

    return fahrenheit                                         # Returning a result.


temperature = float(input("Enter temperature in Celsius: "))  # Asking for input from user.
result = convert_celsius_to_fahrenheit(temperature)           # Calling a function with input parameter.

print("The temperature in Fahrenheit is", result)             # Printing a result.


# Program 3: Function to convert miles to kilometers

os.system("clear")

MILES_TO_KM = 1.609344


def show_miles(miles):                             # Function Definition
    """
    Convert miles to km.

    :param miles: Miles value
    :type miles: float
    :return: Kilometer value
    :rtype: float
    """
    kilometers = miles * MILES_TO_KM               # Formula to convert miles to km

    return kilometers                              # Returning value


mile = float(input("Enter distance in miles: "))   # Taking input
km = show_miles(mile)                              # Function call
rounded_kms = round(km, 2)                         # Rounded to 2 decimal km value

print("The result in kilometers is", rounded_kms)  # Printing result.

# Program 4: Function to calculate taxi fare

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
