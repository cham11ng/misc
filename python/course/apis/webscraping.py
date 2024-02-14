"""Module: Scrap web"""

import requests

from bs4 import BeautifulSoup

page = requests.get("https://sagarchamling.com/blogs/", timeout=10).text

soup = BeautifulSoup(page, "html.parser")
articles = soup.find_all(name="article")

for i, row in enumerate(articles):
    cells = row.header.h2.text
    print(cells)
