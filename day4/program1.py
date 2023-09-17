"""Module: Day 3 Program 1 Classwork: Python - Sagar Chamling Rai"""

import os
from datetime import datetime

os.system("clear")

DEFAULT_WEIGHT = -1


def calculate_bmi(weight, height):
    """
    Calculate BMI.
    """
    bmi_score = weight / (height**2) * 10000

    return round(bmi_score, 1)


def evaluate_bmi(bmi_value, changed_weight, assessment_score):
    """
    Evaluate the bmi score.
    """
    health_score = 0

    print("\n")

    if bmi_value > 30:
        print("\tYou are Obese")
        if changed_weight > 0:
            health_score = health_score - 5

        if changed_weight <= 1:
            health_score = health_score + 5

    elif bmi_value > 25 and bmi_value < 29.9:
        print("\tYou are Overweight")
        if changed_weight > 0:
            health_score = health_score - 3

        if changed_weight <= 1:
            health_score = health_score + 2

    elif bmi_value > 18.5 and bmi_value < 24.9:
        print("\tYou are Healthy")

    elif bmi_value > 17 and bmi_value < 18.4:
        print("\tYou are Underweight")
        if changed_weight < 0:
            health_score = health_score - 3
        if changed_weight >= 1:
            health_score = health_score + 2
    else:
        print("\tYou are Too Thin")
        if changed_weight < 0:
            health_score = health_score - 5
        if changed_weight >= 1:
            health_score = health_score + 5

    return health_score + assessment_score


def analyze_score(result):
    """
    Analyze score
    """
    print("\n\tYour score is:", result)
    if result > 5:
        print("\tGreat condition!")
    elif result >= 3 and result <= 5:
        print("\tNeed a little work")
    elif result >= 1 and result < 3:
        print("\tNeed a lot of work")
    else:
        print("\tAt risk!")


def print_report(weight, changed_weight, days, bmi, health, score):
    """
    Print Report
    """
    print("\tMelanie Diet Clinic")
    print("\t*-------------------------*")

    print("\tPatient weight: ", weight)
    print("\tPatient weight change: ", changed_weight)
    print("\tDays since last visit: ", days)
    print("\t---------------------------")
    print("\tBMI: ", bmi)
    print("\tHealth: ", health)
    print("\t---------------------------")
    print("\tOverall: ", score)


def run_program():
    """
    Run Program.
    """
    is_first_visit = input("Are you a first visit? (Y/n): ")
    current_height = float(input("Enter current height (in meters): "))
    current_weight = float(input("Enter current weight (in kg): "))
    health_assessment = int(input("Enter health assessment (-5 to +5): "))

    if is_first_visit == "Y":
        changed_weight = current_weight - DEFAULT_WEIGHT
        weight_date_diff = datetime.utcnow() - datetime(2000, 1, 1)
        health_assessment = health_assessment + 1
    else:
        last_date = input("Enter the last weighted date yyyy-mm-dd: ")
        last_weight = float(input("Enter the last weight (in kg): "))

        changed_weight = current_weight - last_weight
        weight_date_diff = datetime.utcnow() - datetime.strptime(last_date, "%Y-%m-%d")

        if abs(changed_weight) <= 1:
            health_assessment = health_assessment - 1

    if health_assessment < -5 and health_assessment > 5:
        print("Error: Invalid input")

        return

    bmi = calculate_bmi(current_weight, current_height)
    score = evaluate_bmi(bmi, changed_weight, health_assessment)

    analyze_score(score)

    if is_first_visit == "Y":
        print_report(current_weight, "NEW", "First visit", bmi, health_assessment, score)
    else:
        print_report(current_weight, changed_weight, weight_date_diff, bmi, health_assessment, score)


run_program()
