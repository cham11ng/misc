# wfh-to-timesheet

```sh
(venv) $ ./t --help
usage: t [-h] --token TOKEN [--dry] --days DAYS

optional arguments:
 -h, --help     show this help message and exit
 --token TOKEN  Access Token.
 --dry          DRY Run.
 --days DAYS    Total no. of days..
```

## Prerequisite

Python (3.6+)

## Set and add `TIMESHEET_BASE_APP_URL` variable in ~/zshrc or ~/.bashrc

Get it from the owner. [Note: It's not available here for security reason.]

```sh
export TIMESHEET_BASE_APP_URL=""
```

## Give Executable Permission

```sh
chmod +x t
```

## Fetch access token from browser

> If you see the token stored in cookie use this command in browser console to copy `token` in clipboard.

```js
> copy(document.cookie.split('token=')[1])
```

## For DRY run

```sh
./t --days 30 --token <access_token> --dry
```

## To Transfer

```sh
./t --days 30 --token <access_token>
```
