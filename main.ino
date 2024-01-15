int euro1 = 0;//Münze eingeworfen
int euro2 = 0;//Gesamt Münzen
int kisten = 0;
int coinpin = 2;
int motorpin = 3;
int Sens1 = 6; //Grundstellung
int Sens2 = 7; //Endtaster
int coinresetpin = 4;
int kistenaddpin = 5;
float temp;
float humid;

void setup(){
Serial.begin(9600);
}

void loop(){
coin();
lcd();
control();
  motoroff();
  Serial.write("coins");
  Serial.println(euro1);
  Serial.write("kisten");
  Serial.println(kisten);
 Serial.write("Grundstellung");
  Serial.println(digitalRead(Sens1));
  Serial.write("Endstellung");
  Serial.println(digitalRead(Sens2));
  
}

void control(){
if(digitalRead(coinresetpin) == HIGH){
euro1 = 0;
euro2 = 0;
}
if(digitalRead(kistenaddpin) == HIGH){
 delay(1000);
kisten++;
}
}

void coin(){
if(digitalRead(coinpin) == HIGH){
  delay(1000);
euro1++;
output();
}
}

void output(){
  if(kisten >= 1){
   
    motor();}
euro2++;
}


void motor(){
if(digitalRead(Sens1) == HIGH){
  
if(digitalRead(Sens2) == LOW){
digitalWrite(motorpin, HIGH);
  kisten--;
}
}
}

void motoroff(){
  if(digitalRead(Sens2) == HIGH){
  digitalWrite(motorpin, LOW);
  }
   }
void lcd(){
/*
serial.Println("Temp:" temp);
serial.Println("Humid:" humid);
*/
}
