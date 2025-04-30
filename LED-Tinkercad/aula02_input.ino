// Atribuir nomes aos pinos

// Botões
#define BT1 8
#define BT2 9

// LEDs
#define ledB 2
#define ledW 3
#define ledR 4

// bool statusBT1;
int contador; // variável do tipo inteiro ---> 2^16 = 65.536 (64k)

void setup() {
  // Habilitar porta serial - comunicação do chip com a IDE
  // Baud Rate (9600 bits/s) padrão UNO
  Serial.begin(9600);
  // Configurar o sentido dos pinos de Input/Output
 pinMode(BT1, INPUT);
 pinMode(BT2, INPUT);
 pinMode(ledB, OUTPUT);
 pinMode(ledW, OUTPUT);
 pinMode(ledR, OUTPUT);

}

void loop() {
  // if(digitalRead(BT1) == HIGH) piscaRB(); - quando o if tem só uma instrução, as chaves são opcionais

  bool statusBT2 = digitalRead(BT2);

  if(statusBT2 == HIGH){
    contador++;
    Serial.print("Contador: ");
    Serial.println(contador);
    delay(200);
  }

  bool statusBT1 = digitalRead(BT1);
  
  // if(digitalRead(BT1) == HIGH){
  if(statusBT1 == HIGH){ // se o botão foi pressionado
    Serial.println("BT1 Ligado!!! :D");
    piscaRB();
  }
  else if(digitalRead(BT2) == HIGH){
    piscaRBW();
  }
  else{
    piscaW();
  }
  
}

void piscaRB(){
  digitalWrite(ledB, HIGH);
  digitalWrite(ledR, LOW);
  delay(250);
  digitalWrite(ledR, HIGH);
  digitalWrite(ledB, LOW);
  delay(250);
  digitalWrite(ledR, LOW); // apagando porque, pelo loop, o led vermelho ficaria aceso junto do led branco
}

void piscaW(){
  digitalWrite(ledW, HIGH);
  delay(350);
  digitalWrite(ledW, LOW);
  delay(350);
}

void piscaRBW(){
  digitalWrite(ledB, HIGH);
  digitalWrite(ledW, HIGH);
  digitalWrite(ledR, HIGH);
  delay(250);
  digitalWrite(ledB, LOW);
  digitalWrite(ledW, LOW);
  digitalWrite(ledR, LOW);
  delay(250);
}