#include <Servo.h>

Servo servito; 
int pot = A0; 
int valor; 
double angulo; 

void setup()
{
 servito.attach(3);
}

void loop()
{
 valor = analogRead(pot);
 angulo = map(valor, 0, 1023, 0, 180);
 servito.write(angulo);
 delay(15);
}