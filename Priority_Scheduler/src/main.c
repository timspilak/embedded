/*
 * main.c
 *
 *  Created on: 27.04.2022
 *      Author: Tim
 */

#include <stdio.h>

#include "process.h"
#include <windows.h>
#include "functions.h"

int main (){

	/*
	 * Initializations
	 */
	process processes[20]; 			// maximum 3 processes

	processes[0].ID = 0;
	processes[0].bursttime = 3;
	processes[0].starttime = 2;
	processes[0].cycle = 6;
	processes[0].prio = 3;
	processes[0].pointerToFunction = &processFunction;

	processes[1].ID = 1;
	processes[1].bursttime = 2;
	processes[1].starttime = 1;
	processes[1].cycle = 8;
	processes[1].prio = 2;
	processes[1].pointerToFunction = &processFunction;

	processes[2].ID = 2;
	processes[2].bursttime = 2;
	processes[2].starttime = 2;
	processes[2].cycle = 10;
	processes[2].prio = 6;
	processes[2].pointerToFunction = &processFunction;

	int nrOfProcesses = 3;

	process activeProcesses[20];	// max 20 running processes
	int activeprocesscounter = 0;	// number of active processes (0-20)

	process runningProcess;
	int counter = 0;			// absolute time
	int processIsRunning = 0;	// 1-> a process is running; 0 -> no process is running
	int actualStartTime = 0;	// asolute start time of the actual process

	while(1)
	{
		// check all processes if they want to start
		for(int i = 0; i < nrOfProcesses; i++)
		{
			// if it's the processes starttime or cycle time
			if(processes[i].starttime == counter || (counter - processes[i].starttime)% processes[i].cycle == 0)
			{
				activeProcesses[activeprocesscounter] = processes[i];
				activeprocesscounter++;
			}
		}
		// if a process is running
		if(processIsRunning == 1)
		{
			// run process (for checking if process is still running)
			processIsRunning = runningProcess.pointerToFunction(runningProcess.bursttime,
					actualStartTime, counter, runningProcess.ID);
		}
		// if no process is running
		if(processIsRunning == 0)
		{
			if(activeprocesscounter != 0)
			{
				// Search for Process with highest prio
				int tempprio = -1;
				int pos = -1;

				for(int i = 0; i< activeprocesscounter; i++)
				{
					if(activeProcesses[i].prio > tempprio)
					{
						tempprio = activeProcesses[i].prio;
						pos = i;
					}
				}
				runningProcess = activeProcesses[pos];

				// remove prioProcess from activeProcesses
				for(int i = pos; i < activeprocesscounter; i++)
				{
					activeProcesses[i] = activeProcesses[i+1];
				}
				activeprocesscounter--;
				actualStartTime = counter;
				processIsRunning = runningProcess.pointerToFunction(runningProcess.bursttime,
						actualStartTime, counter, runningProcess.ID);
			}
			else
			{
				printf("At time: %d -> no process is running.\n", counter);
				fflush(stdout);
			}
		}
		printf("At time: %d , %d processes are waiting.\n", counter, activeprocesscounter);
		fflush(stdout);

		// next time step
		Sleep(1000); // sleep 1 sec (linux--> Sleep(1)
		counter++;
	}


}

/**
 * INFO: about times
 *
 * bursttime:	execution time of this process
 * Starttime:	second where this process wants to start
 * cycle:		seconds betweeen each cycle
 *
 * Priority of the processes depend on thair number
 *
 */
