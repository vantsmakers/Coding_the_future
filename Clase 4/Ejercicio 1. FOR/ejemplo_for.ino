int pines[] = {6, 5, 4, 3, 2}; //arreglo de pines de los leds
int pinSensor = A0;
int umbral = 100;

void setup() {

  for (int i = 0; i < 5; i++) {
    pinMode(pines[i], OUTPUT);
  }

}

void loop() {

  int valor = analogRead(pinSensor);
  
  //si el valor que lee el sensor es mayor del umbral
  if (valor > umbral) {

    //hace que parpadeen los leds uno por uno
    for (int i = 0; i < 5; i++) {
      digitalWrite(pines[i], HIGH);
      delay(100);
      digitalWrite(pines[i], LOW);
    }

  }

}