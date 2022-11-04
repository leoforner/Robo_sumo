// ESP
#define motor1V 3
#define motor1B 4
#define motor1F 5
#define motor2V 11
#define motor2B 10
#define motor2F 9
#include <ArduinoBLE.h>

/*
Forward -> F
Back -> B
Left -> L
Right -> R
Forward Left -> G
Forward Right -> I
BackLeft -> H
Back Right -> J
Stop -> S
Front Lights On -> W (upper case)
Front Lights Off -> w (lower case)
Back Lights On -> U (upper case)
Back Lights Off -> u (lower case)
Horn On -> V (upper case) 
Horn Off -> v (lower case)
Extra On -> X (upper case)
Extra Off-> x (lower case)
Speed 0 - 0 (zero)
Speed 10 -> 1
Speed 20 -> 2
Speed 30 -> 3
Speed 40 - 4
Speed 50 -> 5
Speed 60 -> 6
Speed 70 -> ?
Speed 80 -> 8
Speed 90 -> 9
Speed 100 -> q
Stop All -> D
*/

char direcao = 0, velocidade = 0, dadoBluetooth; //VARIÁVEL QUE ARMAZENA O VALOR ENVIADO PELO BLUETOOTH

float velo, velo_1, velo_2;
byte B_1,B_2,F_1,F_2;
bool test = false;
int tempo = millis();

void motores( char dire, int v ){

  v = 255*v/10;
  
  switch (dire)
  {
  case 'F':
    F_1 = HIGH;
    B_2 = LOW;
    B_1 = LOW;
    F_2 = HIGH;
    velo_1 = v;
    velo_2 = v;
    break;
  case 'B':
    B_1 = HIGH;
    F_1 = LOW;
    B_2 = HIGH;
    F_2 = LOW;
    velo_1 = v;
    velo_2 = v;
    break;
  case 'L':
    B_1 = HIGH;
    F_1 = LOW;
    B_2 = LOW;
    F_2 = HIGH;
    velo_1 = v;
    velo_2 = v;
    break;
  case 'R':
    B_1 = LOW;
    F_1 = HIGH;
    B_2 = HIGH;
    F_2 = LOW;
    velo_1 = v;
    velo_2 = v;
    break;
  case 'G':
    B_1 = LOW;
    F_1 = HIGH;
    B_2 = LOW;
    F_2 = HIGH;
    velo_1 = v/2;
    velo_2 = v;
    break;
  case 'I':
    B_1 = LOW;
    F_1 = HIGH;
    B_2 = LOW;
    F_2 = HIGH;
    velo_1 = v;
    velo_2 = v/2;
    break;
  case 'H':
    B_1 = HIGH;
    F_1 = LOW;
    B_2 = HIGH;
    F_2 = LOW;
    velo_1 = v/2;
    velo_2 = v;
    break;
  case 'J':
    B_1 = HIGH;
    F_1 = LOW;
    B_2 = HIGH;
    F_2 = LOW;
    velo_1 = v;
    velo_2 = v/2;
    break;
   case 'S':
    B_1 = LOW;
    F_1 = LOW;
    B_2 = LOW;
    F_2 = LOW;
    velo_1 = 0;
    velo_2 = 0;
    break;
  default:
    break;
  }


  digitalWrite(motor1B, B_1);
  digitalWrite(motor1F, F_1);
  analogWrite(motor1V, velo_1);
  analogWrite(motor2V, velo_2);
  digitalWrite(motor2B, B_2);
  digitalWrite(motor2F, F_2);
}


void status(char dire){
  switch (dire)
  {
  case 'F':
    Serial.println("Pra frente");
    Serial.println(velo_2);
    Serial.println(velo_1);
    break;
  case 'B':
    Serial.println("Pra tras");
    Serial.println(velo_2);
    Serial.println(velo_1);
    break;
  case 'L':
    Serial.println("esquerinha");
    Serial.println(velo_2);
    Serial.println(velo_1);
    break;
  case 'R':
    Serial.println("direitinha");
    Serial.println(velo_2);
    Serial.println(velo_1);
    break;
  case 'G':
    Serial.println("esquerda frente");
    Serial.println(velo_2);
    Serial.println(velo_1);
    break;
  case 'I':
    Serial.println("direita frente");
    Serial.println(velo_2);
    Serial.println(velo_1);
    break;
  case 'H':
    Serial.println("esquerda tras");
    Serial.println(velo_2);
    Serial.println(velo_1);
    break;
  case 'J':
    Serial.println("direita tras");
    Serial.println(velo_2);
    Serial.println(velo_1);
    break;
   case 'S':
    Serial.println("PAROU PAROU PAROU");
    Serial.println(velo_2);
    Serial.println(velo_1);
    break;
  default:
    break;
  }
}


void setup() {
  Serial.begin(9600);

f (!BLE.begin()) 
{
Serial.println("starting BLE failed!");
while (1);
}

BLE.setLocalName("Robô");
BLE.advertise();
Serial.println("Bluetooth device active, waiting for connections...");

  pinMode(motor1V, OUTPUT);
  pinMode(motor1B, OUTPUT);
  pinMode(motor1F, OUTPUT);
  pinMode(motor2V, OUTPUT);
  pinMode(motor2B, OUTPUT);
  pinMode(motor2F, OUTPUT);

}


