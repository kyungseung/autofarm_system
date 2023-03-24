// 먹이통 제어(on/off)
//블루투스 모듈(HC-06)을 이용한 서보모터(SG90) 제어
#include <SoftwareSerial.h> //시리얼 통신 라이브러리 호출
#include "Servo.h" //서보 라이브러리
#include <DS1302.h> //RTC
 
int blueTx=2;   //Tx (블투 보내는핀 설정)
int blueRx=3;   //Rx (블투 받는핀 설정)
SoftwareSerial mySerial(blueTx, blueRx);  //시리얼 통신을 위한 객체선언
String myString=""; //받는 문자열

Servo myservo; //서보객체
int pos = 0;   // variable to store the servo position

#define SCK_PIN 4 // 보드의 CLK 핀 입력
#define IO_PIN 5 // 보드의 DAT 핀 입력
#define RESET_PIN 6 // RST 핀 입력
DS1302 myDS1302(RESET_PIN, IO_PIN, SCK_PIN);
 
void setup() {
  myDS1302.halt(false);
  myDS1302.writeProtect(true);
  Serial.begin(9600);   //시리얼모니터 
  while(!Serial){;}
  delay(500);
  mySerial.begin(9600); //블루투스 시리얼 개방
  pinMode(13,OUTPUT);   //Pin 13을 OUTPUT으로 설정 (LED ON/OFF)
  myservo.attach(12);   //서보 시그널 핀설정
  myservo.write(0);     //서보 초기각도 0도 설정
}
 
void loop() {
  while(mySerial.available())  //mySerial 값이 있으면
  {
    char myChar = (char)mySerial.read();  //mySerial int형식의 값을 char형식으로 변환
    myString+=myChar;   //수신되는 문자열을 myString에 모두 붙임 (1바이트씩 전송되는 것을 모두 붙임)
    delay(5);           //수신 문자열 끊김 방지
  }
  
  if(!myString.equals(""))  //myString 값이 있다면
  {
    Serial.println("input value: "+myString); //시리얼모니터에 myString값 출력
    mySerial.println(myString);
    
    if(myString=="on")  //myString 값이 'on' 이라면
    {
      digitalWrite(13, HIGH); //LED ON
      for (pos = 0; pos <= 180; pos += 1) {
        myservo.write(pos);
        delay(15);
        }
      delay(2000);
      mySerial.print(myDS1302.getDateStr(2,1,'-')); //날짜 불러오기 dd-mm-yyyy 형식
      mySerial.print(" / ");
      mySerial.print(myDS1302.getTimeStr()); // 시간 불러오기 hh:mm:ss 형
      mySerial.println("");
      delay(1000);
      
    } else if(myString=="off") {
      digitalWrite(13, LOW);  //LED OFF
      for (pos = 180; pos >= 0; pos -= 1) {
        myservo.write(pos);
        delay(15);
        }
      mySerial.print(myDS1302.getDateStr(2,1,'-')); //날짜 불러오기 dd-mm-yyyy 형식
      mySerial.print(" / ");
      mySerial.print(myDS1302.getTimeStr()); // 시간 불러오기 hh:mm:ss 형
      mySerial.println("");
      delay(1000);
        }
        myString="";  //myString 변수값 초기화
        }
        }
