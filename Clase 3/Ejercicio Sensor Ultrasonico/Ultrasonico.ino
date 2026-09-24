const int trigPin = 9; 
const int echoPin = 10; 

void setup() {

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  Serial.begin(9600);
}

void loop() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);


  long duration = pulseIn(echoPin, HIGH);// Variable para almacenar el tiempo de ida y vuelta del pulso

  int distancia = duracion / 58.2;; // Variable para almacenar la distancia calculada
  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.println(" cm");

  delay(500);
}
