#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

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

	//opening and reading file with scores   [START]
	FILE *fptr= fopen("scores.txt", "r");
	char recordName[5000];
	char timeScore[5000];

	if (fptr==0){
        return 1;
    }
	fgets(recordName, 5000, fptr);
	recordName[strlen(recordName) - 1] = '\0';
	fgets(timeScore, 5000, fptr);
	double recordTime = atof(timeScore);
	//opening and reading file with scores [END]

	//getting current player's name [START]
	char player[256];
	fgets(player, 257, stdin);
	player[strlen(player) - 1] = '\0';
	//[END]

	//Actual time calculation [START]
    struct timeval stop, start;
	gettimeofday(&start, NULL);
	//do stuff
	getchar();
	gettimeofday(&stop, NULL);

	double acc = (double)((stop.tv_sec - start.tv_sec) * 1000000 + stop.tv_usec - start.tv_usec) / 1000000;
	printf("%f seconds\n", acc);
	//Actual time calculation [END]

	//Checking if new record and calling display function [START]
	if (acc > recordTime){
		acc = recordTime;
		strcpy(player, recordName);
	}

	score(acc, player);
	//Checking if new record and calling display function [END]




	return 0;
}