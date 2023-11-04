# ESP8266 802.11 Deauthentication Frame Injection Tool

This tool demonstrates IEEE 802.11 management frame injection vulnerability exploitation using ESP8266 microcontrollers.

## Overview

The implementation exploits the lack of authentication in 802.11 management frames (pre-802.11w standard) by injecting spoofed deauthentication frames to force client disconnection from access points.

## Technical Details

The tool crafts raw 802.11 deauthentication frames and injects them using ESP8266's promiscuous mode transmission capabilities, bypassing the normal WiFi stack to directly manipulate MAC layer frames.

## Hardware

- ESP8266 microcontroller (NodeMCU, Wemos D1, etc.)
- USB cable for programming and power

## Installation

Upload the code to your ESP8266 using Arduino IDE with ESP8266 board support installed.

## Legal Notice

Unauthorized use of this tool against networks you do not own or have explicit permission to test is illegal in most jurisdictions. This tool is provided for educational and authorized security research purposes only.

## Disclaimer

The author assumes no liability for misuse of this tool. Use at your own risk and only on networks you are authorized to test.
