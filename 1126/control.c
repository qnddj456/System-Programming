#include<stdio.h>
#include<signal.h>

int main() {
	int pid1, pid2;

	pid1 = fork();
	if(pid1 == 0) {
		while(1) {
			sleep(1);
			printf("process[1] start\n");
		}
	}

	pid2 = fork();
	if(pid2 == 0) {
		while(1){
			sleep(1);
			printf("process[2] start\n");
		}

	}

	sleep(2);
	kill(pid1, SIGSTOP);
	sleep(2);
	kill(pid1, SIGCONT);
	sleep(2);
	kill(pid2, SIGSTOP);
	sleep(2);
	kill(pid2, SIGCONT);
	sleep(2);
	kill(pid1, SIGKILL);
	kill(pid2, SIGKILL);
}
