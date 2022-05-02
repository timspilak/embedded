/*
 * task_2.c
 *
 *  Created on: 30.03.2022
 *      Author: Tim
 */

#include <stdio.h>

int main() {
	int arraya[5];
	int arrayb[5];
	int *a;
	int *b;

	a = arraya;
	b = arrayb;

	for(int i = 0; i < 5; i++){
		*(a+i) = i;
	}

	for(int i = 0; i < 5; i++){
			printf("value at position %d is %d.\n", i, *(a+i));
		}

	for(int i = 0; i < 5; i++){
		*(b+i) = *(a+(4-i));
	}

	for(int i = 0; i < 5; i++){
		printf("value at position %d is %d.\n", i, *(b+i));
	}

	return 0;
}
