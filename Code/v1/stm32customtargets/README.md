# CUSTOM boards with STM32

Feel free to propose your custom boards support in mbed-os!


Table of Contents
=================

* [Usage](#usage)
* [GENERIC BOARDS](#generic-boards)
* [STM32F1](#stm32f1)
   * [BLUEPILL](#bluepill)
* [STM32F4](#stm32f4)
   * [CORE2](#core2)
* [STM32L0](#stm32l0)
   * [MURATA LPWAN Wireless Module](#murata-lpwan-wireless-module)
   * [MURATA Grasshopper](#murata-grasshopper)
   * [MURATA Gnat](#murata-gnat)
* [STM32L4](#stm32l4)
   * [STWIN SensorTile Wireless Industrial Node development kit](#stwin-sensortile-wireless-industrial-node-development-kit)
* [STM32WL](#stm32wl)
   * [Seeed Studio LoRa E5](#seeed-studio-lora-e5)
   * [Seeed Studio LoRa E5 Mini](#seeed-studio-lora-e5-mini)
   * [Seeed Studio LoRa E5 Dev Board](#seeed-studio-lora-e5-dev-board)
   * [Charles's LoRa-E5 breakout board](#charless-lora-e5-breakout-board)
   * [Charles's LoRa-E5 Tiny](#charless-lora-e5-tiny)
   * [RAK Wireless RAK3172](#rak-wireless-rak3172)
   * [Charles's RAK3172 breakout board](#charless-rak3172-breakout-board)
* [License](#license)
* [Contributions](#contributions)
   * [Automatic pull request checks](#automatic-pull-request-checks)
   * [Manual pull request checks](#manual-pull-request-checks)
   * [Automatic weekly non regression](#automatic-weekly-non-regression)


# Usage

In your application, clone this repo.

````
git clone https://github.com/ARMmbed/stm32customtargets.git
````

Copy custom_targets.json

````
cp stm32customtargets/custom_targets.json .
````

For some targets, you have to customize the configuration in your local mbed_app.json.

Details are explained for each target below, but you can also use the mbed_app_template.json file as example.

Then build your target with

- CLI1:
````
mbed compile -m XXX -t XXX
````

- CLI2:

Add in the application CMakeLists.txt:
````
add_subdirectory(stm32customtargets)
````
And build:
````
mbedtools compile -m XXX -t XXX
````


# GENERIC BOARDS

A "generic" board is a mbed-os "virtual" target with a pure STM32 MCU.

Goal is to make real custom boards creation very easy
as we ensure that build has alrady been tested.

Check the GENERIC_TARGET branch in this repo:

https://github.com/ARMmbed/stm32customtargets/tree/GENERIC_TARGET


# STM32F1

## BLUEPILL

<img src="https://stm32-base.org/assets/img/boards/STM32F103C8T6_Blue_Pill-1.jpg" width="200">

MCU: STM32F103C8T6

TARGET: BLUEPILL_F103C8



source: https://os.mbed.com/users/hudakz/code/mbed-os-bluepill/

 (https://os.mbed.com/users/hudakz/code/STM32F103C8T6_Hello/)


# STM32F4

## CORE2 

MCU: STM32F407ZG

TARGET: CORE2

https://github.com/byq77/core2-mbed6-template

<img src="https://husarion.com/docs/assets/img/core2-hardware/core2_top_small.jpg" width="200"/>


# STM32L0

## MURATA LPWAN Wireless Module

MCU: STM32L082CZ

TARGET: MTB_MURATA_ABZ

https://wireless.murata.com/type-abz-078.html

- LORA is not enabled by default. You need to update your local mbed_app.json file:

```json
{
    "target_overrides": {
        "MTB_MURATA_ABZ": {
            "target.components_add":             ["SX1276"],
            "sx1276-lora-driver.spi-mosi":       "LORA_SPI_MOSI",
            "sx1276-lora-driver.spi-miso":       "LORA_SPI_MISO",
            "sx1276-lora-driver.spi-sclk":       "LORA_SPI_SCLK",
            "sx1276-lora-driver.spi-cs":         "LORA_CS",
            "sx1276-lora-driver.reset":          "LORA_RESET",
            "sx1276-lora-driver.dio0":           "LORA_DIO0",
            "sx1276-lora-driver.dio1":           "LORA_DIO1",
            "sx1276-lora-driver.dio2":           "LORA_DIO2",
            "sx1276-lora-driver.dio3":           "LORA_DIO3",
            "sx1276-lora-driver.txctl":          "LORA_ANT_TX",
            "sx1276-lora-driver.rxctl":          "LORA_ANT_RX",
            "sx1276-lora-driver.pwr-amp-ctl":    "LORA_ANT_BOOST"
        }
    }
}
```

If you need to Low Power with VDD TXCO like [b-l072z-lrwan1](https://www.st.com/en/evaluation-tools/b-l072z-lrwan1.html), then you need JP9 positionned 1-2.
And reflect the pin used for that because it's defined to `NC` by default.

```json
{
    "target_overrides": {
        "MTB_MURATA_ABZ": {
            "sx1276-lora-driver.tcxo":           "PA_12"
        }
    }
}
```

## MURATA Grasshopper

MCU: STM32L082CZ

<img src="https://cdn.hackaday.io/images/6752761516323719376.jpg" width="200"/>

TARGET: GRASSHOPPER [TleraCorp](https://www.tindie.com/stores/tleracorp/)

- LORA is not enabled by default. You need to update your local mbed_app.json file:

```json
{
    "target_overrides": {
        "GRASSHOPPER": {
            "target.components_add":             ["SX1276"],
            "sx1276-lora-driver.spi-mosi":       "LORA_SPI_MOSI",
            "sx1276-lora-driver.spi-miso":       "LORA_SPI_MISO",
            "sx1276-lora-driver.spi-sclk":       "LORA_SPI_SCLK",
            "sx1276-lora-driver.spi-cs":         "LORA_CS",
            "sx1276-lora-driver.reset":          "LORA_RESET",
            "sx1276-lora-driver.dio0":           "LORA_DIO0",
            "sx1276-lora-driver.dio1":           "LORA_DIO1",
            "sx1276-lora-driver.dio2":           "LORA_DIO2",
            "sx1276-lora-driver.dio3":           "LORA_DIO3",
            "sx1276-lora-driver.txctl":          "LORA_ANT_TX",
            "sx1276-lora-driver.rxctl":          "LORA_ANT_RX",
            "sx1276-lora-driver.pwr-amp-ctl":    "LORA_ANT_BOOST",
            "sx1276-lora-driver.tcxo":           "LORA_VDD_TXCO"
        }
    }
}
```

## MURATA Gnat

MCU: STM32L082CZ

<img src="https://cdn.hackaday.io/images/7985811531762726918.jpg" width="200">

https://www.tindie.com/products/tleracorp/gnat-loragnss-asset-tracker/</img>

TARGET: GNAT [TleraCorp](https://www.tindie.com/products/tleracorp/gnat-loragnss-asset-tracker/)

- LORA is not enabled by default. You need to update your local mbed_app.json file:

```json
{
    "target_overrides": {
        "GNAT": {
            "target.components_add":             ["SX1276"],
            "sx1276-lora-driver.spi-mosi":       "LORA_SPI_MOSI",
            "sx1276-lora-driver.spi-miso":       "LORA_SPI_MISO",
            "sx1276-lora-driver.spi-sclk":       "LORA_SPI_SCLK",
            "sx1276-lora-driver.spi-cs":         "LORA_CS",
            "sx1276-lora-driver.reset":          "LORA_RESET",
            "sx1276-lora-driver.dio0":           "LORA_DIO0",
            "sx1276-lora-driver.dio1":           "LORA_DIO1",
            "sx1276-lora-driver.dio2":           "LORA_DIO2",
            "sx1276-lora-driver.dio3":           "LORA_DIO3",
            "sx1276-lora-driver.txctl":          "LORA_ANT_TX",
            "sx1276-lora-driver.rxctl":          "LORA_ANT_RX",
            "sx1276-lora-driver.pwr-amp-ctl":    "LORA_ANT_BOOST",
            "sx1276-lora-driver.tcxo":           "LORA_VDD_TXCO"
        }
    }
}
```


# STM32L4

## STWIN SensorTile Wireless Industrial Node development kit

MCU: STM32L4R9ZI

<img src="https://www.st.com/bin/ecommerce/api/image.PF268005.en.feature-description-include-personalized-no-cpn-large.jpg"  width="200">

TARGET: STWIN

https://www.st.com/en/evaluation-tools/steval-stwinkt1.html

- BLE is enabled by default


# STM32WL

## Seeed Studio LoRa E5

<img src="https://files.seeedstudio.com/products/317990687/image/lora-e5_Preview-07.png" width="200">

MCU: STM32WLE5JC

TARGET: LORA_E5

https://www.seeedstudio.com/LoRa-E5-Wireless-Module-p-4745.html

LoRa-E5 use only RFO_HP for TX power, so for all boards using this module you need to add this to your `mbed_app.json` on section `target_overrides`

```json

   "LORA_E5": {
      "stm32wl-lora-driver.rf_switch_config": 2
   }
```

## Seeed Studio LoRa E5 Mini

TARGET: LORA_E5_MINI

Use LoRa E5 modulen basic board with USB/Serial and headers

https://www.seeedstudio.com/LoRa-E5-mini-STM32WLE5JC-p-4869.html


## Seeed Studio LoRa E5 Dev Board

<img src="https://files.seeedstudio.com/wiki/LoRa-E5_Development_Kit/202003261_preview-07.png" width="200">

TARGET: LORA_E5_DEV_BOARD

Use LoRa E5 module 

https://www.seeedstudio.com/LoRa-E5-Dev-Kit-p-4868.html

- RS485 Modbus
- all LoRa-E5 pins exposed
- temperature sensor
- buttons
- Led 
- GPIO to enable 3.3V and 5V for sensors
- some grove sonnectors (I2C, Serial, ..)
- Arduino form factor to plug shield


## Charles's LoRa-E5 breakout board

TARGET: LORA_E5_BREAKOUT

<img src="https://github.com/hallard/LoRa-E5-Breakout/blob/main/pictures/LoRa-E5-Breakout-top.png" width="200">

https://github.com/hallard/LoRa-E5-Breakout

Use LoRa E5 module and added

- FTDI 6 pins connector (:warning: **use 3.3V FTDI One, not 5V**)
- Exposed JTAG pins needed to flash module (PA13-SWDIO / PA14-SWCLK / RESET)
- Green Led on PB10 (LED1) reversed (1=OFF, 0=ON)
- Red Led on PB5 (LED2) reversed (1=OFF, 0=ON)

for debug LEDs of breakout so you need to add this to your `mbed_app.json` on section `target_overrides` and don't forget also the `rf_switch_config` seen above


```json
   "LORA_E5_BREAKOUT": {
      "stm32wl-lora-driver.rf_switch_config": 2,
      "stm32wl-lora-driver.debug_tx": "PB_5",
      "stm32wl-lora-driver.debug_rx": "PB_10",
      "stm32wl-lora-driver.debug_invert": 1
   }
```

## Charles's LoRa-E5 Tiny

TARGET: LORA_E5_TINY

<img src="https://github.com/hallard/LoRa-E5-Tiny/blob/main/pictures/LoRa-E5-Tiny-top.png" width="200">

https://github.com/hallard/LoRa-E5-Tiny

Use LoRa E5 module with CR2450 cell coin

- FTDI SMD 6 pads edge connector (:warning: **use 3.3V FTDI One, not 5V**)
- JTAG SMD 6 pads edge connector to flash module (PA13-SWDIO / PA14-SWCLK / PB3-SWO / RESET)
- Green Led on PB13
- Red Led on PA9
- 2 Tactile Switches (user PB4 and reset)
- Stemma QWIIC I2C connector
- PTH CR2450 battery holder

for debug LEDs of this board you need to add this to your `mbed_app.json` on section `target_overrides` and don't forget also the `rf_switch_config` seen above


```json
   "LORA_E5_TINY": {
      "stm32wl-lora-driver.rf_switch_config": 2,
      "stm32wl-lora-driver.debug_tx": "PB_13",
      "stm32wl-lora-driver.debug_rx": "PA_9"
   }
```


## RAK Wireless RAK3172

<img src="https://docs.rakwireless.com/assets/images/wisduo/rak3172-module/overview/RAK3172_Module_buy.png" width="200">

MCU: STM32WLE5CC

TARGET: RAK3172

RAK3172 use only RFO_HP for TX power and no TXCO so for all boards using this module you need to add this to your `mbed_app.json` on section `target_overrides`

```json

   "RAK3172": {
      "stm32wl-lora-driver.rf_switch_config": 2,
      "stm32wl-lora-driver.crystal_select" : 0
   }
```

## Charles's RAK3172 breakout board

TARGET: RAK3172_BREAKOUT

<img src="https://github.com/hallard/RAK3172-Breakout/blob/main/pictures/RAK3172-Breakout-top.png" width="200">

https://github.com/hallard/RAK3172-Breakout

Use RAK3172 and added

- FTDI 6 pins connector (:warning: **use 3.3V FTDI One, not 5V**)
- Exposed JTAG pins needed to flash module (PA13-SWDIO / PA14-SWCLK / RESET)
- Green Led on PA10 (LED1) reversed (1=OFF, 0=ON)
- Red Led on PA9 (LED2) reversed (1=OFF, 0=ON)
- SMD CR2450 battery holder

For debug LEDs of breakout so you need to add this to your `mbed_app.json` on section `target_overrides` and don't forget also the `rf_switch_config` and `crystal_select` seen above

```json
   "RAK3172_BREAKOUT": {
      "stm32wl-lora-driver.rf_switch_config": 2,
      "stm32wl-lora-driver.crystal_select" : 0,
      "stm32wl-lora-driver.debug_tx": "PA_10",
      "stm32wl-lora-driver.debug_rx": "PA_9",
      "stm32wl-lora-driver.debug_invert": 1
   }
```


# License

The software is provided under the [Apache-2.0 license](LICENSE-apache-2.0.txt).


# Contributions

Contributions to this project are accepted under the same license.

## Automatic pull request checks

- Build with CLI1 should be OK
```
python aci_build.py
```

- Build with CLI2 should be OK
```
python aci_build.py --cli2
```

Note that build is using the mbed_app_template.json file as configuration file.

- Standard Pin Names check should be OK

https://os.mbed.com/docs/mbed-os/latest/apis/standard-pin-names.html

```
python aci_build.py --pin
```


## Manual pull request checks

- Each target in custom_targets.json should be described in the README.md file

```
## <Full target name>

MCU: <STM32 MCU>

TARGET: <Target name for build>

<Link to a webpage describing this board>

<all other info is optional>

```

Note we limit image size to 200

- Keep Table of Contents up to date


## Automatic weekly non regression

A full non regression is executed each week-end

```
python aci_build.py --all
python aci_build.py --all --baremetal
python aci_build.py --all --cli2
python aci_build.py --all --cli2 --baremetal
python aci_build.py --all --pin
```

See in https://github.com/ARMmbed/stm32customtargets/actions
