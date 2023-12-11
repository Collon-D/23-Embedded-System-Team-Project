#include "sensor.h"

int getDistance() {
    struct timeval start, end;
    long micros;
    int distance;

    digitalWrite(TRIG, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG, LOW);
    
    while (digitalRead(ECHO) == LOW);
    gettimeofday(&start, NULL);
    while (digitalRead(ECHO) == HIGH);
    gettimeofday(&end, NULL);

    micros = (end.tv_sec - start.tv_sec) * 1000000 + end.tv_usec - start.tv_usec;
    distance = micros / 29 / 2;
    return distance;
}

void *start_microwave(void *args) {
    printf("센서 쓰레드 생성\n");

    pinMode(TRIG, OUTPUT);
    pinMode(ECHO, INPUT);

    struct ThreadData *data = (struct ThreadData*)args;
    int distance;

    while (1) {
        distance = getDistance();
        printf("distance : %d\n", distance);
        if (distance < 15) {
            delay(3000);
            distance = getDistance();
            printf("거리1 : %d\n", distance);
            if (distance < 15) {
                pthread_mutex_lock(&data->lock);
                data->alarm_off = 1;
                pthread_mutex_unlock(&data->lock);
                printf("센서 쓰레드 종료\n");
                pthread_exit(NULL);
            }
        }
        delay(10);
    }
}