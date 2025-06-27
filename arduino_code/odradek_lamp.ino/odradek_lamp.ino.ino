// author: jacob pawlak
// date: June 25, 2025
// file name: odradek_lamp.ino
// gooooo blue team!

// using the FastLED library for the ws2812 strips i bought for easy use of addressable lights
#include <FastLED.h>

// Definitions for pins and LED settings 
#define arm_lights_pin 4 
#define blue_led_pin 8
#define num_leds_per_strip 6
#define led_type WS2812
#define color_order RGB
// array of CRGB leds
CRGB leds[num_leds_per_strip];

// Setup function, should do a fun little flashy annimation to tell you it's turning on
//  gonna use the little blue light on the front for that
void setup() {

    // power-up safety delay
    delay(2000);
    // create the LED object and add the light
    FastLED.addLeds<led_type, arm_lights_pin, color_order>(leds, num_leds_per_strip);

    // flash the little blue light 5 times rapidly and then stay on
    for(int i = 0; i <=5; i++){
        digitalWrite(blue_led_pin, HIGH);
        delay(50);
        digitalWrite(blue_led_pin, LOW);
        delay(50);
    }
    digitalWrite(blue_led_pin, HIGH);
    
}

// Loop function that runs continuously (i think i could put this in the setup but might as well keep it here)
void loop()
{
    // loop through all of the lights and assign them the white light pallet
    for(int led = 0; led < num_leds_per_strip; led++) {
        leds[led] = CRGB::White;
    }
    // turn on the lights!! 
    FastLED.show();

}
