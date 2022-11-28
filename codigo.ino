#include <Wire.h>
#include <LiquidCrystal_I2C.h>


#include <Servo.h>
#include <Ultrasonic.h>

#define pinMotor 9
#define pinBomba 8

#define ledvd 10
#define ledvm 11
#define pino_echo 5
#define pino_trigger 6
 
Servo servo;

LiquidCrystal_I2C lcd(0x27, 2,1,0,4,5,6,7,3, POSITIVE);
Ultrasonic ultrasonic(pino_trigger, pino_echo);

void setup (){
 
  pinMode(pinMotor, OUTPUT);
  pinMode(pinBomba, OUTPUT);

  Serial.begin(9600);
  Serial.print("Lendo dados do sensor...");
  servo.attach(12);
  lcd.begin (20,4);
  lcd.clear();
  lcd.setCursor(0,0);
}

void loop() {

  float cm;
  long microsec = ultrasonic.timing();
      lcd.clear();
  lcd.setCursor(4, 2);
  lcd.print("GhostBusters");

  cm = ultrasonic.convert(microsec, Ultrasonic::CM);
  Serial.print("distancia em cm:");
  Serial.println(cm);
  delay(150);
 
 if(cmMsec >= 60){
    digitalWrite(pinMotor, LOW);
    delay(700);
    digitalWrite(pinMotor, HIGH);
    delay(100);
    digitalWrite(pinBomba, LOW);
    servo.write(110);
    delay(100);
    servo.write(70);
    delay(2000);
    digitalWrite(pinBomba, HIGH);
    servo.write(90);
    delay(200);
  }else{
    digitalWrite(pinMotor, HIGH);
    digitalWrite(pinBomba, HIGH);
    servo.write(90);
   
  }
