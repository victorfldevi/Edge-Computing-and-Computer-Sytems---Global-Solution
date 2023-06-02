#include <LiquidCrystal.h>

// Store Ambient Sensor values
int volSens = 0;
int tempSens = 0;
int lightSens = 0;

// Define the pins used by the LCD screen
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;

// Send the pin's signal to the respective LCD display input port
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Store the values of char concats outside loop() function, 
// so they dont get reset (only rewritten)
String finalString1;
String finalString2;

// Store values to verify if there's changes to finalString
// to avoid LCD visual bugs
String initString1;
String initString2;

// Store the converted values from sensors
int humidPercentage = 0;
int luxValue = 0;

// Store the limit value defined by the user for each regulator
int minHumidPercentage = 0;
int maxTempC = 0;
int minLuxValue = 0;

// Store the values that simulates wifi signal using a on/off button
bool wifi = false;
bool wifi_prev = false;
bool trigger = true;

// Stores the value of the funcion millis() at a given time
unsigned long previousMillis = 0;


void setup()
{
  // Start the Serial Monitor
  Serial.begin(9600);
  
  // Start the LCD display
  lcd.begin(16, 2);
  
  pinMode(10, INPUT);
}

void loop()
{
  	// Stores the millis() function in a variable;
  	unsigned long currentMillis = millis();
  
  	// Detect if 100 milliseconds have passed;
  	if(currentMillis - previousMillis >= 100)
    {
      // Switches the previousMillisecons reset if wifi is on
      if(!wifi)
      {
      	previousMillis = currentMillis;
      }
      
      // Toggle button method to switch wifi
      if(digitalRead(10) == 1 && !wifi_prev)
      {
        if(!wifi)
        {
        	wifi = true;
        }
        else
      	{
        	wifi = false;
      	}
      }
      
      // Sets wifi_prev to button value
      wifi_prev = digitalRead(10);
      
      // Grab and stores the value of each sensor
      volSens = analogRead(A0);
      tempSens = analogRead(A1);
      lightSens = analogRead(A2);

      // Convert voltage to percentage
      humidPercentage = map(volSens, 876, 0, 100, 0);	

      // Convert voltage to Degrees
      tempSens = (tempSens * 0.48828125) - 50;

      // Convert voltage to kilolux (1000 lumens per square meter)
      luxValue = (sensorRawToDaylight(lightSens));

      // Store both values from sprintf function to be converted
      // later to strings
      char finalChar1[15] = "";
      char finalChar2[15] = "";

      // Grab all sensor values and fuse them into a char array
      sprintf(finalChar1, "%d%% %dC %dklux", humidPercentage, tempSens, luxValue);
      
      // Grab the wifi variable to simulate wifi signal on display
      if(wifi)
      {
        if(trigger)
        {
        	sprintf(finalChar2, "Conectando...");
        }
        if(currentMillis - previousMillis >= 1500 || !trigger)
    	{
        	sprintf(finalChar2, "Conectado (wifi)");
          	previousMillis = currentMillis;
          	trigger = false;
        }
      }
      else
      {
        sprintf(finalChar2, "Nao conectado...");
        trigger = true;
      }

      // Convert the char arrays into single strings
      initString1 = (finalChar1);
      initString2 = (finalChar2);	

      // Compare if there were changes to the lenght of the string
      // just for LCD display debugging
      if (finalString1.length() > initString1.length() || finalString2.length() > initString2.length())
      {
          lcd.clear();
      }

      // After debugged, finalStrings are rewritted for next loop
      finalString1 = initString1;
      finalString2 = initString2;

      // Print the finalString1 value on LCD display
      lcd.print(finalString1);

      // Set column to 0 and row to 1(which is the 2nd row)
      lcd.setCursor(0, 1);

      // Print the finalString2 value on LCD display
      lcd.print(finalChar2);

      // Set column to 0 and row to 0(which is the 1st row)
      lcd.setCursor(0, 0);
   }
}

// Convert the sensor value to lumens
int sensorRawToLumens(int raw){
  
  // Convert analog signal to resistance
  float vout = float(raw) * (5 / float(1023));
  
  // Convert resistênce to voltage
  float rLDR = (1000 * (5 - vout)) / vout;
  
  // Convert voltage to lumens
  int lum = 500 /(rLDR / 1000);
  return lum;
}

// Convert lumens in kilolux
int sensorRawToDaylight(int raw)
{
  return (sensorRawToLumens(raw)) / 100;
}
