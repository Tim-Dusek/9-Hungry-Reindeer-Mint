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
#include <sys/shm.h>

using namespace std;

#define KEY 1492

union semaphore {
	int value;
};

struct sembuf sem_operator;
union semaphore sem;
char pass[5];

int main(int argc, char *argv[]) {
	//create variables
	int pipe1[2];
	int pipe2[2];
	int pipe3[2];
	int pipe4[2];
	int pipe5[2];
	int pipe6[2];
	int pipe7[2];
	int pipe8[2];
	int pipe9[2];
	int semaphore;
	int semval;
	int ret;
	string semaphoreID;
	string inputFileName = argv[1];
	char inbuf[200];
	ofstream fileOut1;
	
	//initialize pipes
  	pipe(pipe1);
   	pipe(pipe2);
  	pipe(pipe3);
   	pipe(pipe4);
  	pipe(pipe5);
   	pipe(pipe6);
  	pipe(pipe7);
   	pipe(pipe8);
  	pipe(pipe9);
	
    //create semaphore and give initial value of 0
    semaphore = semget(KEY, 1, IPC_CREAT | 0666);
	sem.value = 0;
	semval = semctl(semaphore, 0, SETVAL, sem);
    semaphoreID = to_string(semaphore);
	
	int shmid = shmget (IPC_PRIVATE, 30, 0660);
	if (shmid<0){
		cout<< "Error creating shared memory";
		exit(1);
	}
	
	char *initial_data = (char *)shmat(shmid, (void *)0,0);
	strcpy(initial_data, "0");
	
	pid_t process1;
	process1 = fork(); //fork time!

 	if(process1 == 0) { //this fork runs program 1
		//child
		sprintf(pass, "%d", KEY);
		
		char readPipe1[100];
		char writePipe1[100];
		char inputFileChar[100];
		char initialDataChar[100];

		sprintf(readPipe1,  "%d", pipe1[0]);
		sprintf(writePipe1, "%d", pipe1[1]);
		sprintf(inputFileChar, "%s", inputFileName.c_str());
		sprintf(initialDataChar, "%s", initial_data);

		char* arrayProgram1[7] = {"./program1", pass, readPipe1, writePipe1, inputFileChar, initialDataChar ,NULL}; // put textfile here, baby
		execv(arrayProgram1[0], arrayProgram1);
		exit(1);	
	}
	
		pid_t process2;
	process2 = fork(); //fork time!
	
 	if(process2 == 0) { //this fork runs program 1
		//child
		sprintf(pass, "%d", KEY);
		
		char readPipe1[100];
		char writePipe1[100];
		char inputFileChar[100];
		char initialDataChar[100];

		sprintf(readPipe1,  "%d", pipe1[0]);
		sprintf(writePipe1, "%d", pipe1[1]);
		sprintf(inputFileChar, "%s", inputFileName.c_str());
		sprintf(initialDataChar, "%s", initial_data);

		char* arrayProgram1[7] = {"./program2", pass, readPipe1, writePipe1, inputFileChar, initialDataChar ,NULL};
		execv(arrayProgram1[0], arrayProgram1);
		exit(1);	
	}	
	
	pid_t process3;
	process3 = fork();
	
 	if(process3 == 0) {
		//child
		sprintf(pass, "%d", KEY);
		
		char readPipe1[100];
		char writePipe1[100];
		char inputFileChar[100];
		char initialDataChar[100];

		sprintf(readPipe1,  "%d", pipe1[0]);
		sprintf(writePipe1, "%d", pipe1[1]);
		sprintf(inputFileChar, "%s", inputFileName.c_str());
		sprintf(initialDataChar, "%s", initial_data);

		char* arrayProgram1[7] = {"./program3", pass, readPipe1, writePipe1, inputFileChar, initialDataChar ,NULL};
		execv(arrayProgram1[0], arrayProgram1);
		exit(1);	
	}
	
	pid_t process4;
	process4 = fork();
	
 	if(process4 == 0) {
		//child
		sprintf(pass, "%d", KEY);
		
		char readPipe1[100];
		char writePipe1[100];
		char inputFileChar[100];
		char initialDataChar[100];

		sprintf(readPipe1,  "%d", pipe1[0]);
		sprintf(writePipe1, "%d", pipe1[1]);
		sprintf(inputFileChar, "%s", inputFileName.c_str());
		sprintf(initialDataChar, "%s", initial_data);

		char* arrayProgram1[7] = {"./program4", pass, readPipe1, writePipe1, inputFileChar, initialDataChar ,NULL};
		execv(arrayProgram1[0], arrayProgram1);
		exit(1);	
	}
	
	pid_t process5;
	process5 = fork();
	
 	if(process5 == 0) {
		//child
		sprintf(pass, "%d", KEY);
		
		char readPipe1[100];
		char writePipe1[100];
		char inputFileChar[100];
		char initialDataChar[100];

		sprintf(readPipe1,  "%d", pipe1[0]);
		sprintf(writePipe1, "%d", pipe1[1]);
		sprintf(inputFileChar, "%s", inputFileName.c_str());
		sprintf(initialDataChar, "%s", initial_data);

		char* arrayProgram1[7] = {"./program5", pass, readPipe1, writePipe1, inputFileChar, initialDataChar ,NULL};
		execv(arrayProgram1[0], arrayProgram1);
		exit(1);	
	}
	
	pid_t process6;
	process6 = fork();
	
 	if(process6 == 0) {
		//child
		sprintf(pass, "%d", KEY);
		
		char readPipe1[100];
		char writePipe1[100];
		char inputFileChar[100];
		char initialDataChar[100];

		sprintf(readPipe1,  "%d", pipe1[0]);
		sprintf(writePipe1, "%d", pipe1[1]);
		sprintf(inputFileChar, "%s", inputFileName.c_str());
		sprintf(initialDataChar, "%s", initial_data);

		char* arrayProgram1[7] = {"./program6", pass, readPipe1, writePipe1, inputFileChar, initialDataChar ,NULL};
		execv(arrayProgram1[0], arrayProgram1);
		exit(1);	
	}
	
	pid_t process7;
	process7 = fork();
	
 	if(process7 == 0) {
		//child
		sprintf(pass, "%d", KEY);
		
		char readPipe1[100];
		char writePipe1[100];
		char inputFileChar[100];
		char initialDataChar[100];

		sprintf(readPipe1,  "%d", pipe1[0]);
		sprintf(writePipe1, "%d", pipe1[1]);
		sprintf(inputFileChar, "%s", inputFileName.c_str());
		sprintf(initialDataChar, "%s", initial_data);

		char* arrayProgram1[7] = {"./program7", pass, readPipe1, writePipe1, inputFileChar, initialDataChar ,NULL};
		execv(arrayProgram1[0], arrayProgram1);
		exit(1);	
	}
	
	pid_t process8;
	process8 = fork();
	
 	if(process8 == 0) {
		//child
		sprintf(pass, "%d", KEY);
		
		char readPipe1[100];
		char writePipe1[100];
		char inputFileChar[100];
		char initialDataChar[100];

		sprintf(readPipe1,  "%d", pipe1[0]);
		sprintf(writePipe1, "%d", pipe1[1]);
		sprintf(inputFileChar, "%s", inputFileName.c_str());
		sprintf(initialDataChar, "%s", initial_data);

		char* arrayProgram1[7] = {"./program8", pass, readPipe1, writePipe1, inputFileChar, initialDataChar ,NULL};
		execv(arrayProgram1[0], arrayProgram1);
		exit(1);	
	}
	
	pid_t process9;
	process9 = fork();
	
 	if(process9 == 0) {
		//child
		sprintf(pass, "%d", KEY);
		
		char readPipe1[100];
		char writePipe1[100];
		char inputFileChar[100];
		char initialDataChar[100];

		sprintf(readPipe1,  "%d", pipe1[0]);
		sprintf(writePipe1, "%d", pipe1[1]);
		sprintf(inputFileChar, "%s", inputFileName.c_str());
		sprintf(initialDataChar, "%s", initial_data);

		char* arrayProgram1[7] = {"./program9", pass, readPipe1, writePipe1, inputFileChar, initialDataChar ,NULL};
		execv(arrayProgram1[0], arrayProgram1);
		exit(1);	
		}	else {

		//parent		
		fileOut1.open("hw9.txt");
		semval = semctl(semaphore, 0, GETVAL);
		while(semval < 2) {
			while (semval == 0){
				semval = semctl(semaphore, 0, GETVAL);	
			}
			
			read(pipe1[0], inbuf, 200);
			printf("Read in from pipe: %s\n", inbuf);
			fileOut1 << inbuf;
			read(pipe1[0], inbuf, 200);
			printf("Read in from pipe: %s\n", inbuf);
			fileOut1 << inbuf;
			//fileOut1 << "\n";
			sem_operator.sem_num = 0;
			sem_operator.sem_op = -1;
			sem_operator.sem_flg = 0;
			semop(semaphore, &sem_operator, 1); //subtract 1 from semop
			usleep(1000);
			semval = semctl(semaphore, 0, GETVAL);
			}
		
		waitpid(process1, 0, 0); //wait till program 1 is done
		
		read(pipe1[0], inbuf, 200);
		printf("Read in from pipe: %s\n", inbuf);
		fileOut1 << inbuf;
		read(pipe1[0], inbuf, 200);
		printf("Read in from pipe: %s\n", inbuf);
		fileOut1 << inbuf;
		fileOut1.close();
		shmdt(initial_data);
		}
	printf("Program has ended. The last empty line is an EOF line.\n");
	return 0;
}
	
