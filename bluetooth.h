#ifndef BLUETOOTH_H
#define BLUETOOTH_H

#include "header.h"

#define BAUD_RATE 115200

extern const char* UART2_DEV;
extern char current_alarm[17];              // 현재 시간 받아오는 공유 변수
extern pthread_mutex_t alarm_mutex;         // 알람 공유 자원

// 1 바이트 데이터를 읽음
unsigned char serialRead(const int fd);

int serialReadBytes(const int fd, char* buf, int len);

void serialWrite(const int fd, const char *s);

// Thread로 돌아갈 함수
void *readBluetoothData(void *args);

#endif 