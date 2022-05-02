/*
 * process.h
 *
 *  Created on: 27.04.2022
 *      Author: Tim
 */

#ifndef PROCESS_H_
#define PROCESS_H_

typedef struct{
	int ID;
	int bursttime;
	int starttime;
	int prio;
	int cycle;
	int(*pointerToFunction)(int a, int b, int c, int ID);
}process;

#endif /* PROCESS_H_ */
