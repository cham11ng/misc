""" Module: To read a info.txt file """

# using with will automatically closes files.
with open("info.txt", "r", encoding="utf-8") as file1:
    output = file1.read()
    print("output inside:", output)

print("file.closed:", file1.closed)
print("output outside:", output)

# output every line as an element in a list using method "readlines"
with open("info.txt", "r", encoding="utf-8") as file2:
    output = file2.readline()
    print("output:", output)

    with_position_output = file2.readline(2)
    print("with_position_output:", with_position_output)

    file2.seek(0)

    all_lines = file2.readlines()
    print("all_lines:", all_lines)
