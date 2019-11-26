#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
void intHandler();

int main() {
	signal(SIGINT, intHandler);
	while(1) {
		pause();
		printf("no exe\n");	
	}
}

void intHandler(int signo) {
	printf("interapt signal \n");
	printf("signal no : %d\n",signo);
	exit(0);
}

