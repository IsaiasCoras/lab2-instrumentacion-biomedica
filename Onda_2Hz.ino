const int pwmPin = 5;
const int analogPin = A0;

const float frecuencia = 2.0;  // 2 Hz
const int muestras = 100;

void setup() {
  pinMode(pwmPin, OUTPUT);
  Serial.begin(115200);
}

void loop() {

  for (int i = 0; i < muestras; i++) {

    // Ángulo de 0 a 2π
    float angulo = 2.0 * PI * i / muestras;

    // Seno de -1 a +1
    float seno = sin(angulo);

    // Lo convertimos a 0-255 para el PWM
    int pwm = (int)(127.5 + 127.5 * seno);

    analogWrite(pwmPin, pwm);

    // Leer A0 después del filtro RC
    int lectura = analogRead(analogPin);

    Serial.println(lectura);

    // 100 muestras en un ciclo de 0.5 s = 5 ms
    delay(5);
  }
}