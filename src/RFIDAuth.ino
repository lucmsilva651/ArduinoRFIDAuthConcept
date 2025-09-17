#include <TimerFreeTone.h>
#include <MFRC522.h>
#include <SPI.h>

#define RST_PIN 9
#define SPK_PIN 7
#define SS_PIN 10

String masterTag = "70471D33";
String tagID = "";

MFRC522 mfrc522(SS_PIN, RST_PIN);

void setup() {
	SPI.begin();
	mfrc522.PCD_Init();
	Serial.begin(9600);
	mfrc522.PCD_DumpVersionToSerial();
}

void loop() {
	while (getID()) {
		if (tagID == masterTag) {
			Serial.println("Door unlocked");
		} else {
			Serial.println("Door locked");
		}
		delay(2000);
	}
}

boolean getID() {
	if (!mfrc522.PICC_IsNewCardPresent()) {
		return;
	}

	if (!mfrc522.PICC_ReadCardSerial()) {
		return;
	}

	TimerFreeTone(SPK_PIN, 1950, 350);
	tagID = "";

	for (uint8_t i = 0; i < 4; i++) {
		tagID.concat(String(mfrc522.uid.uidByte[i], HEX));
	}
	
	tagID.toUpperCase();
	mfrc522.PICC_HaltA();
	
	return true;
}