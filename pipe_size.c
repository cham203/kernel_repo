#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
void main()
{
	int p[2];
	 pipe2(p,O_NONBLOCK);
	int c=0;
	char ch='a';
	while(write(p[1],&ch,1) != -1)
	{
		c++;
		printf("%d\n",c);
	}
	printf("hii\n");
}
