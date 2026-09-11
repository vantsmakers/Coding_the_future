const int pinLed = 13; // Pin donde está conectado el LED
char comando;          // Variable para guardar el dato recibido

void setup() {
  pinMode(pinLed, OUTPUT);     // Configura el pin del LED como salida
  Serial.begin(9600);          // Inicia la comunicación serie a 9600 baudios
  Serial.println("Envia '1' para encender el LED o '0' para apagarlo.");
}

void loop() {
  if (Serial.available() > 0) { // Verifica si hay datos disponibles en el monitor serie
    comando = Serial.read();    // Lee el carácter enviado

    if (comando == '1') {
      digitalWrite(pinLed, HIGH); // Enciende el LED
      Serial.println("LED encendido");
    } 
    else if (comando == '0') {
      digitalWrite(pinLed, LOW);  // Apaga el LED
      Serial.println("LED apagado");
    }
  }
}
