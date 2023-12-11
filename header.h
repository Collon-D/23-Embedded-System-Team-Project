#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>

#include <wiringPi.h>       
#include <pthread.h>

#include <wiringSerial.h>
#include <softTone.h>       // Speaker
#include <errno.h>

extern int setAlarm;                        // 블루투스를 통한 알람 설정 여부 판단

#endif