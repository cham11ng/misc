"""Module: Day 8 Classwork: Python - Sagar Chamling Rai"""

import os

os.system("clear")


# dict.update({}) duplicate key override
# len(dict)
# for i in dict # keys
# dict.keys()
# dict.items()
# dict.pop(')
# dict.popitem() // Last one
# sorted(dict)


def dict_intro():
    """Dictionary"""
    college = {"Name": "triOS", "Program": "Cybersecurity", "Year": "2022", "Course": "CSD105-Python"}

    print(college["Program"])
    print(college["Year"])
    x = college.get("Name")
    print(x)
    print(college.get("Course"))
    # print(histogram())


def dict_fruits():
    """Fruits Dictionary"""
    fruits = {
        "fruit4": "Litchi",
        "fruit1": "Apple",
        "fruit2": "Grape",
        "fruit3": "Mango",
        "fruit0": "Dragon Fruit",
        "fruit9": "Pomegranate",
    }
    print(fruits["fruit1"])
    print(fruits["fruit2"])
    print(fruits["fruit3"])
    print("Name of the fruit 3 is ", fruits["fruit3"])

    fruits.update({"fruit5": "Banana"})
    fruits["fruit6"] = "Kiwi"

    print()
    print(fruits)

    fruits["fruit3"] = "Nadeem"
    fruits.update({"fruit2": "Ali"})
    print()
    print(fruits)

    fruits.pop("fruit3")
    print()
    print(fruits)

    print()

    print("Sorted fruits", sorted(fruits))

    for key, value in fruits.items():
        print(key, value)


def student_dict():
    """Student list"""
    students = {}
    i = 0

    while True:
        student = input("Please enter student name ('no' to exit): ")

        if student.lower() == "no":
            break

        students[i] = student
        i += 1

    print("\n", students)


if __name__ == "__main__":
    dict_intro()  # Calls dict_intro function
    dict_fruits()
    student_dict()
