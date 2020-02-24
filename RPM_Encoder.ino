int OutputA = 2;
int OutputB = 3;
int counter = 0;
int dir = 22;
int pwm = 7;
int pin = 24;
int interval = 1000;
long previousMillis = 0;
long currentMillis = 0;
int rpm = 0;
int PPR = 70;
boolean measureRpm = false;
void setup() {
  // put your setup code here, to run once:
  pinMode(OutputA, INPUT);
  pinMode(OutputB, INPUT);
  pinMode(dir, OUTPUT);
  pinMode(pwm, OUTPUT);
  pinMode(pin, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(OutputA), encoder, RISING);
  previousMillis = millis();
  Serial.begin(9600);
}

void loop() {
  digitalWrite(dir,LOW);
  analogWrite(pwm,50);
 // Serial.println("Start");
  // put your main code here, to run repeatedly:
  currentMillis = millis();
  if (currentMillis - previousMillis > interval)
  {
    previousMillis = currentMillis;


    rpm = (float)(counter * 60 / PPR);
    if (rpm > 0) {
      Serial.print(counter);
      Serial.print(" Pulse/ ");
      Serial.print(PPR);
      Serial.print(" Pulse per rotation * 60 seconds  = ");
      Serial.print(rpm);
      Serial.println(" RPM ");
    }
    counter = 0;
  }
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
