/*
 * functions.c
 *
 *  Created on: 27.04.2022
 *      Author: Tim
 */


#include "functions.h"
#include "stdio.h"

int processFunction(int bursttime, int actualStartTime, int counter, int ID)
{
	if(counter - actualStartTime == bursttime)
	{
		printf("At time: %d -> process with ID %d terminated.\n",counter, ID);
		fflush(stdout);
		return 0;
	}
	else
	{
		printf("At time: %d -> process with ID %d need %d seconds to terminate.\n",
				counter, ID, (bursttime-(counter - actualStartTime)));
		fflush(stdout);
		return 1;

	}
}
