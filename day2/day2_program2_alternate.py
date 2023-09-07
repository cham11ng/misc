"""Module: Day 2 Classwork: Python - Sagar Chamling Rai"""

weekday_mapping = {                                 # Dictionary mapping of weekday number to value
    "1": "Sunday",
    "2": "Monday",
    "3": "Tuesday",
    "4": "Wednesday",
    "5": "Thursday",
    "6": "Friday",
    "7": "Saturday"
}

week_day = input("Please enter weekday value (1-7): ")
week_day_number = int(week_day)
weekday = weekday_mapping.get(week_day)

if week_day_number < 1 or week_day_number > 7:     # Checking the input value beyond 1-7.
    print('Invalid entry should be between (1-7)')
elif week_day_number > 1 and week_day_number < 7:   # Checking for weekday value.
    print(weekday, "\nIt is a Weekday")
else:                                               # If the given value is  fails.
    print(weekday, "\nIt is Weekend")
