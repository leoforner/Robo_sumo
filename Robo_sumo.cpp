//Arduino 
/*
#define motor1V 0
#define motor1B 1
#define motor1F 2
#define motor2V 3
#define motor2B 4
#define motor2F 5
*/

// ESP
#define motor1V 6
#define motor1B 7
#define motor1F 8
#define motor2V 9
#define motor2B 10
#define motor2F 11
#define bluetooth 16


byte direcao = 0 ;
volatile int velo = 105
 

// rotina de configuração:
void setup() {
  Serial.begin(115200);
  for(i=0; i<2; i++) yf[i] = 0;
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

}

void IRAM_ATTR blue(){
  motores(direcao);



  
}

// loop infinito:
void loop()
{

  bluetooth


  if (Serial.available()) {
    direcao = Serial.read();
  }
  
  if (direcao != (1 || 2)){
    direcao = 0
  }

   motores(direcao);

 
  y[0] = analogRead(ADC_PIN);
  

  // Sinal de atuação
  us[0] = r[j];
  
  // Escrita sinal de controle
  u = us[0];
  if(u > 255) u = 255;
  if(u < 0) u  = 0;



}


void motores(direcao){


  if (direcao != 0 && velo < 255 ){
    velo += 50;
    atraso = millis();
  }else if (atraso >  100 ) {
    velo = 105;
  }

  while (direcao == 1)
  {
    analogWrite(motor1V, velo);
    analogWrite(motor1B, 1);
    analogWrite(motor1F, 0);
    analogWrite(motor2V, velo);
    analogWrite(motor2B, 1);
    analogWrite(motor2F, 0);
  }

  while (direcao == 0)
  {
    analogWrite(motor1V, 0);
    analogWrite(motor1B, 0);
    analogWrite(motor1F, 0);
    analogWrite(motor2V, 0);
    analogWrite(motor2B, 0);
    analogWrite(motor2F, 0);
  }

  while (direcao == 2)
  {
    analogWrite(motor1V, velo);
    analogWrite(motor1B, 0);
    analogWrite(motor1F, 1);
    analogWrite(motor2V, velo);
    analogWrite(motor2B, 0);
    analogWrite(motor2F, 1);
  }

  if (millis() > tempo + 500 ){
    Serial.print("a velocidade e: ");
    Serial.print(velo);
    tempo = millis(); 
  }

}

void giro_esquerda(){

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
