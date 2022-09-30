#define motor1V 6
#define motor1B 7
#define motor1F 8
#define motor2V 9
#define motor2B 10
#define motor2F 11



// rotina de configuração:
void setup() {
  Serial.begin(115200);
  for(i=0; i<2; i++) yf[i] = 0;
    
}

// loop infinito:
void loop()
{
   
  y[0] = analogRead(ADC_PIN);
  

  // Sinal de atuação
  us[0] = r[j];
  
  // Escrita sinal de controle
  u = us[0];
  if(u > 255) u = 255;
  if(u < 0) u  = 0;

  analogWrite(PWM_PIN, u);

 Serial.print(yf[0]);

  Serial.print(" ");

  // Serial.println(255);

}
