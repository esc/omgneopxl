#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

#define PIN 2


int mode;
String readSerial;
Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, PIN, NEO_GRB + NEO_KHZ800);
uint32_t red = strip.Color(255, 0, 0);
uint32_t green = strip.Color(0, 255, 0);
uint32_t blue = strip.Color(0, 0, 255);
uint32_t current_color = red;

uint32_t zero = 500;
uint32_t one = 400;
uint32_t two = 300;
uint32_t three = 200;
uint32_t four = 100;
uint32_t five = 50;
uint32_t current_speed = zero;

uint32_t normal = 0;
uint32_t reverse = 1;
uint32_t current_direction = normal;

void setup() {
  //pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  strip.begin();
  strip.show();
}


void loop() {
  if (Serial.available() > 0) {
    readSerial = Serial.readString();
    Serial.print(readSerial);
  }
  if (readSerial[0] == 'r') {
    current_color = red;
  } else if (readSerial[0] == 'b') {
    current_color = blue;
  } else if (readSerial[0] == 'g') {
    current_color = green;
  }

  if (readSerial[1] == '0') {
    current_speed = zero;
  } else if (readSerial[1] == '1') {
    current_speed = one;
  } else if (readSerial[1] == '2') {
    current_speed = two;
  } else if (readSerial[1] == '3') {
    current_speed = three;
  } else if (readSerial[1] == '4') {
    current_speed = four;
  } else if (readSerial[1] == '5') {
    current_speed = five;
  }
  if (readSerial[2] == 'n') {
    current_direction = normal;
  } else if (readSerial[2] == 'r') {
    current_direction = reverse;
  }
  if (current_direction == normal) {
    theater_chase(current_color, current_speed);
  } else if (current_direction == reverse) {
    reverse_theater_chase(current_color, current_speed);
  }
}

void theater_chase(uint32_t color, uint32_t wait) {
  for (uint32_t j = 0 ; j <= 2 ; j++) {
    for (uint32_t i = 0 ; i < strip.numPixels(); i++) {
      if (i % 3 == j) {
        strip.setPixelColor(i, color);
      }
    }
    strip.show();
    delay(wait);
    for (uint32_t i = 0 ; i < strip.numPixels(); i++) {
      if (i % 3 == j) {
        strip.setPixelColor(i, 0);
      }
    }
  }
}

void reverse_theater_chase(uint32_t color, uint32_t wait) {
  for (uint32_t j = 3 ; j > 0 ; j--) {
    for (uint32_t i = 0 ; i < strip.numPixels(); i++) {
      if (i % 3 == j - 1) {
        strip.setPixelColor(i, color);
      }
    }
    strip.show();
    delay(wait);
    for (uint32_t i = 0 ; i < strip.numPixels(); i++) {
      if (i % 3 == j - 1) {
        strip.setPixelColor(i, 0);
      }
    }
  }
}




