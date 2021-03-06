int buzzerPin = 8;
int buttonPin = 2;
int state = 0;
int pressCounter = 0;


void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  state = digitalRead(buttonPin);
  Serial.println(state);
  if (state) {
    pressCounter++;
    tone(buzzerPin,pressCounter*1000, 1000);
    delay(1000);
  }
}
