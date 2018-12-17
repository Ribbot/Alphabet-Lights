#include <FastLED.h>
#define NUM_LEDS 49
#define DATA_PIN 7
#define WORD_DELAY 500

CRGB leds[NUM_LEDS];


/* Function:  setup
 * --------------------
 * Configures FastLED library.
 * 
 * Initiates serial communication between
 * Arduino and PC over USB.
 */
void setup() {
  FastLED.addLeds<WS2811_400, DATA_PIN, RGB>(leds, NUM_LEDS);
  FastLED.setBrightness(25);

  Serial.begin(9600);
  while (!Serial) {}
}


/* Function:  lightAll
 * --------------------
 * Calls lightSingle for each letter of the alphabet.
 * This results in the LED underneath each letter being lit.
 */
void lightAll(){
  String alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  
  for (int i = 0; i < alphabet.length(); i++){
    lightSingle(alphabet[i]);
  }
  
  FastLED.show();
}


/* Function:  setBlack
 * --------------------
 * Turns all LEDs off
 */
void setBlack(){
  for (int i = 0; i < NUM_LEDS; i++){
    leds[i] = CRGB::Black;
  }
  
  FastLED.show();
}

/* Function:  lightSingle
 * --------------------
 * Turns on a single LED underneath a letter.
 * Each LED has a predetermined color that matches
 * the light's color in Stranger Things.
 */
bool lightSingle(char letter) {
  int r, g, b, i;
  bool black = false;

  switch(letter) {
    case 'A': {
      i = 33;
      r = 255;
      g = 255;
      b = 255;
      break;
    }
    case 'B': {
      i = 34;
      r = 0;
      g = 97;
      b = 255;
      break;
    }
    case 'C': {
      i = 35;
      r = 255;
      g = 0;
      b = 80;
      break;
    }
    case 'D': {
      i = 36;
      r = 170;
      g = 232;
      b = 255;
      break;
    }
    case 'E': {
      i = 37;
      r = 40;
      g = 190;
      b = 255;
      break;
    }
    case 'F': {
      i = 38;
      r = 255;
      g = 80;
      b = 0;
      break;
    }
    case 'G': {
      i = 39;
      r = 255;
      g = 0;
      b = 250;
      break;
    }
    case 'H': {
      i = 40;
      r = 40;
      g = 190;
      b = 255;
      break;
    }
    case 'I': {
      i = 29;
      r = 40;
      g = 190;
      b = 255;
      break;
    }
    case 'J': {
      i = 28;
      r = 255;
      g = 0;
      b = 250;
      break;
    }
    case 'K': {
      i = 27;
      r = 40;
      g = 190;
      b = 255;
      break;
    }
    case 'L': {
      i = 26;
      r = 0;
      g = 97;
      b = 255;
      break;
    }
    case 'M': {
      i = 25;
      r = 255;
      g = 80;
      b = 0;
      break;
    }
    case 'N': {
      i = 24;
      r = 255;
      g = 0;
      b = 250;
      break;
    }
    case 'O': {
      i = 23;
      r = 255;
      g = 0;
      b = 80;
      break;
    }
    case 'P': {
      i = 22;
      r = 170;
      g = 232;
      b = 255;
      break;
    }
    case 'Q': {
      i = 21;
      r = 255;
      g = 0;
      b = 0;
      break;
    }
    case 'R': {
      i = 9;
      r = 170;
      g = 232;
      b = 255;
      break;
    }
    case 'S': {
      i = 10;
      r = 255;
      g = 255;
      b = 255;
      break;
    }
    case 'T': {
      i = 11;
      r = 255;
      g = 80;
      b = 0;
      break;
    }
    case 'U': {
      i = 12;
      r = 40;
      g = 190;
      b = 255;
      break;
    }
    case 'V': {
      i = 13;
      r = 255;
      g = 0;
      b = 250;
      break;
    }
    case 'W': {
      i = 14;
      r = 40;
      g = 190;
      b = 255;
      break;
    }
    case 'X': {
      i = 15;
      r = 255;
      g = 80;
      b = 0;
      break;
    }
    case 'Y': {
      i = 16;
      r = 255;
      g = 0;
      b = 250;
      break;
    }
    case 'Z': {
      i = 17;
      r = 255;
      g = 0;
      b = 250;
      break;
    }
    case ' ': {
      i = 0;
      r = 0;
      g = 0;
      b = 0;
      black = true;
      break;
    }
  }

  leds[i].setRGB(r, g, b);
  return black;
}


