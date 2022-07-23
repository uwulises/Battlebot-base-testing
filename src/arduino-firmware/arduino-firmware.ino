
#include <Servo.h>
String inputString = "";
bool stringComplete = false;

const int MAX_SPEED_R = 255;
const int MAX_SPEED_L = 255;
const int SOFT_SPEED_R = 150;
const int SOFT_SPEED_L = 150;
const int STOP_SPEED = 0;


// RIGHT MOTOR
#define DCR1 2    //IN1
#define DCR2 4    //IN2
#define PWM_R 3   //SPEED R

//LEFT MOTOR
#define DCL1 10    //IN3
#define DCL2 11   //IN4
#define PWM_L 6   //SPEED L

void setup()
{
  pinMode(DCR1, OUTPUT);
  pinMode(DCR2, OUTPUT);
  pinMode(DCL1, OUTPUT);
  pinMode(DCL2, OUTPUT);
  pinMode(PWM_R, OUTPUT);
  pinMode(PWM_L, OUTPUT);
  //softspeed();
  Serial.begin(9600);
  delay(1000);
  Serial.println("----");
  Serial.println("READY");
  Serial.println("----");
  delay(200);
}

// put your main code here, to run repeatedly:
void serialEvent()
{
  while (Serial.available())
  {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag so the main loop can
    // do something about it:
    if (inChar == '\n')
    {
      stringComplete = true;
    }
  }
}


void BW()
{
  digitalWrite(DCR1, HIGH);
  digitalWrite(DCR2, LOW);
  digitalWrite(DCL1, LOW);
  digitalWrite(DCL2, HIGH);
}
void FW()
{
  digitalWrite(DCR1, LOW);
  digitalWrite(DCR2, HIGH);
  digitalWrite(DCL1, HIGH);
  digitalWrite(DCL2, LOW);

}

void TR()
{
  digitalWrite(DCR1, HIGH);
  digitalWrite(DCR2, LOW);
  digitalWrite(DCL1, HIGH);
  digitalWrite(DCL2, LOW);

}

void TL()
{
  digitalWrite(DCR1, LOW);
  digitalWrite(DCR2, HIGH);
  digitalWrite(DCL1, LOW);
  digitalWrite(DCL2, HIGH);
}

void STOP()
{
  digitalWrite(DCR1, LOW);
  digitalWrite(DCR2, LOW);
  digitalWrite(DCL1, LOW);
  digitalWrite(DCL2, LOW);
  digitalWrite(PWM_R, STOP_SPEED);
  digitalWrite(PWM_L, STOP_SPEED);

}
void FULLSPEED()
{
  analogWrite(PWM_L, MAX_SPEED_L);
  analogWrite(PWM_R, MAX_SPEED_R);
}

void SOFTSPEED()
{
  analogWrite(PWM_L, SOFT_SPEED_L);
  analogWrite(PWM_R, SOFT_SPEED_R);
}

void loop()
{

  if (stringComplete)
  {
    Serial.println(inputString);
    if (inputString == "FW\n")
    {
      FW();
    }

    if (inputString == "BW\n")
    {
      BW();
    }
    if (inputString == "TR\n")
    {
      TR();
    }

    if (inputString == "TL\n")
    {
      TL();
    }
    if (inputString == "FULLSPEED\n")
    {
      FULLSPEED();
    }
    if (inputString == "SOFTSPEED\n")
    {
      SOFTSPEED();
    }
    if (inputString == "STOP\n")
    {
      STOP();
    }
    else
    {
      inputString = "";
    }

    // clear the string:
    inputString = "";
    stringComplete = false;
  }
}
