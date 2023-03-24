
//Give convenient names to the control pins

#define CONTROL0 5    

#define CONTROL1 4

#define CONTROL2 3

#define CONTROL3 2







void setup()

{

  //Set MUX control pins to output

  pinMode(CONTROL0, OUTPUT);

  pinMode(CONTROL1, OUTPUT);

  pinMode(CONTROL2, OUTPUT);

  pinMode(CONTROL3, OUTPUT);

  

  //Open the serial port at 28800 bps

  Serial.begin(9600);

}

  



void loop()

{


  Serial.print(muxAnalogRead(0,0));
  Serial.print("    ");
  Serial.println(muxAnalogRead(0,2));

  delay(10);

}



int muxAnalogRead(int muxChip,int muxPin)

{

   //The following 4 commands set the correct logic for the control pins to select the desired input

    //See the Arduino Bitwise AND Reference: http://www.arduino.cc/en/Reference/BitwiseAnd

    //See the Aruino Bitshift Reference: http://www.arduino.cc/en/Reference/Bitshift

    digitalWrite(CONTROL0, (muxPin&15)>>3); 

    digitalWrite(CONTROL1, (muxPin&7)>>2);  

    digitalWrite(CONTROL2, (muxPin&3)>>1);  

    digitalWrite(CONTROL3, (muxPin&1));     

    

    //Read and store the input value at a location in the array

    return analogRead(muxChip);

}

