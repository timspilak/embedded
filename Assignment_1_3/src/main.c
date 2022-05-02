/*
 * main.c
 *
 *  Created on: 02.04.2022
 *      Author: Tim
 */

#include <stdio.h>
#include <stdlib.h>

void print_array (int *array, int size);

int main (){
	// Size of the arrays from command line
	int size;

	printf("Enter size of array a\n");
	fflush(stdout);
	scanf("%d", &size); // Eingabe Bsp:5
	printf("Size of the arrays is: %d", size);

	// define dynamic arrays
	int *a, *b;
	a = (int *)malloc(size * sizeof(int));

	b = (int *)malloc(size * sizeof(int));

	// get Values into Array a
	for(int i = 0; i < size; i++){
		printf("\nEnter value of the array at %d: ", i);
		fflush(stdout);
		scanf("%d", (a+i));
	}

	// print array a for debugging
	//print_array(&a, size);
	printf("a = {");
	for (int i = 0; i < size; i++){
		printf("%d ", *(a+i));
	}
	printf("}\n");

	// get numbers reverese to b
	for(int i = 0; i < size; i++){
		*(b+i) = *(a+(size-1-i));
	}

	// print resulting array b
	//print_array(&b, size);
	printf("b = {");
	for (int i = 0; i < size; i++){
		printf("%d ", *(b+i));
	}
	printf("}\n");

	return 0;
}

void print_array (int *array, int size){

	printf("a = {");
	for (int i = 0; i < size; i++){
		printf("%d ", *(array+i));
	}
	printf("}\n");
}
