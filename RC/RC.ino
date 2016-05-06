
int pwma = 3;
int pwmb = 11;
int dira = 12;
int dirb = 13;
int Speed = 9;
int turn = 10;
int direc = 6;
int vals = 0;
int valt = 0;
int vald = 0;
int mot1 = 0;
int mot2 = 0;

int vals1 = 0;
int vals2 = 0;
int vals3 = 0;
int vals4 = 0;
int vals5 = 0;

int valt1 = 0;
int valt2 = 0;
int valt3 = 0;
int valt4 = 0;
int valt5 = 0;

int vald1 = 0;
int vald2 = 0;
int vald3 = 0;
int vald4 = 0;
int vald5 = 0;

void setup() {
  // put your setup code here, to run once:

  pinMode(pwma, OUTPUT);
  pinMode(pwmb, OUTPUT);
  pinMode(Speed, INPUT);
  pinMode(turn, INPUT);

  Serial.begin(9600);
}

void loop() {

  //vals = pulseIn(Speed, HIGH);
  //valt = pulseIn(turn, HIGH);

  //*
  vals1 = pulseIn(Speed, HIGH);
  vals2 = pulseIn(Speed, HIGH);
  vals3 = pulseIn(Speed, HIGH);
  vals4 = pulseIn(Speed, HIGH);
  vals5 = pulseIn(Speed, HIGH);
  vals = (vals1 + vals2 + vals3 + vals4 + vals5) / 5;

  valt1 = pulseIn(turn, HIGH);
  valt2 = pulseIn(turn, HIGH);
  valt3 = pulseIn(turn, HIGH);
  valt4 = pulseIn(turn, HIGH);
  valt5 = pulseIn(turn, HIGH);
  valt = (valt1 + valt2 + valt3 + valt4 + valt5) / 5;
  //*/
  vald1 = pulseIn(direc, HIGH);
  vald2 = pulseIn(direc, HIGH);
  vald3 = pulseIn(direc, HIGH);
  vald4 = pulseIn(direc, HIGH);
  vald5 = pulseIn(direc, HIGH);
  vald = (vald1 + vald2 + vald3 + vald4 + vald5) / 5;

  Serial.println(vald);

  vals = map(vals, 1000, 1830, 0, 250);
  valt = map(valt, 1235, 1744, -120, 120);
  vald = map(vald, 1860, 1030, -50, 50);

  //Serial.println(valt);




  if (vals > 30) {

    if (vald < 30 ) {

      if (vald > -30) {
        analogWrite(pwma, 0);
        analogWrite(pwmb, 0);

        digitalWrite(dira, LOW);
        digitalWrite(dirb, LOW);
      }
      if (vald < -30) {

        if (valt < 0) {

          mot2 = vals;
          mot1 = vals;
          if (valt < -30) {
            mot1 = map(100 * (-valt / 120.0), 25, 105, vals, 0) ;
            mot2 = vals;
          }
        }

        if (valt > 0) {
          mot2 = vals;
          mot1 = vals;
          if (valt > 30) {
            mot2 = map(100 * (valt / 120.0), 25, 105, vals, 0) ;
            mot1 = vals;
          }
        }
        //Serial.println(mot2);

        digitalWrite(dira, HIGH);
        digitalWrite(dirb, HIGH);

        analogWrite(pwma, mot1);
        analogWrite(pwmb, mot2);
      }
    }

    if (vald > -30 ) {
      if (vald < 30) {
        analogWrite(pwma, 0);
        analogWrite(pwmb, 0);

        digitalWrite(dira, LOW);
        digitalWrite(dirb, LOW);
      }
      if (vald > 30) {

        if (valt < 0) {

          mot2 = vals;
          mot1 = vals;
          if (valt < -30) {
            mot2 = map(100 * (-valt / 120.0), 25, 105, vals, 0) ;
            mot1 = vals;
          }
        }

        if (valt > 0) {
          mot2 = vals;
          mot1 = vals;
          if (valt > 30) {
            mot1 = map(100 * (valt / 120.0), 25, 105, vals, 0) ;
            mot2 = vals;
          }
        }
        //Serial.println(mot2);

        digitalWrite(dira, LOW);
        digitalWrite(dirb, LOW);

        analogWrite(pwma, mot1);
        analogWrite(pwmb, mot2);
      }
    }
  }

  else if (vals < 30) {
    analogWrite(pwma, 0);
    analogWrite(pwmb, 0);

  }

}



/*/
  if (vals > 30) {

    if (vald > 30 ) {

      if (valt < 0) {

        mot2 = vals;
        mot1 = vals;
        if (valt < -30) {
          mot2 = map(100 * (-valt / 120.0), 25, 105, vals, 0) ;
          mot1 = vals;
        }
      }

      if (valt > 0) {
        mot2 = vals;
        mot1 = vals;
        if (valt > 30) {
          mot1 = map(100 * (valt / 120.0), 25, 105, vals, 0) ;
          mot2 = vals;
        }
      }
      //Serial.println(mot2);

      digitalWrite(dira, LOW);
      digitalWrite(dirb, LOW);

      analogWrite(pwma, mot1);
      analogWrite(pwmb, mot2);
    }
    else if (vals < 30) {
      analogWrite(pwma, 0);
      analogWrite(pwmb, 0);

    }


  }
}
/*/
/*/
if (vald < 0) {


  if (vald < -30) {

    if (valt < 0) {

      mot2 = -vals;
      mot1 = -vals;
      if (valt < -30) {
        mot2 = map(100 * (-valt / 120.0), 25, 105, -vals, 0) ;
        mot1 = -vals;
      }
    }

    if (valt > 0) {
      mot2 = -vals;
      mot1 = -vals;
      if (valt > 30) {
        mot1 = map(100 * (valt / 120.0), 25, 105, -vals, 0) ;
        mot2 = -vals;
      }
    }
    //Serial.println(mot2);

    digitalWrite(dira, HIGH);
    digitalWrite(dirb, HIGH);

    //analogWrite(pwma, mot1);
    //analogWrite(pwmb, mot2);
  }
  else if (vals > -30) {
    analogWrite(pwma, 0);
    analogWrite(pwmb, 0);
  }
}
}
/*/
