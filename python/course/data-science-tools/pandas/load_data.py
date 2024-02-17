""" Module: To introduce pandas """

import pandas as pd

CSV_PATH = "info.csv"

df = pd.read_csv(CSV_PATH)

print("df", df.head())

## series

data = [10, 20, 30, 40, 50]
series = pd.Series(data)

print('series', series)

# accessing by label
print('series[2]:', series[2])
# accessing by position
print('series.iloc[3]', series.iloc[3])
# accessing by multiple elements
print('series[1:4]', series[1:4])
# series attributes and methods
print('series.shape', series.shape)
print('series.mean()', series.mean())
print('series.median()', series.median())

# dataframes can be created out of a dictionary
# keys correspond to the columns headers
# values corresponds to the rows

songs = {
    "Album": ["Thriller", "Back in Black", "The Dark Side of the Moon"],
    "Released": [1982, 1980, 1982],
    "Length": ["00:42:19", "00:42:11", "00:42:49"],
}

songs_df = pd.DataFrame(songs)

print("songs_df:\n", songs_df)
print("songs_df.loc[2]:\n", songs_df.loc[2])
print("songs_df.iloc[1]:\n", songs_df.iloc[1])
print("songs_df.iloc[0, 0]:\n", songs_df.iloc[0, 0])
print("songs_df[['Album', 'Released', 'Length']]:\n", songs_df[["Album", "Released", "Length"]])
