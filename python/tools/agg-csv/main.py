"""
CSV Aggregator

Description:
# Sample CSV File 1
Endpoint,Status,Last Online,Issue
A,ONLINE,2024-1-27,Cry
B,OFFLINE,2023-1-20,Unhappy
C,ONLINE,2024-1-27,Surprise
D,OFFLINE,2023-1-10,Shocked
E,OFFLINE,2023-01-09,Sad

# Sample CSV File 2
Endpoint,Status,Last Date Online,Remarks
A,ONLINE,2024-1-27,Cry
B,OFFLINE,2023-1-20,Unhappy
C,ONLINE,2024-1-27,Surprise
D,ONLINE,2024-1-5,Shocked

# Output File
Endpoint,Status,Last Online,Issue,Status 2,Last Date Online 2
A,ONLINE,2024-1-27,Cry,ONLINE,2024-1-27
B,OFFLINE,2023-1-20,Unhappy,OFFLINE,2023-1-20
C,ONLINE,2024-1-27,Surprise,ONLINE,2024-1-27
D,OFFLINE,2023-1-10,Shocked,ONLINE,2024-1-5
E,OFFLINE,2023-01-09,Sad,NA,NA
"""
import csv
import os

FILE2_IDENTIFIER = "2"
MATCHING_COLUMN = "Endpoint"
COLUMN_LIST = ["Status", "Last Date Online"]
FILE_PATH = os.path.abspath(os.path.dirname(__file__))

merged_data = []


def merge_csv_files(file1, file2):
    """
    Merge two csv files based on the column name MATCHING_COLUMN on both files
    and create as new csv formatted variable and print it as output.
    """
    with open(file1, "r", encoding="utf-8") as csv_file1, open(file2, "r", encoding="utf-8") as csv_file2:
        reader1 = csv.DictReader(csv_file1)
        reader2 = csv.DictReader(csv_file2)
        fieldnames = reader1.fieldnames
        fieldnames2 = reader2.fieldnames

        merged_data.append(
            {
                **{fieldname: fieldname for fieldname in fieldnames},
                **{
                    f"{fieldname} {FILE2_IDENTIFIER}": f"{fieldname} {FILE2_IDENTIFIER}"
                    for fieldname in fieldnames2
                    if fieldname in COLUMN_LIST
                },
            }
        )

        for row1 in reader1:
            endpoint1 = row1[MATCHING_COLUMN]
            merged_row = row1
            found_match = False
            for row2 in reader2:
                endpoint2 = row2[MATCHING_COLUMN]
                if endpoint1 == endpoint2:
                    merged_row.update(
                        {
                            f"{fieldname} {FILE2_IDENTIFIER}": value
                            for fieldname, value in row2.items()
                            if fieldname in COLUMN_LIST
                        }
                    )
                    found_match = True
                    break

            if not found_match:
                merged_row2 = {
                    f"{fieldname} {FILE2_IDENTIFIER}": "NA" for fieldname in fieldnames2 if fieldname in COLUMN_LIST
                }
                merged_row.update(merged_row2)

            merged_data.append(merged_row)
            csv_file2.seek(0)

    return merged_data


# Get the absolute path of the csv files
csv1_path = os.path.join(FILE_PATH, "file1.csv")
csv2_path = os.path.join(FILE_PATH, "file2.csv")

merged_data = merge_csv_files(csv1_path, csv2_path)

# Print the merged data in csv format
for row in merged_data:
    print(",".join(row.values()))
