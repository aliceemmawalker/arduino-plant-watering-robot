/*

CONNECTIONS:

ARDUINO

GND - Breadboard GND

MOISTURE SENSOR

VCC - Arduino 5V
GND - Breadboard GND
D0 - Arduino A0

RELAY

IN - Arduino D3
GND - Breadboard GND
VCC - Breadboard Power

Always Open - Water pump power
Public - Breadboard power
Always closed - DO NOT CONNECT

WATER PUMP

GND (black wire) - Breadboard GND
Power (red wire) already described above - Relay 'Always Open'
 
 */

int greenLight = 13; // Green light power connects to pin D13

int redLight = 12; // Red light power connects to pin D12

int soilSensor1 = 0; // Soil moisture sensor connects to Analog pin A0 -- make sure it's the "A" pin!

int sensorValue = 0; // This is not a connection! This is the variable for our sensor, leave this at 0

int relay = 3; // A relay turns electronics on and off. We need this for our water pump. Connect the "IN" on the relay to pin D3 on the Arduino


void setup() { //A setup function defines all the important facts before the code runs
  
   Serial.begin(9600); // Tells the Arduino to start recording text in the Serial Monitor
   
   pinMode(greenLight, OUTPUT); // Tells the Arduino that a green light will be used to communicate
   
   pinMode(redLight, OUTPUT); // Tells the Arduino that a red light will be used to communicate
   
   pinMode(relay, OUTPUT); // Tells the Arduino that a relay will be used to communicate and control the water pump
   
   Serial.println("BEGIN PLANT WATERING CODE"); // When the Arduino starts, it will print this message in the Serial Monitor
}


void loop() { // A loop function runs approximately every second. It is the main action in our code

  digitalWrite(relay, HIGH); // When the relay voltage is "high", no electricity is getting to our water pump, so the pump is turned off
  
   sensorValue= analogRead(soilSensor1); // Check the sensorValue (how much moisture is in the soil
   
   sensorValue= sensorValue/10; // Divide the sensorValue by 10 to make it easier to read
   
   Serial.println(sensorValue); // Print out the sensorValue in the Serial Monitor
   
   if(sensorValue<70) // If the sensorValue is less than 50 (meaning the soil is very wet) Do this:
   
   {
      digitalWrite(greenLight, HIGH); // Turn on the green light
      
      Serial.println("wet"); // Write this message in the Serial Monitor
   }
   
   else // If the sensorValue is greater than 50 (very dry) Do this:
   
   {
    
      digitalWrite(redLight,HIGH); // Turn the red light on
      
      Serial.println("dry"); // Write this message in the Serial Monitor
      
      digitalWrite(relay, LOW); // Turn down the voltage in the relay, which allows power to the water pump
      
      delay(1500); // Do all the actions in the "else" statement for 1000 milliseconds, which is the same at 10 seconds
      
   }
   
   delay(1000); // When all the actions are done, wait one second before moving on
   
   digitalWrite(greenLight,LOW); // Turn off the green light
   
   digitalWrite(redLight, LOW); // Turn off the red light
   
   digitalWrite(relay, HIGH); // Turn the voltage on the relay to high again to stop power going to the water pump
   
}
