int Pin = A0;
int state = 40;
int flag = 1;
int count = 0;
int tim = 0;
//int Led = 13;

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

void setup() {
  // put your setup code here, to run once:
pinMode(Pin, INPUT);
//pinMode(Led, OUTPUT);
Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:



val1=analogRead(Pin);
val2=analogRead(Pin);
val3=analogRead(Pin);
val4=analogRead(Pin);
val5=analogRead(Pin);
val6=analogRead(Pin);
val7=analogRead(Pin);
val8=analogRead(Pin);
val9=analogRead(Pin);
val10=analogRead(Pin);
val11=analogRead(Pin);
val12=analogRead(Pin);
val13=analogRead(Pin);
val14=analogRead(Pin);
val15=analogRead(Pin);
val16=analogRead(Pin);
val17=analogRead(Pin);
val18=analogRead(Pin);
val19=analogRead(Pin);
val20=analogRead(Pin);

state = (val1+val2+val3+val4+val5+val6+val7+val8+val9+val10+val11+val12+val13+val14+val15+val16+val17+val19+val20)/20;

Serial.println(state);


if (state > 70){
  if (flag == 1){

  count = count + 1;
  
  flag =0;
  tim = (millis()-tim)/1000;
  //Serial.println(count);
  tim = millis();
}
}
if(state < 70){
  if( flag == 0){
    flag = 1;
    
  }
  
}

}
