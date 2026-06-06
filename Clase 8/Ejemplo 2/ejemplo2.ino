// Definición de pines
const int Pot = A0;       // Potenciómetro conectado a pin analógico A0
const int Boton = 4;      // Pulsador conectado al pin digital 4

const int ENA =  9;       // Pin PWM del L298N (Control de velocidad)
const int IN1 =  8;       // Pin de dirección 1 del L298N
const int IN2 =  7;       // Pin de dirección 2 del L298N

// Variables para la lógica del pulsador y dirección
bool direccion = true;       // true = Giro horario, false = Giro antihorario
bool ultimoEstadoBoton = HIGH;
unsigned long ultimoTiempoRebote = 0;
const unsigned long tiempoDebounce = 50; // Tiempo de espera para evitar rebotes (ms)

void setup() {
  // Configuración de pines de salida para el puente H
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  
  // Configuración del pulsador con resistencia Pull-Up interna
  pinMode(Boton, INPUT_PULLUP);
}

void loop() {
  // ---- 1. CONTROL DE VELOCIDAD ----
  int valorPot = analogRead(Pot); // Lee el potenciómetro (0 a 1023)
  // Mapea el valor a un rango PWM (0 a 255)
  int velocidad = map(valorPot, 0, 1023, 0, 255); 
  
  // Envía la velocidad al pin ENA del módulo
  analogWrite(ENA, velocidad);

  // ---- 2. CONTROL DE DIRECCIÓN (Detección del Pulsador) ----
  int lecturaBoton = digitalRead(Boton);

  // Si el estado del botón cambió (por ruido o presión)
  if (lecturaBoton != ultimoEstadoBoton) {
    ultimoTiempoRebote = millis(); // Reinicia el temporizador
  }

  // Si ha pasado suficiente tiempo, la lectura es estable
  if ((millis() - ultimoTiempoRebote) > tiempoDebounce) {
    // Si el botón está presionado (LOW debido al INPUT_PULLUP)
    if (lecturaBoton == LOW && ultimoEstadoBoton == HIGH) {
      direccion = !direccion; // Invierte el sentido del giro
    }
  }
  
  ultimoEstadoBoton = lecturaBoton;

  // ---- 3. APLICAR DIRECCIÓN AL MOTOR ----
  if (direccion) {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
  } else {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
  }
}