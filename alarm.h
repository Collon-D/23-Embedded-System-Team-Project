#ifndef ALARM_H
#define ALARM_H

#include "header.h"
#include "bluetooth.h"
#include "sensor.h"

#define SPEAKER 13

extern time_t ct;
extern struct tm tm;

extern double scale4[12];
extern double scale3[12];

int calcu(double di);

void initMyTone(int gpio, int freq);

void myTone(int freq);

void mute();

void *musicPlay();

void *alarmPlay();

#endif