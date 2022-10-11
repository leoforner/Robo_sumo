const int MotorDireita_A = 4;
const int MotorDireita_B = 5;
const int MotorDireita_PWM = 3;
const int MotorDireita = 1;

const int MotorEsquerda_A = 9;
const int MotorEsquerda_B = 10;
const int MotorEsquerda_PWM = 11;
const int MotorEsquerda = 2;

void setup()
{
  pinMode(MotorDireita_A, OUTPUT);
  pinMode(MotorDireita_B, OUTPUT);
  pinMode(MotorDireita_PWM, OUTPUT);

  pinMode(MotorEsquerda_A, OUTPUT);
  pinMode(MotorEsquerda_B, OUTPUT);
  pinMode(MotorEsquerda_PWM, OUTPUT);
}

void Forward(int Motor, int Velocidade)
{
  if (Motor == 1)
  {
    digitalWrite(MotorDireita_A, HIGH);
    digitalWrite(MotorDireita_B, LOW);
    analogWrite (MotorDireita_PWM, Velocidade);
  }

  else if (Motor == 2)
  {
    digitalWrite(MotorEsquerda_A, HIGH);
    digitalWrite(MotorEsquerda_B, LOW);
    analogWrite (MotorEsquerda_PWM, Velocidade);
  }
}

void loop()
{
  Forward(MotorEsquerda, 200);
  delay(1000);

  Forward(MotorDireita, 200);
  delay(1000);
}
