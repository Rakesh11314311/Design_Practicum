#define IR_SENSOR_RIGHT A0
#define IR_SENSOR_LEFT A1
#define MOTOR_SPEED 170
#define REV_MOTOR_SPEED 80

//Right motor
int enableRightMotor=10;
int rightMotorPin1=7;
int rightMotorPin2=6;

//Left motor
int enableLeftMotor=11;
int leftMotorPin1=5;
int leftMotorPin2=4;

void rotateMotor(int rightMotorSpeed, int leftMotorSpeed);

void setup()
{
  // put your setup code here, to run once:
  pinMode(enableRightMotor, OUTPUT);
  pinMode(rightMotorPin1, OUTPUT);
  pinMode(rightMotorPin2, OUTPUT);
  
  pinMode(enableLeftMotor, OUTPUT);
  pinMode(leftMotorPin1, OUTPUT);
  pinMode(leftMotorPin2, OUTPUT);

  pinMode(IR_SENSOR_RIGHT, INPUT);
  pinMode(IR_SENSOR_LEFT, INPUT);
  rotateMotor(0,0);    
}


void loop() 
{

  int rightIRSensorValue = digitalRead(IR_SENSOR_RIGHT);
  int leftIRSensorValue = digitalRead(IR_SENSOR_LEFT);


  //If none of the sensors detects black line, then go straight
  if ((rightIRSensorValue==LOW)&&(leftIRSensorValue==LOW))
  {
    rotateMotor(MOTOR_SPEED, MOTOR_SPEED);
  }
  //If right sensor detects black line, then turn right
  else if ((leftIRSensorValue == HIGH )&&(rightIRSensorValue==LOW))
  {
      rotateMotor(MOTOR_SPEED, -REV_MOTOR_SPEED);     
  }
  //If left sensor detects black line, then turn left  
  else if ((rightIRSensorValue == HIGH )&&(leftIRSensorValue==LOW))
  {
      rotateMotor(-REV_MOTOR_SPEED, MOTOR_SPEED); 
  } 
  //If both the sensors detect black line, then stop 
  else 
  {
    rotateMotor(0, 0);
  }
}


void rotateMotor(int rightMotorSpeed, int leftMotorSpeed)
{
  
  if (rightMotorSpeed > 0)
  {
    digitalWrite(rightMotorPin1,HIGH);
    digitalWrite(rightMotorPin2,LOW);
    analogWrite(enableRightMotor, abs(rightMotorSpeed));      
  }
  else if (rightMotorSpeed < 0){
    digitalWrite(rightMotorPin1,LOW);
    digitalWrite(rightMotorPin2,HIGH);
    analogWrite(enableRightMotor, -(abs(rightMotorSpeed))); 
  }
  else
  {
    digitalWrite(rightMotorPin1,LOW);
    digitalWrite(rightMotorPin2,LOW);      
  }

  if (leftMotorSpeed > 0)
  {
    digitalWrite(leftMotorPin1,HIGH);
    digitalWrite(leftMotorPin2,LOW);  
    analogWrite(enableLeftMotor, abs(leftMotorSpeed)); 
  }
  else if (leftMotorSpeed < 0)
  {
    digitalWrite(leftMotorPin1,LOW);
    digitalWrite(leftMotorPin2,HIGH);  
    analogWrite(enableLeftMotor, -(abs(leftMotorSpeed))); 
  }
  else 
  {
    digitalWrite(leftMotorPin1,LOW);
    digitalWrite(leftMotorPin2,LOW);      
  }
  
     
}
