/*
   Copyright 2021 Leon Kiefer

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

	   http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/
#include <CorsairLightingProtocol.h>
#include <FastLED.h>

#define DATA_PIN2 2
#define DATA_PIN3 3
#define DATA_PIN4 4
#define DATA_PIN5 5
#define DATA_PIN6 6
#define DATA_PIN7 7
#define DATA_PIN8 8
#define DATA_PIN9 9
#define DATA_PIN10 10
#define DATA_PIN11 11
#define DATA_PIN12 12
#define DATA_PIN13 13
#define DATA_PIN14 14
#define DATA_PIN15 15
#define DATA_PIN16 16
#define DATA_PIN17 17
#define DATA_PIN18 18
#define DATA_PIN19 19
#define DATA_PIN20 20
#define DATA_PIN21 21

#define OFFSET_PIN2 0
#define OFFSET_PIN3 8
#define OFFSET_PIN4 16
#define OFFSET_PIN5 24
#define OFFSET_PIN6 32
#define OFFSET_PIN7 40
#define OFFSET_PIN8 48
#define OFFSET_PIN9 56
#define OFFSET_PIN10 64
#define OFFSET_PIN11 72
#define OFFSET_PIN12 0
#define OFFSET_PIN13 8
#define OFFSET_PIN14 16
#define OFFSET_PIN15 24
#define OFFSET_PIN16 32
#define OFFSET_PIN17 40
#define OFFSET_PIN18 48
#define OFFSET_PIN19 56
#define OFFSET_PIN20 64
#define OFFSET_PIN21 72

CRGB ledsChannel1[80];
CRGB ledsChannel2[80];

// Most ARM devices do not contain an EEPROM; we will use static storage for the Device ID
DeviceID deviceID = {0x9A, 0xDA, 0xA7, 0x8E};
CorsairLightingFirmwareStorageStatic firmwareStorage(deviceID);
CorsairLightingFirmware firmware(CORSAIR_LIGHTING_NODE_PRO, &firmwareStorage);
FastLEDController ledController(nullptr);
CorsairLightingProtocolController cLP(&ledController, &firmware);
CorsairLightingProtocolTinyUSBHID cHID(&cLP);

void setup() {
	cHID.setup();
  FastLED.addLeds<WS2812B, DATA_PIN2, GRB>(ledsChannel1, OFFSET_PIN2, 8);
  FastLED.addLeds<WS2812B, DATA_PIN3, GRB>(ledsChannel1, OFFSET_PIN3, 8);
  FastLED.addLeds<WS2812B, DATA_PIN4, GRB>(ledsChannel1, OFFSET_PIN4, 8);
  FastLED.addLeds<WS2812B, DATA_PIN5, GRB>(ledsChannel1, OFFSET_PIN5, 8);
  FastLED.addLeds<WS2812B, DATA_PIN6, GRB>(ledsChannel1, OFFSET_PIN6, 8);
  FastLED.addLeds<WS2812B, DATA_PIN7, GRB>(ledsChannel1, OFFSET_PIN7, 8);
  FastLED.addLeds<WS2812B, DATA_PIN8, GRB>(ledsChannel1, OFFSET_PIN8, 8);
  FastLED.addLeds<WS2812B, DATA_PIN9, GRB>(ledsChannel1, OFFSET_PIN9, 8);
  FastLED.addLeds<WS2812B, DATA_PIN10, GRB>(ledsChannel1, OFFSET_PIN10, 8);
  FastLED.addLeds<WS2812B, DATA_PIN11, GRB>(ledsChannel1, OFFSET_PIN11, 8);
  FastLED.addLeds<WS2812B, DATA_PIN12, GRB>(ledsChannel2, OFFSET_PIN12, 8);
  FastLED.addLeds<WS2812B, DATA_PIN13, GRB>(ledsChannel2, OFFSET_PIN13, 8);
  FastLED.addLeds<WS2812B, DATA_PIN14, GRB>(ledsChannel2, OFFSET_PIN14, 8);
  FastLED.addLeds<WS2812B, DATA_PIN15, GRB>(ledsChannel2, OFFSET_PIN15, 8);
  FastLED.addLeds<WS2812B, DATA_PIN16, GRB>(ledsChannel2, OFFSET_PIN16, 8);
  FastLED.addLeds<WS2812B, DATA_PIN17, GRB>(ledsChannel2, OFFSET_PIN17, 8);
  FastLED.addLeds<WS2812B, DATA_PIN18, GRB>(ledsChannel2, OFFSET_PIN18, 8);
  FastLED.addLeds<WS2812B, DATA_PIN19, GRB>(ledsChannel2, OFFSET_PIN19, 8);
  FastLED.addLeds<WS2812B, DATA_PIN20, GRB>(ledsChannel2, OFFSET_PIN20, 8);
  FastLED.addLeds<WS2812B, DATA_PIN21, GRB>(ledsChannel2, OFFSET_PIN21, 8);
  ledController.addLEDs(0, ledsChannel1, 80);
  ledController.addLEDs(1, ledsChannel2, 80);
}

void loop() {
	cHID.update();

	if (ledController.updateLEDs()) {
		FastLED.show();
	}
}
