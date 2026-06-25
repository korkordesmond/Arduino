#define ledPin1 D4
#define ledPin2 D5
#define ledPin3 D7
#define controlSwitch D6

void setup() {
  Serial.begin(9600);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(controlSwitch, INPUT_PULLUP);
}

int mode = 0;
int switchState = 0;
int lastSwitchState = 1;

void loop() {
  switchState = digitalRead(controlSwitch);

  if (switchState == LOW && lastSwitchState == HIGH) {
    delay(50);
    if (digitalRead(controlSwitch) == LOW) {
      mode = (mode + 1) % 3;
    }
  }

  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, LOW);
  digitalWrite(ledPin3, LOW);

  if (mode == 0) {
    digitalWrite(ledPin1, HIGH);
  } else if (mode == 1) {
    digitalWrite(ledPin2, HIGH);
  } else if (mode == 2) {
    digitalWrite(ledPin3, HIGH);
  }

  lastSwitchState = switchState;
  delay(50);
}