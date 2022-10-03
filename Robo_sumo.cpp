//Arduino 

#define motor1V 0
#define motor1B 1
#define motor1F 2
#define motor2V 3
#define motor2B 4
#define motor2F 5


// ESP
/*
#define motor1V 6
#define motor1B 7
#define motor1F 8
#define motor2V 9
#define motor2B 10
#define motor2F 11
#define bluetooth 16
*/

byte direcao = 0 ;
byte direcao_antes = 0;
byte F = 0;
byte B = 0;
volatile int velo = 105
 

void setup() {
  Serial.begin(115200);
  pinMode(motor1V, OUTPUT);
  pinMode(motor1B, OUTPUT);
  pinMode(motor1F, OUTPUT);
  pinMode(motor2V, OUTPUT);
  pinMode(motor2B, OUTPUT);
  pinMode(motor2F, OUTPUT);
  pinMode(bluetooth, INPUT);
  attachInterrupt(bluetooth, blue, RISING);
  // vou usar a variavel bluethooth como pino para ativar a interrupcao ate descobir 
  // qual a variavel de coneccao do sinal bluetooth 
  tempo = millis();
}

void IRAM_ATTR blue(){


  motores(direcao);

}

void loop()
{
  bluetooth

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
}

void motores(direcao){

  if (direcao != 0 && velo < 255 )
  {
    velo += 50;
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

  if (millis() > tempo + 500 ){
    Serial.print("a velocidade e: ");
    Serial.print(velo);
    tempo = millis(); 
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
