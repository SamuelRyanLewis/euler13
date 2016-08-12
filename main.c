#include <stdio.h>
#include <stdlib.h>
#include <math.h>


/**
 * This reads in X chars from the 50 lines of the file
 *
 */
void readToArray(char *fileName, long *array) {
	FILE *fp = (FILE *)malloc(sizeof(char) * 5101);
	fp =  fopen(fileName, "r");
	if(fp == NULL) {
		perror("Error opening file");
	}
	char buffer[16];
	char dbuff[37];
	for (int x = 0; x < 100; x++) {
		if(fgets(buffer, 16, fp) == NULL) {
			printf("FOUND THE ERROR\n");
		}
		*array = strtol(buffer, NULL, 10);
		array += sizeof(long);
		fgets(dbuff, 37, fp);
	}
	free(fp);
}

/**
 * Project Euler Problem 13
 * Large Sum
 * Work out the first ten digits of the sum of the following [see file]
 * one-hundred 50-digit numbers.
 * 
 * main provides the basic logic and flow fo the program.
 * First it calls the helper function to load the array, then
 * it runs a loop to get the sum. I added the first 15 digits
 * of each number, it yields an accurate answer for the first 10 digits.
 */
int main(void) {
	long *numbers = (long *)malloc(sizeof(long) * 150);
	readToArray("50digitNums.txt", numbers);
	long theSum = 0;
	for(int x = 0; x < 100; x++) {
		theSum += *(numbers + (x * sizeof(long)));
	}
	printf("%ld\n", theSum);
	free(numbers);
}
