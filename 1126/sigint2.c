#include<stdio.h>
#include<signal.h>
struct sigaction newact;
struct sigaction oldact;
void sigint_handler(int signo);

int main(void) {
	newact.sa_handler = sigint_handler;
	sigfillset(&newact.sa_mask);
	
	sigaction(SIGINT, &newact, &oldact);

	while(1) {
		printf("please Ctrl_c press\n");
		sleep(1);
	}
}

void sigint_handler(int signo) {
	printf("%d th signal \n", signo);
	printf("one more press end\n");
	sigaction(SIGINT, &oldact, NULL);
}

