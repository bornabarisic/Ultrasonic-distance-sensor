int Trig = 3;
int Echo = 2;
int izlaz = 11;
int i = 0;
int j = 0;
float t;
float s;
float v = 33000.; // brzina zvuka u cm/s
void setup(){
  pinMode(Trig, OUTPUT);
  pinMode(Echo, INPUT);
  Serial.begin(9600);
}
void loop(){
  // davanjem impulsa od 10us na Trig pin,odašiljemo signal
  digitalWrite(Trig, LOW);
  delayMicroseconds(20);
  digitalWrite(Trig, HIGH);
  delayMicroseconds(20);
  digitalWrite(Trig, LOW);
  // očitavanje vremena iz Echo pina na Rise-ing edge
  t = pulseIn(Echo,HIGH); 
 
  // konverzija iz mikrosekunde u sekundu
  t = t/1000000.;
  // računanje udaljenosti, rezultat u cm
  s = v*t;
  s = s/2.;
  // postavaljanje delay-a kako bi se ocitavao rezultat svaku sekundu
  Serial.print("Udaljenost je:");
  Serial.print(s);
  Serial.println("cm");
  delay(100);   
  
  if((s<200.)&(s>100.)){
    i = 0;
    while(i<2){
      digitalWrite(izlaz, HIGH);
      delay(750);
      digitalWrite(izlaz,LOW);
      delay(750);
      i++;
      j = 0;
    }
  }else if((s<100.)&(s>50.)){
    j = 0;
    while(j<3){
      digitalWrite(izlaz, HIGH);
      delay(300);
      digitalWrite(izlaz,LOW);
      delay(300); 
      j++;
      i=0;
    }
  }else if(s<50.){
    digitalWrite(izlaz, HIGH);
    delay(100);
    digitalWrite(izlaz,LOW);
    delay(100);
    i = 0;
    j = 0;
  }else{
    digitalWrite(izlaz,LOW);
    i = 0;
    j = 0;
  }
}
