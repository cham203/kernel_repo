#include<stdio.h>
#include<string.h>
#include<unistd.h>
int main(int argc,char **argv)
{
	int count=0;
	for(count=1;count<argc;count++)
	{
		write(1,argv[count],strlen(argv[count]));
		write(1," ",1);	
	}
}
