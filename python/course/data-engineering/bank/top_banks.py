"""Module: Code for ETL operations on Country-GDP data"""

import os
import sqlite3
import requests
import numpy as np
import pandas as pd

from bs4 import BeautifulSoup
from datetime import datetime

os.system("clear")

WIKIPEDIA_BANK_URL = "https://web.archive.org/web/20230908091635/https://en.wikipedia.org/wiki/List_of_largest_banks"
TABLE_ATTRIBUTES = ["Bank_Name", "USD_Billion"]
DB_NAME = "banks.db"
TABLE_NAME = "largest_banks"
CSV_PATH = "banks.csv"


def extract(url, table_attributes):
    """
    This function extracts the required
    information from the website and saves it to a dataframe. The
    function returns the dataframe for further processing.
    """
    page_output = requests.get(url, timeout=10)
    html_soup = BeautifulSoup(page_output.text, "html.parser")
    bank_df = pd.DataFrame(columns=table_attributes)

    tables = html_soup.find_all("tbody")
    rows = tables[0].find_all("tr")

    for row in rows:
        data = row.find_all("td")

        if not data:
            continue

        bank = data[1].find_all("a")
        billion = data[2]

        row_dict = {"Bank_Name": bank[1].text, "USD_Billion": billion.text}
        row_df = pd.DataFrame(row_dict, index=[0])
        bank_df = pd.concat([bank_df, row_df], ignore_index=[0])

    return bank_df


def convert_currency_to_numeric(currency):
    """
    This function converts the currency text into numeric form.
    """
    return float("".join(currency.split(",")))


def transform(df):
    """
    This function converts the GDP information from Currency
    format to float value, transforms the information of GDP from
    USD (Millions) to USD (Billions) rounding to 2 decimal places.
    The function returns the transformed dataframe.
    """
    currency_df = pd.read_csv("exchange_rate.csv")
    exchange_rate = currency_df.set_index("Currency").to_dict()["Value"]
    df["USD_Billion"] = [convert_currency_to_numeric(x) for x in df["USD_Billion"]]
    df["GBP_Billion"] = [np.round(x * exchange_rate["GBP"], 2) for x in df["USD_Billion"]]
    df["EUR_Billion"] = [np.round(x * exchange_rate["EUR"], 2) for x in df["USD_Billion"]]
    df["NPR_Billion"] = [np.round(x * exchange_rate["NPR"], 2) for x in df["USD_Billion"]]

    return df


def load_to_csv(df, csv_path):
    """
    This function saves the final dataframe as a `CSV` file
    in the provided path. Function returns nothing.
    """

    df.to_csv(csv_path)


def load_to_db(df, sql_connection, table_name):
    """
    This function saves the final dataframe as a database table
    with the provided name. Function returns nothing.
    """
    df.to_sql(table_name, sql_connection, if_exists="replace", index=False)


def run_query(statement, sql_connection):
    """
    This function runs the stated query on the database table and
    prints the output on the terminal. Function returns nothing.
    """
    print("Query Statement:", statement)
    output = pd.read_sql(statement, sql_connection)
    print("Query Output:", output)


def log_progress(message):
    """
    This function logs the mentioned message at a given
    stage of the code execution to a log file.
    Function returns nothing
    """
    timestamp_format = "%Y-%h-%d-%H:%M:%S"
    now = datetime.now()
    timestamp = now.strftime(timestamp_format)

    with open("./code_log.txt", "a") as f:
        f.write(timestamp + " : " + message + "\n")


if __name__ == "__main__":
    log_progress("Preliminaries complete. Initiating ETL process.")

    extracted_data = extract(WIKIPEDIA_BANK_URL, TABLE_ATTRIBUTES)
    log_progress("Data Extraction complete. Initiating transformation process.")

    transform_data = transform(extracted_data)
    log_progress("Data Transformation complete. Initiating loading process.")

    load_to_csv(transform_data, "gdp.csv")
    log_progress("Data load to CSV file complete. Initiating SQL connection.")

    sql_connection = sqlite3.connect(DB_NAME)
    log_progress("SQL Connection Initiated. Initiating loading process.")

    load_to_db(transform_data, sql_connection, TABLE_NAME)
    log_progress("Data load to database complete. Running the query")

    query_statement = f"SELECT * FROM {TABLE_NAME}"
    run_query(query_statement, sql_connection)
    log_progress("Run query 1 complete. Closing SQL connection.")

    query_statement = f"SELECT AVG(NPR_Billion) FROM {TABLE_NAME}"
    run_query(query_statement, sql_connection)
    log_progress("Run query 2 complete. Closing SQL connection.")

    query_statement = f"SELECT * FROM {TABLE_NAME} LIMIT 5"
    run_query(query_statement, sql_connection)
    log_progress("Run query 3 complete. Closing SQL connection.")

    sql_connection.close()
    log_progress("Process Complete. Connection Closed.")
