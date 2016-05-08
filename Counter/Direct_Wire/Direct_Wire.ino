
int pwma = 3;
int pwmb = 11;
int on = A5;
int Speeda = 70;
int Speedb = 75;
int val;

void setup() {
  // put your setup code here, to run once:

pinMode(pwma, OUTPUT);
pinMode(pwmb, OUTPUT);
pinMode(on, INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
val = analogRead(on);
if (val < 1020) {
analogWrite(pwma, Speeda);
analogWrite(pwmb, 0);
Serial.println("turn");
}
if (val > 1020) {
analogWrite(pwma, Speeda);
analogWrite(pwmb, Speedb);
Serial.println("straight");
}
}
