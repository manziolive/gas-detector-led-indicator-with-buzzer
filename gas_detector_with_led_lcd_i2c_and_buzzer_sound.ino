//Prateek
//www.prateeks.in

#include<LiquidCrystal_I2C.h>
#include<Wire.h>
#include <SoftwareSerial.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
SoftwareSerial mySerial(2, 3);
int speaker=8;
int gasValue = A0; 
int data = 0;
int Red = 6;
int Green = 7;
String msg;

char country_code[] = "+250"; // Country code
char ph[] = "0784405573 "; // owner's (receiver's) phone no.

void setup()
{
  randomSeed(analogRead(0));
  mySerial.begin(9600); // Setting the baud rate of GSM Module
  Serial.begin(9600); // Setting the baud rate of Serial Monitor (Arduino)
  lcd.begin();
  lcd.backlight();
  pinMode(speaker,OUTPUT);
  pinMode(gasValue, INPUT);
  pinMode(Red, OUTPUT);
  pinMode(Green, OUTPUT);
  lcd.print ("   WELCOME TO");
  lcd.setCursor(0, 1);
  lcd.print ("ELECTRONIC olive");
  delay(3000);
  lcd.clear();
  lcd.print (" Gas Leakage ");
  lcd.setCursor(0, 1);
  lcd.print (" Detector Alarm ");
  delay(3000);
  lcd.clear();
}

void loop()
{

  data = analogRead(gasValue);

  Serial.print("Gas Level: ");
  Serial.println(data);
  lcd.print ("Gas Scan is ON");
  lcd.setCursor(0, 1);
  lcd.print("Gas Level: ");
  lcd.print(data);
  delay(1000);

  if ( data > 80) //
  {
//    SendMessage();
    Serial.print("Gas detect alarm");
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(" Gas Leakage");
    lcd.setCursor(0, 1);
    lcd.print(" SMS Sent");
    delay(1000);
    digitalWrite(Red, HIGH);
    digitalWrite(Green, LOW);
    digitalWrite(speaker,HIGH);

  }
  else
  {
    Serial.print("Gas Level Low");
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Gas Level Normal");
    digitalWrite(Red, LOW);
    digitalWrite(Green, HIGH);
    digitalWrite(speaker,LOW);
    delay(1000);
  }

  lcd.clear();
}

//void SendMessage(){
//Serial.print("I am in send ");
//Serial.println("Open Windows And Check Your Gas Cylinder");
//Serial.println(msg);
//mySerial.println("AT"); //Once the handshake test is successful, it will back to OK

  //mySerial.println("AT+CMGF=1"); // Configuring TEXT mode
 // updateSerial();
 //mySerial.println("AT+CMGS=\"0784405573\"");//change ZZ with country code and xxxxxxxxxxx with phone number to sms
  //updateSerial();
  //mySerial.print(msg); //text content
 // updateSerial();
  //mySerial.write(26);

 
//delay(1000);
 
 // Serial.println("I am in send");
 // mySerial.println("AT+CMGF=1"); //Sets the GSM Module in Text Mode
  //delay(1000); // Delay of 1000 milli seconds or 1 second
 // mySerial.println("AT+CMGS=\"+250784405573\"\r"); // Replace x with mobile number
//  delay(1000);
//  mySerial.println("Hi Prateek Gas Detected plz Open Windows And Check Your Gas Cylinder");// The SMS text you want to send
//  delay(100);
//  mySerial.println((char)26);// ASCII code of CTRL+Z
//  delay(1000);
//}
