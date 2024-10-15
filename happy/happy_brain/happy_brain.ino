#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for SSD1306 display connected using I2C
#define OLED_RESET     -1 // Reset pin
#define SCREEN_ADDRESS 0x3C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);



// Global Variables
unsigned long previousMillis = 0;
unsigned long blinkInterval;
unsigned long normalInterval = 100; // Default interval for closed eyes
bool isBlinking = false;

// Initialize display setup
void setup() {
  Serial.begin(9600);
  
  // Initialize the OLED object
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  display.clearDisplay();
  
  // Display startup messages
  displayText("kendal percimoney", "is my creator.", 2000);
  displayText("built by percimoney", "industries inc.", 2000);

  // Set up initial display for normal eyes
  showNormalEyes();
  blinkInterval = random(3000, 20000);
}



// Display startup text messages
void displayText(String line1, String line2, int displayTime) {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 28);
  display.println(line1);
  display.setCursor(0, 35);
  display.println(line2);
  display.display();
  delay(displayTime);
  display.clearDisplay();
}

// Function for normal open eyes
void showNormalEyes() {
  display.clearDisplay();
  display.setTextSize(3);
  display.setTextColor(WHITE);
  display.setCursor(18, 10);
  display.println("O ^ O");
  display.display();
}

// Function for blinking eyes
void showBlinkingEyes() {
  display.clearDisplay();
  display.setTextSize(3);
  display.setTextColor(WHITE);
  display.setCursor(18, 10);
  display.println("- ^ -");
  display.display();
}

void loop() {
  unsigned long currentMillis = millis();

  if (!isBlinking && currentMillis - previousMillis >= blinkInterval) {
    // when not blinking and time is up, blink. 
    isBlinking = true; //set blinking to true
    previousMillis = currentMillis;
    showBlinkingEyes();
  } 
  else if (isBlinking && currentMillis - previousMillis >= normalInterval) {
    // when blinking true and time is up, return to normal eyes
    isBlinking = false;
    previousMillis = currentMillis;
    showNormalEyes();
    blinkInterval = random(3000, 20000);
  }
}