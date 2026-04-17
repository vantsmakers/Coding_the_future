//
void setup()
{
 pinMode(7,OUTPUT);
 pinMode(8,INPUT);
 
 digitalWrite(7,LOW);
}

void loop()
{
  if(digitalRead(8)== 1){
  digitalWrite(7, HIGH);
  }
  else{digitalWrite(7, LOW);
  }
 
}
