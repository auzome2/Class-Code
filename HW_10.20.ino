//Collect 200 temp values and find the min, max and avg
int val = 0;
float minVal;
float maxVal;
float totalVal = 0;
float Average;
float minTemp;
float maxTemp;
float averageTemp;
float Valtemp;

void setup() {
  Serial.begin(9600);
}
void loop() {
  Serial.println();
  minVal = 1023; //Provides a starting point for min val
  maxVal = 0; //Provides a starting point for Max val
  for (int i = 0; i < 200; i++) {
    Serial.print(i);
    Serial.print("\n");
    val = analogRead(2); // Finds the val from analog 2
    Serial.print(" val= ");
    Serial.print(val);
    Serial.print("\n ");
    Valtemp = 0.0909 * val - 20.629; // converts the val to a tempature
    Serial.print("Valtemp= ");
    Serial.print(Valtemp); Serial.println("degC");
    if (minVal >= val) { //Checks if min value is >= analog read
      minVal = val; //if minVal > val, then val becomes new minVal

    }
    else {
      minVal = minVal; //otherwise keep minVal the same

    }
    minTemp = 0.0909 * minVal - 20.629; // converts to tempature
    Serial.print(" minTemp= ");
    Serial.print(minTemp); Serial.println("degC");
    if (maxVal <= val) { // checks if max value is <= analog read
      maxVal = val; // if so then val becomes new Max

    }
    else {
      maxVal = maxVal; // otherwise keep max the same

    }
    maxTemp = 0.0909 * maxVal - 20.629; // converts to tempature
    Serial.print(" maxTemp= ");
    Serial.print(maxTemp); Serial.println("degC");

    totalVal = totalVal + val; // calculate total value

    delay(500);
  }
  Serial.print("For 200 points");
  Serial.print(" Absolute Min = ");
  Serial.print(minTemp);
  Serial.print(" = "); Serial.print(minTemp); Serial.println("degC");
  Serial.print(" Absolute Max = ");
  Serial.print(maxTemp);
  Serial.print(" = "); Serial.print(maxTemp); Serial.println("degC");
  Serial.print("Average = ");
  Average = (totalVal - minVal - maxVal) / 198.0; // Finds average after removing max and min
  Serial.print(Average, 4);
  averageTemp = 0.0909 * Average - 20.629; // converts average to a tempature
  Serial.print(" = "); Serial.print(averageTemp); Serial.println("degC");
  delay(10000);
}
