//int counter = 0;
int pin = 2;
int pulseHigh;
int pulseLow;
int period;
int frecuency;
int duty;

void setup()
{
  Serial.begin(9600);
  pinMode(pin, INPUT);
}

void loop()
{
  pulseHigh = pulseIn(pin,HIGH); // Cuenta el tiempo que el pulso permanece arriba
  pulseLow = pulseIn(pin,LOW); // Cuenta el tiempo que el pulso permanece abajo
  period = pulseHigh + pulseLow; // La suma de los dos tiempos da un periodo
  frecuency = 10000000/period;; // La frecuencia es 1/periodo pero esto da en segundos y lo necesitamos en micro
  Serial.println(frecuency);
  duty = (100*pulseHigh/period); // Regla de 3, si 100 es el periodo ¿Cuánto es el pulseHigh?
  Serial.println(duty);
}