#include <Adafruit_LiquidCrystal.h>
Adafruit_LiquidCrystal lcd_1(0);
int euro1 = 0;  //Münze eingeworfen
int euro2 = 0;  //Gesamt Münzen
int kisten = 0;
int coinpin = 2;
int motorpin = 3;
int Sens1 = 6;  //Grundstellung
int Sens2 = 7;  //Endtaster
int coinresetpin = 4;
int kistenaddpin = 5;
float temp;
float humid;

void setup() {
  Serial.begin(9600);
  lcd_1.begin(16, 2);
  lcdi2c();
}

void loop() {
  coin();
  control();
  motoroff();
}

void control() {
  if (digitalRead(coinresetpin) == HIGH) {
    euro1 = 0;
    euro2 = 0;
    lcdi2c();
  }
  if (digitalRead(kistenaddpin) == HIGH) {
    delay(0);
    kisten++;
    lcd_1.clear();
    lcdi2c();
  }
}

void coin() {
  if (digitalRead(coinpin) == HIGH) {
    delay(0);
    euro1++;
    euro2++;
    lcdi2c();
    if (euro1 >= 3) {
      output();
    }
  }
}

void output() {
  if (kisten >= 1) {
    motor();
  }
  lcdi2c();
}


void motor() {
  if (digitalRead(Sens1) == HIGH) {

    if (digitalRead(Sens2) == LOW) {
      digitalWrite(motorpin, HIGH);
      kisten--;
      lcd_1.clear();
      euro1 = euro1 - 3;
      lcdi2c();
    }
  }
}

void motoroff() {
  if (digitalRead(Sens2) == HIGH) {
    digitalWrite(motorpin, LOW);
  }
}

void lcdi2c() {

  lcd_1.setCursor(0, 0);
  lcd_1.print("Kisten:");
  lcd_1.setCursor(7, 0);
  lcd_1.print(kisten);

  if (kisten < 1) {
    lcd_1.setCursor(9, 0);
    lcd_1.print("!!!");
  }

  lcd_1.setCursor(0, 1);
  lcd_1.print("Kredit:");
  lcd_1.setCursor(7, 1);
  lcd_1.print(euro1);
  lcd_1.setCursor(14, 1);
  lcd_1.print(euro2);
}
