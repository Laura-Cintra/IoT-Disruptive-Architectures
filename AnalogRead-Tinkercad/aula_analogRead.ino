/*
Sinal analógico: de 0.00 a 5.00V

Conversor Analógico Digital (Analog To Digital Converter - ADC)
(módulo dentro do chip ATMEGA328P)
Converte o valor de tensão dos pinos de A0 a A5 em um valor decimal de 0 a 1023, por meio da função analogRead()

10 bits --> 1024 valores convertidos
12 bits --> 4096 
*/

// Variável que armazenará o valor convertido pelo ADC
int valor;

#define BT1 8
#define BT2 9
#define BT3 10

#define ledGp 6
#define ledRp 5
#define ledGc 4
#define ledYc 3
#define ledRc 2

void setup() {
  Serial.begin(9600); // Habilita comunicação serial do Arduino
  // Baud Rate 9600 bits/s

  Serial.println("Laura de Oliveira Cintra - RM558843");

  pinMode(BT1, INPUT);
  pinMode(BT2, INPUT);
  pinMode(BT3, INPUT);

  pinMode(ledGp, OUTPUT); 
  pinMode(ledRp, OUTPUT);
  pinMode(ledGc, OUTPUT);
  pinMode(ledYc, OUTPUT);
  pinMode(ledRc, OUTPUT);
}

void loop() {
  valor = analogRead(A2); // pino onde tá ligado o potenciômetro
  Serial.println(valor);
  // delay(1000);
  
  // ex2();
  // ex3();
  ex4();
}

void ex2(){
  digitalWrite(ledGc, HIGH);
  digitalWrite(ledRp, HIGH);
  delay(5000);
  digitalWrite(ledGc, LOW);
  digitalWrite(ledYc, HIGH);
  delay(2000);
  digitalWrite(ledRp, LOW);
  digitalWrite(ledYc, LOW);
  digitalWrite(ledRc, HIGH);
  digitalWrite(ledGp, HIGH);
  delay(5000);
  digitalWrite(ledGp, LOW);
  for (int i=0; i < 10; i ++){
    piscaRed();
  }
  digitalWrite(ledRc, LOW);
}

void piscaRed(){
  digitalWrite(ledRp, HIGH);
  delay(150);
  digitalWrite(ledRp, LOW);
  delay(150);
}

void ex3(){
  if(valor < 300) {
    ledOff();
    digitalWrite(ledGp, HIGH);
  }
  else if (valor >= 300 && valor < 600) {
    ledOff();
    digitalWrite(ledYc, HIGH);
  }
  else if (valor >= 600 && valor < 900) {
    ledOff();
    digitalWrite(ledRp, HIGH);
  }
  else if (valor >= 900 && valor < 1000) {
    ledOff();
    piscaRYG();
  }
  // else if (valor >= 1000) pisca2Red();
  else {
    while(true){
      pisca2Red();
    }
  }

  Serial.println(valor);
  delay(1000);
}

void piscaRYG(){
  digitalWrite(ledRc, HIGH);
  digitalWrite(ledYc, HIGH);
  digitalWrite(ledGc, HIGH);
  delay(100);
  digitalWrite(ledRc, LOW);
  digitalWrite(ledYc, LOW);
  digitalWrite(ledGc, LOW);
  delay(100);
}

void pisca2Red(){
  Serial.println("Alarme!");
  digitalWrite(ledRc, HIGH);
  digitalWrite(ledRp, HIGH);
  delay(200);
  digitalWrite(ledRc, LOW);
  digitalWrite(ledRp, LOW);
  delay(200);
}

void ledOff(){
  digitalWrite(ledGp, LOW);
  digitalWrite(ledRp, LOW);
  digitalWrite(ledGc, LOW);
  digitalWrite(ledYc, LOW);
  digitalWrite(ledRc, LOW);
}