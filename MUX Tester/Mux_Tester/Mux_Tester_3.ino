//For the LEDs
#include <FastLED.h>

#define NUM_LEDS 30

#define DATA_PIN1 4

CRGB leds[NUM_LEDS];

//Attempting mux0 and mux1 analog in, and mux2 digital out
#define CONTROL0 5    
#define CONTROL1 4
#define CONTROL2 3
#define CONTROL3 2


int mux0array[16];


void setup()
{
  
  Serial.begin(9600);
  FastLED.addLeds<NEOPIXEL, DATA_PIN1>(leds, NUM_LEDS);


  pinMode(CONTROL0, OUTPUT);
  pinMode(CONTROL1, OUTPUT);
  pinMode(CONTROL2, OUTPUT);
  pinMode(CONTROL3, OUTPUT);
}
  

void loop() {
int RedValue1 = mux0array[0];
int RedValue2 = mux0array[1];
int RedValue3 = mux0array[2];

int GreenValue1 = mux0array[3];
int GreenValue2 = mux0array[4];
int GreenValue3 = mux0array[5];

int BlueValue1 = mux0array[6];
int BlueValue2 = mux0array[7];
int BlueValue3 = mux0array[8];

int brightnessR1 = map(RedValue1, 0,650,0,85);
int brightnessR2 = map(RedValue2, 0,650,0,85);
int brightnessR3 = map(RedValue3, 0,650,0,85);

int brightnessG1 = map(GreenValue1, 0,650,0,85);
int brightnessG2 = map(GreenValue2, 0,650,0,85);
int brightnessG3 = map(GreenValue3, 0,650,0,85);

int brightnessB1 = map(BlueValue1, 0,650,0,85);
int brightnessB2 = map(BlueValue2, 0,650,0,85);
int brightnessB3 = map(BlueValue3, 0,650,0,85);


 for (int i = 0; i < NUM_LEDS; i = i + 1)

  {



    leds[i] = CRGB(brightnessR1 + brightnessR2 + brightnessR3,brightnessG1 + brightnessG2 + brightnessG3, brightnessB1 + brightnessB2 + brightnessB3);

  }

  FastLED.show();

for (int i=0; i<3; i++)
  {

    digitalWrite(CONTROL0, (i&15)>>3); 
    digitalWrite(CONTROL1, (i&7)>>2);  
    digitalWrite(CONTROL2, (i&3)>>1);  
    digitalWrite(CONTROL3, (i&1));     
    
    mux0array[i] = analogRead(0);
    Serial.print("mux0array: ");
    for (int i=0; i<3; i++)
  {
    Serial.print(mux0array[i]);
    Serial.print("-");
  }
    Serial.println();
  }
}
 