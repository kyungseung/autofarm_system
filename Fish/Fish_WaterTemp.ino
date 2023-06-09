//수온센서
#include <OneWire.h>
 
int DS18S20_Pin = 2;                             //온도센서를 2번 핀으로 연결
int red = 11;                                    //빨간색led를 11번 핀으로 연결
int blue = 10;                                   //파란색led를 10번 핀으로 연결
 
OneWire ds(DS18S20_Pin);                         //2번 핀과 연결되 OneWire 객체 생성
 
void setup(){
  Serial.begin(9600);                           // 시리얼 통신, 속도는 9600
  pinMode(red, OUTPUT);                         
  pinMode(blue, OUTPUT);
} 
 
void loop(){
  float temperature = getTemp();                 //온도 측정 후 변수에 저장
  Serial.println(temperature);
  if(temperature < 23){                          //온도가 24도 이하일 때, 파란색 LED 점등
    digitalWrite(red, LOW);                      
    digitalWrite(blue, HIGH);
    delay(500);
  }
  else{                                          //온도가 24도 이상일 때, 빨간색 LED 점등
    digitalWrite(red, HIGH);
    digitalWrite(blue, LOW);
    delay(500);
  }
}
 
float getTemp(){                                   //온도 측정 후 반환하는 함수
 byte data[12];
 byte addr[8];
 if ( !ds.search(addr)) {
   ds.reset_search();
   return -1000;
 }
 if ( OneWire::crc8( addr, 7) != addr[7]) {
   Serial.println("CRC is not valid!");
   return -1000;
 }
 if ( addr[0] != 0x10 && addr[0] != 0x28) {
   Serial.print("Device is not recognized");
   return -1000;
 }
 ds.reset();
 ds.select(addr);
 ds.write(0x44,1);                                   
 byte present = ds.reset();
 ds.select(addr);  
 ds.write(0xBE); 
 
 for (int i = 0; i < 9; i++) { 
  data[i] = ds.read();                                                          
 }
 
 ds.reset_search(); 
 byte MSB = data[1];
 byte LSB = data[0];
 float tempRead = ((MSB << 8) | LSB); 
 float TemperatureSum = tempRead / 16; 
 return TemperatureSum;                                                                    
}
