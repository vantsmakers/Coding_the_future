// Definir las conexiones de los pines 
const int irSensorPin = 7; // Pin de salida del sensor IR conectado al pin digital 7 
const int ledPin = 9; // LED conectado al pin digital 9 (opcional) 

void setup() { 
  pinMode(irSensorPin, INPUT); // Configurar el pin del sensor IR como entrada 
  pinMode(ledPin, OUTPUT); // Configurar el pin del LED como salida (opcional) 
  Serial.begin(9600); // Iniciar la comunicación serial para depuración 
} 

void loop() { 
  int sensorValue = digitalRead(irSensorPin); // Leer el valor del sensor IR 

  if (sensorValue == LOW) { 
    // Obstáculo detectado 
    digitalWrite(ledPin, HIGH); // Encender el LED (opcional) 
    Serial.println("¡Obstáculo detectado!"); 
  } else { 
    // Sin obstáculo 
    digitalWrite(ledPin, LOW); // Apagar el LED (opcional) 
    Serial.println("Sin obstáculo."); 
  } 

  delay(100); // Pequeño retardo para mayor estabilidad 
}
