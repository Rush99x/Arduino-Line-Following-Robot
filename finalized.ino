int middlesensor = 7;     // Pin connected to the IR sensor - forward
int leftsensorSmooth = 2; //get Smooth turns  left
int rightsensorSmooth = 3; //get Smooth turns right
int threshold = 100;  // Adjust this value according to your specific sensor readings
int leftM1 = 10;      // Pin connected to motor 1 input 1 on L298N
int leftM2 = 11;      // Pin connected to motor 1 input 2 on L298N
int rightM1 = 12;      // Pin connected to motor 2 input 1 on L298N
int rightM2 = 13;      // Pin connected to motor 2 input 2 on L298N
int rpwm = 5;          // Pin connected to enA on L298N (speed control for motor 1)
int lpwm = 6;          // Pin connected to enB on L298N (speed control for motor 2)


void setup() {
  Serial.begin(9600);  // Initialize Serial Monitor

  //sensors
  pinMode(middlesensor, INPUT); //pin 7
  pinMode(leftsensorSmooth, INPUT); //pin 2
  pinMode(rightsensorSmooth, INPUT); //pin 3
  
  
  // Initialize motor control pins as outputs
  pinMode(leftM1, OUTPUT);
  pinMode(leftM2, OUTPUT);
  pinMode(rightM1, OUTPUT);
  pinMode(rightM2, OUTPUT);

}

void loop() {
  int sensorValueMiddle1 = digitalRead(middlesensor);  // Read the digital middlesensor value
  int sensorValueLeftSmooth4 = digitalRead(leftsensorSmooth);  // Read the digital rightsensor value
  int sensorValueRightSmooth5 = digitalRead(rightsensorSmooth);  // Read the digital rightsensor value //code by Rush

// turn right
 if (sensorValueLeftSmooth4 == LOW && sensorValueMiddle1 == LOW && sensorValueRightSmooth5 == HIGH)
 {
  turnright();
 }
 //forward
 if (sensorValueLeftSmooth4 == LOW && sensorValueMiddle1 == HIGH && sensorValueRightSmooth5 == LOW)
 {
  forward();
 }
//turn left smooth
 if (sensorValueLeftSmooth4 == HIGH && sensorValueMiddle1 == LOW && sensorValueRightSmooth5 == LOW)
 {
  turnleftsmooth();
 }
 //turn left
 if (sensorValueLeftSmooth4 == HIGH && sensorValueMiddle1 == HIGH && sensorValueRightSmooth5 == LOW)
 {
  turnright();
 }
  //turn right smooth//////////////////////
 if (sensorValueLeftSmooth4 == HIGH && sensorValueMiddle1 == LOW && sensorValueRightSmooth5 == HIGH)
 {
  turnleft();
 }
  //turn right
 if (sensorValueLeftSmooth4 == LOW && sensorValueMiddle1 == HIGH && sensorValueRightSmooth5 == HIGH)
 {
  turnleft();
 }
 if (sensorValueLeftSmooth4 == LOW && sensorValueMiddle1 == LOW && sensorValueRightSmooth5 == LOW)
 {
  turnleft();
 }
if (sensorValueLeftSmooth4 == HIGH && sensorValueMiddle1 == HIGH && sensorValueRightSmooth5 == HIGH)
 {
  turnright();
 }
// delay(2000);  // Delay for a short period before reading again
}

void forward()
{
    digitalWrite(leftM1, HIGH);
    digitalWrite(leftM2, LOW);
    analogWrite(lpwm,118);
    digitalWrite(rightM1, HIGH);
    digitalWrite(rightM2, LOW);
    analogWrite(rpwm,129);
}
void stop()
{
    digitalWrite(leftM1, LOW);
    digitalWrite(leftM2, LOW);
    analogWrite(lpwm,100);
    digitalWrite(rightM1, LOW);
    digitalWrite(rightM2, LOW);
    analogWrite(rpwm,111);
}

void turnleft()
{
    digitalWrite(leftM1, LOW);
    digitalWrite(leftM2, HIGH);
    analogWrite(lpwm,118);
    digitalWrite(rightM1, HIGH);
    digitalWrite(rightM2, LOW);
    analogWrite(rpwm,129);
}
void turnright()
{
    digitalWrite(leftM1, HIGH);
    digitalWrite(leftM2, LOW);
    analogWrite(lpwm,118);
    digitalWrite(rightM1, LOW);
    digitalWrite(rightM2, HIGH);
    analogWrite(rpwm,129);
}

void turnleftsmooth()
{
    digitalWrite(leftM1, LOW);
    digitalWrite(leftM2, LOW);
    analogWrite(lpwm,118);
    digitalWrite(rightM1, HIGH);
    digitalWrite(rightM2, LOW);
    analogWrite(rpwm,129);
}
void turnrightsmooth()
{
 digitalWrite(leftM1, HIGH);
    digitalWrite(leftM2, LOW);
    //analogWrite(lpwm,135);
    analogWrite(lpwm,118);
    digitalWrite(rightM1, LOW);
    digitalWrite(rightM2, LOW);
    analogWrite(rpwm,129);
}
void backward()
{
   digitalWrite(leftM1, LOW);
    digitalWrite(leftM2, HIGH);
    analogWrite(lpwm,118);
    digitalWrite(rightM1, LOW);
    digitalWrite(rightM2, HIGH);
    analogWrite(rpwm,129);
}
