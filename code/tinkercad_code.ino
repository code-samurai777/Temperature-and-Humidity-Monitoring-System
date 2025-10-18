#include <LiquidCrystal.h>

// Pins for the LCD (RS, E, D4, D5, D6, D7)
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Pin assignments for the sensors
const int tempPin = A0;  // TMP36 is connected to analog pin A0
const int humPin = A1;   // Potentiometer is connected to analog pin A1

// --- Moving Average Filter Configuration ---
const int numReadings = 10; // Number of readings to average
int tempReadings[numReadings]; // Array to store temperature readings
int humReadings[numReadings];  // Array to store humidity readings
int tempIndex = 0;             // The current position in the temperature array
int humIndex = 0;              // The current position in the humidity array
long tempTotal = 0;            // The total sum of temperature readings
long humTotal = 0;             // The total sum of humidity readings
float tempAverage = 0;         // The smoothed average temperature
int humAverage = 0;            // The smoothed average humidity

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);

  // Initialize all values in the arrays to 0
  for (int i = 0; i < numReadings; i++) {
    tempReadings[i] = 0;
    humReadings[i] = 0;
  }
}

void loop() {
  // --- Read and process temperature with moving average filter ---
  // Subtract the oldest reading from the total
  tempTotal = tempTotal - tempReadings[tempIndex];
  
  // Read a new value from the sensor
  tempReadings[tempIndex] = analogRead(tempPin);
  
  // Add the new reading to the total
  tempTotal = tempTotal + tempReadings[tempIndex];
  
  // Move to the next position in the array
  tempIndex++;
  
  // If we've reached the end of the array, wrap around to the beginning
  if (tempIndex >= numReadings) {
    tempIndex = 0;
  }
  
  // Calculate the new average
  tempAverage = tempTotal / (float)numReadings;
  
  // Convert the smoothed average analog reading to temperature in Celsius
  float voltage = tempAverage * (5.0 / 1024.0);
  float temperatureC = (voltage - 0.5) * 100;
  
  // --- Read and process humidity with moving average filter ---
  // Subtract the oldest reading from the total
  humTotal = humTotal - humReadings[humIndex];
  
  // Read a new value from the sensor
  humReadings[humIndex] = analogRead(humPin);
  
  // Add the new reading to the total
  humTotal = humTotal + humReadings[humIndex];
  
  // Move to the next position in the array
  humIndex++;
  
  // If we've reached the end of the array, wrap around to the beginning
  if (humIndex >= numReadings) {
    humIndex = 0;
  }
  
  // Calculate the new average
  humAverage = humTotal / numReadings;
  
  // Map the smoothed average value (0-1023) to a humidity percentage (0-100)
  int humidity = map(humAverage, 0, 1023, 0, 100);
  
  // --- Display on LCD ---
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperatureC, 1); // Display with one decimal place
  lcd.print(" C   ");
  
  lcd.setCursor(0, 1);
  lcd.print("Hum:  ");
  lcd.print(humidity);
  lcd.print(" %   ");
  
  // Print smoothed values to the Serial Monitor for verification
  Serial.print("Smoothed Temp: ");
  Serial.print(temperatureC);
  Serial.print(" C, Smoothed Hum: ");
  Serial.print(humidity);
  Serial.println(" %");
  
  delay(100); 
}
