float frecuencia = 1000;
float dureza = 50;
int start = 0;
int stop;
int reset;
int pin = 13;
String consola;


void setup() {
  Serial.println(">> ");
  Serial.begin(9600);
  pinMode(pin, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    consola = Serial.readString();
      if (consola.startsWith("FREQ")){
        frecuencia = consola.substring(consola.indexOf(" ") + 1).toInt();
        if (frecuencia >= 1 && frecuencia < 100000) {
          Serial.println("Generating signal, f =");
          Serial.println(frecuencia);
        } else {
          frecuencia = 1000;
          Serial.println("frequency not available");
        }
      } else if (consola.startsWith("DUTY")){
        dureza = consola.substring(consola.indexOf(" ") + 1).toInt();
        if (dureza >= 1 && dureza <= 100) {
          Serial.println("Generating signal, duty =");
          Serial.println(dureza);
        } else {
          dureza = 50;
          Serial.println("duty cicle not available");
        }
      } else if (consola.startsWith("START")){
        start = 1;
      } else if (consola.startsWith("STOP")){
        stop = 1;
      } else if (consola.startsWith("RESET")){
        dureza = 50;
        frecuencia = 1000;
      }
     Serial.println(">> ");
  }

  if (start == 1) {
    for (int i = 0; i <= dureza; i++ ) {
      digitalWrite(pin, HIGH);
      delay((1000*dureza)/(frecuencia*100));
      digitalWrite(pin, LOW);
      delay((1000*(100-dureza))/(frecuencia*100));
      if (stop == 1) {
        digitalWrite(pin, LOW);
        start = 0;
        break;
      }
    }
  } 
}
