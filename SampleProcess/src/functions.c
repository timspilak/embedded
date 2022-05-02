/*
 * functions.c
 *
 *  Created on: 04.04.2022
 *      Author: Tim
 */


#include "functions.h"
#include <windows.h> // windows
//#include <time.h>// linux mac

void processSleepFunction(int bursttime){
	// Windows
	Sleep(bursttime * 1000); // in ms

	// Linux
	//sleep(bursttime); // in s
}
