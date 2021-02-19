#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>

//Function to print the score board
void score(double score, char* name){

	printf("_____________________________________________________________________\n");
	printf("|                                                                   |\n");
	printf("|                                                                   |\n");
	printf("|                                                                   |\n");
	printf("|                                                                   |\n");
	printf("	#1.%s                         %f                     \n", name, score);
	printf("|                                                                   |\n");
	printf("|                                                                   |\n");
	printf("|                                                                   |\n");
	printf("|                                                                   |\n");
	printf("_____________________________________________________________________\n");
}


int main(){

    struct timeval stop, start;
	gettimeofday(&start, NULL);
	//do stuff
	getchar();
	gettimeofday(&stop, NULL);
	
	char* name = "Uagadougou";

	double acc = (double)((stop.tv_sec - start.tv_sec) * 1000000 + stop.tv_usec - start.tv_usec) / 1000000;
	printf("%f seconds\n", acc);

	score(acc, name);




	return 0;
}