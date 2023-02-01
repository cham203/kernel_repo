#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#define MAX 1000
int i;
pthread_mutex_t mutex;
void *odd()
{
    pthread_mutex_lock(&mutex);
    for (;i<MAX;)
    {
        if(i%2!=0)
        {
            printf("%d ",i);
            i++;
            // sleep(1);
        }
        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(0);
}
void *even()
{
    pthread_mutex_lock(&mutex);
    for (;i<MAX;)
    {
        if(i%2==0)
        {
            printf("%d ",i);
            i++;
            // sleep(1);
        }
        pthread_mutex_unlock(&mutex);
    }
}

int main()
{
    pthread_t thread1,thread2;
    pthread_create(&thread1,NULL,&even,NULL);
    pthread_create(&thread2,NULL,&odd,NULL);
    pthread_join(thread1,NULL);
    // pthread_join(thread2,NULL);
    exit(0);
}