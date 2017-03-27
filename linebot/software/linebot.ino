// RaumZeitLabor - Line Following Bot V1.0
// Ingo M. Schaefer
// March 2017

#define motorPin1 0
#define motorPin2 1
#define ledPin 2
#define sensorPin1 A2
#define sensorPin2 A3
#define pwmValue 128 // 0..255
#define sensorThreshold 100
#define sensorReadings 8 // smooth out sensor readings, max.64

// The sensor values can be 1 - sensor sees light, 0 - sensor sees dark
byte sensorVal1 = 0;
byte sensorVal2 = 0;
byte sensorVal1_old = 0;
byte sensorVal2_old = 0;

void readSensors()
{
  unsigned int avgSensor1 = 0;
  unsigned int avgSensor2 = 0;
  for(byte i=0; i<sensorReadings; i++)
  {
    avgSensor1 += analogRead(sensorPin1);
    avgSensor2 += analogRead(sensorPin2);
  }
  avgSensor1 /= sensorReadings;
  avgSensor2 /= sensorReadings;

  // store old sensor values
  sensorVal1_old = sensorVal1;
  sensorVal2_old = sensorVal2;

  // compare to threshold
  if(avgSensor1 < sensorThreshold) { sensorVal1 = 0; } else { sensorVal1 = 1; }
  if(avgSensor2 < sensorThreshold) { sensorVal2 = 0; } else { sensorVal2 = 1; }
}

// the function expects two values for the motors (0 - off, 1 - on)
void moveMotors(byte m1, byte m2)
{
  analogWrite(motorPin1, pwmValue*m1);
  analogWrite(motorPin2, pwmValue*m2);
}

// the brain of the bot - movement decisions are based on sensor readings
void moveBot()
{
  // best case: edge of the line - go straight
  if((sensorVal1 == 0 && sensorVal2 == 1) || (sensorVal1 == 1 && sensorVal2 == 0)) { moveMotors(1,1); }

  // both sensors see dark
  if(sensorVal1 == 0 && sensorVal2 == 0) 
  {
    // if previous values have been good, try to turn back
    if(sensorVal1_old == 0 && sensorVal2_old == 1) { moveMotors(1,0); }
    if(sensorVal1_old == 1 && sensorVal2_old == 0) { moveMotors(0,1); }

    // if previous values haven been light we hit the line straight, try to turn left
    if(sensorVal1_old == 1 && sensorVal2_old == 1) { moveMotors(0,1); }

    // if previous values haven been dark we might have found a broad line? Let's turn right.
    if(sensorVal1_old == 0 && sensorVal2_old == 0) { moveMotors(1,0); }    
  }

  // both sensors see light
  if(sensorVal1 == 1 && sensorVal2 == 1) 
  {
    // if previous values have been good, try to turn back
    if(sensorVal1_old == 0 && sensorVal2_old == 1) { moveMotors(0,1); }
    if(sensorVal1_old == 1 && sensorVal2_old == 0) { moveMotors(1,0); }

    // if previous values haven been light we still haven't found any line. Keep going forward.
    if(sensorVal1_old == 1 && sensorVal2_old == 1) { moveMotors(1,1); }

    // if previous values haven been dark we might have crossed a line. Let's turn right.
    if(sensorVal1_old == 0 && sensorVal2_old == 0) { moveMotors(1,0); }    
  }
}

void setup() 
{
  // we start with motors off
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  moveMotors(0,0);
  
  // blink, then turn on the light
  pinMode(ledPin, OUTPUT);
  for(byte i=0; i<10; i++)
  {
    digitalWrite(ledPin, i%2);
    delay(200);
  }
  digitalWrite(ledPin, HIGH);
}

void loop() 
{
  readSensors();
  moveBot();
  delay(5); // longer delay - smoother movement but less accuracy
}

