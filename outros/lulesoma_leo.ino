// ESP
#include <string.h>
#define motor1V 3
#define motor1B 4
#define motor1F 5
#define motor2V 11
#define motor2B 9
#define motor2F 10
const int pinoRX = 2; //PINO DIGITAL 2 (RX)
const int pinoTX = 3; //PINO DIGITAL 3 (TX)
//#include "BluetoothSerial.h"
//#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED) #error Bluetooth is not enabled! Please run 'make menuconfig' to and enable it
//#endif
//#include <SoftwareSerial.h>
//SoftwareSerial bluetooth(pinoRX, pinoTX);

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

char direcao[1];

int velo, velo_1, velo_2;
byte B_1,B_2,F_1,F_2;
//BluetoothSerial SerialBT;
bool test = false;
//char dadoBluetooth[1]; //VARIÁVEL QUE ARMAZENA O VALOR ENVIADO PELO BLUETOOTH




void setup() {
  Serial.begin(115200);
  //SerialBT.begin("sumo");
  /*
  bluetooth.begin(9600); //INICIALIZA A SERIAL DO BLUETOOTH
  bluetooth.print("$"); //IMPRIME O CARACTERE
  bluetooth.print("$"); //IMPRIME O CARACTERE
  bluetooth.print("$"); //IMPRIME O CARACTERE
  */
  Serial.println("Bluetooth Started! Ready to pair...");
  pinMode(motor1V, OUTPUT);
  pinMode(motor1B, OUTPUT);
  pinMode(motor1F, OUTPUT);
  pinMode(motor2V, OUTPUT);
  pinMode(motor2B, OUTPUT);
  pinMode(motor2F, OUTPUT);
  //timer = timerBegin(0, 80000, true);
  //timerAttachInterrupt(timer, &onTimer, true);
  //timerAlarmWrite(timer, 100, true);
  //timerAlarmEnable(timer);
}
/*
void IRAM_ATTR onTimer() {
 if ( comparacao("FBLRGIHJS", SerialBT.read()) )
  {
    direcao = SerialBT.read();
    test = false;
  }
 
}
*/
/*
void comparacao(comp,recebido){
  for (size_t i = 0; i < strlen(comp); i++)
  {
    test = test || strcmp(comp[i], recebido);
  }
 
} */

void loop()
{
/*
  if (bluetooth.available()){
    dadoBluetooth = bluetooth.read(); //VARIÁVEL RECEBE O VALOR ENVIADO PELO BLUETOOTH
    if ( comparacao("FBLRGIHJS", dadoBluetooth) ){
      direcao = dadoBluetooth;
      test = false;
    }
    if ( comparacao("0123456789q",dadoBluetooth) ){
      velo = 255*atoi(dadoBluetooth)/10;
      if (dadoBluetooth =='q') velo = 0;
      Serial.print("a velocidade e: ");
      Serial.println(velo);
      test = false;
    }
    if ( comparacao("wWuUxXvV", dadoBluetooth) ){
      especial = dadoBluetooth;
      test = false;
    }
    
  }
*/
  

/*
  if (especial_0)  giro_180();
  if (especial_1)  giro_esquerda();
  if (especial_2)  giro_direita();
  if (especial_3)  piao();
  if (especial_4)  batebate();
*/


char dire = 'F';
int v = 255;

  switch (dire)
  {
  case 'F':
    Serial.println("Pra frente");
    F_1 = 1;
    B_2 = 0;
    B_1 = 0;
    F_2 = 1;
    velo_1 = v;
    velo_2 = v;
    break;
  case 'B':
    Serial.println("Pra tras");
    B_1 = 1;
    F_1 = 0;
    B_2 = 1;
    F_2 = 0;
    velo_1 = v;
    velo_2 = v;
    break;
  case 'L':
    Serial.println("esquerinha");
    B_1 = 1;
    F_1 = 0;
    B_2 = 0;
    F_2 = 1;
    velo_1 = v;
    velo_2 = v;
    break;
  case 'R':
    Serial.println("direitinha");
    B_1 = 0;
    F_1 = 1;
    B_2 = 1;
    F_2 = 0;
    velo_1 = v;
    velo_2 = v;
    break;
  case 'G':
    Serial.println("esquerda frente");
    B_1 = 0;
    F_1 = 1;
    B_2 = 0;
    F_2 = 1;
    velo_1 = v/2;
    velo_2 = v;
    break;
  case 'I':
    Serial.println("direita frente");
    B_1 = 0;
    F_1 = 1;
    B_2 = 0;
    F_2 = 1;
    velo_1 = v;
    velo_2 = v/2;
    break;
  case 'H':
    Serial.println("esquerda tras");
    B_1 = 1;
    F_1 = 0;
    B_2 = 1;
    F_2 = 0;
    velo_1 = v/2;
    velo_2 = v;
    break;
  case 'J':
    Serial.println("direita tras");
    B_1 = 1;
    F_1 = 0;
    B_2 = 1;
    F_2 = 0;
    velo_1 = v;
    velo_2 = v/2;
    break;
   case 'S':
    Serial.println("PAROU PAROU PAROU");
    B_1 = 0;
    F_1 = 0;
    B_2 = 0;
    F_2 = 1;
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