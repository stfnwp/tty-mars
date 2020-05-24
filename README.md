# tty-mars
retrieve mars sol and temperature via http.

## dependencies
- pkg-config (build only)
- curl
- json-c
- ncurses

## consumed API
```
https://api.nasa.gov/insight_weather/?api_key=DEMO_KEY&feedtype=json&ver=1.0
```
By default, the `DEMO_KEY` is used as the API key for the http request. It has a request limit.  
You can increase this limit by providing your own API key. Just assign the key to the environment variable `API_KEY` before calling the command:
```
API_KEY=<your-api-key> tty-mars
```

## thanks
The ncurses output is heavily inspired by [tty-clock](https://github.com/xorg62/tty-clock).