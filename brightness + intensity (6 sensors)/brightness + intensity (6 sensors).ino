#include <FastLED.h>

// How many leds in your strip?
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
int RedValue2 = analogRead(A1);
int GreenValue = analogRead(A2);
int GreenValue2 = analogRead(A3);
Serial.print(RedValue);
Serial.print("   ");
Serial.print(RedValue2);
Serial.print("   ");
Serial.print(GreenValue);
Serial.print("   ");
Serial.println(GreenValue2);


  int brightnessR1 = map(analogRead(A0), 0,650,0,255);
  int brightnessR2 = map(analogRead(A1), 0,650,0,255);
  int brightnessG1 = map(analogRead(A2), 0,650,0,255);
  int brightnessG2 = map(analogRead(A4), 0,650,0,255);
  int brightnessB1 = map(analogRead(A5), 0,650,0,255);
  int brightnessB2 = map(analogRead(A6), 0,650,0,255);

 
  for (int i = 0; i < NUM_LEDS; i = i + 1)

  {

 

    leds[i] = CRGB(brightnessR1 + brightnessR2 + 0 ,brightnessG1 + brightnessG2 + 0, brightnessB1 + brightnessB2 + 0);

  }

  FastLED.show();



}