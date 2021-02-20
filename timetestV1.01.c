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
#define clrscr() printf("\e[1;1H\e[2J")

//Function to print the score board
void score(double score, char* name, int number_of_test, float acc){

	printf("Test #%d time: %f\n\n", number_of_test, acc);//Showing the result for current test
	printf("_____________________________________________________________________\n");
	printf("|                                                                   |\n");
	printf("|                                                                   |\n");
	printf("|                                                                   |\n");
	printf("|                                                                   |\n");
	printf("	#1.%s                         %fseconds              \n", name, score);
	printf("|                                                                   |\n");
	printf("|                                                                   |\n");
	printf("|                                                                   |\n");
	printf("|                                                                   |\n");
	printf("_____________________________________________________________________\n");
}

float float_rand(){//function to generate a random time period for sleep
	float min = 1, max = 5;
    float scale = rand() / (float) RAND_MAX; /* [0, 1.0] */
    return min + scale * ( max - min );      /* [min, max] */
}

float timeCalculation(){//main function, calculates time taken to press

	struct timeval stop, start;
	printf("PRESS ENTER\n");
	gettimeofday(&start, NULL);
	//do stuff
	getchar();
	gettimeofday(&stop, NULL);

	return (double)((stop.tv_sec - start.tv_sec) * 1000000 + stop.tv_usec - start.tv_usec) / 1000000;//returning time taken to press enter
}

int checkRecord(float* acc, double* recordTime, char player[256], char nameShow[256], float cur_acc, int test_number){//Checking if new record and calling display function
	
	if (*acc > *recordTime){//Checking if the attempt was slower
			*acc = *recordTime;
		}else {// if faster, rewrite the scores.txt file with the new record
			*recordTime = *acc;
			strcpy(nameShow, player);
			FILE *rewrite = fopen("scores.txt", "w");
			if (rewrite==0){
     		   return 1;
    		}
    		fprintf(rewrite, "%s\n",nameShow );
    		fprintf(rewrite, "%f\n",*recordTime );
    		fclose(rewrite);
		}


	score(*acc, nameShow, test_number, cur_acc);//display the current record
	return 0;
}


int main(){
	int number_of_test = 1;//Variable to track the current test number for displaying current test time.
	char nameShow[256];//Name to be shown as record holder
	

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
	strcpy(nameShow, recordName);//Setting the record holder name to be shown if record not bitten
	//opening and reading file with scores [END]

	//***********************************************************//
	//*****************Pre-game information**********************//
	
	//Getting the number of tests to be run [START]
	printf("Hello, how many times would you like to try?\n");
	int i;
	scanf("%d", &i);//Getting the number of tests to be loaded
	//Getting the number of tests to be run [END]

	// getting current player's name [START]
	printf("How to call you?\n");
	char player[256];
	fgets(player, 257, stdin);
	fgets(player, 257, stdin);//Getting the name of current user
	player[strlen(player) - 1] = '\0';
	printf("Ok, let's go\n");
	//getting current player's name [END] 

	//*****************Pre-game information**********************//
	//***********************************************************//


	while(i){
		float timer = float_rand();//generating a random amount of time between 1 and 5 seconds
		printf("WAITNG...\n");
		sleep(timer);// waiting for the time to pass
		clrscr();

		float acc = timeCalculation();//running the speed test
		checkRecord(&acc, &recordTime, player, nameShow, acc, number_of_test);//Checking if new record and calling display function
		number_of_test++;
		


		//Checking if new record and calling display function [START]  {if above function (checkRecord) is not working, this for sure works}
		/*if (acc > recordTime){
			acc = recordTime;
		}else {
			recordTime = acc;
			strcpy(nameShow, player);
			FILE *rewrite = fopen("scores.txt", "w");
			if (rewrite==0){
     		   return 1;
    		}
    		fprintf(rewrite, "%s\n",nameShow );
    		fprintf(rewrite, "%f\n",recordTime );
    		fclose(rewrite);
		}


		score(acc, nameShow);*/
		//Checking if new record and calling display function [END]
		i--;

	}

	fclose(fptr);

	return 0;
}