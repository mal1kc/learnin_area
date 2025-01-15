const int butonPin = 2;
const int ledPin = 3;
int butonDurumu = LOW;

void setup() {
  pinMode(butonPin, INPUT);
  pinMode(ledPin, OUTPUT);
}
void loop() {
  butonDurumu = digitalRead(butonPin);
  if (butonDurumu == HIGH) {
    delay(500);
    if (digitalRead(butonPin) == HIGH) {
      Serial.println("button basildi");
      butonDurumu == LOW;
      digitalWrite(ledPin, LOW);
    } else {

      digitalWrite(ledPin, HIGH);
    }
  } else {
    digitalWrite(ledPin, LOW);
  }
}
