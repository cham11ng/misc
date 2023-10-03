"""
Module: Practice 4: Python: Python - Sagar Chamling Rai
The average income of a Cyber security professional in

USA = US$55,000
Canada = CAD$72,000
Europe is = 40,000 Euros and
Lebanon = 600,000,000 LBP

Assume this information is used by a professional to migrate to above four countries.
So, allow only four countries choice of migration and consider that the user
is in an Asian country, use conversion ratio is 1US$ = 50 Rs of that Asian country.

Use this info and convert salary to print on screen that:
You will be rich in Lebanon with salary ………………. Or
You will be poor in Canada with salary ………………. Or

Output:
Pls enter your salary in an Asian country = 100,000 Rs
You want to migrate to …………………. (country name – only 4 above countries)

e.g. if entered choice is USA then the message would be:
You would be poor in ……(USA)…………. With salary …………

e.g. if entered choice is Lebanon then the message would be:
You would be rich in ……. with salary …………….
"""

import os

os.system("clear")

USA = "USA"
CANADA = "Canada"
EUROPE = "Europe"
LEBANON = "Lebanon"

US_SALARY = 55_000
CANADA_SALARY = 72_000
EUROPE_SALARY = 40_000
LEBANON_SALARY = 600_000_000


def run_user_interaction():
    """
    Run user interaction.
    """

    salary = int(input("Please enter your salary in an Asian country (Rs): "))
    convert_to = input("You want to migrate to (USA/Canada/Europe/Lebanon): ")

    if convert_to in [USA, CANADA, EUROPE, LEBANON]:
        return salary, convert_to
    else:
        print("Error: Country not allowed:", convert_to)
        run_user_interaction()


def evaluate_salary(salary, convert_to):
    """
    Evaluate salary

    1 USD       => 50 Rs
    $55000 USD  => 50 * 55000 Rs
        -> $72,000 CAD  => $55,000 USD
        -> $72,000 CAD  => Rs 50 * 55,000
        -> $1 CAD       => Rs 50 * 55,000 / 72,000
    """
    us_rate = 50

    if convert_to.lower() == USA.lower():
        converted_salary = salary / us_rate
    elif convert_to.lower() == CANADA.lower():
        canada_rate = US_SALARY / CANADA_SALARY * us_rate
        converted_salary = salary / canada_rate
    elif convert_to.lower() == EUROPE.lower():
        europe_rate = US_SALARY / EUROPE_SALARY * us_rate
        converted_salary = salary / europe_rate
    else:
        lebanon_rate = US_SALARY / LEBANON_SALARY * us_rate
        converted_salary = salary / lebanon_rate

    return round(converted_salary, 2)


def main():
    """
    Main function.
    """
    salary, convert_to = run_user_interaction()

    converted_salary = evaluate_salary(salary, convert_to)

    if converted_salary > salary:
        print(f"You would be rich in {convert_to} with salary {converted_salary}.")
    else:
        print(f"You would be poor in {convert_to} with salary {converted_salary}.")


if __name__ == "__main__":
    main()  # Calls main function.
