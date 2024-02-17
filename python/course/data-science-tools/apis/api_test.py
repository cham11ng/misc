""" Module: requests """

import requests

URL = "https://sagarchamling.com/"

r = requests.get(URL, timeout=10)

print(r.status_code)
