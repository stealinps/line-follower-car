int pinLF=17;
int pinLR=16;
int pinRF=18;
int pinRR=19;


void setup() {
  pinMode(pinLF,OUTPUT);
  pinMode(pinLR,OUTPUT);
  pinMode(pinRF,OUTPUT);
  pinMode(pinRR,OUTPUT);
}

void loop() {
}

void right(int duration){
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
