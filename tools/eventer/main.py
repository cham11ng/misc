import datetime
import os.path

from google.auth.transport.requests import Request
from google.oauth2.credentials import Credentials
from google_auth_oauthlib.flow import InstalledAppFlow
from googleapiclient.discovery import build
from googleapiclient.errors import HttpError

# If modifying these scopes, delete the file token.json.
SCOPES = ["https://www.googleapis.com/auth/calendar"]
DATETIME_FORMAT = "%A, %B %d, %Y %I:%M %p"


def init():
    """Initializes the Google Calendar API."""
    creds = None

    # The file token.json stores the user's access and refresh tokens, and is
    # created automatically when the authorization flow completes for the first
    # time.
    if os.path.exists("token.json"):
        creds = Credentials.from_authorized_user_file("token.json", SCOPES)
    # If there are no (valid) credentials available, let the user log in.
    if not creds or not creds.valid:
        if creds and creds.expired and creds.refresh_token:
            creds.refresh(Request())
        else:
            flow = InstalledAppFlow.from_client_secrets_file("credentials.json", SCOPES)
            creds = flow.run_local_server(port=0)
        # Save the credentials for the next run
        with open("token.json", "w") as token:
            token.write(creds.to_json())

    return creds


def display_events(service):
    """Displays the start and name of the next 10 events on the user's calendar."""
    now = datetime.datetime.utcnow().isoformat() + "Z"  # 'Z' indicates UTC time
    print("Getting the upcoming 10 events")

    events_result = (
        service.events()
        .list(
            calendarId="primary",
            timeMin=now,
            maxResults=10,
            singleEvents=True,
            orderBy="startTime",
        )
        .execute()
    )
    events = events_result.get("items", [])

    if not events:
        print("No upcoming events found.")
        return

    # Prints the start and name of the next 10 events
    for event in events:
        date = event["start"].get("dateTime").split("T")[0]
        start = event["start"].get("dateTime").split("T")[1].split("-")[0]
        end = event["end"].get("dateTime").split("T")[1].split("-")[0]

        print(date, ":", event["summary"], "(", start, "-", end, ")")


def create_event(service, start_time, end_time):
    """Creates a new event on the user's calendar."""
    event = {
        "summary": "Job",
        "location": "10 The Queensway, Toronto, M6R 1B4",
        "start": {
            "dateTime": start_time,
            "timeZone": "America/New_York",
        },
        "end": {
            "dateTime": end_time,
            "timeZone": "America/New_York",
        },
    }
    created_event = service.events().insert(calendarId="primary", body=event).execute()
    print(f"Created event: {created_event['id']}")


def parse_events():
    """Parses the event string and returns a list of event tuples."""
    with open("schedule.txt", "r") as file:
        event_str = file.read()

    events = []
    lines = event_str.strip().split("\n")

    for line in lines:
        date_time_range = line.split(", BK")[0]

        if not date_time_range:
            return []

        start_str, end_str = date_time_range.split(" - ")

        start_dt = datetime.datetime.strptime(start_str, DATETIME_FORMAT)
        end_dt_time = datetime.datetime.strptime(end_str, "%I:%M %p")

        # Adjust end date if the end time is earlier than the start time
        end_dt = datetime.datetime.strptime(start_str, DATETIME_FORMAT)

        if end_dt_time.time() < start_dt.time():
            end_dt += datetime.timedelta(days=1)

        end_dt = end_dt.replace(hour=end_dt_time.hour, minute=end_dt_time.minute)

        events.append((start_dt.strftime(DATETIME_FORMAT), end_dt.strftime(DATETIME_FORMAT)))

    return events


def list_calenders(service):
    print("Fetching all calendars:")
    calendar_list = service.calendarList().list().execute().get("items", [])
    for calendar in calendar_list:
        print(calendar["id"])


def main():
    """Shows basic usage of the Google Calendar API.
    Prints the start and name of the next 10 events on the user's calendar.
    """
    try:
        creds = init()
        service = build("calendar", "v3", credentials=creds)

        display_events(service)

        events = parse_events()

        for start_time_str, end_time_str in events:
            start_time = datetime.datetime.strptime(start_time_str, DATETIME_FORMAT).isoformat()
            end_time = datetime.datetime.strptime(end_time_str, DATETIME_FORMAT).isoformat()
            create_event(service, start_time, end_time)

    except HttpError as error:
        print(f"An error occurred: {error}")


if __name__ == "__main__":
    main()
