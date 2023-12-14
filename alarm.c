#include "alarm.h"
#include "sensor.h"
#include "bluetooth.h"

double scale4[12] = {
    261.6256, 277.1826, 293.6648,
    311.1270, 329.6276, 349.6276,
    369.9944, 391.9954, 415.3047,
    440.0000, 466.1638, 493.8833
};

double scale3[12] = {
    130.8128, 138.5913, 146.8324,
    155.5635, 164.8138, 174.6141,
    184.9972, 195.9977, 207.6523,
    220.0000, 233.0819, 246.9417
};

int calcu(double di)
{
    int c;
    c = (19200000 / (di * 100));
    return c;
}

void initMyTone(int gpio, int freq)
{
    pinMode(gpio, PWM_OUTPUT);
    pwmSetMode(PWM_MODE_MS);
    pwmSetRange(100);
    pwmSetClock(734);
}

void myTone(int freq) 
{
    pwmSetClock(freq);
    pwmWrite(SPEAKER, 50);
    delay(200);
}

void mute()
{
    pwmWrite(SPEAKER, 0);
}

void *musicPlay(void *args){
    myTone(calcu(scale4[11]));
    mute();
    delay(100);
    myTone(calcu(scale4[11]));
    delay(250);
    mute();
    delay(50);
    myTone(calcu(scale4[4]));
    delay(100);
    myTone(calcu(scale4[7]));
    delay(500);
    myTone(calcu(scale4[5]));
    delay(300);
    mute();
    delay(1000);

    myTone(calcu(scale4[11]));
    mute();
    delay(100);
    myTone(calcu(scale4[11]));
    delay(250);
    mute();
    delay(50);
    myTone(calcu(scale4[4]));
    delay(100);
    myTone(calcu(scale4[7]));
    delay(800);
    mute();
    delay(1000);
        
    while(1) {
        myTone(calcu(scale4[4]));
        delay(100);
        mute();
        delay(50);
        myTone(calcu(scale4[4]));
        mute();
        delay(100);
        myTone(calcu(scale4[4]));
        mute();
        delay(100);
        myTone(calcu(scale4[4]));
        mute();
        myTone(calcu(scale4[4]));
        mute();
        delay(400);
        // stay in the middle

        myTone(calcu(scale4[4]));
        delay(100);
        mute();
        delay(50);
        myTone(calcu(scale4[4]));
        mute();
        delay(100);
        myTone(calcu(scale4[4]));
        mute();
        delay(100);
        myTone(calcu(scale4[4]));
        mute();
        myTone(calcu(scale4[4]));
        mute();
        delay(400);
        // like you a little

        myTone(calcu(scale4[2]));
        delay(100);
        mute();
        delay(50);
        myTone(calcu(scale4[2]));
        mute();
        delay(100);
        myTone(calcu(scale4[2]));
        mute();
        delay(100);
        myTone(calcu(scale4[2]));
        mute();
        myTone(calcu(scale4[2]));
        mute();
        delay(400);
        // don't want no riddle

        myTone(calcu(scale4[2]));
        delay(100);
        mute();
        delay(50);
        myTone(calcu(scale4[2]));
        mute();
        delay(100);
        myTone(calcu(scale4[2]));
        mute();
        delay(100);
        myTone(calcu(scale4[2]));
        mute();
        delay(200);
        myTone(calcu(scale3[11]));
        mute();
        delay(100);
        myTone(calcu(scale3[11]));
        mute();
        delay(100);
        // 말해줘 say it back

        myTone(calcu(scale4[0]));
        mute();
        delay(100);
        myTone(calcu(scale4[0]));
        mute();
        delay(100);
        myTone(calcu(scale4[0]));
        mute();
        delay(100);
        myTone(calcu(scale4[0]));
        mute();
        myTone(calcu(scale4[0]));
        mute();
        delay(400);
        // oh say it ditto

        myTone(calcu(scale4[0]));
        mute();
        delay(100);
        myTone(calcu(scale4[0]));
        mute();
        delay(100);
        myTone(calcu(scale4[0]));
        mute();
        delay(100);
        myTone(calcu(scale4[0]));
        mute();
        delay(50);
        myTone(calcu(scale4[4]));
        delay(120);
        myTone(calcu(scale4[2]));
        mute();
        delay(200);
        // 아침은 너무 멀어

        myTone(calcu(scale3[11]));
        mute();
        delay(50);
        myTone(calcu(scale3[11]));
        mute();
        delay(50);

        myTone(calcu(scale3[11]));
        mute();
        delay(10);

        myTone(calcu(scale3[9]));
        mute();
        myTone(calcu(scale3[11]));
        mute();
        delay(100);

        myTone(calcu(scale3[7]));
        mute();
        myTone(calcu(scale3[4]));
        mute();
        delay(50);
        myTone(calcu(scale3[4]));
        mute();
        delay(1000);
        // So say it ditto

        myTone(calcu(scale3[11]));
        delay(100);
        mute();
        myTone(calcu(scale3[11]));
        mute();
        delay(100);
        myTone(calcu(scale3[4]));
        delay(70);
        myTone(calcu(scale3[4]));
        delay(70);
        myTone(calcu(scale3[7]));
        delay(70);
        myTone(calcu(scale3[9]));
        delay(50);
        mute();
        delay(500);
        // 훌쩍 커버렸어

        myTone(calcu(scale3[11]));
        mute();
        delay(50);
        myTone(calcu(scale3[11]));
        mute();
        delay(50);
        myTone(calcu(scale3[11]));
        mute();
        delay(50);
        myTone(calcu(scale3[4]));
        mute();
        delay(50);
        myTone(calcu(scale3[4]));
        mute();
        delay(50);
        myTone(calcu(scale3[7]));
        mute();
        delay(50);
        myTone(calcu(scale3[9]));
        mute();
        delay(500);
        // 함께한 기억처럼

        myTone(calcu(scale3[11]));
        mute();
        delay(50);
        myTone(calcu(scale3[11]));
        mute();
        delay(50);
        myTone(calcu(scale3[11]));
        mute();
        delay(50);
        myTone(calcu(scale3[4]));
        mute();
        delay(50);
        myTone(calcu(scale3[4]));
        mute();
        delay(50);
        myTone(calcu(scale3[7]));
        mute();
        delay(50);
        myTone(calcu(scale3[9]));
        mute();
        delay(300);
        // 널본는 내 마음은

        myTone(calcu(scale3[11]));
        mute();
        delay(50);
        myTone(calcu(scale3[11]));
        mute();
        delay(50);
        myTone(calcu(scale3[11]));
        mute();
        delay(100);
        myTone(calcu(scale3[11]));
        mute();
        delay(50);
        myTone(calcu(scale3[11]));
        mute();
        delay(50);
        myTone(calcu(scale4[0]));
        mute();
        delay(50);
        myTone(calcu(scale3[11]));
        mute();
        delay(100);
        myTone(calcu(scale3[9]));
        delay(350);
        mute();
        delay(20);
        myTone(calcu(scale3[7]));
        delay(50);
        mute();
        delay(300);
        // 어느새 여름 지나 가을
        
        myTone(calcu(scale4[0]));
        delay(50);
        mute();
        myTone(calcu(scale3[11]));
        mute();
        delay(50);
        myTone(calcu(scale3[9]));
        delay(350);
        myTone(calcu(scale3[7]));
        delay(50);
        mute();
        delay(400);
        // 기다렸지

        myTone(calcu(scale4[0]));
        delay(50);
        myTone(calcu(scale3[11]));
        delay(75);
        myTone(calcu(scale3[9]));
        delay(200);
        myTone(calcu(scale3[11]));
        myTone(calcu(scale3[9]));
        delay(300);
        myTone(calcu(scale3[11]));
        myTone(calcu(scale3[9]));
        myTone(calcu(scale3[7]));
        delay(50);
        mute();
        delay(1000);
        // all this time

        myTone(calcu(scale3[11]));
        mute();
        delay(300);
        myTone(calcu(scale3[11]));
        mute();
        delay(50);
        myTone(calcu(scale3[4]));
        delay(50);
        myTone(calcu(scale3[4]));
        delay(50);
        myTone(calcu(scale3[7]));
        delay(50);
        myTone(calcu(scale3[9]));
        delay(50);
        mute();
        delay(500);
        // Do you want somebody

        myTone(calcu(scale3[11]));
        mute();
        delay(300);
        myTone(calcu(scale3[11]));
        mute();
        delay(50);
        myTone(calcu(scale3[4]));
        mute();
        delay(50);
        myTone(calcu(scale3[4]));
        mute();
        delay(50);
        myTone(calcu(scale3[7]));
        mute();
        delay(50);
        myTone(calcu(scale3[9]));
        mute();
        delay(500);
        // like i want somebody

        myTone(calcu(scale3[11]));
        mute();
        delay(50);
        myTone(calcu(scale3[11]));
        mute();
        delay(50);
        myTone(calcu(scale3[11]));
        mute();
        delay(50);
        myTone(calcu(scale3[4]));
        mute();
        delay(50);
        myTone(calcu(scale3[4]));
        mute();
        delay(50);
        myTone(calcu(scale3[7]));
        mute();
        delay(50);
        myTone(calcu(scale3[9]));
        mute();
        delay(300);
        // 날보고 웃었지만

        myTone(calcu(scale3[11]));
        mute();
        delay(50);
        myTone(calcu(scale3[11]));
        mute();
        delay(50);
        myTone(calcu(scale3[11]));
        mute();
        delay(100);
        myTone(calcu(scale3[11]));
        mute();
        delay(50);
        myTone(calcu(scale3[11]));
        mute();
        delay(50);
        myTone(calcu(scale4[0]));
        mute();
        delay(50);
        myTone(calcu(scale3[11]));
        mute();
        delay(100);
        myTone(calcu(scale3[9]));
        delay(350);
        mute();
        delay(20);
        myTone(calcu(scale3[7]));
        delay(50);
        mute();
        delay(300);
        // Do you think about mt now yeah
        
        myTone(calcu(scale4[0]));
        delay(50);
        mute();
        myTone(calcu(scale3[11]));
        mute();
        delay(50);
        myTone(calcu(scale3[9]));
        delay(350);
        myTone(calcu(scale3[7]));
        delay(50);
        mute();
        delay(400);
        // all the time yeah

        myTone(calcu(scale4[0]));
        delay(50);
        myTone(calcu(scale3[11]));
        delay(75);
        myTone(calcu(scale3[9]));
        delay(200);
        myTone(calcu(scale3[11]));
        myTone(calcu(scale3[9]));
        myTone(calcu(scale3[7]));
        mute();
        delay(1000);
        // all the time

        myTone(calcu(scale3[11]));
        delay(50);
        myTone(calcu(scale4[4]));
        delay(200);
        myTone(calcu(scale4[5]));
        delay(200);
        myTone(calcu(scale4[7]));
        delay(200);
        myTone(calcu(scale4[4]));
        delay(200);
        myTone(calcu(scale4[11]));
        delay(500);
        mute();
        delay(200);
        // I got no time to lose

        myTone(calcu(scale3[11]));
        delay(50);
        myTone(calcu(scale4[4]));
        delay(200);
        myTone(calcu(scale4[5]));
        delay(200);
        myTone(calcu(scale4[7]));
        delay(200);
        myTone(calcu(scale4[4]));
        delay(200);
        myTone(calcu(scale4[11]));
        delay(500);
        mute();
        delay(200);
        // 내 길었던 하루

        myTone(calcu(scale3[11]));
        delay(100);
        myTone(calcu(scale4[4]));
        delay(200);
        myTone(calcu(scale4[5]));
        delay(200);
        myTone(calcu(scale4[7]));
        delay(100);
        mute();
        delay(100);
        myTone(calcu(scale4[7]));
        myTone(calcu(scale4[2]));
        mute();
        delay(300);
        // 널 보고 싶어

        myTone(calcu(scale4[2]));
        mute();
        delay(200);
        myTone(calcu(scale4[2]));
        mute();
        delay(100);
        myTone(calcu(scale4[2]));
        mute();
        myTone(calcu(scale4[2]));
        mute();
        delay(200);
        myTone(calcu(scale3[11]));
        delay(100);
        myTone(calcu(scale4[0]));
        mute();
        delay(100);
        myTone(calcu(scale4[2]));
        mute();
        delay(100);
        myTone(calcu(scale4[2]));
        mute();
        delay(400);
        // ra ta ta ta 울린 심장

        myTone(calcu(scale4[2]));
        mute();
        delay(200);
        myTone(calcu(scale4[2]));
        mute();
        delay(100);
        myTone(calcu(scale4[4]));
        delay(100);
        myTone(calcu(scale4[2]));
        delay(250);
        myTone(calcu(scale3[11]));
        mute();
        delay(500);
        // (Ra ta ta ta)

        myTone(calcu(scale3[11]));
        delay(50);
        myTone(calcu(scale4[4]));
        delay(200);
        myTone(calcu(scale4[5]));
        delay(200);
        myTone(calcu(scale4[7]));
        delay(200);
        myTone(calcu(scale4[4]));
        delay(200);
        myTone(calcu(scale4[11]));
        delay(500);
        mute();
        delay(200);
        // I got no time to lose

        myTone(calcu(scale3[11]));
        delay(50);
        myTone(calcu(scale4[4]));
        delay(200);
        myTone(calcu(scale4[5]));
        delay(200);
        myTone(calcu(scale4[7]));
        delay(200);
        myTone(calcu(scale4[11]));
        delay(50);
        myTone(calcu(scale4[7]));
        delay(100);
        myTone(calcu(scale4[9]));
        delay(300);
        myTone(calcu(scale4[7]));
        delay(50);
        myTone(calcu(scale4[5]));
        delay(200);
        myTone(calcu(scale4[2]));
        mute();
        delay(50);
        myTone(calcu(scale4[2]));
        delay(200);
        myTone(calcu(scale3[11]));
        mute();
        delay(50);
        myTone(calcu(scale3[11]));
        delay(200);
        myTone(calcu(scale3[7]));
        delay(400);
        // 널 좋아 한다고 wooah wooah wooah

        myTone(calcu(scale4[2]));
        mute();
        delay(200);
        myTone(calcu(scale4[2]));
        mute();
        delay(100);
        myTone(calcu(scale4[2]));
        mute();
        myTone(calcu(scale4[2]));
        mute();
        delay(200);
        myTone(calcu(scale3[11]));
        delay(100);
        myTone(calcu(scale4[0]));
        mute();
        delay(100);
        myTone(calcu(scale4[2]));
        mute();
        delay(100);
        myTone(calcu(scale4[2]));
        mute();
        delay(400);
        // ra ta ta ta 울린 심장

        myTone(calcu(scale4[2]));
        mute();
        delay(200);
        myTone(calcu(scale4[2]));
        mute();
        delay(100);
        myTone(calcu(scale4[4]));
        delay(100);
        myTone(calcu(scale4[2]));
        delay(250);
        myTone(calcu(scale3[11]));
        mute();
        delay(500);
        // (Ra ta ta ta)

        myTone(calcu(scale4[4]));
        mute();
        delay(100);
        myTone(calcu(scale4[4]));
        delay(200);
        myTone(calcu(scale4[5]));
        delay(200);
        myTone(calcu(scale4[7]));
        delay(200);
        myTone(calcu(scale4[11]));
        delay(300);
        mute();
        delay(100);
        // i don't want to
    }

    return NULL;
}

