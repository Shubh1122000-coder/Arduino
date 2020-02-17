int dir = 22;
int pwm = 8;
int encoderA = 2;
int encoderB = 3;
int counter = 0;
float angle = 0;
void setup() {
  Serial.begin(9600);
  pinMode(dir, OUTPUT);
  pinMode(pwm, OUTPUT);
  pinMode(encoderA, INPUT_PULLUP);
  pinMode(encoderB, INPUT_PULLUP);
  attachInterrupt(0, encoder, RISING);
}
void loop() {
  if (angle < 89) {
    digitalWrite(dir, LOW);

    analogWrite(pwm, 100);
  }  angle = (float)(counter * 360) / 72;
  Serial.print("angle is  ");
  //Serial.print(angle);
  if (angle > 89) {
    analogWrite(pwm, 0);
    Serial.print("  Stop  ");
  }
  Serial.print(angle);
  Serial.print("  pulses is  ");
  Serial.println(counter);
}
void encoder() {
  if (digitalRead(encoderA) == 1) {
    if (digitalRead(encoderB) == 0) {
      counter++;
    }
    else {
      counter--;
    }
  }
}
