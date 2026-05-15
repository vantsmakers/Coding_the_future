int boton = 2;

int leds[] = {8, 9, 10, 11};

void setup() {

  pinMode(boton, INPUT_PULLUP);

  int i = 0;

  // Configurar LEDs como salida
  do {
    pinMode(leds[i], OUTPUT);
    i++;

  } while (i < 4);

}

void loop() {

  // Si el botón se presiona
  if (digitalRead(boton) == LOW) {

    int i = 0;

    // Encender LEDs uno por uno
    do {

      digitalWrite(leds[i], HIGH);
      delay(300);

      i++;

    } while (i < 4);

    delay(500);

    i = 0;

    // Apagar LEDs uno por uno
    do {

      digitalWrite(leds[i], LOW);
      delay(300);

      i++;

    } while (i < 4);

  }
}