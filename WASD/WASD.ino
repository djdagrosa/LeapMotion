/*To control the rover, Copy and paste the code below into the Arduino software*/
int M1 = 12; //M1 Speed Control
int M2 = 13; //M2 Speed Control
int E1 = 3; //M1 Direction Control
int E2 = 11; //M2 Direction Control


//Pin values for the motors
int pwma = 3;
int pwmb = 11;
int dira = 12;
int dirb = 13;
int Speed = 0;

//Various speed levels
int sp1 = 0;
int sp2 = 100;
int sp3 = 113;
int sp4 = 175;
int sp5 = 250;

int Pin = A0; //Pins the encoders are on
int Pin2 = A3;
int state1 = 40; //State is the value the encoder is reading from the light sensor
int state2 = 40;
int flag1 = 1; //Flags for determining if the encoder is seeing a light for the first time; Flag says the last state he encoder was at, on or off
int flag2 = 1;
int count1 = 0; //Counts for the number of 18 degrees the wheel rotates
int count2 = 0;
int tim = 0; //Time for calculating speed
//int Led = 13;

//These values are the input from the first encoder to be averaged
int val1 = 0;
int val2 = 0;
int val3 = 0;
int val4 = 0;
int val5 = 0;
int val6 = 0;
int val7 = 0;
int val8 = 0;
int val9 = 0;
int val10 = 0;
int val11 = 0;
int val12 = 0;
int val13 = 0;
int val14 = 0;
int val15 = 0;
int val16 = 0;
int val17 = 0;
int val18 = 0;
int val19 = 0;
int val20 = 0;

//These values are the input from the second encoder to be averaged
int val21 = 0;
int val22 = 0;
int val23 = 0;
int val24 = 0;
int val25 = 0;
int val26 = 0;
int val27 = 0;
int val28 = 0;
int val29 = 0;
int val210 = 0;
int val211 = 0;
int val212 = 0;
int val213 = 0;
int val214 = 0;
int val215 = 0;
int val216 = 0;
int val217 = 0;
int val218 = 0;
int val219 = 0;
int val220 = 0;

int marker = 0;
int num = 2;




//int leftspeed = 120; //255 is maximum speed
//int rightspeed = 120;