/* Function:  setColors
 * --------------------
 * Lights all LEDs in a repeating 3 color sequence.
 * Each color is described by RGB input parameters.
 */
void setColors(int r1, int g1, int b1, int r2, int g2, int b2, int r3, int g3, int b3){
  int i = 0;
  
  while(i < (NUM_LEDS - 3)){
    leds[i].setRGB(r1, g1, b1);
    i++;
    leds[i].setRGB(r2, g2, b2);
    i++;
    leds[i].setRGB(r3, g3, b3);
    i++;
  }
  
  FastLED.show();
}


/* Function:  lightPhrase
 * --------------------
 * Iterates through each character in a phrase command string
 * and lights the LED corresponding to each selected character
 * 
 * Turns all LEDs off when a space is encountered in the phrase
 * 
 * Phrase Command Format: "4 Phrase"
 */
void lightPhrase(String phrase) {
  for(int i = 2; i < phrase.length(); i++){
    bool black = lightSingle(phrase[i]); //black is set to TRUE if character is a space and FALSE otherwise
    FastLED.show();
    FastLED.delay(WORD_DELAY);
    if (black == false){
      setBlack();
      FastLED.delay(WORD_DELAY);
    }
  }   
}

/* Function:  parseColors
 * --------------------
 * Extracts the R, G, and B values for each of
 * the three colors in a color selection command.
 * 
 * Sequentially lights all LEDs with 
 * each color extracted from the command.
 * 
 * Color Selection Command Format: "3 R1 G1 B1 R2 G2 B2 R3 B3 G3"
 */
void parseColors(String serialStr){
  int i = 2; //Start reading the command string at R1 instead of beginning
  char c;
  String R, G, B;
  String R2, G2, B2;
  String R3, G3, B3;

  do {
    c = serialStr.charAt(i); //Read next character in command string
    if(c != ' ')
      R.concat(c);
    i++;
  }while (c != ' '); //Check if at end of R1 portion of command string

  do {
    c = serialStr.charAt(i);
    if(c != ' ')
      G.concat(c);  
    i++;
  }while (c != ' ');

  do {
    c = serialStr.charAt(i); 
    if(c != ' ')
      B.concat(c); 
    i++;
  }while (c != ' ');

  do {
    c = serialStr.charAt(i);
    if(c != ' ')
      R2.concat(c);
    i++;
  }while (c != ' ');

  do {
    c = serialStr.charAt(i);
    if(c != ' ')
      G2.concat(c);  
    i++;
  }while (c != ' ');

  do {
    c = serialStr.charAt(i); 
    if(c != ' ')
      B2.concat(c); 
    i++;
  }while (c != ' ');

  do {
    c = serialStr.charAt(i);
    if(c != ' ')
      R3.concat(c);
    i++;
  }while (c != ' ');

  do {
    c = serialStr.charAt(i);
    if(c != ' ')
      G3.concat(c);  
    i++;
  }while (c != ' ');

  do {
    c = serialStr.charAt(i); 
    if(c != ' ')
      B3.concat(c); 
    i++;
  }while (c != ' ');

  setColors(R.toInt(), G.toInt(), B.toInt(), R2.toInt(), G2.toInt(), B2.toInt(), R3.toInt(), G3.toInt(), B3.toInt());
}


/* Function:  loop
 * --------------------
 * Reads incoming command strings from the USB serial connection.
 * 
 * Using the numeric value at the start of the command string, the 
 * command type is determined and its corresponding functions are called.
 */
void loop() {
  String serialStr;
  
  while(Serial.available()){
    serialStr = Serial.readString();
    FastLED.delay(10);
  }
  serialStr.remove(serialStr.length() - 1);

  if (serialStr.length() != 0){
    serialStr.toUpperCase();
    
    if(serialStr == "1") //"On" command
      lightAll();
    else if (serialStr == "2") //"Off" command
      setBlack();
    else if(serialStr.charAt(0) == '3') //Color selection command
      parseColors(serialStr);
    else if(serialStr.charAt(0) == '4'){ //Phrase command
      setBlack();
      lightPhrase(serialStr);  
    }
  }
}
