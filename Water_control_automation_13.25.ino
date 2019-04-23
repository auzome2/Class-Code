//Class 13.25
//Controls the Fan Motor ON and OFF based on measured temperature, setpoint, UCL and LCL

float waterval; //= analogRead(0);  // variable to store water value; read initial value of water sensor
float LCL;
void setup() {
  waterval = analogRead(0);  // variable to store water value; read initial value of water sensor
  LCL = 120;  // subtract 3 STDEV
  pinMode(6, OUTPUT); //digital pin 6 controls the water pump
  Serial.begin(9600); //set up to print out text to monitor
}

void loop() {
 waterval = analogRead(0);  // variable to store water value; read initial value of water sensor
  delay(2000);  // wait for 2 seconds each time through loop
  //Serial.print("  UCL = "); Serial.print(UCL);
  Serial.print("  LCL = "); Serial.print(LCL);
  Serial.println();
  waterval = analogRead(0);  // read water sensor input pin 0
  Serial.print("Current waterval = ");
  Serial.println(waterval);    // print water sensor value to serial monitor
  if (waterval < LCL) // turn ON Water Pump if measured water value < LCL (water value too low)
  {
    Serial.println("***waterval < LCL");
    PUMPON();
  } 
  else {
  Serial.println("***waterval > LCL");
  //Serial.println(); //print
  PUMPOFF();
}
}
void PUMPON() {
  Serial.println("Executing function for < LCL "); // Print out function that the Smart Factory will run
  digitalWrite(6, HIGH); //Water Pump On
  delay(2200);
  digitalWrite(6, LOW); //Water Pump off
}

void PUMPOFF() {
  Serial.println("Executing function for > LCL "); // Print out function that the Smart Factory will run
  digitalWrite(6, LOW);  //Water Pump Off
}
