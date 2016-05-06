
int pwma = 3;
int pwmb = 11;
int dira = 12;
int dirb = 13;
int Speed = 0;


void setup() {
  // put your setup code here, to run once:

  pinMode(pwma, OUTPUT);
  pinMode(pwmb, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
    digitalWrite(dira, LOW);
    digitalWrite(dirb, LOW);
    Speed = Serial.read();
    //Speed = (Serial.read()<<24)+(Serial.read()<<16)+(Serial.read()<<8)+Serial.read();
    if (Speed < 53) {
      if (Speed > 48) {

        Speed = map(Speed, 49, 52, 0, 255);
        //Serial.println(Speed);
        analogWrite(pwma, Speed);
        analogWrite(pwmb, Speed);
      }
    }
    else if (Speed < 69) {
      if (Speed > 64) {

        Speed = map(Speed, 65, 68, 0, 255);
        //Serial.println(Speed);
        analogWrite(pwma, Speed * .5);
        analogWrite(pwmb, Speed);
      }
    }
    else if (Speed < 73) {
      if (Speed > 68) {

        Speed = map(Speed, 69, 72, 0, 255);
        //Serial.println(Speed);
        analogWrite(pwma, Speed);
        analogWrite(pwmb, Speed * .5);
      }
    }
    else if (Speed = 90) {
      analogWrite(pwma, 100);
      analogWrite(pwmb, 100);
      digitalWrite(dira, HIGH);
      digitalWrite(dirb, HIGH);

    }
  }
}

