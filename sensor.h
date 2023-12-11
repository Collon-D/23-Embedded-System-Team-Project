#ifndef SENSOR_H
#define SENSOR_H

#include "header.h"

#define TRIG 15
#define ECHO 18

struct ThreadData {
    pthread_mutex_t lock;
    int alarm_off;
};

extern struct ThreadData data;

// 초음파 센서와 물체 간의 거리 반환 함수
int getDistance();

// 쓰레드로 돌아갈 함수
void *start_microwave(void* args);

#endif