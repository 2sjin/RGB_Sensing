//컬러센서로 pH측정
#include <Wire.h>//I2C
#include "Adafruit_TCS34725.h"//컬러센서 라이브러리 추가

#include <LiquidCrystal_I2C.h>     //LiquidCrystal 라이브러리 추가 
LiquidCrystal_I2C lcd(0x27, 16, 2);  //lcd 객체 선언

Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);

void setup() {
  //

  lcd.begin(); //LCD 사용 시작
  //PH
  for(int i=0; i<=2999; i++){
    lcd.setCursor(5, 0);    // 커서를 5, 0에 가져다 놓아라. (열, 행)
    lcd.print("pH");     // 5, 0에 Hi ^^를 출력해라.
  }

  //
  Serial.begin(9600);
  Serial.println("Color View Test!");

  if (tcs.begin()) {
    Serial.println("Found sensor");
  }
  else {
    Serial.println("No TCS34725 found ... check your connections");
    while (1); // halt!
  }
}

void loop() {
  //16RGB
  uint16_t clear, red, green, blue;

  tcs.getRawData(&clear, &red, &green, &blue);
  //delay(1000);//1000ms

  //RGB
  Serial.print("C:\t"); Serial.print(clear);
  Serial.print("\tR:\t"); Serial.print(red);
  Serial.print("\tG:\t"); Serial.print(green);
  Serial.print("\tB:\t"); Serial.print(blue);

  //
  uint32_t sum = clear;
  float r, g, b;
  r = red; r /= sum;
  g = green; g /= sum;
  b = blue; b /= sum;
  r *= 256; g *= 256; b *= 256;
  Serial.print("\t/");
  Serial.print("\tr:"); Serial.print((int)r);
  Serial.print("\tg:"); Serial.print((int)g);
  Serial.print("\tb:"); Serial.print((int)b);

  //pH
  float pH_r, pH_g, pH_b;
  int pH;
  //pH Function
  pH_r = 0.0000001216*r*r*r-0.0001876*r*r+0.1009*r-11.62;//r
  pH_g = 0.000000007332*g*g*g-0.00001259*g*g+0.01022*g+4.676;//g
  pH_b = 0.000000005716*b*b*b-0.00001896*b*b+0.02183*b-1.428;//b

  pH = (pH_r+pH_g+pH_b)*10/3;

  String VV = String(pH);
  //pH
  for(int i=0; i<=999; i++){
    lcd.setCursor(7, 0);    // 커서를 5, 0에 가져다 놓아라. (열, 행)
    lcd.print(VV.charAt(0));     // 5, 0에 Hi ^^를 출력해라.
    lcd.setCursor(8, 0);    // 커서를 5, 0에 가져다 놓아라. (열, 행)
    lcd.print(".");     // 5, 0에 Hi ^^를 출력해라.
    lcd.setCursor(9, 0);    // 커서를 5, 0에 가져다 놓아라. (열, 행)
    lcd.print(VV.charAt(1));     // 5, 0에 Hi ^^를 출력해라.
  }

  //pH
  Serial.print("\t/");
  Serial.print("\tpH_r:"); Serial.print((int)pH_r);
  Serial.print("\tpH_g:"); Serial.print((int)pH_g);
  Serial.print("\tpH_b:"); Serial.print((int)pH_b);
  Serial.print("\tpH:"); Serial.print(pH);
  Serial.println();
  delay(1000);
}
