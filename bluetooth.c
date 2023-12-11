#include "bluetooth.h"
#include "alarm.h"

unsigned char serialRead(const int fd) {
    unsigned char x;
    if (read(fd, &x, 1) != 1) // read 함수를 통해 1바이트를 읽어옴
        return -1;
    return x;
}

void serialReadBytes(const int fd, char* buf, int len) {
    int i = 0;
    unsigned char data;
    int startReading = 0;
    
    while (i < len) {
        data = serialRead(fd);
        
        if (data == '@') {
            startReading = 1;
            continue;
        } else if (data == '#') {
            break;
        } else if (data == (unsigned char)-1) {
            continue;
        }
        
        if (startReading) {
            buf[i] = data;
            i++;
        }
    }

}

void *readBluetoothData(void *args) {
    printf("블루투스 쓰레드 생성\n");
    int fd = *((int*)args); // 디바이스 파일 서술자
    char input_alarm[50];   // 블루투스 데이터 저장

    pthread_t alarm_thread;

    while (1) {
        if (serialDataAvail(fd)) {
            delay(500);
            serialReadBytes(fd, input_alarm, 16);    // yyyy.mm.dd.hh.mm
            input_alarm[16] = '\0';
            pthread_mutex_lock(&alarm_mutex);
            strcpy(current_alarm, input_alarm);
            pthread_mutex_unlock(&alarm_mutex);

            printf("Input Alarm : %s\n", input_alarm);
            printf("Return Alarm : %s\n", current_alarm);
            
            // 알람 쓰레드 생성
            if (pthread_create(&alarm_thread, NULL, alarmPlay, NULL) != 0) {
                perror("Failed to create Alarm Thread");
                exit(1);
            }
            pthread_join(alarm_thread, NULL);
        }
    }
}