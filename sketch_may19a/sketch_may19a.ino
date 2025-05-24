const int trigPin = 4; 
const int echoPin = 5; 

const int greenLed = 2;
const int redLed = 3;

void setup() {

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(redLed, INPUT);
  pinMode(greenLed, INPUT);

  Serial.begin(9600);
}

void loop() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);


  long duration = pulseIn(echoPin, HIGH);

  float distance = duration * 0.034 / 2; 
  Serial.println(distance);

  if(distance > 30) {
  	digitalWrite(greenLed, HIGH);
    digitalWrite(redLed, LOW);
  } else {
  	digitalWrite(greenLed, LOW);
    digitalWrite(redLed, HIGH);
  };

  delay(100);
}
