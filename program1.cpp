//Timothy Dusek
//compile with the -std=c++11 flag
#include <stdlib.h>
#include <unistd.h>
#include <cstdlib>
#include <sys/types.h>
#include <sys/sem.h>
#include <fstream>
#include <sys/wait.h>
#include <regex>
#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <sys/ipc.h>
using std::ostream;
using std::cout;
using namespace std;

#define KEY 1492

union semaphore {
	int value;
};

struct sembuf sem_operator;
union semaphore sem;

int main(int argc, char *argv[]) {
	
	int semID = atoi(argv[1]); // semaphoreID
	int sem = semget(semID, 1, IPC_CREAT | 0666);
	int semval;
    int pipe1[2];
	int randomNumber;
	pipe1[0] = atoi(argv[2]); //pipeID
	pipe1[1] = atoi(argv[3]); //pipeID
	string inputFileName = argv[4]; //file name of input file
	char* fileCount = argv[5]; //shared memory
	int fileCountNumber = atoi(fileCount); //file count into a number
	string stuffToExport;
	string threadPad = "_p1";
	string line = "";
	string completeString = "";
	ifstream inFile;
    inFile.open(inputFileName);
	
	semval = semctl(sem, 0, GETVAL);
	
    while(inFile) { //reads the file and puts it into a variable
        getline(inFile, line);
        completeString += line;
		//printf("complete String: %s\n\n\n", completeString.c_str());
    }
	
	if (sem==0){ // if error getting semaphore exit
		exit(1);
	}
	
    while(fileCountNumber <= completeString.length()) { // while the file end hasn't beenreached
		while(semval == 1) {
			semval = semctl(sem, 0, GETVAL);
		}
		//fileCountNumber = atoi(fileCount);
		//printf("semval is %d\n", semval);
		randomNumber = rand() % 10 + 1; //random number 1-10
		printf("The random number is %d\n", randomNumber); //user feedback for random number
		for (int i = 0; i < randomNumber; i++){
			stuffToExport[i] = completeString[fileCountNumber+i]; //gets characters from input file
		}
		fileCountNumber = fileCountNumber + randomNumber; //updates the shared memory value
		printf("input test from input file: %s\n", stuffToExport.c_str()); //userfeedback for chars taken from file
		write(pipe1[1], threadPad.c_str(), 200); //write padding to pipe
		write(pipe1[1], stuffToExport.c_str(), 200); //write chars to pipe
		
		
		//delete this when actually doing the program
		for (int x = 0; x<10;x++){
			stuffToExport[x]='\0'; //wipe the export chars from the inpt 
		}
		sem_operator.sem_num = 0;
		sem_operator.sem_op = 1;
		sem_operator.sem_flg = 0;
		semop(sem, &sem_operator, 1); //add 1 to semop
		semval = semctl(sem, 0, GETVAL); //update semval
	}
	sem_operator.sem_num = 0;
	sem_operator.sem_op = 4;
	sem_operator.sem_flg = 0;
	semop(sem, &sem_operator, 1); //add 4 to semop to signal a close
    inFile.close();
	return 0;
}







