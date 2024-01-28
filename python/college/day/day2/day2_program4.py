"""Module: Day 2 Classwork: Python - Sagar Chamling Rai"""

n = int(input('Enter integer value n: '))

if (n % 2) != 0:            # Condition for Range A odd integer comparison
    print('Range A')
elif n >= 2 and n <= 5:     # Even number Range B comparison between 2 and 5
    print('Range B')
elif n >= 6 and n <= 20:    # Even number Range C comparison between 6 and 20
    print('Range C')
elif n >= 20:               # Even number Range D comparison above 20
    print('Range D')
else:                       # Condition for negative values and other invalid entries.
    print('Undefined Range.')
