const int led_1 = 5;
const int led_2 = 4;
const int led_3 = 3;
const int led_4 = 2;
const int boton = 7;

int num = 0;

void setup()
{
  pinMode(led_1, OUTPUT);
  pinMode(led_2, OUTPUT);
  pinMode(led_3, OUTPUT);
  pinMode(led_4, OUTPUT);
  pinMode(boton, INPUT);
}

void loop()
{
  if (digitalRead(boton)){
    num = num + 1;
    if (num > 15){
      num = 0;
    }
    delay(800);
  }
  
  switch (num) {
    case 0:
    digitalWrite(led_1, LOW);
    digitalWrite(led_2, LOW);
    digitalWrite(led_3, LOW);
    digitalWrite(led_4, LOW);
    break;
    case 1:
    digitalWrite(led_1, HIGH);
    digitalWrite(led_2, LOW);
    digitalWrite(led_3, LOW);
    digitalWrite(led_4, LOW);
    break;
    case 2:
    digitalWrite(led_1, LOW);
    digitalWrite(led_2, HIGH);
    digitalWrite(led_3, LOW);
    digitalWrite(led_4, LOW);
    break;
    case 3:
    digitalWrite(led_1, HIGH);
    digitalWrite(led_2, HIGH);
    digitalWrite(led_3, LOW);
    digitalWrite(led_4, LOW);
    break;
    case 4:
    digitalWrite(led_1, LOW);
    digitalWrite(led_2, LOW);
    digitalWrite(led_3, HIGH);
    digitalWrite(led_4, LOW);
    break;
    case 5:
    digitalWrite(led_1, HIGH);
    digitalWrite(led_2, LOW);
    digitalWrite(led_3, HIGH);
    digitalWrite(led_4, LOW);
    break;
    case 6:
    digitalWrite(led_1, LOW);
    digitalWrite(led_2, HIGH);
    digitalWrite(led_3, HIGH);
    digitalWrite(led_4, LOW);
    break;
    case 7:
    digitalWrite(led_1, HIGH);
    digitalWrite(led_2, HIGH);
    digitalWrite(led_3, HIGH);
    digitalWrite(led_4, LOW);
    break;
    case 8:
    digitalWrite(led_1, LOW);
    digitalWrite(led_2, LOW);
    digitalWrite(led_3, LOW);
    digitalWrite(led_4, HIGH);
    break;
    case 9:
    digitalWrite(led_1, HIGH);
    digitalWrite(led_2, LOW);
    digitalWrite(led_3, LOW);
    digitalWrite(led_4, HIGH);
    break;
    case 10:
    digitalWrite(led_1, LOW);
    digitalWrite(led_2, HIGH);
    digitalWrite(led_3, LOW);
    digitalWrite(led_4, HIGH);
    break;
    case 11:
    digitalWrite(led_1, HIGH);
    digitalWrite(led_2, HIGH);
    digitalWrite(led_3, LOW);
    digitalWrite(led_4, HIGH);
    break;
    case 12:
    digitalWrite(led_1, LOW);
    digitalWrite(led_2, LOW);
    digitalWrite(led_3, HIGH);
    digitalWrite(led_4, HIGH);
    break;
    case 13:
    digitalWrite(led_1, HIGH);
    digitalWrite(led_2, LOW);
    digitalWrite(led_3, HIGH);
    digitalWrite(led_4, HIGH);
    break;
    case 14:
    digitalWrite(led_1, LOW);
    digitalWrite(led_2, HIGH);
    digitalWrite(led_3, HIGH);
    digitalWrite(led_4, HIGH);
    break;
    case 15:
    digitalWrite(led_1, HIGH);
    digitalWrite(led_2, HIGH);
    digitalWrite(led_3, HIGH);
    digitalWrite(led_4, HIGH);
    break;
  }
}