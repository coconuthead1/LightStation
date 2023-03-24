#include "FastLED.h"



// How many leds in your strip?

#define NUM_LEDS 30

#define DATA_PIN1 8
#define DATA_PIN2 6
#define DATA_PIN3 4





// Define the array of leds

CRGB leds[NUM_LEDS];



void setup() {
  Serial.begin(9600);
  FastLED.addLeds<NEOPIXEL, DATA_PIN1>(leds, NUM_LEDS);
  FastLED.addLeds<NEOPIXEL, DATA_PIN2>(leds, NUM_LEDS);
      FastLED.addLeds<NEOPIXEL, DATA_PIN3>(leds, NUM_LEDS);
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


  int brightnessR = map(analogRead(A0), 0,650,0,255);
  int brightnessG = map(analogRead(A2), 0,650,0,255);
  int brightnessB = map(analogRead(A4), 0,650,0,255);

  for (int i = 0; i < NUM_LEDS; i = i + 1)

  {

    leds[i] = CRGB(brightnessR,brightnessG,brightnessB);

  }

  FastLED.show();



}