/***************************************************
  Lamborghino sensor detects the absolute angular position of the shaft.
  For more information visit
  ----> http://lamborghino.com
  ----> https://www.youtube.com/lamborghino
  Written by Andrés Bercovich: twitter: @andresbercovich
  MIT license, all text above must be included in any redistribution
****************************************************/


#include <Motorghino.h>

//Declare the motorghino variable, like a "Motor_Left"
Motorghino Motor_Left;

void setup() {
 //Begin function of the element have 3 arguments: .begin(Diametert of the wheel, Reduction Ratio, CS pin of SPI)
 // Keep in mind that OpenLamborghino 2.2 have the CS pin of the left motor in D2, and right motor in D3 in Arduino), but
 //if you want a use Motorghino without Open Lamborghino, you can select any digital pin (except SPI pins)

  Motor_Left.begin(32, 5, 2);

  //init the serial port comunication
  Serial.begin(115200);

}

void loop() {
// Declare variable, for example "rps" (Remember that "get_rps()" function, return a float variable).
float rps;

// assign the rps to "rps" variable
rps = Motor_Left.get_rps();

// finally, print "rps" variable through Serial Terminal
Serial.println(rps);

}
