# ArduinoRFIDAuthConcept

"Authentication" via RFID using a Arduino Uno + RFID-RC522. Uses the concept of door locking/unlocking using a master RFID tag to unlock the door every time and any other RFID tag would lock the door and make it stay locked. A piezo buzzer will make sounds every time a card is recognized.

## Materials needed

- Arduino Uno
- RFID-RC522
- Piezo Buzzer (optional)

## Libraries needed

- [TimerFreeTone](https://forum.arduino.cc/t/timerfreetone-library-v1-5-play-tones-without-timers-and-therefore-no-conflicts/229448/1)
- [MFRC522](https://github.com/miguelbalboa/rfid)

## Schematics

![Schematics](src/schematics.png)

## Setup

You may need to change some settings in the ``ArduinoRFIDAuthConcept.ino`` file according to your needs.

Pick your RFID tag or card ID using any reader (you can use NFC Tools on Android if you have a NFC compatible phone), then write it down for later usage.

Now change the ``masterTag`` variable value to your tag ID removing any colons.

Example:

```ino
String masterTag = "70471D33";
```

Now you can import the code into your Arduino and test it to see if it works.

## License

2025 Lucas Gabriel (lucmsilva) - All rights reserved.
