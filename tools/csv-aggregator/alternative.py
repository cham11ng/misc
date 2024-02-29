"""CSV Aggregator"""

import os
import pandas as pd

FILE2_IDENTIFIER = "2"
MATCHING_COLUMN = "Endpoint"
COLUMN_LIST = ["Status", "Last Date Online"]
FILE_PATH = os.path.abspath(os.path.dirname(__file__))

# Read the CSV files
df1 = pd.read_csv(os.path.join(FILE_PATH, "file1.csv"))
df2 = pd.read_csv(os.path.join(FILE_PATH, "file2.csv"))

# Merge the dataframes based on the MATCHING_COLUMN column
merged_df = pd.merge(
    df1, df2, on=MATCHING_COLUMN, how="left", suffixes=("", " " + FILE2_IDENTIFIER)
)

# Create a new column with lowercase values for case-insensitive merging
df1["lower_" + MATCHING_COLUMN] = df1[MATCHING_COLUMN].str.lower()
df2["lower_" + MATCHING_COLUMN] = df2[MATCHING_COLUMN].str.lower()

# Merge the dataframes based on the lowercase column
merged_df = pd.merge(
    df1,
    df2,
    left_on="lower_" + MATCHING_COLUMN,
    right_on="lower_" + MATCHING_COLUMN,
    how="outer",
    suffixes=("", " " + FILE2_IDENTIFIER),
)

# Drop the lowercase column
merged_df.drop(columns=["lower_" + MATCHING_COLUMN], inplace=True)
df1.drop(columns=["lower_" + MATCHING_COLUMN], inplace=True)
df2.drop(columns=["lower_" + MATCHING_COLUMN], inplace=True)

# Fill missing values with "NA"
merged_df = merged_df.fillna("NA")

# Preparing the column list
columns_file1 = df1.columns.tolist()
common_columns = (
    df1.columns.intersection(df2.columns).difference([MATCHING_COLUMN]).tolist()
)
new_column_list = [col for col in COLUMN_LIST if col not in common_columns]

# Selecting only desired columns
new_merged_df = merged_df[
    columns_file1
    + [col + " " + FILE2_IDENTIFIER for col in common_columns]
    + new_column_list
]

# Export the dataframe to CSV
new_merged_df.to_csv(os.path.join(FILE_PATH, "outer_merge.csv"), index=False)
print(new_merged_df)