void *alarmPlay(void *args)
{
    printf("알람 쓰레드 생성\n");
    int fd = *((int*)args); // 디바이스 파일 서술자
    char current_time[17];
    initMyTone(SPEAKER, 0);

    int flag = 1;
    while (flag)
    {
        delay(100);
        ct = time(NULL);
        tm = *localtime(&ct);
        if (serialRead(fd) == 'q'){
            printf("알람 쓰레드 강제종료\n");
            serialWrite(fd, " 알람 종료\n");
            pthread_exit(NULL);
        }
        sprintf(current_time, "%4d.%02d.%02d.%02d.%02d",
                tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min);
        pthread_mutex_lock(&alarm_mutex);
        if (!strcmp(current_time, current_alarm)) flag = 0; // 같으면 while 탈출
        pthread_mutex_unlock(&alarm_mutex);
    }
    serialWrite(fd, " 알람 시작\n");
    pthread_t music_thread;
    if (pthread_create(&music_thread, NULL, musicPlay, NULL) != 0) {
        perror("Failed to create music thread");
        exit(1);
    }

    // 알람 쓰레드가 생성되면 센서 쓰레드도 같이 생성
    pthread_t sensor_thread;
    if (pthread_create(&sensor_thread, NULL, start_microwave, &data) != 0) {
        perror("Failed to create Sensor Thread");
        exit(1);
    }

    while (1) {
        if (data.alarm_off) {
            pthread_cancel(music_thread);
            data.alarm_off = 0;
            mute();
            break;
        }
    }

    
    if (pthread_join(sensor_thread, NULL) != 0) {
        perror("Failed to join Sensor Thread");
        exit(1);
    }

    if (pthread_join(music_thread, NULL) != 0) {
        perror("Failed to join music thread");
        exit(1);
    }
    
    printf("알람 쓰레드 종료\n");
    serialWrite(fd, " 알람 종료\n");

    return NULL;
}