#include<stdio.h>
#include<unistd.h>
#include<string.h>
int main()
{
	int p[2];
	pipe(p);
	printf("read:%d\n",p[0]);
	printf("write:%d\n",p[1]);
	if(fork())
	{
		printf("its parent...\n");
		char parent[20];
		printf("enter the data..\n");
		scanf("%s",parent);
		write(p[1],parent,strlen(parent)+1);
	}
	else
	{
		printf("it's child..\n");
		char child[20];
		read(p[0],child,sizeof(child));
		printf("read the data: %s\n",child);
	}
}
