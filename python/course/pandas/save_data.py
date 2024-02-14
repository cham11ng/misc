""" Module: to introduce save data in pandas """

import pandas as pd

from songs import songs

songs_df = pd.DataFrame(songs)


# working with dataframes
print("songs_df['Released'].unique():\n", songs_df["Released"].unique())

filtered_songs_df = songs_df[songs_df["Released"] > 1980]

print("songs_df[songs_df['Released'] > 1980]:\n", filtered_songs_df)

filtered_songs_df.to_csv("filtered_songs.csv")
