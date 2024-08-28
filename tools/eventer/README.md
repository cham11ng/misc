# Eventer

Eventer is a Python script that interacts with the Google Calendar API to display upcoming events and create new events based on a schedule file.

## Prerequisites

Before running the script, make sure you have the following:

- Python 3 installed on your machine.
- Google API credentials file (`credentials.json`) obtained from the Google Cloud Console.
- Access to the Google Calendar API enabled in your Google Cloud project.
- The required Python packages installed. You can install them by running `pip install -r requirements.txt`.

## Setup

1. Install the required Python packages:

    ```shell
    pip install -r requirements.txt
    ```

2. Place your `credentials.json` file in the project directory.

3. Run the script:

    ```shell
    python main.py
    ```

## Usage

The script performs the following actions:

1. Initializes the Google Calendar API and obtains user authorization if necessary.
2. Displays the start and name of the next 10 events on the user's calendar.
3. Parses the event schedule from the `schedule.txt` file.
4. Creates new events on the user's calendar based on the schedule.

You can modify the following files to customize the behavior of the script:

- `schedule.txt`: Contains the event schedule in a specific format. Update this file to define your own events.

    ```txt
    Tuesday, September 10, 2024 6:00 PM - 10:00 PM
    Wednesday, September 11, 2024 3:00 PM - 7:30 PM
    ```

- `credentials.json`: Contains your Google API credentials. Make sure to obtain this file from the Google Cloud Console.
