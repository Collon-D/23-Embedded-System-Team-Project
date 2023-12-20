# 원격 제어 알람
라즈베리 파이를 이용한 알람 프로그램

### 목차
[0.프로젝트 소개](#%EF%B8%8F-프로젝트-소개) <br/>
[1.개발 기간](#-개발-기간) <br/>
[2.맴버 구성](#-맴버-구성) <br/>
[3.실행 방법](#-실행-방법) <br/>
[4.기능](#-기능) <br/>
[5.모듈](#-모듈) <br/>
[6.전체 시스템 구조](#-전체-시스템-구조) <br/>
[7.문제점 및 해결 방안](#-문제점-및-해결-방안) <br/>
[8.데모 영상](#-데모-영상) <br/>

## 🖥️ 프로젝트 소개
라즈베리 파이에 블루투스 모듈, 초음파 센서, 스피커를 연결하여 만든 알람 프로그램입니다.

<br/>

## 📆 개발 기간
* 23.12.02일 - 23.12.14일
![간트차트_최종](https://github.com/Collon-D/23-Embedded-System-Team-Project/assets/138470360/f357a190-7ab5-4c28-9ee8-4a201ac6741b)
<br/>

## 🧑‍🤝‍🧑 맴버 구성
| 학번 | 이름 | 역할 |
|--------|-----|-------------------------------------------------------------|
|20190325|김태현|〰️초음파 센서 쓰레드|
|20190558|배진열|🕢알람 쓰레드, 스피커 쓰레드|
|20190757|윤건우|➿코드 연결|
|20200225|김수빈|📲블루투스 쓰레드|
<br/>

## 🎮 실행 방법
- 컴파일
```bash
$ make
```
- 생성 파일 삭제
```bash
$ make clean
```
- 실행
```bash
$ ./Alarm
```
<br/>

## 📌 기능
### 블루투스 연결
- 프로그램을 실행시키고 스마트폰과 블루투스를 연결한다.
### 알람 설정
- 사용자가 양식에 맞게 시간을 입력한다.
- 양식에 맞는 값이 들어오면 해당 알람이 실행된다.
- 설정된 시간과 현재 시간이 같아지면 스피커와 초음파 센서 실행된다.
- 초음파 센서에서 바꾼 값을 확인하여 true가 되면 스피커를 종료시키고 알람 종료.
### 스피커
- 실행이 되면 Newjeans - ditto가 알림음으로 소리가 나온다.
### 초음파 센서
- 실행이 되면 물체와의 거리를 탐지한다.
- 거리가 15cm 이하가 되고 3초이상 유지된다면 값 변경후 종료된다.
<br/>

## 📟 모듈
- 통신: UART 블루투스 모듈(HC-06)
- 탐지: 초음파 센서(HC-SR04)
- 소리: 스피커 (Piezo Speaker)

<br/>

## 🔧 전체 시스템 구조
- 하드웨어 구조
<img src="https://github.com/Collon-D/23-Embedded-System-Team-Project/assets/108410316/74bf7a84-3fda-4164-86a3-8e493effb90e" width="500" height="500"/>

- 소프트웨어 구조
![시스템 구조도 수정](https://github.com/Collon-D/23-Embedded-System-Team-Project/assets/138470360/5d012957-f04a-41b3-8662-cf56c07ef5f7)


<br/>

## 💊 문제점 및 해결 방안
- 알람을 종료하고 나면 이전에 사용한 알람 시간값을 가지고 알람 한번더 실행되는 문제
  - if문을 사용하여 해결

문제 코드
```c
void *readBluetoothData(void *data){
	int fd = *((int *)data); //디바이스 파일 서술자
	char input_alarm[20]; // 블루투스 데이터 저장

	while(1){
		if (serialDataAvail(fd)){ 
			pthread_mutex_lock(&alarm_mutex); // 뮤텍스 잠금
			serialReadBytes(fd, input_alarm, 16); //16 = length of 'yyyy.mm.dd.hh.mm'
			input_alarm[16] = '\0';
			strcpy(current_alarm, input_alarm);
			pthread_mutex_unlock(&alarm_mutex); // 뮤텍스 잠금 해제	
			
			printf ("Return Alarm : %s\n", current_alarm) ; 
		} 
		delay (1);
	}
}
```

해결 코드
```c
void *readBluetoothData(void *args) {
   printf("블루투스 쓰레드 생성\n");
   int fd = *((int*)args); // 디바이스 파일 서술자
   char input_alarm[50];  // 블루투스 데이터 저장
   int setAlarm = 0;
   //...생략
   while (1) {
	   delay(200);
	   if (serialDataAvail(fd)) {
		   if (serialReadBytes(fd, input_alarm, 16)) { 
				input_alarm[16] = '\0';
				setAlarm++;
		   }
	   }
       if (setAlarm == 1) {
           delay(100);
           pthread_mutex_lock(&alarm_mutex);
           strcpy(current_alarm, input_alarm);
           pthread_mutex_unlock(&alarm_mutex);

           printf("Input Alarm : %s\n", input_alarm);
            //...생략
		       setAlarm = 0;
       }
   }
}
```

<br/>

## 🎥 데모 영상 
[![데모 영상](https://img.youtube.com/vi/Xqf82Hni_yA&ab_channel=%EC%98%81%EC%83%81%EC%97%85%EB%A1%9C%EB%93%9C%EC%9A%A9%EC%B1%84%EB%84%90/0.jpg)](https://www.youtube.com/watch?v=Xqf82Hni_yA&ab_channel=%EC%98%81%EC%83%81%EC%97%85%EB%A1%9C%EB%93%9C%EC%9A%A9%EC%B1%84%EB%84%90) <br/>
(클릭하면 유튜브 영상으로 이동)
https://www.youtube.com/watch?v=Xqf82Hni_yA&ab_channel=%EC%98%81%EC%83%81%EC%97%85%EB%A1%9C%EB%93%9C%EC%9A%A9%EC%B1%84%EB%84%90
