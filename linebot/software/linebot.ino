// RaumZeitLabor - Line Following Bot V1.0
// Ingo M. Schaefer
// March 2017

#define motorPin1 0
#define motorPin2 1
#define ledPin 2
#define sensorPin1 A2
#define sensorPin2 A3
#define pwmValue 80 // 0..255 speed
#define sensorThreshold 120 // 120
#define sensorReadings 8 // smooth out sensor readings, max.64

// The sensor values can be 1:sensor sees light, 0:sensor sees dark
byte sensorVal1 = 0;
byte sensorVal2 = 0;
byte sensorVal1_old = 0;
byte sensorVal2_old = 0;

byte botState = 0; // 0:stand, 1/2:turn, 3:go straight

// read sensor values compare to threshold and store variables for further processing
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

// the function expects two values for the motors (0:off, 1:on)
void moveMotors(byte m1, byte m2)
{
  analogWrite(motorPin1, pwmValue*m1);
  analogWrite(motorPin2, pwmValue*m2);
}

// the brain of the bot - movement decisions are based on sensor readings
void moveBot()
{
  // if(sensorVal1==1) { analogWrite(motorPin1, 128); } else { analogWrite(motorPin1, 0); }
  // if(sensorVal2==1) { analogWrite(motorPin2, 128); } else { analogWrite(motorPin2, 0); }
  
  // best case: edge of the line - go straight
  if((sensorVal1 == 0 && sensorVal2 == 1) || (sensorVal1 == 1 && sensorVal2 == 0)) { moveMotors(1,1); botState=3; }

  // both sensors see dark
  if(sensorVal1 == 0 && sensorVal2 == 0) 
  {
    // do we have a plan already? If not, decide on a direction
    if(botState != 3) 
    {
      if(botState==2) moveMotors(1,0);
      if(botState==1) moveMotors(0,1);
    } else {
      moveMotors(1,1);            
      // if previous values have been good, try to turn back
      if(sensorVal1_old == 0 && sensorVal2_old == 1) { botState = 2; }
      if(sensorVal1_old == 1 && sensorVal2_old == 0) { botState = 1; }

      // if previous values haven been light we hit the line straight, try to turn left
      if(sensorVal1_old == 1 && sensorVal2_old == 1) { botState = 1; }

      // if previous values haven been dark we might have found a broad line? Let's turn right.
      if(sensorVal1_old == 0 && sensorVal2_old == 0) { botState = 2; }    
    }
  }

  // both sensors see light
  if(sensorVal1 == 1 && sensorVal2 == 1)
  {
    // do we have a plan already? If not, decide on a direction
    if(botState != 3) 
    {
      if(botState==2) moveMotors(1,0);
      if(botState==1) moveMotors(0,1);
    } else {      
      moveMotors(1,1);
      // if previous values have been good, try to turn back
      if(sensorVal1_old == 0 && sensorVal2_old == 1) { botState = 1; }
      if(sensorVal1_old == 1 && sensorVal2_old == 0) { botState = 2; }

      // if previous values haven been light we still haven't found any line. Keep going forward.
      if(sensorVal1_old == 1 && sensorVal2_old == 1) { botState = 3; }

      // if previous values haven been dark we might have crossed a line. Let's turn right.
      if(sensorVal1_old == 0 && sensorVal2_old == 0) { botState = 1; }    
    }
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
  delay(10); // longer delay - smoother movement but less accuracy
}

