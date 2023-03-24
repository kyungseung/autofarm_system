// 토양습도, 조도센서(+led), 온습도 + 쿨링팬 예정
#include <Adafruit_NeoPixel.h>
#include <SoftwareSerial.h>
#include <DHT11.h> //라이브러리 불러옴

SoftwareSerial bluetooth(8, 9); // 8번 TX, 9번 RX

#define NUMPIXELS      20 
Adafruit_NeoPixel pixels1 = Adafruit_NeoPixel(NUMPIXELS, 7, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels2 = Adafruit_NeoPixel(NUMPIXELS, 5, NEO_GRB + NEO_KHZ800);

int delayval = 500; // delay for half a second

// 토양습도 센서
int sensorA0 = 0;
int sensorA2 = 0;

// 조도센서
int sensorA1 = 0;
int sensorA3 = 0;

// 온습도 센서
int pin=2; //Signal 이 연결된 아두이노의 핀번호
DHT11 dht11(pin);
int err;
float temp, humi;

// 쿨링팬
int cool1 = 0;
int cool2 = 0;


void setup() {
  
  Serial.begin(9600);
  pixels1.begin(); //네오픽셀 시작
  pixels2.begin(); //네오픽셀 시작
  bluetooth.begin(9600); // 블루투스 시작
 

}
void loop() {


  // 토양습도센서
  sensorA0 = analogRead(A0);
  sensorA2 = analogRead(A2);

  // 조도센서
  sensorA1 = analogRead(A1);
  sensorA3 = analogRead(A3);

  // 쿨링팬
  cool1 = analogRead(A4);
  cool2 = analogRead(A5);

  // 0(습함) ~ 1023(건조)값 출력
  bluetooth.print("토양습도 A0 = ");
  bluetooth.print(sensorA0);   
  bluetooth.print("\t");

  bluetooth.print("토양습도 A2 =");
  bluetooth.print(sensorA2);  
  bluetooth.print("\n");

  bluetooth.print("조도 A1 = ");
  bluetooth.print(sensorA1);  
  bluetooth.print("\t");

  bluetooth.print("조도 A3 = ");
  bluetooth.print(sensorA3);  
  bluetooth.print("\n");

  // 공기 - 온습도센서
  if((err=dht11.read(humi, temp))==0) //온도, 습도 읽어와서 표시
  {
  bluetooth.print("현재 기온:");
  bluetooth.print(temp);
  bluetooth.print("\t");
  
  bluetooth.print("현재 습도:");
  bluetooth.print(humi);
  bluetooth.print("\n");
  bluetooth.print("------------------------------------\n");

  digitalWrite(cool1, HIGH);
  digitalWrite(cool2, HIGH);
  }
  
  else //에러일 경우 처리
  {
  bluetooth.println();
  bluetooth.print("Error No :");
  bluetooth.print(err);
  bluetooth.println();
  }
  
  delay(1000); //1초마다 측정
  
  //식물생장통 1층 LED제어 (조도 + LED)
  if(sensorA1 >= 0){
    for(int i=0; i<NUMPIXELS; i++){
      pixels1.setPixelColor(i, pixels1.Color(150,0,150));
      pixels1.show();
    }
    
    bluetooth.print("생장실 1층 - LED ON \n");
  }

  else{
    for(int i=0; i<NUMPIXELS; i++){
      pixels1.setPixelColor(i, pixels1.Color(0,0,0));
      pixels1.show();
    }

    bluetooth.print("생장실 1층 - LED OFF \n");
  }

  //식물생장통 2층 LED제어 (조도 + LED)
  if(sensorA3 >= 0){
    for(int i=0; i<NUMPIXELS; i++){
      pixels2.setPixelColor(i, pixels1.Color(150,0,150));
      pixels2.show();
    }

    bluetooth.print("생장실 2층 - LED ON \n");
    bluetooth.print("\n");
    
  }

  else {
    for(int i=0; i<NUMPIXELS; i++){
      pixels2.setPixelColor(i, pixels1.Color(0,0,0));
      pixels2.show();
    }

    bluetooth.print("생장실 2층 - LED OFF \n");
    bluetooth.print("\n");
  }
 Serial.print("\n");

 


  
 

 
}
