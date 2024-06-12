# proveskit-fprime

## Getting Started

You must already have python 3.10+ installed.

1. Clone this repo and cd into the directory
1. Download fprime `git submodule update --init`
1. Setup virtual env `python -m venv fprime-venv`
1. Install the arduino CLI into the venv `curl -fsSL https://raw.githubusercontent.com/arduino/arduino-cli/master/install.sh | BINDIR=$VIRTUAL_ENV/bin sh`
1. Install the arduino CLI wrapper package into the venv `pip install arduino-cli-cmake-wrapper`
1. Install fprime requirements `pip install -r fprime/requirements.txt`
1. Initialize the arduino CLI `arduino-cli config init`
1. Add the adafruit board manager url
```
arduino-cli config add board_manager.additional_urls https://adafruit.github.io/arduino-board-index/package_adafruit_index.json
arduino-cli config add board_manager.additional_urls https://github.com/earlephilhower/arduino-pico/releases/download/global/package_rp2040_index.json
```
1. Install the M0 board package ```
arduino-cli core install adafruit:samd
arduino-cli core install rp2040:rp2040
```
1. (Only on linux) Download the udev rules `curl -fsSL -o /etc/udev/rules.d/99-adafruit-boards.rules https://raw.githubusercontent.com/fprime-community/fprime-tutorial-arduino-blinker/main/docs/rules/99-adafruit-boards.rules`
1. Install the arduino time library `arduino-cli lib install Time`

## Test Deployment

`fprime-util generate`
`fprime-util build`