bool comparacao(String comparador,char recebido){
  Serial.println(comparador);
  Serial.println(recebido);
  int tamanho = comparador.length();
  for (size_t i = 0; i < tamanho; i++){
    if (comparador[i] == recebido ) test = true;
    
  }
  return test;
}


void loop()
{
BLEDevice controle = BLE.central();

/* MODO BLUETOOTH
  if (controle){
  	Serial.print("Connected to central: ");
	Serial.println(central.address());
    dadoBluetooth = bluetooth.read(); //VARIÁVEL RECEBE O VALOR ENVIADO PELO BLUETOOTH
    if ( comparacao("FBLRGIHJS", dadoBluetooth) ){
      direcao = dadoBluetooth;
      test = false;
    }
    if ( comparacao("0123456789q",dadoBluetooth) ){
      velocidade = dadoBluetooth;
      Serial.print("a velocidade e: ");
      Serial.println(velo);
      test = false;
      velo = velocidade - '0';
      if (dadoBluetooth =='q') velo = 0;

    }
    if ( comparacao("wWuUxXvV", dadoBluetooth) ){
      especial = dadoBluetooth;
      test = false;
    }
    
  }
  */

/* MODO SERIAL COM COMPARAÇÃO*/
  if (Serial.available()){
    dadoBluetooth = Serial.read(); //VARIÁVEL RECEBE O VALOR ENVIADO PELO BLUETOOTH
    if ( comparacao("FBLRGIHJS", dadoBluetooth) ){
      direcao = dadoBluetooth;
      test = false;
    }
    if ( comparacao("0123456789q",dadoBluetooth) ){
      velocidade = dadoBluetooth;
      Serial.print("a velocidade e: ");
      Serial.println(velo);
      test = false;
      velo = velocidade - '0';
      if (velocidade == 'q') velo = 10;
    }
    if ( comparacao("wWuUxXvV", dadoBluetooth) ){
//      especial = dadoBluetooth;
//      test = false;
    }
    
  }
  

/* MODO SERIAL DIRETO 
  if (Serial.available()){
  //direcao = Serial.read();
  //Serial.println(direcao);
  //velocidade = Serial.read();
  //Serial.println(velocidade);
  
  int contador = 0;
  if(Serial.available() and contador == 0){
  velocidade = Serial.read();
  Serial.println(velocidade);
  contador = 1;
  }
  if(Serial.available() and contador == 1){
  velocidade = Serial.read();
  Serial.println("aqui");
  Serial.println(velocidade);
  contador = 0;
}
  
  velo = velocidade - '0';
  if (velocidade == 'q') velo = 10;
*/

  motores( direcao, velo );

 if (millis() >= tempo + 1000){
  tempo = millis();
  status(direcao);
 }
/*
  if (especial)  giro_180();
  if (especial)  giro_esquerda();
  if (especial)  giro_direita();
  if (especial)  piao();
  if (especial)  batebate();
*/
}


/*
void giro_180(){

  for (int v = 100; v < 200; v += 10)
  {
    analogWrite(motor1V, v);
    analogWrite(motor1B, 0);
    analogWrite(motor1F, 1);
    analogWrite(motor2V, v);
    analogWrite(motor2B, 1);
    analogWrite(motor2F, 0);
    delay(20)
  }
  
}

void giro_esquerda(){

  for (int v = 100; v < 200; v += 10)
  {
    analogWrite(motor1V, v);
    analogWrite(motor1B, 1);
    analogWrite(motor1F, 0);
    analogWrite(motor2V, v);
    analogWrite(motor2B, 0);
    analogWrite(motor2F, 1);
    delay(10)
  }
  
}

void giro_direita(){

  for (int v = 100; v < 200; v += 10)
  {
    analogWrite(motor1V, v);
    analogWrite(motor1B, 0);
    analogWrite(motor1F, 1);
    analogWrite(motor2V, v);
    analogWrite(motor2B, 1);
    analogWrite(motor2F, 0);
    delay(10)
  }
  
}

void piao(){

  for (int v = 100; v < 200; v += 10)
  {
    analogWrite(motor1V, v);
    analogWrite(motor1B, 0);
    analogWrite(motor1F, 1);
    analogWrite(motor2V, v);
    analogWrite(motor2B, 1);
    analogWrite(motor2F, 0);
    delay(10)
  }
  delay(10000);
  
}

void batebate(){
  for (byte i = 0; i < 3; i++)
  {
    for (int v = 100; v < 200; v += 10)
    {
      analogWrite(motor1V, v);
      analogWrite(motor1B, 0);
      analogWrite(motor1F, 1);
      analogWrite(motor2V, v);
      analogWrite(motor2B, 0);
      analogWrite(motor2F, 1);
      delay(10)
    }
    for (int v = 100; v < 200; v += 10)
    {
      analogWrite(motor1V, v);
      analogWrite(motor1B, 1);
      analogWrite(motor1F, 0);
      analogWrite(motor2V, v);
      analogWrite(motor2B, 1);
      analogWrite(motor2F, 0);
      delay(20)
    }
  }
}
*/
