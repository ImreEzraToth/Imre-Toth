int DirPin    = 4;
int StepPin   = 3;
int motorState = 0;
int buttonPin = 2;
int buttonNew;
int buttonOld = 1;
int dt = 100;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(buttonPin, INPUT);
  pinMode(StepPin, OUTPUT);
  pinMode(DirPin, OUTPUT);
  }

void loop() {
  buttonNew = digitalRead(buttonPin);
  if (buttonOld == 0 && buttonNew == 1) {
    if (motorState == 0) {
      Serial.println("Instrument begint met het masker uitrekken.")
      for (int i; i <= 1879; i++) {
        digitalWrite(StepPin, HIGH);
        delayMicroseconds(1000);
        digitalWrite(StepPin, LOW);
        delayMicroseconds(1000);
        delay(500);
    }
  }
  else {
    Serial.println("Instrument is uitgeschakeld.");
    motorState = 0;
  }
delay(dt);
}
 buttonOld = buttonNew;
}
