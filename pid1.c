#include<stdio.h>
#include <unistd.h>
int main()
{
	pid_t pid;
	char *message;
	int n, exit_code;

	printf("fork programing staring\n");
	pid = fork();
	switch(pid)
	{
		case = -1:
			perror("fork failed");
			exit(1);
		case 0:
			message = "This is child";
			n = 1;
			exit_code = 37;
			break;

		default:
			message = "This is parent;
			n = 1;
			exit_code = 0;
			break;
	}
	for (;n > 0; n--)
	{
		puts(message);
		sleep(1);
	}
if (pid != 0)
{
	int stat_value;
	pid_t child_pid;
	child_pid = wait(&stat_val);
	printf("Child has finished
}
