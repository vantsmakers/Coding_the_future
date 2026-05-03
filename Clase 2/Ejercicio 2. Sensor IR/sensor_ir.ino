const int sensorPin = A0;
const int ledR = 4;
const int ledV = 5;

void setup() {
    Serial.begin(9600);   
    pinMode(sensorPin , INPUT);  
    pinMode(ledR, OUTPUT);
    pinMode(ledV, OUTPUT);
}
 
void loop(){
    int value = 0;
    value = digitalRead(sensorPin );  
 
    if (value == HIGH) {
        digitalWrite(ledR, HIGH);
        digitalWrite(ledV, LOW);
        Serial.println("Detectado obstaculo");
        }
    else{
        digitalWrite(ledR, LOW);
        digitalWrite(ledV, HIGH);
        Serial.println("No hay obsataculo");
        }
    delay(1000);
}