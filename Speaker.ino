int frequency = 5000; //sets frequency
float period; // declares all our variables
int halfPeriod;
long timer;
int setpoint = 520; //sets setpoint to room temp
int settemp;
int valtemp;

void setup() {
 Serial.begin(9600);
 pinMode(4, OUTPUT); //speaker output
 pinMode(10,OUTPUT); //LED output
 period = 1.0/frequency; //period is 1/frequency
 halfPeriod = period/2*1000000; //half period is 1/2 of period
 settemp= .0909*setpoint-20.629; // converts analog value of setpoint to degC
 Serial.print("f = ");Serial.print(frequency);
 Serial.print(" T = ");Serial.print(period,6);
 Serial.print(" 1/2T = ");Serial.print(halfPeriod);
 Serial.println("ms");

 Serial.print(" setpoint = ");Serial.print(setpoint);Serial.print(", ");Serial.print(settemp);Serial.print("degC");
 
 
 
}

void loop() {
  int val=analogRead(5); //Thermistor 
  Serial.print("analog value = ");Serial.print(val);
  valtemp = .0909*val-20.629; //Converts val read to a temp
  Serial.print(" Analog temp = ");Serial.print(valtemp);Serial.print("degC");
  if(val<setpoint) alarm(); //if below setpoint sound alarm
  if(val>setpoint) LED(); //if above setpoint blink LED
  
  

}
void alarm(){
  Serial.println(" below setpoint");
  for (int i=1; i<3000; i++){
  digitalWrite(4,HIGH);
  delayMicroseconds(halfPeriod);
  digitalWrite(4,LOW);
  delayMicroseconds(halfPeriod);
}
  delay(1000);
}
void LED(){
  Serial.println(" above setpoint");
  digitalWrite(10,HIGH);
  delay(1000);
  digitalWrite(10,LOW);
  delay(700);
}
