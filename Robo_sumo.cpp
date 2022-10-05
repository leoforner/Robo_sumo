// ESP
#define motor1V 6
#define motor1B 7
#define motor1F 8
#define motor2V 9
#define motor2B 10
#define motor2F 11
#include "BluetoothSerial.h"
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED) #error Bluetooth is not enabled! Please run 'make menuconfig' to and enable it
#endif

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

byte direcao = 0 ;
byte F = 0;
byte B = 0;
volatile int velo = 0;
byte speed = 0;
BluetoothSerial SerialBT;


void setup() {
  Serial.begin(115200);
  SerialBT.begin("sumo");
  Serial.println("Bluetooth Started! Ready to pair...");
  pinMode(motor1V, OUTPUT);
  pinMode(motor1B, OUTPUT);
  pinMode(motor1F, OUTPUT);
  pinMode(motor2V, OUTPUT);
  pinMode(motor2B, OUTPUT);
  pinMode(motor2F, OUTPUT);
  
  attachInterrupt(bluetooth, blue, RISING);
  // vou usar a variavel bluethooth como pino para ativar a interrupcao ate descobir 
  // qual a variavel de coneccao do sinal bluetooth 
  tempo1 = millis();
  tempo2 = millis();
  tempo3 = millis();
}

void IRAM_ATTR blue(){
  if (Serial.available()) 
  {
    direcao = Serial.read();
  }
  motores(direcao);

}

void loop()
{

  if (Serial.available()){
    SerialBT.write(Serial.read()); //envio p/celular
  }
  if (SerialBT.available()){
    Serial.write(SerialBT.read()); //receber
    if ( SerialBT.read() == 'F' OR 'B' OR 'L' OR 'R' OR 'G' OR 'I' OR 'H' OR 'J' OR 'S' ){
     direcao = SerialBT.read();
    }
    if ( SerialBT.read() == 0 OR 1 OR 2 OR 3 OR 4 OR 5 OR 6 OR 7 OR 8 OR 9 OR q ){
      speed = SerialBT.read();
    }
    if ( SerialBT.read() == 'w' OR 'W' OR 'u' OR 'U' OR 'x' OR 'X' OR 'v' OR 'V' OR  ){
      especial = SerialBT.read();
    }
    
  }

 

  if (Serial.available()) {
    direcao = Serial.read();
  }
  
  if (direcao != (1 || 2)){
    direcao = 0
  }

  if (direcao == 0)//parado
  {
    if (direcao_anterior = 1 ){
      F = 0;
      B = 1;
    }else if (direcao_anterior = 2) {
      F = 1;
      B = 0
    }else {
      F = 0;
      B = 0;
    }
    tempo = millis();
  
   if ((tempo >= millis() + 100) && velo > 100)
   {
     analogWrite(motor1V, velo);
     analogWrite(motor1B, B);
     analogWrite(motor1F, F);
     analogWrite(motor2V, velo);
     analogWrite(motor2B, B);
     analogWrite(motor2F, F);
     tempo =  millis();
     i = i -20
   }
  }   
  
  motores(direcao);

  if (especial_0)  giro_180();
  if (especial_1)  giro_esquerda();
  if (especial_2)  giro_direita();
  if (especial_3)  piao();
  if (especial_4)  batebate();

  direcao_anterior = bluetooth; 
}

void motores(direcao){

  if (direcao != 0 && velo < 255 && millis() > tempo2 + 20)
  {
    velo += 50;
    tempo2 = millis();
  }

  while (direcao == 1)//pra tras
  {
    B = 1;
    F = 0;
    analogWrite(motor1V, velo);
    analogWrite(motor1B, B);
    analogWrite(motor1F, F);
    analogWrite(motor2V, velo);
    analogWrite(motor2B, B);
    analogWrite(motor2F, F);
  }

 
  while (direcao == 2)// pra frente
  {
    B = 0;
    F = 1;
    analogWrite(motor1V, velo);
    analogWrite(motor1B, B);
    analogWrite(motor1F, F);
    analogWrite(motor2V, velo);
    analogWrite(motor2B, B);
    analogWrite(motor2F, F);
  }

  if (millis() > tempo3 + 500 ){
    Serial.print("a velocidade e: ");
    Serial.print(velo);
    tempo3 = millis(); 
  }

}

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
