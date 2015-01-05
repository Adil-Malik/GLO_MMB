/* 
Adil Malik 06/01/2014
GLO: The Midnight Message Board
V1
*/
int latchPin = 8;
int clockPin = 11;
int dataPin = 10; 
int OEPin = 9; // Output Enable
int MCPin = 12; //Master Clear pin
int i = 0;
byte A[] = {B00010000,B00110000,B01110000,B11110000,B11110000,B11110000,B11110000,B11110000,B11110000,B11110000,B11110000,B11110000};
byte T[] = {B00000000,B00000000,B00000000,00000000,B00000001,B00000011,B00000111,B00001111,B00011111,B00111111,B01111111,B11111111};

void setup() {
  //set pins to output so you can control the shift register
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(OEPin, OUTPUT);
   pinMode(MCPin, OUTPUT);
  analogWrite(OEPin, 0);
}

void loop() {
  // count from 0 to 255 and display the number 

for(i=0;i<12;i++){
   digitalWrite(MCPi,LOW);
       delay(10); 
         digitalWrite(MCPi,HIGH);
    digitalWrite(latchPin, LOW);
   
    // shift out the bits:
    shiftOut(dataPin, clockPin, LSBFIRST, A[i]);  

    //take the latch pin high so the LEDs will light up:
   
    // pause before next value:
    delay(50);
    
   
    // shift out the bits:
    shiftOut(dataPin, clockPin, LSBFIRST, T[i]);  

    //take the latch pin high so the LEDs will light up:
    digitalWrite(latchPin, HIGH);
    // pause before next value:
    delay(50);
}
  }


  


