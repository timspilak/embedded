/*
 * main.c
 *
 *  Created on: 02.05.2022
 *      Author: Tim
 */

#include <stdio.h>
#include <stdlib.h>
// Linux
#include <time.h>
// linux add pthread lib >> settings >> add lib >> insert name
// cmd: man pthread_create
// cmd: man pthread_exit

void * function_thread1(void * parameter);
void * function_thread2(void * parameter);
int main()
{
	// declare thread structure
	pthread_t thread1, thread2;
	char * msg1 = "First Thread";
	char * msg2 = "Second Thread";

	// create threads
	pthread_creat(&, NULL, function_thread1, (void *)msg1);
	pthread_creat(&, NULL, function_thread2, (void *)msg2);

	// Join procedure (wait for threads to exit)
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	return 0;
}
void * function_thread1(void * parameter)
{
	char * msg;
	msg = (char *)parameter;

	for(int i = 0; i < 10; i++)
	{
		pthread_t selfid = pthread_self();
		printf("Thread ID: %u", selfid);
		printf("%s %d\n", msg, i);
		fflush(stdout);
		sleep(1); // sleep 1s in Linux
	}

	return NULL;
}

void * function_thread1(void * parameter)
{
	char * msg;
	msg = (char *)parameter;

	for(int i = 0; i < 10; i++)
	{
		if (i == 3)
		{
			int  ret = 10;
			// terminate thread
			pthread_exit(&ret);
		}
		pthread_t selfid = pthread_self();
		printf("Thread ID: %u", selfid);
		printf("%s %d\n", msg, i);
		fflush(stdout);
		sleep(1); // sleep 1s in Linux
	}
	return NULL;
}
