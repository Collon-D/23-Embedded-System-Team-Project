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
* 23.11.04일 - 23.12.14일

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
- 거리가 ? 이하가 되고 3초이상 유지된다면 값 변경후 종료된다.
<br/>

## 📟 모듈
- 통신: UART 블루투스 모듈(HC-06)?
- 탐지: 초음파 센서(HC-SR04)?
- 소리: 스피커 ()?

<br/>

## 🔧 전체 시스템 구조
- 하드웨어 구조


- 소프트웨어 구조
![시스템 구조도 수정](https://github.com/Collon-D/23-Embedded-System-Team-Project/assets/138470360/5d012957-f04a-41b3-8662-cf56c07ef5f7)


<br/>

## 💊 문제점 및 해결 방안
- 알람을 종료하고 나면 이전에 사용한 알람 시간값을 가지고 알람 한번더 실행되는 문제
  - if문을 사용하여 해결

<br/>

## 🎥 데모 영상 

<br/>

## 📅 간트 차트
![간트차트_최종](https://github.com/Collon-D/23-Embedded-System-Team-Project/assets/138470360/f357a190-7ab5-4c28-9ee8-4a201ac6741b)

