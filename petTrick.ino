int buttonPin = 2;
int analog = A0;
int ledPinOne = 9;
int ledPinTwo = 10;
int ledPinThree = 11;
int buttonCounter = 0;
int ledCount = 3;

void ledControl(int high,int low,int alsoLow, int brightness){
  analogWrite(high, brightness);
  digitalWrite(low, LOW);
  digitalWrite(alsoLow, LOW);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledPinOne, OUTPUT);
  pinMode(ledPinTwo, OUTPUT);
  pinMode(ledPinThree, OUTPUT);
  pinMode(buttonPin, INPUT);
}

int previousState = 0;

void loop() {
  int buttonState = digitalRead(buttonPin);
  int rawData = analogRead(analog);
  int brightness = map(rawData, 0, 1023, 0, 254);
  Serial.println(brightness);
  int ledFlip = buttonCounter%ledCount;  
  if (!ledFlip){
    ledControl(ledPinOne,ledPinTwo,ledPinThree, brightness);
  } else if (ledFlip == 1){
    ledControl(ledPinTwo,ledPinOne,ledPinThree, brightness);
  } else {
    ledControl(ledPinThree,ledPinOne,ledPinTwo, brightness);
  }
  if (buttonState){
    if (!previousState){
      buttonCounter++;
      previousState = 1;
    }
  } else {
    if (previousState) {
      previousState = 0;
    }
  }
}
