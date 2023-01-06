#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVOMIN  150 // This is the 'minimum' pulse length count (out of 4096) //increasing it makes ccw go less
#define SERVOMAX  500 // This is the 'maximum' pulse length count (out of 4096) //increasing it makes cw go more
#define SERVO_FREQ 50 // Analog servos run at ~50 Hz updates

#define sgn(x) ((x) < 0 ? -1 : ((x) > 0 ? 1 : 0))

uint8_t servonumINDEX = 0;
uint8_t servonumMIDDLE = 1;
uint8_t servonumRING = 2;
uint8_t servonumPINKY = 3;
uint8_t servonumTHUMBFINGER = 4;
uint8_t servonumTHUMBBASE = 5;

int buttonnumINDEX = 0;
int buttonnumMIDDLE = 1;
int buttonnumRING = 2;
int buttonnumPINKY = 3;
int buttonnumTHUMBFINGER = 4;
int buttonnumTHUMBBASE = 5;

int buttonStateINDEX = 0;
int buttonStateMIDDLE = 0;
int buttonStateRING = 0;
int buttonStatePINKY = 0;
int buttonStateTHUMBFINGER = 0;
int buttonStateTHUMBBASE = 0;

double maxReleaseINDEX = 0;
double maxContractionINDEX = 120;

double maxReleaseMIDDLE = 150;
double maxContractionMIDDLE = 60;

double maxReleaseRING = 0;
double maxContractionRING = 0;

double maxReleasePINKY = 160;
double maxContractionPINKY = 90;

double maxReleaseTHUMBFINGER = 0;
double maxContractionTHUMBFINGER = 0;

double maxReleaseTHUMBBASE = 0;
double maxContractionTHUMBBASE = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("program started");

  pinMode(buttonnumINDEX, INPUT);
  pinMode(buttonnumMIDDLE, INPUT);
  pinMode(buttonnumRING, INPUT);
  pinMode(buttonnumPINKY, INPUT);
  pinMode(buttonnumTHUMBFINGER, INPUT);
  pinMode(buttonnumTHUMBBASE INPUT);


  pwm.begin();


  
  /*
   * In theory the internal oscillator (clock) is 25MHz but it really isn't
   * that precise. You can 'calibrate' this by tweaking this number until
   * you get the PWM update frequency you're expecting!
   * The int.osc. for the PCA9685 chip is a range between about 23-27MHz and
   * is used for calculating things like writeMicroseconds()
   * Analog servos run at ~50 Hz updates, It is importaint to use an
   * oscilloscope in setting the int.osc frequency for the I2C PCA9685 chip.
   * 1) Attach the oscilloscope to one of the PWM signal pins and ground on
   *    the I2C PCA9685 chip you are setting the value for.
   * 2) Adjust setOscillatorFrequency() until the PWM update frequency is the
   *    expected value (50Hz for most ESCs)
   * Setting the value here is specific to each individual I2C PCA9685 chip and
   * affects the calculations for the PWM update frequency. 
   * Failure to correctly set the int.osc value will cause unexpected PWM results
   */
  pwm.setOscillatorFrequency(27000000);
  pwm.setPWMFreq(SERVO_FREQ);  // Analog servos run at ~50 Hz updates

  delay(10);
}
//for index finger
//(130 ultra max, but really pulls on string)
// 0 <-- 120 push fingy out 
// 0 --> 120 pull fingy in

//for middle finger
//(160 ultra min, but really loose string)
//(50 ultra max, but really pulls on string)
// 60 --> 150 push fingy out 
// 60 <-- 150 pull fingy in

//for ring finger
// 0 <-- 180 push fingy out 
// 0 --> 180 pull fingy in

//for pinky finger 
//(80 ultra max, but really pulls on string)
// 90 --> 160 push fingy out 
// 90 <-- 160 pull fingy in

//for thumb finger
// 0 --> 180 push fingy out
// 0 <-- 180 pull fingy in

//for thumb base
// 0 --> 180 push base out
// 0 <-- 180 pull base in

void moveFingy(double servoNum, double degrees)
{
   double pulsePOSITIONnow = (map(degrees, 0, 180, SERVOMIN, SERVOMAX));
   
   Serial.println("pulsePOS = " + String(pulsePOSITIONnow));

   pwm.setPWM(servoNum, 0, pulsePOSITIONnow);
  
  Serial.println("move fingy done");
  delay(20);
}



void loop() {
  moveFingy(servonumINDEX, maxContractionINDEX);
  moveFingy(servonumMIDDLE, maxContractionMIDDLE);
  moveFingy(servonumPINKY, maxContractionPINKY);
  moveFingy(servonumTHUMBBASE, maxContrationTHUMBBASE);

  delay(3000);

  moveFingy(servonumINDEX, maxReleaseINDEX);
  moveFingy(servonumMIDDLE, maxReleaseMIDDLE);
  moveFingy(servonumPINKY, maxReleasePINKY);
  moveFingy(servonumTHUMBBASE, maxReleaseTHUMBBASE);

  delay(3000);
/*
  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) {
    Serial.println("button ON :D");
  } else {
    Serial.println("button OFF :(");
  }
  //delay(20);*/  
}