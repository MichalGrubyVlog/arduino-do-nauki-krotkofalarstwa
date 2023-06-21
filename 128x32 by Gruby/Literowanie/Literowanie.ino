#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 display(128, 32, &Wire, -1);

String letters[] {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};
String polish[] {"adam", "barbara", "cezary", "dorota", "ewa", "franciszek", "grazyna", "henryk", "irena", "jadwiga", "karol", "ludwik", "maria", "natalia", "olga", "pawel", "klebek", "roman", "stanislaw", "tadeusz", "urszula", "violetta", "wanda", "xawery", "ypsylon", "zygmunt"};
String english[] {"alfa", "bravo", "charlie", "delta", "echo", "foxtrott", "golf", "hotel", "india", "juliet", "kilo", "lima", "mike", "november", "oscar", "papa", "quebec", "romeo", "sierra", "tango", "uniform", "victor", "whiskey", "x-ray", "yankee", "zulu"};
int iterator = 26;

void setup() {
  Serial.begin(9600);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  delay(2000);
  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  // Display static text
  display.println("Hello, world!");
  display.display(); 
}

void loop() {
    for (int i = 0; i < iterator; i++) {
      display.clearDisplay();
      display.setCursor(0, 0);
      
      display.setTextSize(2);
      display.println(letters[i]);

      display.setCursor(0, 25);
      display.setTextSize(1);
      display.println(polish[i] + " - " + english[i]);
      display.display();
      delay(3000);
    }
}
