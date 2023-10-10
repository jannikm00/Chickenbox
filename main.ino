int euro1 = 0
int euro2 = 0
int kisten = 0
int coinpin = 2
int motorpin = 3
int coinresetpin = 4
int kistenaddpin = 5
float temp;
float humid;

void loop(){
coin();
lcd();
control();
}

void control(){
if(digitalRead(coinresetpin)) == HIGH{
euro1 = 0;
euro2 = 0;
}
if(digitalRead(kistenaddpin)) == HIGH{
kisten++;
}
}

void coin(){
if(digitalRead(coinpin)) == HIGH{
euro1++;
output();
}
}

void output(){
if(euro2 => euro1){
motor();
euro2++;
}
}

void motor(){
digitalWrite(motorpin, HIGH);
delay(1000);
digitalWrite(motorpin, LOW);
kisten--;
}

void lcd(){
/*
serial.Println("Temp:" temp);
serial.Println("Humid:" humid);
*/
}
