""" Module: Interpreting bitcoin data """

import pandas as pd

from pycoingecko import CoinGeckoAPI

cg = CoinGeckoAPI()

bitcoin_data = cg.get_coin_market_chart_by_id(id="bitcoin", vs_currency="cad", days=1)
print(bitcoin_data)

data = pd.DataFrame(bitcoin_data, columns=["timestamps", "prices"])
data["Date"] = pd.to_datetime(data["TimeStamp"], unit="ms")
candlestick_data = data.groupby(data.Date.dt.date).agg({"Price": ["min", "max", "first", "last"]})

print(data)
print(candlestick_data)
