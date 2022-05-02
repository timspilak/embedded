/*
 * main.c
 *
 *  Created on: 31.03.2022
 *      Author: Tim
 */


#include <stdio.h>

#include "function.h"

int main(){
	//pointers on array

	int array[] = {1,2,3,4,5};
	int arrayb[5]; //declared a pointer

	int *arraypt;
	arraypt=array; // arraypt = &array[0]

	//array[2]= 10;
	*(arraypt +2)=10;

	for(int i=0; i<sizeof(array)/sizeof(int);i++)
	{
		//index notation
		printf("%d ", array[i]);
		//pointer notation
		printf("%d ", *(arraypt +i));
	}

	////////////dynamic memory allocation

	int size;
	printf("Size of dynamic memory: ");
	fflush(stdout);
	scanf("%d", &size); // Eingabe Bsp:5

	float *ftp;
	//malloc - memory allocation

	ftp = (float *)malloc(size * sizeof(float));

	for(int i=0; i<size; i++)
	{
		*(ftp + i) = (float)i;
	}
	printf("hier");
	for(int i=0; i<size; i++)
		{
			printf("%f, ", *(ftp + i));
		}

	/////////////////Pointers on Functions---------------
	//sum(3,2); // old version
	// declaration of pointer variable that points to a function with void as returntype
	// and two parameters of type integer
	void(*pointerToFunctionSum)(int a, int b);

	//pointer variable pointerToFunctionSum points to function sum
	pointerToFunctionSum = &sum;

	//call of function using the pointer variable
	pointerToFunctionSum(4,5);


	return 0;
}


void sum (int a, int b)
{
	printf("\nSum of %d and %d is %d", a,b,a+b);
}

