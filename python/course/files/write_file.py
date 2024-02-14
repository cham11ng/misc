""" Module: To write a info.txt file """

file1 = open("info.txt", "a+", encoding="utf-8")

file1.seek(0)

output = file1.readlines()

print("output:", output)

file1.write('new line added using write function\n')
file1.close()

print("file1.closed:", file1.closed)
