int filas[4] = {9,8,7,6};
int columnas[4] = {5,4,3,2};

char teclas[4][4] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

String contrasena = "1234";
String ingreso = "";

int led = 13;

void setup() {

  iniciarSistema();
}

void loop() {

  char tecla = leerTecla();

  if (tecla != '\0') {

    Serial.print(tecla);

    if (tecla == '#') {

      verificarContrasena();

    } else {

      ingreso += tecla;
    }

    delay(300);
  }
}


// FUNCION PARA INICIAR SISTEMA
void iniciarSistema() {

  Serial.begin(9600);

  pinMode(led, OUTPUT);

  // CONFIGURAR FILAS
  for (int i = 0; i < 4; i++) {

    pinMode(filas[i], OUTPUT);

    digitalWrite(filas[i], HIGH);
  }

  // CONFIGURAR COLUMNAS
  for (int i = 0; i < 4; i++) {

    pinMode(columnas[i], INPUT_PULLUP);
  }

  Serial.println("Ingrese contrasena:");
}


// FUNCION PARA LEER TECLA
char leerTecla() {

  for (int f = 0; f < 4; f++) {

    digitalWrite(filas[f], LOW);

    for (int c = 0; c < 4; c++) {

      if (digitalRead(columnas[c]) == LOW) {

        digitalWrite(filas[f], HIGH);

        return teclas[f][c];
      }
    }

    digitalWrite(filas[f], HIGH);
  }

  return '\0';
}


// FUNCION PARA VERIFICAR CONTRASENA
void verificarContrasena() {

  if (ingreso == contrasena) {

    accesoCorrecto();

  } else {

    accesoIncorrecto();
  }

  ingreso = "";
}


// FUNCION DE ACCESO CORRECTO
void accesoCorrecto() {

  Serial.println("\nClave correcta");

  digitalWrite(led, HIGH);

  delay(3000);

  digitalWrite(led, LOW);

  Serial.println("Ingrese contrasena:");
}


// FUNCION DE ACCESO INCORRECTO
void accesoIncorrecto() {

  Serial.println("\nClave incorrecta");

  Serial.println("Intente nuevamente");
}