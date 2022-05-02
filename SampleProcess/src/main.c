/*
 * main.c
 *
 *  Created on: 04.04.2022
 *      Author: Tim
 */

#include <stdio.h>
#include "process.h"
#include "functions.h"

int main(){

	process processes[20]; // maximum 20 processes

	printf("Insert number of existing processes (max = 20)\n");
	fflush(stdout);

	int nrOfProcesses;
	scanf("%d", &nrOfProcesses);

	for(int i = 0; i<nrOfProcesses; i++){
		processes[i].ID = i;
		printf("Insert executiontime of process %d:", i);
		fflush(stdout);

		scanf("%d", &processes[i].bursttime);

		processes[i].pointerToFunction = &processSleepFunction;
	}

	processes[0].waitingtime = 0;
	processes[0].overalltime = processes[0].bursttime + processes[0].waitingtime;

	for(int i = 1; i < nrOfProcesses; i++){
		processes[i].waitingtime = processes[i-1].overalltime;
		processes[i].overalltime = processes[i].bursttime + processes[i].waitingtime;
	}

	printf("\n\tID\tBursttime\tWaiting Time\tOverall Time");

	for(int i=0; i<nrOfProcesses; i++){
		printf("\n\tP[%d]\t%d\t\t%d\t\t%d", processes[i].ID, processes[i].bursttime,
				processes[i].waitingtime, processes[i].overalltime);

		fflush(stdout);

		processes[i].pointerToFunction(processes[i].bursttime);
	}

	return 0;
}

