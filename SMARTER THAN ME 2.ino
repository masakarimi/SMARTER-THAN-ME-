

/*
---------------------------SMARTER THAN ME------------------------------------------
PROJECT TITLE: SMARTER THAN ME
Created by: Sara Gazzaz
            Mahsa Karimi
Date of completion:11-24-2016
Description: Smarter Than Me are two notification devices
that are triggered according to specific sensors.First device
is a ring that is attached to a temperature sensor and according
to the surrounding temperature it's colors vary from dark blue to
bright red.Second device is a jewelry attached to winter gloves.
This smart device is a notification system which triggers if it
enters a previously set location by the wearer.
----------------------------------------------------------------------------------
*/


// This #include statement was automatically added by the Particle IDE.
#include "lib1.h"
// This #include statement was automatically added by the Particle IDE.
#include "neopixel/neopixel.h"

Adafruit_NeoPixel lightbar = Adafruit_NeoPixel(8, neoPixel, WS2812);


Particle.subscribe("True", performLights);
// Initial Setup
void setup() {
    //initialize the global variables

    //initalize the NeoPixel lightbar
    lightbar.begin();
    lightbar.setBrightness(40);
    lightbar.show();


// Main Loop
void loop() {

    performLights();

}

void performLights()
{
    // an Array of the RGB components of these colors: red[255, 0. 0], orange[255, 128, 0], yellow[255, 255, 0],
    // green[0, 255, 0], cyan[0, 255, 255], blue[0, 0, 255], purple[128, 0, 255]
    int colorArray[7][3] = {255, 0, 0, 255, 128, 0, 255, 255, 0, 0, 255, 0, 0, 255, 255, 0, 0, 255, 128, 0, 255};

    for (int color = 0; color < 7; color++)
    {
        for(int i = 0; i < lightbar.numPixels(); i++){
            lightbar.setPixelColor(i, lightbar.Color(colorArray[color][0], colorArray[color][1], colorArray[color][2]));
        }
        lightbar.show();
        delay(1500);
    }
}
