// 릴레이모듈, 수위센서, ph센서
#include <SoftwareSerial.h>
 
#define BT_RXD 2 // RX(초록색)블로그에 8
#define BT_TXD 1 // TX(노란색)블로그에 7 !
SoftwareSerial bluetooth(BT_RXD, BT_TXD);

float calibration = 0.00; //change this value to calibrate
const int analogInPin = A5; //PH센서 (검은색)
int water_pin = A0;         // 수위센서(기존_갈색)
int water_pin1 = A1;        // 수위센서(새로운_흰색)
int sensorValue = 0; 

//릴레이 모듈
int relay1 = 7; // 새로운(파란색)
int relay2 = 8; // 기존(빨간색)

unsigned long int avgValue; 
float b;
int buf[10],temp;

void setup(){
  Serial.begin(9600);
  bluetooth.begin(9600);
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
}

void loop(){

   for(int i=0;i<10;i++) 
 { 
  buf[i]=analogRead(analogInPin);
  delay(10);
 }
 for(int i=0;i<9;i++)
 {
  for(int j=i+1;j<10;j++)
  {
   if(buf[i]>buf[j])
   {
    temp=buf[i];
    buf[i]=buf[j];
    buf[j]=temp;
   }
  }
 }
 avgValue=0;
 for(int i=2;i<8;i++)
 avgValue+=buf[i];
 float pHVol=(float)avgValue*5.0/1024/6;
 float phValue = -5.70 * pHVol + 21.34;
  int val = digitalRead(A0);
  int vall = digitalRead(A1);

  if(val > 0 && vall > 0) {
      Serial.println("CLOSE");
      Serial.println(phValue);
      digitalWrite(relay1, LOW); //펌프
      digitalWrite(relay2, HIGH); //솔밸브
      Serial.println("펌프 끔, 솔밸브 ON");
      //delay(500);
       if(phValue >= 7.0){
          Serial.println("PH[위험] 상태");
          Serial.write(bluetooth.read());
          delay(500);
          }
       if(phValue <= 6.9){
          Serial.println("PH[주의] 상태");
          Serial.write(bluetooth.read());
          delay(500);
          }
          Serial.println(phValue);
    }
    else{
      if(phValue >= 7.0){
          Serial.println("OPEN");
          Serial.println(phValue);
          Serial.println("PH[위험] 상태");
         digitalWrite(relay1, HIGH); //펌프
          digitalWrite(relay2, LOW);  //솔밸브
          Serial.println("펌프 작동, 솔밸브 OFF");
          Serial.write(bluetooth.read());
          delay(500);
     }
     if(phValue <= 6.9){
        Serial.println("PH[주의] 상태");
        digitalWrite(relay1, LOW); //펌프
        digitalWrite(relay2, LOW); //솔밸브
        Serial.println("펌프 OFF, 솔밸브 OFF");
        Serial.write(bluetooth.read());
        delay(500);
      }
   }
}
