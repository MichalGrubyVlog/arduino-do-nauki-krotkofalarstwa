// Prosta "pomoc naukowa" 
// ulepiona na podstawie przykładu ssd1306wire

//używa ładniejszych czcionek wygenerowanych stąd https://oleddisplay.squix.ch/
// rozmiary wyglądają dziwnie, ale miały się mieścić. 

// wyświetla po kolei dane z trzech tabel - tu akurat literowanie
// esp8266 + i2c oled 1306 w rozmiarze 128x64 
// 
// oled podłaczony do pinów 
// SCL	GPIO 5 (D1)
// SDA	GPIO 4 (D2)

#include "SSD1306Wire.h"

//czcionki
#include "Dialog_bold_29.h"
#include "Dialog_bold_14.h"


// Initialize the OLED display using Arduino Wire:
SSD1306Wire display(0x3c, D2, D1);   // ADDRESS, SDA, SCL  -  SDA and SCL usually populate automatically based on your board's pins_arduino.h e.g. https://github.com/esp8266/Arduino/blob/master/variants/nodemcu/pins_arduino.h
// SSD1306Wire display(0x3c, D3, D5);  // ADDRESS, SDA, SCL  -  If not, they can be specified manually.
// SSD1306Wire display(0x3c, SDA, SCL, GEOMETRY_128_32);  // ADDRESS, SDA, SCL, OLEDDISPLAY_GEOMETRY  -  Extra param required for 128x32 displays.
// SH1106Wire display(0x3c, SDA, SCL);     // ADDRESS, SDA, SCL


// ----------------- główne tablice ------------
String litery[] {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};
String polskie[] {"adam", "barbara", "cezary", "dorota", "ewa", "franciszek", "grazyna", "henryk", "irena", "jadwiga", "karol", "ludwik", "maria", "natalia", "olga", "pawel", "klebek", "roman", "stanislaw", "tadeusz", "urszula", "violetta", "wanda", "xawery", "ypsylon", "zygmunt"};
String englisz[] {"alfa", "bravo", "charlie", "delta", "echo", "foxtrott", "golf", "hotel", "india", "juliet", "kilo", "lima", "mike", "november", "oscar", "papa", "quebec", "romeo", "sierra", "tango", "uniform", "victor", "whiskey", "x-ray", "yankee", "zulu"};
int ile = 26;


void setup() {

  display.init();

  //display.flipScreenVertically();  //zależnie od tego jak jest umieszczony ekran w obudowie

}



void loop() {

  for (int i=0; i<ile; i++) {

  // clear the display
  display.clear();
  display.setTextAlignment(TEXT_ALIGN_CENTER);
  
  display.setFont(Dialog_bold_29);
  display.drawString(64,0,litery[i]);
  
  display.setFont(Dialog_bold_14);
  display.drawString(64,31,polskie[i]);
  display.drawString(64,47,englisz[i]);
  
  // write the buffer to the display
  display.display();

  delay(3000);
  }


}
