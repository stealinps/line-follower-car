int pinLF=17;
int pinLR=16;
int pinRF=18;
int pinRR=19;

int echo=34;
int trig=5;


void setup() {
  Serial.begin(115200);
  pinMode(pinLF,OUTPUT);
  pinMode(pinLR,OUTPUT);
  pinMode(pinRF,OUTPUT);
  pinMode(pinRR,OUTPUT);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
}

void loop() {
  int distance=ultrasonic();
  if (distance<10){
    stop();
    delay(100);
    right();
    delay(100);
  }
  else{
    forward();
    delay(100);
  }
}

void right(){
  digitalWrite(pinLF,LOW);
  digitalWrite(pinLR,HIGH);
  digitalWrite(pinRF,HIGH);
  digitalWrite(pinRR,LOW);
}
void left(){
  digitalWrite(pinLF,HIGH);
  digitalWrite(pinLR,LOW);
  digitalWrite(pinRF,LOW);
  digitalWrite(pinRR,HIGH);
}
void reverse(){
  digitalWrite(pinLF,LOW);
  digitalWrite(pinLR,HIGH);
  digitalWrite(pinRF,LOW);
  digitalWrite(pinRR,HIGH);
}
void forward(){
  digitalWrite(pinLF,HIGH);
  digitalWrite(pinLR,LOW);
  digitalWrite(pinRF,HIGH);
  digitalWrite(pinRR,LOW);
}
void stop(){
  digitalWrite(pinLF,LOW);
  digitalWrite(pinLR,LOW);
  digitalWrite(pinRF,LOW);
  digitalWrite(pinRR,LOW);
}
void test(){
  forward();
  delay(1000);
  reverse();
  delay(1000);
  right();
  delay(1000);
  left();
  delay(1000);
  stop();
}
int ultrasonic(){
  long duration, cm;

  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  duration = pulseIn(echo, HIGH,30000);
  cm = microsecondsToCentimeters(duration);
  
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  delay(10);
  return cm;

}

long microsecondsToInches(long microseconds) {
  return microseconds / 74 / 2;
} 

long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2;
}
