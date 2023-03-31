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

int maxData;

int mux0array[16];

int A;
int B;
int C;
int D;

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
int RedValue = mux0array[0];
int GreenValue = mux0array[1];
int BlueValue = mux0array[2];

int brightnessR1 = map(RedValue, 0,650,0,255);
int brightnessG1 = map(GreenValue, 0,650,0,255);
int brightnessB1 = map(BlueValue, 0,650,0,255);

 for (int i = 0; i < NUM_LEDS; i = i + 1)

  {



    leds[i] = CRGB(brightnessR1,brightnessG1, brightnessB1);

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
 

 
/* 
  {  
  pinMode(16, OUTPUT);
  }
   while(Serial.available() > 0) {
      maxData = Serial.read();
    }
     if (maxData == 0)
    {
    A = 2;
    B = 2;
    C = 2;
    D = 2;
    }
    if (maxData == 1)
    {
    A = 0;
    B = 0;
    C = 0;
    D = 0;
    }
    if (maxData == 3)
    {
    A = 1;
    B = 0;
    C = 0;
    D = 0;
    }
     if (maxData == 5)
    {
    A = 0;
    B = 1;
    C = 0;
    D = 0;
    }
    if (maxData == 7)
    {
    A = 1;
    B = 1;
    C = 0;
    D = 0;
    }
    
  {
    digitalWrite(16, HIGH);
  }

  for (int i=0; i<16; i++)
    digitalWrite(CONTROL0, (D)); //S3
    digitalWrite(CONTROL1, (C)); //S2
    digitalWrite(CONTROL2, (B)); //S1
    digitalWrite(CONTROL3, (A)); //S0
}
*/
