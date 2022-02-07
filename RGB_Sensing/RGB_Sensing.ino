
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "Adafruit_TCS34725.h"
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X); // Adafruit_TCS34725라이브러리 사용을 위한 객체 생성
LiquidCrystal_I2C lcd(0x27,16,2); 

void setup() {
  Serial.begin(9600); // 시리얼 통신 시작, 속도는 9600

  lcd.init();  // LCD초기 설정             
  lcd.backlight(); // LCD초기 설정

  if (tcs.begin()) { // tcs34725센서가 연결되어 인식했을 경우
    Serial.println("Found sensor");
  }
  else { // tcs34725센서가 연경되지 않아 인식하지 못했을 경우
    Serial.println("No TCS34725 found ... check your connections");
    while (1); // 중단
  }
}

void loop() {
  uint16_t clear, red, green, blue; // unit16_t = unsigned short int 타입
  //tcs.setInterrupt(false); // led 켜기 turn on LED delay(60);
  tcs.getRawData(&red, &green, &blue, &clear); // 색상 감지 센서에서 데이터 값 받아오기
  //tcs.setInterrupt(true); // turn off LED
  
  int r = map(red, 0, 21504, 0, 1025); // 색상 감지 센서에서 받아온 빨간색 데이터값을 3색led에서 사용할수 있도록 수치 변경
  int g = map(green, 0, 21504, 0, 1025); // 녹색
  int b = map(blue, 0, 21504, 0, 1025); // 파란색 

  printRGBOnSerial(r, g, b);
  printRGBOnLCD(r, g, b);

  delay(500);
}

void printRGBOnSerial(int r, int g, int b) {
  Serial.print("\tR:\t");
  Serial.print(r); // 시리얼 모니터에 3색 led에 출력중인 붉은색 값 출력
  Serial.print("\tG:\t");
  Serial.print(g); //녹색 값 출력
  Serial.print("\tB:\t");
  Serial.println(b); // 파란색 값 출력 }  
}

void printRGBOnLCD(int r, int g, int b) {
  lcd.clear();

  lcd.setCursor(0,0);
  lcd.print("R");
  lcd.setCursor(4,0);
  lcd.print("G");
  lcd.setCursor(8,0);
  lcd.print("B");

  lcd.setCursor(0,1);
  lcd.print(r);
  lcd.setCursor(4,1);
  lcd.print(g);
  lcd.setCursor(8,1);
  lcd.print(b);
}
