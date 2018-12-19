#define black 7
#define white 6
#define trig 8
#define echo 9

long duration,cm;

void dist(){
  digitalWrite(trig, LOW);

delayMicroseconds(1);

digitalWrite(trig, HIGH);

delayMicroseconds(8);

digitalWrite(trig, LOW);

duration = pulseIn(echo, HIGH);
cm = duration/29/2;
}


void forwardRight(){
  
  digitalWrite(2,HIGH);
  digitalWrite(3,LOW);
  
}
void forwardLeft(){
  
  digitalWrite(4,HIGH);
  digitalWrite(5,LOW );
  
}
void backwardRight(){
  
  digitalWrite(2,LOW);
  digitalWrite(3,HIGH);
}
void backwardLeft(){
  
  digitalWrite(4,LOW);
  digitalWrite(5,HIGH);  
}
void stopmov(){
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);   
}
void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  dist();

while (((digitalRead(white)==LOW) && (digitalRead(black)==LOW)) || cm<15){
   stopmov();
   dist();
   Serial.println(1);
   Serial.println(cm);
   
}
while (!((digitalRead(white)==LOW) && (digitalRead(black)==LOW )) && cm>=15){
  Serial.println(2);
  while (digitalRead(white)==HIGH && (digitalRead(black)==LOW && cm>=15)){
    forwardRight();
    forwardLeft();
    dist();
    Serial.println(3);
    Serial.println(cm);
    
  }
  while(digitalRead(white)==LOW && digitalRead(black)==HIGH && cm>=15){
    backwardRight();
    forwardLeft();
    dist();
    Serial.println(4);
    Serial.println(cm);
  }
  while(digitalRead(white)==HIGH && digitalRead(black)==HIGH && cm>=15){
    backwardLeft();
    forwardRight();
    dist();
    Serial.println(5);
    Serial.println(cm);
  }

/*
  while(digitalRead(white)==LOW){
    backwardRight();
  }
  forwardRight();
  while(digitalRead(black)==HIGH){
    backwardLeft();
  }
  forwardLeft();*/

  dist();
}

}
