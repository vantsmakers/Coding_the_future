int sensor = A0;
int led = 8;

float temperatura;
float temperaturaBase;

void setup() {

  iniciarSistema();
}

void loop() {

  leerTemperatura();

  mostrarTemperatura();

  detectarCalor();

  delay(1000);
}


// FUNCION PARA INICIAR EL SISTEMA
void iniciarSistema() {

  Serial.begin(9600);

  pinMode(led, OUTPUT);

  delay(2000);

  // Guardar temperatura ambiente
  temperaturaBase = obtenerTemperatura();

  Serial.print("Temperatura base: ");
  Serial.println(temperaturaBase);
}


// FUNCION PARA OBTENER TEMPERATURA
float obtenerTemperatura() {

  int lectura = analogRead(sensor);

  float voltaje = lectura * 5.0 / 1023.0;

  float temp = (voltaje - 0.5) * 100;

  return temp;
}


// FUNCION PARA LEER TEMPERATURA
void leerTemperatura() {

  temperatura = obtenerTemperatura();
}


// FUNCION PARA MOSTRAR TEMPERATURA
void mostrarTemperatura() {

  Serial.print("Temperatura actual: ");

  Serial.print(temperatura);

  Serial.println(" C");
}


// FUNCION PARA DETECTAR CALOR
void detectarCalor() {

  if (temperatura >= temperaturaBase + 0.5) {

    digitalWrite(led, HIGH);

    Serial.println("Calor detectado");

  } else {

    digitalWrite(led, LOW);

    Serial.println("Temperatura normal");
  }

  Serial.println("----------------");
}