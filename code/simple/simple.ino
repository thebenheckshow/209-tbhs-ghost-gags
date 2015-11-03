
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN            5

#define NUMPIXELS      8

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 500; // delay for half a second

unsigned long blinkCounter = 0;
unsigned long blinkTarget = 5;

#define baseTarget  5

void setup() {

  pinMode(2, OUTPUT);

  pixels.begin();
  
  for(int i=0;i<NUMPIXELS;i++){
    pixels.setPixelColor(i, pixels.Color(150,0,0)); // Set all NeoPixels to red.
  }
  
  pixels.show();
  
}

void loop() {

  blinkCounter += 1;
  
  if (blinkCounter == (blinkTarget * 1000)) {
  
    blink();
    
  }

  digitalWrite(2, 0);

  delay(1);  

}

void blink() {
  
  blinkCounter = 0;                //Reset timer
  
  for (unsigned long x = 0 ; x < 75000 ; x++) {

    digitalWrite(2, 1);              //Pulse the motor
    
  } 
  
  digitalWrite(2, 0);              //Motor off

  changeColor(255, random(6) * 25, random(6) * 25);  //Change the color (always has some red)

  blinkTarget = baseTarget + random(10);                 //baseTarget + random(10);

}




void changeColor(unsigned char redx, unsigned char greenx, unsigned char bluex) {
  
  for(int i=0;i<NUMPIXELS;i++){
    
    pixels.setPixelColor(i, pixels.Color(redx, greenx, bluex));
    
  }
  
  pixels.show();  
  
}  
