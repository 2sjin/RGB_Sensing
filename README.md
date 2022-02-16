# pH 분석을 위한 RGB 컬러센서<br>(RGB Color Sensor for pH Analysis)
아두이노의 RGB 컬러 센서를 활용하여 pH(수소 이온 농도)를 분석하기 위한 장치 제작.
- 기여자: 이승진, 이영섭

## 목적
- pH 분석을 위해 만능지시약 또는 리트머스종이에 액체시약을 넣어 관능적으로 분석하는데, 이는 사람마다 인식하는 정도가 다르기 때문에, 오차가 존재함
- 오차를 제거하기 위해 기계가 직접적으로 그 색을 분석하여 pH를 찾을 필요가 있음
- 본 프로젝트는 사람으로 인해 발생하는 오차를 줄이고 pH를 정확하게 분석하기 위함임

## 사용 부품
- 아두이노 라즈베리파이 RGB 컬러센서 색깔감지 TCS34725 STM32 정방형(가격 : 3,200원)
- 아두이노 우노 케이스 블랙 투명(가격 : 1,360원)
- 아두이노 우노 Arduino UNO R3 CH340 CH341모델(가격 : 6,400원)
- 아두이노 LCD1602+I2C IIC/I2C 황록색 어댑터 납땜(가격 : 3,600원)
> 총 금액 : 14,560원

## 기능
- pH분석
  - 색깔에 따라 pH를 분석을 함, pH분석기준은 WR pH test paper, BTB pH test pape로 한다.
> ![image](https://user-images.githubusercontent.com/91407433/154213268-4d95cca2-5827-4417-ad91-c7ee03305fd5.png)
> ![image](https://user-images.githubusercontent.com/91407433/154213272-716bc190-d772-4205-98cb-8370a4f2aa92.png)

## 구현
![image](https://user-images.githubusercontent.com/91407433/154213218-c5810225-e27e-4efb-9b9a-9ce02dd602b5.png)
![image](https://user-images.githubusercontent.com/91407433/154213220-e08161c6-f104-456c-9839-3fa997dbbb2c.png)

## 개선 방향
- 실제 pH test paper를 구매 후 기기교정이 필요
  - pH 계산식이 기존에 나와있는 정석적인 식을 가져왔기 때문에, 실제로 다른 환경에서는 다른 pH가 나올 수 있기 때문에 기기오차가 발생할 수 있음
  - ● 이러한 기기오차를 줄이기 위해 실제로 pH test paper를 구매하여 식을 세우고 기기에 대한 교정이 필요함
