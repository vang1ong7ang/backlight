# backlight

adjust my screen backlight

## compile

```sh
g++ -std=c++17 -Os -o backlight main.cpp
```

```sh
sudo chown root:root backlight
sudo chmod u+s backlight
```

## usage

```sh
<environments> backlight
```

where `<environments>` is a list of environment variables:

- `NAME`: device name (default: the first device found in `/sys/class/backlight`)
- `VAL`: brightness value (default: maximum value)
