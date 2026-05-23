#include <Servo.h>
#include <NewPing.h>

Servo servo1;
#define PINSERVO 2
#define TRIG_PIN 10
#define ECHO_PIN 9
#define LED_PIN 3
#define MAX_DISTANCE 200 // Distancia máxima de detección en centímetros

NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE); // Define el objeto sonar

void setup() {
servo1.attach(PINSERVO);
pinMode(LED_PIN, OUTPUT);
posicion_inicial();
}

void loop() {
unsigned int duration, distance;

duration = sonar.ping_median(5); // Realiza 5 mediciones y devuelve la mediana
distance = duration / US_ROUNDTRIP_CM; // Convierte el tiempo en distancia en cm

if (distance <= 20 && distance >= 0) {
digitalWrite(LED_PIN, HIGH);
for (int angle = 0; angle <= 90; angle++) {
servo1.write(angle);
delay(15);
}
delay(5000); // Espera 5 segundos después de mover el servo
} else {
digitalWrite(LED_PIN, LOW);
servo1.write(0); // Mueve el servo a 0 grados si no hay objeto
delay(5000);
}
}

void posicion_inicial() {
servo1.write(0);
delay(5000);
}