#include <stdio.h>
#include<unistd.h>

int main() {
	int pid;
	printf("[%d] start process \n", getpid());

	pid = fork();
	printf("[%d] process is: return value %d\n", getpid(), pid);
}
