#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

void *producer();
void *consumer();
int counter = 0;
char buffer[5];

int main() 
{
    int res;
    pthread_t a_thread,b_thread;

    res = pthread_create(&a_thread, NULL, producer, NULL);
    res = pthread_create(&b_thread, NULL, consumer, NULL);
    res = pthread_join(a_thread, NULL);
    res = pthread_join(b_thread, NULL);

}

void *producer() 
{
    int in = 0; 
    char ch='A';
    while(1)
	{
		while(counter == 5);
		buffer[in]=ch;
		in = (in+1)% 5;
		ch++;
		if (in == 0 )
		{
		    ch='A';
		    printf("p:%s\n",buffer);
		}
		counter++;
	}
   pthread_exit("exit");	

}

void *consumer() 
{
    int out = 0;
    char data[5];
    while(1)
	{
		while(counter == 0);
		data[out] = buffer[out];
		out = (out+1)% 5;
		if (out == 0)
		    printf ("\tc:%s\n",data); 
		counter--;
	}
   pthread_exit("exit");	

}