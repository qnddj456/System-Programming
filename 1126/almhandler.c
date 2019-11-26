#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
void alarmHandler();

int main() {
	signal(SIGALRM,alarmHandler);
	alarm(5);
	printf("loop\n");
	while(1) {
		sleep(1);
		printf("1 sec\n");
	}
	printf("no exe\n");
}

void alarmHandler() {
	printf("wake up\n");
	exit(0);
}

