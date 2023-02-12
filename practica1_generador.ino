int frecuencia;
int cicloDeDureza;
int start;
int stop;
int reset;
String consola;

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    consola = Serial.readString();
    Serial.println(consola);
      if (consola.startsWith("FREQ")){
        frecuencia = consola.substring(consola.indexOf(" ") + 1).toInt();
        Serial.println(frecuencia);
      }
  }
}
