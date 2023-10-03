"""Module: Day X Classwork: Python - Sagar Chamling Rai"""

import os

os.system("clear")


def run_employee_salaries():
    """Running employee salaries."""
    total_departments = 2
    department_employee_salaries = []

    for j in range(total_departments):
        total_salary = 0
        employee_salaries = []

        total_employees = int(input("Enter total number of employees: "))

        for i in range(total_employees):
            salary = int(input(f"Enter hourly salary of department {j+1} - employee {i+1}: "))

            total_salary += salary
            employee_salaries.append(salary)

        department_employee_salaries.append(employee_salaries)
        avg_salary = sum(employee_salaries) / total_employees
        print(f"The average salary of the department {j+1}:", avg_salary)

        employee_salaries.sort(reverse=True)  # Sorting salary from low to highest.
        print(f"The second richest from the department {j+1}: ", employee_salaries[1])

    common_salaries = list(set(department_employee_salaries[0]) & set(department_employee_salaries[1]))
    print("Common salaries: ", common_salaries)


def is_sorted(lists):
    """Check is sorted or not."""
    result = True
    total = len(lists)

    for i in range(total - 1):
        if lists[i] > lists[i + 1]:
            result = False
            break

    if result:
        print("The list is sorted in ascending order.")
    else:
        print("The list is not sorted in ascending order.")


def is_anagrams(string1, string2):
    """Check given arguments are anagrams or not"""
    list_string1 = list(string1)
    list_string2 = list(string2)

    list_string1.sort()
    list_string2.sort()

    if str(list_string1) == str(list_string2):
        return True

    return False


def run_matrix_operations():
    """
    Run matrix operations
    | a11  a12 | + | b11  b12 | = | a11+b11  a12+b12 |
    | a21  a22 |   | b21  b22 |   | a21+b21  a22+b22 |

    | a11  a12 | + | b11  b12 | = | a11*b11 + a12*b21    a11*b12 + a12*b22 |
    | a21  a22 |   | b21  b22 |   | a21+b11 + a22*b21    a21*b12 + a22*b22 |

    m X n * n X p = m X p
    """

    matrix_a = [[7, 5], [6, 3]]
    matrix_b = [[2, 1], [5, 1]]
    addition_c = [[0, 0], [0, 0]]
    multiply_d = [[0, 0], [0, 0]]
    m = len(matrix_a)
    n = len(matrix_a[0])
    p = len(matrix_b[0])

    for i in range(m):
        for j in range(n):
            addition_c[i][j] = matrix_a[i][j] + matrix_b[i][j]

    for i in range(m):  # Total number of rows to be generated
        for j in range(p):  # Total number columns to be generated
            for k in range(n):  # Total times needs to be added
                multiply_d[i][j] += matrix_a[i][k] * matrix_b[k][j]

    print("Addition:")
    for i in addition_c:
        print(i)
    print("Multiplication:")
    for i in multiply_d:
        print(i)


if __name__ == "__main__":
    # run_employee_salaries()  # Calls run employee_salaries function.
    is_sorted([1, 2, 3, 4, 5])
    is_sorted([1, 2, 3, 5, 3, 7])

    word1 = "listen"
    word2 = "silent"

    if is_anagrams(word1, word2):
        print(f"{word1} and {word2} are anagrams.")
    else:
        print(f"{word1} and {word2} are not anagrams.")

    run_matrix_operations()
