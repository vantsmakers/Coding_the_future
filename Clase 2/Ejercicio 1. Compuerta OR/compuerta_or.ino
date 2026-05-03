int led1 = 3;
int button1 = A0;
int button2 = A1;
int estado_boton1;
int estado_boton2;

void setup() {
    Serial.begin(9600);
    pinMode(led1, OUTPUT);
    pinMode(button1, INPUT);
    pinMode(button2, INPUT);
}

void loop() {
    estado_boton1 = digitalRead(button1);
    estado_boton2 = digitalRead(button2);
  
    Serial.print("Boton 1: ");
    Serial.print(estado_boton1);
    Serial.print(" | Boton 2: ");
    Serial.print(estado_boton2);

    //Compuerta OR
    if(estado_boton1==HIGH || estado_boton2==HIGH){
        digitalWrite(led1,HIGH);
        Serial.println("LED ENCENDIDO");
    }
    else{
        digitalWrite(led1, LOW);
        Serial.println("LED APAGADO");
    }
    delay(300);
}