// ESP
#define motor1V 3
#define motor1B 4
#define motor1F 5
#define motor2V 11
#define motor2B 9
#define motor2F 10

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

int velo_1, velo_2;
byte B_1,B_2,F_1,F_2;
char dire = 'F';
int v = 255;


void setup() {
  Serial.begin(9600);
  pinMode(motor1V, OUTPUT);
  pinMode(motor1B, OUTPUT);
  pinMode(motor1F, OUTPUT);
  pinMode(motor2V, OUTPUT);
  pinMode(motor2B, OUTPUT);
  pinMode(motor2F, OUTPUT);
 }


void loop()
{

  Serial.println(dire);
  switch (dire)
  {
  case 'F':
    Serial.println("Pra frente");
    B_1 = 0;
    F_1 = 1;
    B_2 = 0;
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
    F_2 = 0;
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

  
  dire = Serial.read();
    
}
