#include <SPI.h>
#include <Pixy.h>
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif
// pixel shield pin
#define PIN            6
// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      40

Pixy pixy;
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup(){
  
  Serial.begin(9600);
  while (!Serial) ;

  Serial.print("Starting...\n");
  // initialize libraries
  pixy.init();
  pixels.begin(); 
}

void loop(){
  
  uint16_t blocks;

  // grab blocks!
  blocks = pixy.getBlocks();

  //clear pixels of colors
  for (int i = 0; i < NUMPIXELS; i++) {
    pixels.setPixelColor(i, pixels.Color(0, 0, 0));
  }
  
  // If there are detected blocks
  if (blocks){
    // if it's block 1
    if (pixy.blocks[0].signature) {

      // get x and y coordinates
      int xPos = pixy.blocks[0].x / 40; // 8 across
      int yPos = 5 - ((pixy.blocks[0].y / 40) + 1); // need to math this out
      int arrayPos = xPos + yPos * 8; // this is the position in the array

      pixels.setPixelColor(arrayPos, pixels.Color(127, 0, 0)); // Moderately bright green color.
    }
  }
  pixels.show(); // send updated pixel colors
  delay(25); // need to delay for more than 20ms to prevent flickering
}

