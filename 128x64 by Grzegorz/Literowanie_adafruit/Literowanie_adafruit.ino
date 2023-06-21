// Prosta "pomoc naukowa" 
// ulepiona na podstawie przykładu dla adafruit

// wyświetla po kolei dane z trzech tabel - tu akurat literowanie
// esp8266 + i2c oled 1306 w rozmiarze 128x64 
// 
// oled podłaczony do pinów 
// SCL	GPIO 5 (D1)
// SDA	GPIO 4 (D2)

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 
#define SCREEN_HEIGHT 64 

#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C //adres ekranu (zobacz datasheet) - 0x3D dla 128x64, 0x3C dla 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


// ----------------- główne tablice ------------
String litery[] {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};
String polskie[] {"adam", "barbara", "cezary", "dorota", "ewa", "franciszek", "grazyna", "henryk", "irena", "jadwiga", "karol", "ludwik", "maria", "natalia", "olga", "pawel", "klebek", "roman", "stanislaw", "tadeusz", "urszula", "violetta", "wanda", "xawery", "ypsylon", "zygmunt"};
String englisz[] {"alfa", "bravo", "charlie", "delta", "echo", "foxtrott", "golf", "hotel", "india", "juliet", "kilo", "lima", "mike", "november", "oscar", "papa", "quebec", "romeo", "sierra", "tango", "uniform", "victor", "whiskey", "x-ray", "yankee", "zulu"};
int ile = 26;



void setup() {

  Serial.begin(9600);

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); 
  }

  // Show initial display buffer contents on the screen --
  // the library initializes this with an Adafruit splash screen.
  display.display();
  delay(1000); // Pause for 2 seconds

  // Clear the buffer
  display.clearDisplay();

  // Draw a single pixel in white
  display.drawPixel(10, 10, SSD1306_WHITE);
  
  // Show the display buffer on the screen. You MUST call display() after
  // drawing commands to make them visible on screen!
  display.display();
  delay(2000);
  
}




void loop() {

for (int i=0; i<ile; i++) {

      display.clearDisplay();
      display.setCursor(0,0);
      display.setTextSize(3);             
      display.setTextColor(SSD1306_WHITE);
      
      display.println("   "+litery[i]);
      
      display.setTextSize(1);
      
      display.println(" ");
      //display.println("---------------------");
      
      display.setTextSize(2);

      display.println(polskie[i]);
      display.println(englisz[i]);

      display.display();
      delay(3000);


}

}
 