/*
  Take pressure and temperature readings with the LPS25HB using I2C
  By: Owen Lyke
  SparkFun Electronics
  Date: May 31st 2018
  License: This code is public domain but you buy me a beer if you use this and we meet someday (Beerware license).

  Example1_Basic Readings

  To connect the sensor to an Arduino:
  This library supports the sensor using the I2C protocol
  On Qwiic enabled boards simply connnect the sensor with a Qwiic cable and it is set to go
  On non-qwiic boards you will need to connect 4 wires between the sensor and the host board
  (Arduino pin) = (Display pin)
  SCL = SCL on display carrier
  SDA = SDA
  GND = GND
  3.3V = 3.3V
*/

// Click here to get the library: http://librarymanager/All#SparkFun_LPS25HB
#include <LPS25HB.h>  //

LPS25HB pressureSensor; // Create an object of the LPS25HB class

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Hello!");

  while(pressureSensor.isConnected == LPS25HB_CODE_DISCONNECTED)  // The library supports some different error codes such as "DISCONNECTED"
  {
    Serial.print("Waiting for connection to LPS25HB.");                         // Alert the user that the device cannot be reached
    Serial.print(" Are you using the right Wire port and I2C address?");        // Suggest possible fixes
    Serial.println(" See Example2_I2C_Configuration for how to change these."); // Suggest possible fixes
    delay(250);
  }

  pressureSensor.begin();    // Begin links an I2C port and I2C address to the sensor, begins I2C on the main board, and then sets default settings
}

void loop() {
  // put your main code here, to run repeatedly:
    Serial.print("Pressure in hPa: "); 
    Serial.print(pressureSensor.getPressure_hPa());          // Get the pressure reading in hPa
    Serial.print(", Temperature (degC): "); 
    Serial.println(pressureSensor.getTemperature_degC());    // Get the temperature in degrees C

    delay(40);                                               // Wait - 40 ms corresponds to the maximum update rate of the sensor (25 Hz)
}