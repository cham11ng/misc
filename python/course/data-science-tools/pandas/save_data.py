""" Module: to introduce save data in pandas """

import pandas as pd

SONGS = {
    "Album": ["Thriller", "Back in Black", "The Dark Side of the Moon"],
    "Released": [1982, 1980, 1982],
    "Length": ["00:42:19", "00:42:11", "00:42:49"],
}

songs_df = pd.DataFrame(SONGS)


# working with dataframes
print("songs_df['Released'].unique():\n", songs_df["Released"].unique())

filtered_songs_df = songs_df[songs_df["Released"] > 1980]

print("songs_df[songs_df['Released'] > 1980]:\n", filtered_songs_df)

filtered_songs_df.to_csv("filtered_songs.csv")
