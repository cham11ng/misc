"""
Module: Test 1: Program 3 Classwork - Sagar Chamling Rai
Write a Python program for the following problem.

Let us assume our user is currently working in Germany and wishes
to migrate to another country. Ask the user to enter their annual salary
in euros. Prompt the user to enter the country to which they want to migrate.
Acceptable inputs are: ‘Canada’, ‘USA’, ‘Cambodia’, and ‘United Kingdom’.
Other inputs must be rejected.

By calling the function “convertSalary()”, convert the user’s
salary into the corresponding currency based on the conversion rates given below:

Compare the converted user’s salary against the average salaries
of the respective country given below and print,
“You will be <rich/poor> in <Country Name> with a salary of <Converted Amount> <Currency Name>.”

Average salaries of countries:

Note:

Students must use the concept of functions during conversions and all the other calculations.
The function must return the final output value back to the function call.
Demo program operation 1:

Please enter your salary in Germany in euros: 17,000
Enter the country you want to migrate to: Canada
You will be poor in Canada with a salary of 26520 CAD.

Demo program operation 2:
Please enter your salary in Germany in euros: 17,000
Enter the country you want to migrate to: Cambodia
You will be rich in Cambodia with a salary of 79,120,890 Cambodian Riel.
"""


import os

os.system("clear")

# Acceptable Countries
CANADA = "Canada"
USA = "USA"
UK = "United Kingdom"
CAMBODIA = "Cambodia"

# Average Salaries
UK_SALARY = 45_423
USA_SALARY = 45_000
CANADA_SALARY = 56_000
CAMBODIA_SALARY = 7_649_856

# Since the rate was not mentioned, using the values given in example
UK_RATE = 0.8
USA_RATE = 1.13
CANADA_RATE = 26_520 / 17_000                                                                                      # Using the values from example 1
CAMBODIA_RATE = 79_120_890 / 17_000                                                                                # Using the values from example 2


def convertSalary(salary, rate):
    """Convert salary."""
    return salary * rate                                                                                           # Conversion of salary with given rate.


def evaluateSalary(salary, target):
    """Evaluate salary"""
    status = ""
    currency = ""

    if target.lower() == USA.lower():                                                                              # Comparing with USA salary
        converted_salary = convertSalary(salary, USA_RATE)
        currency = "US Dollars"

        if converted_salary > USA_SALARY:
            status = "rich"
        else:
            status = "poor"
    elif target.lower() == CANADA.lower():                                                                         # Comparing with Canada salary
        converted_salary = convertSalary(salary, CANADA_RATE)
        currency = "CAD"

        if converted_salary > CANADA_SALARY:
            status = "rich"
        else:
            status = "poor"
    elif target.lower() == CAMBODIA.lower():                                                                       # Comparing with Cambodia salary
        converted_salary = convertSalary(salary, CAMBODIA_RATE)
        currency = "Cambodian Riel"

        if converted_salary > CAMBODIA_SALARY:
            status = "rich"
        else:
            status = "poor"
    else:                                                                                                          # Comparing with UK salary
        converted_salary = convertSalary(salary, UK_RATE)
        currency = "Pound Sterling"

        if converted_salary > UK_SALARY:
            status = "rich"
        else:
            status = "poor"

    return status, converted_salary, currency


def main():
    """
    Main function.
    """
    salary = input("Please enter your salary in Germany in euros: ")

    if not salary.isnumeric():                                                                                     # Validating the input value.
        print("Error: Please enter the salary in numeric form.")

        return

    print(f"Allowed Countries: {UK}/{CAMBODIA}/{CANADA}/{USA}")
    target_country = input("Enter the country you want to migrate to: ")

    if target_country != CANADA and target_country != USA and target_country != UK and target_country != CAMBODIA: # Validating acceptable countries
        print("Error: Country not allowed:", target_country)

        return

    status, converted_salary, currency = evaluateSalary(int(salary), target_country)                               # Calling evaluateSalary function.

    print(f"You would be {status} in {target_country} with salary {int(converted_salary)} {currency}")


if __name__ == "__main__":
    main()                                                                                                         # Calls main function.
