#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 display(128, 32, &Wire, -1);

String band[] {"160m", "80m", "40m", "30m", "20m", "17m", "15m", "12m", "10m", "6m", "2m"};
String startBand[] {"1810 kHz", "3500 kHz", "7000 kHz", "10100 kHz", "14000 kHz", "18068 kHz", "21000 kHz", "24890 kHz", "28000 kHz", "50 MHz", "144 MHz"};
String endBand[] {"2000 kHz", "3800 kHz", "7200 kHz", "10150 kHz", "14350 kHz", "18168 kHz", "21450 kHz", "24990 kHz", "29700 kHz", "52 MHz", "146 MHz"};
int iterator = 11;

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
      display.println(band[i]);

      display.setCursor(0, 25);
      
      display.setTextSize(1);
      display.println(startBand[i] + " - " + endBand[i]);
      display.display();
      delay(3000);
    }
}
