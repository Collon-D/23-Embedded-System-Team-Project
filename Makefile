CC = gcc
CFLAGS = -Wall
LIBS = -lwiringPi -lpthread

SRCS = main.c bluetooth.c sensor.c alarm.c
OBJS = $(SRCS:.c=.o)
TARGET = Alarm

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)