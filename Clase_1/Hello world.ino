//Poner doble diagonal significa comentario, lo que nos permite

//escribir texto sin afectar el código

//Creamos una variable llamada LED,

// a esta variable asignamos un numero que

// en nuestro caso es el 13

int led = 13;

// Esta es una rutina de inicialización donde hacemos configuraciones

void setup() {

// inicializamos el Pin 13, que es el del nuestro LED como salida

pinMode(led, OUTPUT);

}

// Aquí creamos una rutina llamada Loop, la cual se corre de manera infinita

// vaya, significa que cuando termina la rutina vuelve a empezar

void loop() {

digitalWrite(led, HIGH); // Escribimos en nuestro "pin" con HIGH

// Esto significa que mandamos señal alta o de prendido

delay(1000); // creamos un retraso o delay de 1000 ms = 1 segundo

//De esta manera permanecerá encendido el LED por un segundo

digitalWrite(led, LOW); // Escribimos en nuestro "pin" con LOW

// Esto significa que mandamos señal baja o de apagado

