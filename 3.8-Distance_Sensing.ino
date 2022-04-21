int Echopin=A0;
int TRIGpin=A1;
int Green=9;
int Yellow=10;
int Red=11;

long duriation;
int distance;

void setup() {
  pinMode(TRIGpin, OUTPUT);
  pinMode(Echopin, INPUT);
  pinMode(Green, OUTPUT);
  pinMode(Yellow,OUTPUT);
  pinMode(Red, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(TRIGpin,LOW);
  delay(2);
  digitalWrite(TRIGpin,HIGH);
  delay(10);
  digitalWrite(TRIGpin,LOW);
  duriation=pulseIn(Echopin, HIGH);
  distance=duriation*0.034/2;
  Serial.print("distance: ");
  Serial.println(distance);
  
  if (distance<=10) {
  digitalWrite(Green, LOW);
  digitalWrite(Yellow, LOW);
  digitalWrite(Red, HIGH);
  }
  else if (distance>10 && distance<32) {
  digitalWrite(Green, LOW);
  digitalWrite(Yellow, HIGH);
  digitalWrite(Red, LOW);
}
  else {
  digitalWrite(Green, HIGH);
  digitalWrite(Yellow, LOW);
  digitalWrite(Red, LOW);
  }
}
