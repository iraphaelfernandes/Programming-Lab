#include <stdio.h>
#include <pthread>

#define SIZE 10

pthread_mutex_t buffer_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t buffer_full = PTHREAD_COND_INITIALIZER;
pthread_cond_t buffer_empty = PTHREAD_COND_INITIALIZER;

int buffer[SIZE];
int ind_c, ind_p = 0;
int n = 0;

void push(int val)
{

	buffer[ind_c] = val;
	ind_c = (ind_c+1)%SIZE;	
	n++;

	return;
	 
}

int pop()
{
	int val = buffer[ind_p];
	ind_p = (ind_p+1)%SIZE;
	n--;
	
	return val;
	 
}

void *producer()
{
	int i = 0;
	n_threads = 10;
	while(n_threads--)
	{
		pthread_mutex_lock(&buffer_mutex);
		if(n >= SIZE)
		{
			pthread_cond_wait(&buffer_full);
		}
		push(i);
		pthread_cond_signal(&buffer_empty);
		pthread_mutex_unlock(&buffer_mutex);
	}
	pthread_exit(NULL);
}

void *consumer()
{


	pthread_exit(NULL);
}

int main()
{

	pthread_t thread thread_consumer;
	pthread_t thread thread_producer;

	pthread_create(&thread_consumer, NULL, consumer, NULL);
	pthread_create(&thread_producer, NULL, producer, NULL);

	pthread_join(thread_consumer,NULL);
	pthread_join(thread_producer,NULL);

	return 0;
}






pthread_lock								pthread_lock
if(n >= SIZE)									if(n <= 0)
	pthread_cond_wait(F_cheio, )				pthread_cond_wait(F_vazio, )				
producer()										consumer()
n++											n--
pthread_cond)signal(F_vazio, )		pthread_cond)signal(F_cheio, )
pthread_unlock								pthread_unlock




pthread_lock
if(n >= SIZE)
	pthread_cond_wait(F_cheio, )				
push()
n++
pthread_cond)signal(F_vazio, )
pthread_unlock

pthread_lock
if(n <= 0)
pthread_cond_wait(F_vazio, )				
pop()
n--
pthread_cond)signal(F_cheio, )
pthread_unlock


















