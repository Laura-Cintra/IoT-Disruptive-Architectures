// Atribuir nomes aos pinos
// Botões 1 e 2
#define BT1 8
#define BT2 9
#define BT3 10
// LEDs 
#define ledB 2
#define ledW 3
#define ledR 4
#define ledG 5

bool statusBTprof, flag1;

// bool statusBT1; 
// bool statusBT1 = digitalRead(BT1);
bool statusBT2 = digitalRead(BT1);
bool statusBT3 = digitalRead(BT1);

int contador; // variável do tipo inteiro ---> 2^16 = 65.536 (64k)

void setup() {
  Serial.begin(9600);
  // Configurar o sentido dos pinos de I/O
  pinMode(BT1, INPUT);
  pinMode(BT2, INPUT);
  pinMode(BT3, INPUT);

  pinMode(ledB, OUTPUT);
  pinMode(ledW, OUTPUT);
  pinMode(ledR, OUTPUT);
  
  // exProf();
  // ex6();
}

// Rotina principal
void loop() {
  // piscaRB(); // rb vai piscar sempre
  
  statusBTprof = digitalRead(BT1);
  delay(100); // minimizar o efeito debounce

  if(statusBTprof == 1 && flag1 == 0){
    flag1 == 1;
    Serial.println("O botão foi pressionado");
    delay(300);
    allOn();
    // Foi detectada a borda de subida
  }

  if(statusBTprof == 0 && flag1 == 1){
    Serial.println("O botão foi solto");
    flag1 == 0;
    delay(300);
    allOff();
    // Foi detectada a borda de descida
  }

  // ex7();

}

void piscaRB(){
  digitalWrite(ledB, HIGH);
  digitalWrite(ledR, LOW);
  delay(250);
  digitalWrite(ledR, HIGH);
  digitalWrite(ledB, LOW);
  delay(250);
}

void piscaW(){
  digitalWrite(ledR, LOW);
  digitalWrite(ledW, HIGH);
  delay(350);
  digitalWrite(ledW, LOW);
  delay(350);
}

void piscaS6(){
  digitalWrite(ledB, HIGH);
  digitalWrite(ledW, HIGH);
  delay(350);
  digitalWrite(ledB, LOW);
  digitalWrite(ledW, LOW);
  delay(350);
}

void piscaA8(){
  digitalWrite(ledG, HIGH);
  digitalWrite(ledR, LOW);
  delay(250);
  digitalWrite(ledR, HIGH);
  digitalWrite(ledG, LOW);
  delay(250);
}

void piscaM9(){
  digitalWrite(ledG, HIGH);
  digitalWrite(ledR, HIGH);
  digitalWrite(ledB, LOW);
  digitalWrite(ledW, LOW);
  delay(1000);
  digitalWrite(ledB, HIGH);
  digitalWrite(ledW, HIGH);
  digitalWrite(ledR, LOW);
  digitalWrite(ledG, LOW);
  delay(1000);
}

void allOff(){
  digitalWrite(ledG, LOW);
  digitalWrite(ledR, LOW);
  digitalWrite(ledB, LOW);
  digitalWrite(ledW, LOW);
}

void allOn(){
  digitalWrite(ledG, HIGH);
  digitalWrite(ledR, HIGH);
  digitalWrite(ledB, HIGH);
  digitalWrite(ledW, HIGH);
}

void exProf(){
  for(int i = 0; i < 10; i++){
    Serial.println(i);
    piscaW();
  }
 
  Serial.println("Fim da inicializacao");
  delay(2000);
}

void ex6(){
  for(int i = 0; i < 6; i++){
    Serial.println(i);
    piscaS6();
  }
 
  Serial.println("Fim da inicializacao");
}

void ex7(){
    if(statusBT2 == HIGH){ // se o botão foi pressionado
      Serial.println("BT2 Ligado!!! :D");
      piscaS6();
    }
    else if(digitalRead(BT2) == HIGH){
      piscaA8();
    }
    else if(digitalRead(BT3) == HIGH){
      piscaM9();
    }
    else{
      allOff();
    }
}