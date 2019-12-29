#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include<LiquidCrystal_I2C.h>
#include <dht.h>
#define BLYNK_PRINT Serial
dht DHT;
LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3,POSITIVE);
char auth[] = "9f1accc018f94d14a3fefb797e02ab98";
char ssid[] = "note4";
char pass[] = "123456788";
void setup()
{
  Serial.begin(9600);
  pinMode(D4,INPUT);
  Blynk.begin(auth, ssid, pass);
  lcd.begin(16,2);
}

void loop()
{
  int a;
  Blynk.run();

  int d = DHT.read11(D4);

  lcd.setCursor(0,1);
  lcd.print("TEM:");
  lcd.print(d);
  Blynk.virtualWrite(V1,"TEMP:");
  Blynk.virtualWrite(V2,d);
}
