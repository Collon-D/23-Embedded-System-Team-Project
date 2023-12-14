#include "bluetooth.h"
#include "alarm.h"

unsigned char serialRead(const int fd) {
    unsigned char x;
    if (read(fd, &x, 1) != 1) // read 함수를 통해 1바이트를 읽어옴
        return -1;
    return x;
}

int serialReadBytes(const int fd, char* buf, int len) {
    int i = 0;
    unsigned char data;
    int startReading = 0;
    
    while (i <= len) {
        data = serialRead(fd);
        
        if (data == '@') {
            startReading = 1;
            continue;
        } else if (data == '#' && i == len) {
            return 1;
        } else if (data == (unsigned char)-1) {
            continue;
        }
        
        if (startReading) {
            buf[i] = data;
            i++;
        }
    }
    serialWrite(fd, " 잘못된 양식 입니다. (@YYYY.MM.DD.HH.MM#)\n");
    return 0;
}

void *readBluetoothData(void *args) {
   printf("블루투스 쓰레드 생성\n");
   int fd = *((int*)args); // 디바이스 파일 서술자
   char input_alarm[50];  // 블루투스 데이터 저장
   int setAlarm = 0; // 데이터 가용성 확인을 위한 변수

   pthread_t alarm_thread;

   serialWrite(fd, " 사용 양식 : @YYYY.MM.DD.HH.MM#\n");

   while (1) {
	   delay(200);
	   if (serialDataAvail(fd)) {
		   if (serialReadBytes(fd, input_alarm, 16)) { // 데이터를 전부 읽으면 16 반환
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
           serialWrite(fd, " 알람 설정 완료\n");
           
           // 알람 쓰레드 생성
           if (pthread_create(&alarm_thread, NULL, alarmPlay, (void*)&fd) != 0) {
               perror("Failed to create Alarm Thread");
               exit(1);
           }

           pthread_join(alarm_thread, NULL);
		   setAlarm = 0;
       }
   }
}

void serialWrite(const int fd, const char *s) {
    write(fd, s, strlen(s));
}