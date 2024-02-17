# csv-aggregator

Compare two CSV files and perform difference merge into new file.

## Sample CSV File 1

```csv
Endpoint,Status,Last Online,Issue
A,ONLINE,2024-1-27,Cry
B,OFFLINE,2023-1-20,Unhappy
C,ONLINE,2024-1-27,Surprise
D,OFFLINE,2023-1-10,Shocked
E,OFFLINE,2023-01-09,Sad
```

## Sample CSV File 2

```csv
Endpoint,Status,Last Date Online,Remarks
A,ONLINE,2024-1-27,Cry
B,OFFLINE,2023-1-20,Unhappy
C,ONLINE,2024-1-27,Surprise
D,ONLINE,2024-1-5,Shocked
```

## Output File

```csv
Endpoint,Status,Last Online,Issue,Status 2,Last Date Online 2
A,ONLINE,2024-1-27,Cry,ONLINE,2024-1-27
B,OFFLINE,2023-1-20,Unhappy,OFFLINE,2023-1-20
C,ONLINE,2024-1-27,Surprise,ONLINE,2024-1-27
D,OFFLINE,2023-1-10,Shocked,ONLINE,2024-1-5
E,OFFLINE,2023-01-09,Sad,NA,NA
```
