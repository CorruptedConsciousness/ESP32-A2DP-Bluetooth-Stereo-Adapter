# ESP32 Bluetooth Stereo Adapter

### DIY Bluetooth A2DP Audio Receiver with UDA1334A I²S DAC

Modernize a vintage home stereo with a custom-built Bluetooth audio receiver using an ESP32 microcontroller and a UDA1334A digital-to-analog converter.

This project receives wireless Bluetooth audio from compatible phones, tablets, and computers and converts it into analog stereo audio for amplifiers and vintage home stereo systems.

**Project status: Working — successfully tested with a Windows 11 computer.**

---

## Features

- Bluetooth A2DP stereo audio reception
- UDA1334A I²S digital-to-analog conversion
- Stereo analog output for AUX or line-level inputs
- Onboard Bluetooth connection status LED
- Compatible with Bluetooth-enabled computers, phones, and tablets
- Arduino IDE programming
- Low-cost, DIY electronics
- No Wi-Fi connection or internet service required

---

## Hardware

### Working Configuration

- ESP32 development board with Bluetooth Classic support
- UDA1334A I²S DAC module
- Stereo audio output connection and RCA/AUX cable
- USB power supply
- Vintage stereo receiver or compatible amplifier

### Previous Hardware

The project originally used a PCM5102A I²S DAC. Although the original hardware was assembled and tested, it never successfully produced music.

The PCM5102A was subsequently replaced with a UDA1334A DAC, which successfully produced stereo audio.

**The UDA1334A is the verified working DAC for this project.**

---

## Software

- Arduino IDE
- ESP32 board support package
- BluetoothA2DPSink library
- Arduino/C++ firmware

The ESP32 handles Bluetooth A2DP reception and outputs digital audio over I²S to the external DAC.

---

## How It Works

```text
   Phone / Tablet / Computer
              |
        Bluetooth A2DP
              |
              v
            ESP32
    (Bluetooth Audio Sink)
              |
         I²S Digital Audio
              |
              v
         UDA1334A DAC
              |
       Analog Stereo Audio
              |
              v
       RCA / AUX Connection
              |
              v
       Vintage Stereo Receiver
              |
              v
           Speakers
```

The ESP32 receives digital audio through Bluetooth Classic A2DP.

The Bluetooth audio library manages reception and audio streaming, while the UDA1334A converts the I²S digital audio into an analog stereo signal.

The signal is then delivered to the stereo's line-level input.

---

## Bluetooth Connection Indicator

The ESP32's onboard blue LED provides visual connection status.

| Bluetooth Status | LED |
|---|---|
| Disconnected / Waiting | OFF |
| Connected | ON |

The LED is controlled by a Bluetooth connection-state callback in the firmware.

---

## Wiring — ESP32 to UDA1334A

The working adapter connects the ESP32 to the UDA1334A through power, ground, and I²S audio signals.

| Signal | Purpose |
|---|---|
| VIN / Power | DAC power supply |
| GND | Common electrical ground |
| BCLK / BCK | I²S bit clock |
| WSEL / LRCLK | Left/right channel selection |
| DIN | Digital audio data |

**Important:** The exact GPIO assignments and power connection must be verified against the final working assembly before publishing a pin-by-pin wiring diagram.

The previous PCM5102A wiring diagram does not document the final UDA1334A configuration and should not be used as the wiring reference for this version.

---

## Audio Connection

Connect the DAC's analog stereo output to an appropriate line-level input on the stereo receiver.

```text
UDA1334A Analog Output
          |
          v
Stereo Audio Connection
          |
          v
Stereo AUX / CD / LINE Input
          |
          v
       Speakers
```

**Do not connect the adapter to a PHONO input.**

A ground loop isolator was tested during development. The working setup produced clear audio without it, and the isolator was not required for successful playback.

---

## Installation

1. Install Arduino IDE.
2. Install the appropriate ESP32 board package.
3. Install the BluetoothA2DPSink library.
4. Open `DIY_BT.ino`.
5. Select the correct ESP32 board and serial port.
6. Upload the firmware.
7. Power the ESP32 and connected UDA1334A.
8. Enable Bluetooth on the source device.
9. Pair with the device named:

```text
ESP32_BT_Stereo
```

10. Select `ESP32_BT_Stereo` as the audio output device.
11. Connect the DAC's analog output to the stereo.
12. Select the appropriate stereo input and begin playback.

---

## Testing and Results

### Successful Test — November 24, 2026

The completed adapter was paired with a Windows 11 computer named Clyde.

**Results:**

- Bluetooth pairing successful
- Recognized by Windows as a connected Bluetooth audio device
- Recognized by Spotify as an available playback device
- Successful stereo music playback
- Clear, smooth audio without noticeable interruptions during testing
- Functional Bluetooth connection status LED

### Troubleshooting History

During testing with a phone, intermittent audio glitches occurred approximately every 5–10 seconds.

Removing the ground loop isolator did not resolve those interruptions.

The same adapter was then tested using a Windows 11 computer, where playback was smooth and clear.

These results suggest the interruptions were associated with the original Bluetooth source or its interaction with the receiver, rather than a general failure of the UDA1334A audio output.

The precise cause of the phone-specific interruptions has not yet been determined.

---

## Project Gallery

[Original adapter build photograph](https://github.com/CorruptedConsciousness/ESP32-A2DP-Bluetooth-Stereo-Adapter/blob/main/images/20260728_172026.jpg)

[Browse the project image gallery](https://github.com/CorruptedConsciousness/ESP32-A2DP-Bluetooth-Stereo-Adapter/tree/main/images)

*Note: Earlier photographs may show the original PCM5102A configuration. Updated photographs of the working UDA1334A assembly should be added.*

---

## Development History

This project began as an experiment in adding modern Bluetooth audio functionality to a classic 1990s home stereo.

The original PCM5102A implementation did not produce usable music. Development continued through additional hardware testing, soldering, DAC replacement, and troubleshooting.

On November 24, 2026, the UDA1334A configuration successfully delivered clear stereo audio from a Windows computer to the vintage stereo system.

The project demonstrates practical experience with microcontrollers, digital audio, Bluetooth communication, hardware integration, and troubleshooting.

---

## AI Assistance Disclosure

This project was developed with assistance from OpenAI's ChatGPT.

AI assistance was used for technical explanations, firmware guidance, troubleshooting, documentation, and development support.

The project author selected and assembled the hardware, performed soldering and physical connections, uploaded and tested firmware, conducted audio playback tests, identified hardware and playback issues, and verified the functioning system.

AI-assisted code and documentation are included transparently. Successful operation was established through testing on the physical hardware.

---

## License

MIT License

---

## Author

**Trevor Youmans**

Independent software and electronics developer.

Built to bring modern Bluetooth audio functionality to a vintage home stereo using accessible, inexpensive hardware and open-source software.
