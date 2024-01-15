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

void setup(){}

void loop(){
coin();
lcd();
control();
}

void control(){
if(digitalRead(coinresetpin) == HIGH){
euro1 = 0;
euro2 = 0;
}
if(digitalRead(kistenaddpin) == HIGH){
kisten++;
}
}

void coin(){
if(digitalRead(coinpin) == HIGH){
euro1++;
output();
}
}

void output(){
if(euro2 >= euro1){
motor();
euro2++;
}
}

void motor(){
if(digitalRead(Sens1) == HIGH){
  
while(digitalRead(Sens2) == LOW){
digitalWrite(motorpin, HIGH); }

}
else{
digitalWrite(motorpin, LOW); 
}
}

void lcd(){
/*
serial.Println("Temp:" temp);
serial.Println("Humid:" humid);
*/
}
