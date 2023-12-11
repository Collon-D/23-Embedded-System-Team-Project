#include "bluetooth.h"  // 블루투스 통신 헤더
#include "sensor.h"     // 초음파 센서 헤더
#include "alarm.h"      // 알람 관련 헤더

/* ------ 외부 변수 선언 ------ */
char current_alarm[17];                     // bluetooth
pthread_mutex_t alarm_mutex;                // bluetooth
int setAlarm;

const char* UART2_DEV = "/dev/ttyAMA1";
struct ThreadData data = { PTHREAD_MUTEX_INITIALIZER, 0 };

/* ------ 전역 변수 선언 ------ */
int fd_serial;
int status;

time_t ct;
struct tm tm;

void init();    // 모든 초기화 작업

/* --------------------------- */
int main(int argc, char** argv) {
    init();

    pthread_t bluetooth_thread;

    // 블루투스 UART 연결 시도
    if ((fd_serial = serialOpen(UART2_DEV, BAUD_RATE)) < 0) {
        printf("Unable to open serial device\n");
        return 1;
    }

    // 블루투스 쓰레드 생성
    if (pthread_create(&bluetooth_thread, NULL, readBluetoothData, (void*)&fd_serial) != 0) {
        perror("Failed to create bluetooth thread\n");
        return 1;
    }
    
    pthread_join(bluetooth_thread, NULL);

    return 0;
}

void init() {
    pthread_mutex_init(&alarm_mutex, NULL);

    if (wiringPiSetupGpio() < 0) {
        printf("Initialize Failed!!\n");
        return;
    }
}   