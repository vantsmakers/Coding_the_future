//Ejemplo estructura IF

const int ent_IR = 2;
const int Led = 3;

void setup()
{
  pinMode(ent_IR, INPUT_PULLUP);
  pinMode(Led, OUTPUT);
}

void loop()
{
  if(digitalRead(ent_IR) == LOW){
    digitalWrite(Led, HIGH);
  }
  else {
    digitalWrite(Led, LOW);
  }
}