"""Module: Code for ETL operations on Country-GDP data"""

import os
import sqlite3
import requests
import numpy as np
import pandas as pd

from bs4 import BeautifulSoup
from datetime import datetime

os.system("clear")

WIKIPEDIA_GDP_URL = (
    "https://web.archive.org/web/20230902185326/https://en.wikipedia.org/wiki/List_of_countries_by_GDP_%28nominal%29"
)
TABLE_ATTRIBUTES = ["Country", "GDP_USD_millions"]
DB_NAME = "world_economies.db"
TABLE_NAME = "countries_by_gdp"
CSV_PATH = "countries_by_gdp.csv"


def extract(url, table_attributes):
    """
    This function extracts the required
    information from the website and saves it to a dataframe. The
    function returns the dataframe for further processing.
    """
    page_output = requests.get(url, timeout=10)
    html_soup = BeautifulSoup(page_output.text, "html.parser")
    gdp_df = pd.DataFrame(columns=table_attributes)

    tables = html_soup.find_all("tbody")
    rows = tables[2].find_all("tr")

    for row in rows:
        data = row.find_all("td")

        if len(data) == 0:
            continue

        country = data[0].find("a")
        gdp = data[2]

        if country is None or "—" in gdp:
            continue

        row_dict = {"Country": country.text, "GDP_USD_millions": gdp.text}
        row_df = pd.DataFrame(row_dict, index=[0])
        gdp_df = pd.concat([gdp_df, row_df], ignore_index=[0])

    return gdp_df


def convert_currency_to_numeric(currency):
    """
    This function converts the currency text into numeric form.
    """
    return float("".join(currency.split(",")))


def convert_millions_to_billions(millions):
    """
    This function convert millions value to billions and round
    to 2 decimal places.
    """
    return np.round(millions / 1000, 2)


def transform(df):
    """
    This function converts the GDP information from Currency
    format to float value, transforms the information of GDP from
    USD (Millions) to USD (Billions) rounding to 2 decimal places.
    The function returns the transformed dataframe.
    """
    gdp_list = df["GDP_USD_millions"].tolist()
    gdp_list = [convert_millions_to_billions(convert_currency_to_numeric(gdp_value)) for gdp_value in gdp_list]
    df["GDP_USD_millions"] = gdp_list
    df = df.rename(columns={"GDP_USD_millions": "GDP_USD_billions"})

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

    with open("./etl_project_log.txt", "a") as f:
        f.write(timestamp + " : " + message + "\n")


if __name__ == "__main__":
    log_progress("Preliminaries complete. Initiating ETL process.")

    extracted_data = extract(WIKIPEDIA_GDP_URL, TABLE_ATTRIBUTES)
    log_progress("Data Extraction complete. Initiating transformation process.")

    transform_data = transform(extracted_data)
    log_progress("Data Transformation complete. Initiating loading process.")

    load_to_csv(transform_data, "gdp.csv")
    log_progress("Data load to CSV file complete. Initiating SQL connection.")

    sql_connection = sqlite3.connect(DB_NAME)
    log_progress("SQL Connection Initiated. Initiating loading process.")

    load_to_db(transform_data, sql_connection, TABLE_NAME)
    log_progress("Data load to database complete. Running the query")

    query_statement = f"SELECT * from {TABLE_NAME} WHERE GDP_USD_billions >= 100"
    run_query(query_statement, sql_connection)
    log_progress("Run query complete. Closing SQL connection.")

    sql_connection.close()
    log_progress('Process Complete. Connection Closed.')
