// Prosta "pomoc naukowa" 
// ulepiona na podstawie przykładu ssd1306wire

//używa ładniejszych czcionek wygenerowanych stąd https://oleddisplay.squix.ch/
// rozmiary wyglądają dziwnie, ale miały się mieścić. 

// wyświetla po kolei dane z trzech tabel - tu akurat zakresy pasm amatorskich z pytań egzaminacyjnych
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

String pasmo[] {"160m", "80m", "40m", "30m", "20m", "17m", "15m", "12m", "10m", "6m", "2m"};
String start[] {"1810 kHz", "3500 kHz", "7000 kHz", "10100 kHz", "14000 kHz", "18068 kHz", "21000 kHz", "24890 kHz", "28000 kHz", "50 MHz", "144 MHz"};
String stop[] {"2000 kHz", "3800 kHz", "7200 kHz", "10150 kHz", "14350 kHz", "18168 kHz", "21450 kHz", "24990 kHz", "29700 kHz", "52 MHz", "146 MHz"};
int ile = 11;


void setup() {

  display.init();

  //display.flipScreenVertically();  //zależne od tego jak jest w obudowie umieszczony ekran

}



void loop() {

  for (int i=0; i<ile; i++) {

  // clear the display
  display.clear();
  display.setTextAlignment(TEXT_ALIGN_CENTER);
  
  display.setFont(Dialog_bold_29);
  display.drawString(64,0,pasmo[i]);
  
  display.setFont(Dialog_bold_14);
  display.drawString(64,31,start[i]);
  display.drawString(64,47,stop[i]);
  
  // write the buffer to the display
  display.display();

  delay(3000);
  }


}
