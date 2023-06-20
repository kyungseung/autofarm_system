# autofarm
양식업을 이용한 농작물 재배
- 오토팜은 물고기 양어 기술과 농작물 수경재배 기술을 융·복합한 환경친화적인 기술인, 아쿠아포닉스의 단점을 기술적으로 보완한 시스템이다.
- 아쿠아포닉스 농법에 필요한 물의 순환, 온·습도 환경 설정을 여러 가지 센서를 통해 실시간 모니터링, 제어를 자동화하였다.

<br/>

- 참여인원 : 4명
- 작업기간 : 2021.03 ~ 2021.11
- 사용언어 : C++
- 사용SW : Arduino IDE, MIT APP INVENTOR

<br/>

## 기능
1. 사용자가 설정한 환경설정값에 따라 시스템 직접 제어
2. 사용자가 작물과 양식에 필요한 환경 값과 오차 범위 설정, 해당 오차 범위가 넘어가면 안전, 주의, 위험 단계에 따라 알림
3. 센서와 밸브를 이용한 자동 환수 기능
4. 여러 가지 센서를 이용한 실시간 모니터링 기능
5. 먹이 급여 기능

<br/>

## 자동 환수 알고리즘
![자동환수](https://github.com/kyungseung/autofarm_system/assets/81572693/138369ef-8f8e-4998-9f34-aa4edbef539f)

<br/>

## 시스템 시나리오
![image](https://github.com/kyungseung/autofarm_system/assets/81572693/dbf7d85f-f5bc-4e43-8ce8-a9e1d7ed9c88)
 - 상시 수중펌프와 솔레노이드 밸브를 작동 시키며, 농작물의 설치된 토양습도센서 값에 따라 수중펌프와 솔레노이드 밸브의 작동 여부를 판단한다. 부가적으로 조도가 낮아지면 LED를 켜고, 온습도가 높아지면 냉각 팬을 작동시킨다.

<br/>

## 최종실행
- 메인페이지
![메인페이지](https://github.com/kyungseung/autofarm_system/assets/81572693/a49d4272-f9b6-4eda-8b6e-5f82c6c750a7)


- 블루투스 설정
![블루투스](https://github.com/kyungseung/autofarm_system/assets/81572693/c87f7935-87c4-4c66-9a28-af542703033d)


- 양식장 모니터링
![양식장](https://github.com/kyungseung/autofarm_system/assets/81572693/c2e9b351-5960-4e83-a3ee-24640c4a40ec)
  + ph값이 일정 수준 이상일때
  ![양식장_ph알림](https://github.com/kyungseung/autofarm_system/assets/81572693/4950b1b2-fa22-4ac6-9a0a-79f46e747f4c)

<br/>

- 농작물 모니터링
![농작물](https://github.com/kyungseung/autofarm_system/assets/81572693/18d2fb9c-ca90-425a-ad17-800f86b71dea)
  + 토양습도가 건조할때
 ![농작물_토양습도](https://github.com/kyungseung/autofarm_system/assets/81572693/50ee06b6-6a8a-420f-8030-95cf458db898)

  + 조도량이 많을때
 ![농작물_조도](https://github.com/kyungseung/autofarm_system/assets/81572693/a7625b9c-5d4c-453c-a784-be8b9672ad9c)

  + 조도량이 적을때
![농작물_조도 적을때](https://github.com/kyungseung/autofarm_system/assets/81572693/4c3a5e99-e12c-41c5-8d71-15fe4c4ee875)


<br/>

- 양식장 먹이급여
![먹이급여](https://github.com/kyungseung/autofarm_system/assets/81572693/6f9db3fc-eaa0-40f6-a313-ddac11cd786b)


- 백과사전
![백과사전](https://github.com/kyungseung/autofarm_system/assets/81572693/34bd21d9-032e-4779-b751-1f22127665cc)

<br/>

- 오토팜 최종구조
![구조](https://github.com/kyungseung/autofarm_system/assets/81572693/25ff4261-651b-4a84-af3e-87a97b06c39d)



<br/>


## 수상경력
2021

[교내] 소셜벤처 혁신아이디어 경진대회 **장려상**

[교내] 한양여자대학교 창업아이디어 경진대회 **최우수상**

2021 이브와 공모전 **은상**

2021 한국정보처리학회 ICT멘토링 학술대회(ACK 2021) **최우수상**

<br/>

2022

제4회 전문대학재학생 창업창직창작 아이디어 경진대회 **장려상**
