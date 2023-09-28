"""
Module: Lab 2 - Program 1 Classwork: Python - Sagar Chamling Rai
Create a Python program to calculate the average daily high temperature and the average monthly high temperature.

Instructions:

Ask the user to enter the number of years.
Prompt the user to input the average high temperature for each month.
You must use while loops here.
After receiving the monthly inputs per year, you must calculate the average high temperature for every year,
along with the average monthly high temperature over the full period.
"""

import os

os.system("clear")

MONTHS = [
    "Jan",
    "Feb",
    "Mar",
    "Apr",
    "May",
    "Jun",
    "July",
    "Aug",
    "Sept",
    "Oct",
    "Nov",
    "Dec",
]


def calculate_temperature():
    """
    Calculate average high temperature.
    """
    total_months = 12
    year_averages = []
    total_year_averages = 0
    total_years = int(input("Enter total number of years: "))  # Asking for total year.

    i = 1
    while i <= total_years:                                    # Running loop for total number of years.
        j = 1
        total_month_temperature = 0
        print('')                                              # Extra line
        while j <= total_months:                               # Running loop for total months in a year.
            temperature = float(input(f"Enter year {i}, average temperature value in (°C) on {MONTHS[j - 1]}: "))

            total_month_temperature += temperature             # Summing temperatures of the same year.
            j += 1

        year_average = total_month_temperature / total_months  # Calculating average temp of that year.
        year_averages.append(year_average)                     # Appending average year temperature in list
        total_year_averages += year_average                    # Adding total year average.
        i += 1

    full_period_average = total_year_averages / total_years    # Calculating full period average.

    k = 0
    print('')
    while k < len(year_averages):                              # Running loop to print each year average.
        print(f"The average high temperature of the year {k + 1} is: {round(year_averages[k], 2)} °C")
        k += 1

    print(f"\nThe average high temperature for {total_years} year(s): {round(full_period_average, 2)} °C")


if __name__ == "__main__":
    calculate_temperature()                                    # Calls calculate_temperature function.
