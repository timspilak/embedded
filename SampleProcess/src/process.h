/*
 * process.h
 *
 *  Created on: 04.04.2022
 *      Author: Tim
 */

#ifndef PROCESS_H_
#define PROCESS_H_

typedef struct{
	int ID;
	int bursttime;
	int waitingtime;
	int overalltime;
	void(*pointerToFunction)(int a);
}process;


#endif /* PROCESS_H_ */
