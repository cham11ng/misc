"""Module: Day 2 Classwork: Python - Sagar Chamling Rai"""

week_day_number = int(input("Please enter weekday integer value (1-7): "))

if week_day_number == 1:                            # If else condition for weekdays
    print(week_day_number, 'is Sunday')
elif week_day_number == 2:
    print(week_day_number, 'is Monday')
elif week_day_number == 3:
    print(week_day_number, 'is Tuesday')
elif week_day_number == 4:
    print(week_day_number, 'is Wednesday')
elif week_day_number == 5:
    print(week_day_number, 'is Thursday')
elif week_day_number == 6:
    print(week_day_number, 'is Friday')
elif week_day_number == 7:
    print(week_day_number, 'is Saturday')
else:
    print('Invalid entry, should be between 1 and 7.')

if week_day_number == 1 or week_day_number == 7:     # Checking for weekend.
    print("It is a Weekend")
else:
    if week_day_number > 1 and week_day_number < 7:   # Checking for weekday.
        print("It is a Weekday")
