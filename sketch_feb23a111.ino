int OutputA = 2;
int OutputB = 3;
int counter = 0;
int pwm = 8;
int dir = 22;
void setup() {
  // put your setup code here, to run once:
  pinMode(OutputA, INPUT);
  pinMode(OutputB, INPUT);
  pinMode(pwm, OUTPUT);
  pinMode(dir, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(OutputA), encoder, RISING);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(dir, HIGH);
  analogWrite(pwm, 100); 
  // put your main code here, to run repeatedly:
  //Serial.println(counter);
  if (counter >= 1848 || counter <= -1848) {
    analogWrite(pwm, 0);
    Serial.println("  Stop  ");
  }
 Serial.println(counter);
}
void encoder() {
  if (digitalRead(OutputA) == 1) {
    if (digitalRead(OutputB) == 0) {
      counter++;
    }
    else {
      counter--;
    }
  }
}
