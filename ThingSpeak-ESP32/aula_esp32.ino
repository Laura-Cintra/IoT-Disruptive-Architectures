// Já existe um LED azul ligado ao pino 2
#define LED_ONBOARD 2

void setup() {
  // Habilita a porta serial com baudrate de 115200 bits/s
  // padrão de ESP32
  Serial.begin(115200);
  Serial.println("2TDSPK - 2025");
  pinMode(LED_ONBOARD, OUTPUT);
}

void loop() {
  // HIGH: 3.3V --> No Arduino Uno era 5V
  digitalWrite(LED_ONBOARD, HIGH);
  delay(200);
  digitalWrite(LED_ONBOARD, LOW);
  delay(200);
}