void setup(void)
{

  pinMode(3, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(pwma, OUTPUT);
  pinMode(pwmb, OUTPUT);
  pinMode(Pin, INPUT);
  pinMode(Pin2, INPUT);
  Serial.begin(9600);
  //Serial.println("setup");
}

void loop(void)
{
  while (Serial.available() < 1) {} // Wait until a character is received
  char val = Serial.read();
  int leftspeed = 125; //255 is maximum speed
  int rightspeed = 138;
  int leftspeeds = 100; //255 is maximum speed
  int rightspeeds = 113;
  switch (val) // Perform an action depending on the command
  {
    case 'w'://Move Forward
    case 'W':
      forward (leftspeed, rightspeed);
      break;
    case 's'://Move Backwards
    case 'S':
      reverse (leftspeed, rightspeed);
      break;
    case 'a'://Turn Left
    case 'A':
      left (leftspeeds, rightspeeds);
      break;
    case 'd'://Turn Right
    case 'D':
      right (leftspeeds, rightspeeds);
      break;
    case 'e'://Stop
    case 'E':
      stops (0, 0);
      break;
  }
}

void stops (char a, char b)
{
  analogWrite (E1, a);
  digitalWrite(M1, LOW);
  analogWrite (E2, b);
  digitalWrite(M2, LOW);
  //Serial.println("forward");
}

//*/
void forward (char a, char b)
{
  
  analogWrite (E1, a);
  digitalWrite(M1, LOW);
  analogWrite (E2, b);
  digitalWrite(M2, LOW);
  
  //Serial.println("forward");
}

void reverse (char a, char b)
{
  analogWrite (E1, a);
  digitalWrite(M1, HIGH);
  analogWrite (E2, b);
  digitalWrite(M2, HIGH);
  //Serial.println("reverse");
}

void right (char a, char b)
{

  analogWrite (E2, b);
  digitalWrite(M2, LOW);
  analogWrite (E1, 30);
  digitalWrite(M1, LOW);
  //Serial.println("left");
}

void left (char a, char b)
{
  analogWrite (E1, a);
  digitalWrite(M1, LOW);
  analogWrite (E2, 30);
  digitalWrite(M2, LOW);

  //Serial.println("right");
}
//*/

/*/
void forward (char a, char b)
{
  
 
  while (count1 < num || count2 < num) {
    digitalWrite(dira, LOW);
    digitalWrite(dirb, LOW);
    analogWrite(pwma, sp2);
    analogWrite(pwmb, sp3);

    Encoder1();
    Encoder2();
  }

  count1 = 0;
  count2 = 0;
  //Serial.println("forward");
}

void reverse (char a, char b)
{
  while (count1 < num || count2 < num) {
    digitalWrite(dira, HIGH);
    digitalWrite(dirb, HIGH);
    analogWrite(pwma, sp2);
    analogWrite(pwmb, sp3);

    Encoder1();
    Encoder2();
  }

  count1 = 0;
  count2 = 0;
  //Serial.println("reverse");
}

void right (char a, char b)
{

  analogWrite (E2, b);
  digitalWrite(M2, LOW);
  analogWrite (E1, 0);
  digitalWrite(M1, LOW);
  //Serial.println("left");
}

void left (char a, char b)
{
  analogWrite (E1, a);
  digitalWrite(M1, LOW);
  analogWrite (E2, 0);
  digitalWrite(M2, LOW);

  //Serial.println("right");
}
//*/


int Encoder1() {
  val1 = analogRead(Pin);
  val2 = analogRead(Pin);
  val3 = analogRead(Pin);
  val4 = analogRead(Pin);
  val5 = analogRead(Pin);
  val6 = analogRead(Pin);
  val7 = analogRead(Pin);
  val8 = analogRead(Pin);
  val9 = analogRead(Pin);
  val10 = analogRead(Pin);
  val11 = analogRead(Pin);
  val12 = analogRead(Pin);
  val13 = analogRead(Pin);
  val14 = analogRead(Pin);
  val15 = analogRead(Pin);
  val16 = analogRead(Pin);
  val17 = analogRead(Pin);
  val18 = analogRead(Pin);
  val19 = analogRead(Pin);
  val20 = analogRead(Pin);

  state1 = (val1 + val2 + val3 + val4 + val5 + val6 + val7 + val8 + val9 + val10 + val11 + val12 + val13 + val14 + val15 + val16 + val17 + val19 + val20) / 20;

  //Serial.println(state1);


  if (state1 > 70) {
    if (flag1 == 1) {

      count1 = count1 + 1;

      flag1 = 0;
      //tim = (millis()-tim)/1000;
      //Serial.println(count1);
      //tim = millis();
    }
  }
  if (state1 < 70) {
    if ( flag1 == 0) {
      flag1 = 1;

    }

  }
}

int Encoder2() {
  val21 = analogRead(Pin2);
  val22 = analogRead(Pin2);
  val23 = analogRead(Pin2);
  val24 = analogRead(Pin2);
  val25 = analogRead(Pin2);
  val26 = analogRead(Pin2);
  val27 = analogRead(Pin2);
  val28 = analogRead(Pin2);
  val29 = analogRead(Pin2);
  val210 = analogRead(Pin2);
  val211 = analogRead(Pin2);
  val212 = analogRead(Pin2);
  val213 = analogRead(Pin2);
  val214 = analogRead(Pin2);
  val215 = analogRead(Pin2);
  val216 = analogRead(Pin2);
  val217 = analogRead(Pin2);
  val218 = analogRead(Pin2);
  val219 = analogRead(Pin2);
  val220 = analogRead(Pin2);

  state2 = (val21 + val22 + val23 + val24 + val25 + val26 + val27 + val28 + val29 + val210 + val211 + val212 + val213 + val214 + val215 + val216 + val17 + val219 + val220) / 20;

  //Serial.println(state2);


  if (state2 > 70) {
    if (flag2 == 1) {

      count2 = count2 + 1;

      flag2 = 0;
      //tim = (millis()-tim)/1000;
      //Serial.println(count2);
      //tim = millis();
    }
  }
  if (state2 < 70) {
    if ( flag2 == 0) {
      flag2 = 1;

    }

  }
}

