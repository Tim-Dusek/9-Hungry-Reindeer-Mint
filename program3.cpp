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
	
	int semID = atoi(argv[1]);
	int sem = semget(semID, 1, IPC_CREAT | 0666);
	int semval;
    int pipe1[2];
	int randomNumber;
	pipe1[0] = atoi(argv[2]);
	pipe1[1] = atoi(argv[3]);
	string inputFileName = argv[4];
	char* fileCount = argv[5];
	int fileCountNumber = atoi(fileCount);
	string stuffToExport;
	string threadPad = "_p3";
	string line = "";
	string completeString = "";
	ifstream inFile;
    inFile.open(inputFileName);
	
	semval = semctl(sem, 0, GETVAL);
	
    while(inFile) {
        getline(inFile, line);
        completeString += line;
		//printf("complete String: %s\n\n\n", completeString.c_str());
    }
	
	if (sem==0){ //error getting semaphore
		exit(1);
	}
	
    while(fileCountNumber <= completeString.length()) {
		while(semval == 1) {
			semval = semctl(sem, 0, GETVAL);
		}
		//fileCountNumber = atoi(fileCount);
		//printf("semval is %d\n", semval);
		randomNumber = rand() % 10 + 1; //random number 1-10
		printf("The random number is %d\n", randomNumber);
		for (int i = 0; i < randomNumber; i++){
			stuffToExport[i] = completeString[fileCountNumber+i];
		}
		fileCountNumber = fileCountNumber + randomNumber;
		printf("input test from input file: %s\n", stuffToExport.c_str());
		write(pipe1[1], threadPad.c_str(), 200);
		write(pipe1[1], stuffToExport.c_str(), 200);
		
		
		//delete this when actually doing the program
		for (int x = 0; x<10;x++){
			stuffToExport[x]='\0';
		}
		sem_operator.sem_num = 0;
		sem_operator.sem_op = 1;
		sem_operator.sem_flg = 0;
		semop(sem, &sem_operator, 1); //add 1 to semop
		semval = semctl(sem, 0, GETVAL);
	}
	sem_operator.sem_num = 0;
	sem_operator.sem_op = 4;
	sem_operator.sem_flg = 0;
	semop(sem, &sem_operator, 1); //add 2 to semop to signal a close
    inFile.close();
	return 0;
}







