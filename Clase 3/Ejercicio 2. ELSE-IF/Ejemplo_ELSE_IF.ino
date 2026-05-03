//Ejemplo estructura ELSE-IF

const int led_v = 2;
const int led_a = 3;
const int led_r = 4;

void setup()
{
  pinMode(led_v, OUTPUT);
  pinMode(led_a, OUTPUT);
  pinMode(led_r, OUTPUT);
}

void loop()
{
  if (analogRead(A0) <= 500) {
    digitalWrite(led_v,HIGH);
    digitalWrite(led_a,LOW);
    digitalWrite(led_r,LOW);
  }
  else if (analogRead(A1) >= 300 && analogRead(A1) <= 900) {
    digitalWrite(led_v,LOW);
    digitalWrite(led_a,HIGH);
    digitalWrite(led_r,LOW);
  }
  else if (analogRead(A2) >= 700) {
    digitalWrite(led_v,LOW);
    digitalWrite(led_a,LOW);
    digitalWrite(led_r,HIGH);
  }
  else {
    digitalWrite(led_v,LOW);
    digitalWrite(led_a,LOW);
    digitalWrite(led_r,LOW);
    delay(1000);
    digitalWrite(led_v,HIGH);
    digitalWrite(led_a,HIGH);
    digitalWrite(led_r,HIGH);
    delay(1000);
  }
}