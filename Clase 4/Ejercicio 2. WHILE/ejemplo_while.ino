const int trigPin = 7; //pin que habla
const int echoPin = 6; //pin que escucha
const int ledAmarillo = 2;
const int ledNaranja = 3;
const int ledRojo = 4;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledAmarillo, OUTPUT);
  pinMode(ledNaranja, OUTPUT);
  pinMode(ledRojo, OUTPUT);
}

//función para sensor
long obtenerDistancia() {
    digitalWrite(trigPin, LOW); //se comprueba que esta apagado
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH); //se envía el sonido que dura 10ms
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW); //se cierra
    
    long duracion = pulseIn(echoPin, HIGH); //con este pin escuchamos el eco y calculamos la duración
    long distancia = duracion * 0.034 / 2;
    return distancia;
}

void loop() {

    long distancia = obtenerDistancia();

    if (distancia < 30) digitalWrite(ledAmarillo, HIGH); 
    else digitalWrite(ledAmarillo, LOW);

    if (distancia < 20) digitalWrite(ledNaranja, HIGH); 
    else digitalWrite(ledNaranja, LOW);

    while (distancia > 0 && distancia < 10) {

        //se encienden los leds
        digitalWrite(ledAmarillo, HIGH);
        digitalWrite(ledNaranja, HIGH);
        digitalWrite(ledRojo, HIGH);
        delay(200);

        //se apagan los leds
        digitalWrite(ledAmarillo, LOW);
        digitalWrite(ledNaranja, LOW);
        digitalWrite(ledRojo, LOW);
        delay(200);

        //volvemos a medir para ver si ya se alejó y podemos salir del while
        distancia = obtenerDistancia();
  }
  delay(50);
}