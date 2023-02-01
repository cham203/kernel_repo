#include<stdio.h>
#include<pthread.h>
#include <stdlib.h>
#include<unistd.h>
#define MAX 10
int min,max;
void *even()
{
	for (;min<=max;)
	{
		if (min % 2 == 0)
		{
			printf("%d\n",min);
			min++;
			sleep(1);
		}
	}
}
//   pthread_exit(0);


void *odd()
{
	for (;min<=max;)
	{
		if (min % 2 == 1)
		{
			printf("%d\n",min);
			min++;
			sleep(1);
		}
	}
	//pthread_exit(0);

}
int main(int argc,char argv[])
{
	pthread_t thread1,thread2;
	printf("enter min and max value");
	scanf("%d %d",&min,&max);
	if(pthread_create(&thread1,NULL,&even,NULL)!=0)
	{
		return 1;
	}
	// sleep(1);
	if(pthread_create(&thread2,NULL,&odd,NULL)!=0)
	{
		return 2;
	}
	// sleep(1);
	if(pthread_join(thread1,NULL)!=0)
	{
		return 5;
	}

		if(pthread_join(thread2,NULL)!=0)
		{
			return 4;

		}
		return 0;
	}

