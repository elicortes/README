int pon=0;
int boton=6;
int led1=1;
int led2=2;
int led3=3;
int led4=4;
int led5=5;



void setup() {
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  pinMode(led5,OUTPUT);
  pinMode(boton, INPUT);
  
}
void loop() {
  pon=analogRead(A0);
if(digitalRead(boton)==LOW) {
  digitalWrite(led1,LOW);
digitalWrite(led5,LOW);  
delay(pon);
digitalWrite(led1,HIGH);
digitalWrite(led5,HIGH);

for(int ciclo=0; ciclo<2;ciclo++){
   delay(pon);
  digitalWrite(led1,HIGH);
  delay(pon);
  digitalWrite(led1,LOW);
  } 

for(int ciclo=0; ciclo<2;ciclo++){
   delay(pon);
  digitalWrite(led2,HIGH);
  delay(pon);
  digitalWrite(led2,LOW);
digitalWrite(led1,LOW);

  }
    digitalWrite(led5,LOW);
    digitalWrite(led4,HIGH);
    digitalWrite(led3,HIGH);
    delay(pon);
     digitalWrite(led4,LOW);
    digitalWrite(led3,LOW);
    
}else {
  digitalWrite(led1,LOW);
digitalWrite(led5,LOW);  
delay(pon);
digitalWrite(led1,HIGH);
digitalWrite(led5,HIGH);

for(int ciclo=0; ciclo<2;ciclo++){
   delay(pon);
  digitalWrite(led1,HIGH);
  delay(pon);
  digitalWrite(led1,LOW);
  } 

for(int ciclo=0; ciclo<2;ciclo++){
   delay(pon);
  digitalWrite(led2,HIGH);
  delay(pon);
  digitalWrite(led2,LOW);
digitalWrite(led1,LOW);

  }
    digitalWrite(led5,LOW);
    digitalWrite(led4,HIGH);
    digitalWrite(led3,HIGH);
    delay(pon);
     digitalWrite(led4,LOW);
    digitalWrite(led3,LOW);
    
  }



  

}
