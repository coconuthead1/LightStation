#include "FastLED.h"



// How many leds in your strip?

#define NUM_LEDS 30

#define DATA_PIN 6





// Define the array of leds

CRGB leds[NUM_LEDS];



void setup() {

  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);

}



void loop() {

int RedValue = analogRead(A0);
int GreenValue = analogRead(A2);
int BlueValue = analogRead(A4);
Serial.print(RedValue);
Serial.print("   ");
Serial.print(GreenValue);
Serial.print("   ");
Serial.println(BlueValue);


  int brightness1 = map(analogRead(A0), 0,650,0,85);
  int brightness2 = map(analogRead(A2), 0,650,0,85);
  int brightness3 = map(analogRead(A4), 0,650,0,85);

  for (int i = 0; i < NUM_LEDS; i = i + 1)

  {

    leds[i] = CRGB(brightness1 + brightness2 + brightness3, 0, 0);

  }

  FastLED.show();



}