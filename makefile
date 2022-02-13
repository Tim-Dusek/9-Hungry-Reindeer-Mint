CC = g++
CFLAGS = -std=c++11 -w

testmake: program0.cpp program1.cpp program2.cpp program3.cpp program4.cpp program5.cpp program6.cpp program7.cpp program8.cpp program9.cpp	
	$(CC) $(CFLAGS) -o program0 program0.cpp
	$(CC) $(CFLAGS) -o program1 program1.cpp
	$(CC) $(CFLAGS) -o program2 program2.cpp
	$(CC) $(CFLAGS) -o program3 program3.cpp
	$(CC) $(CFLAGS) -o program4 program4.cpp
	$(CC) $(CFLAGS) -o program5 program5.cpp
	$(CC) $(CFLAGS) -o program6 program6.cpp
	$(CC) $(CFLAGS) -o program7 program7.cpp
	$(CC) $(CFLAGS) -o program8 program8.cpp
	$(CC) $(CFLAGS) -o program9 program9.cpp
	$(info TO END USER: Run this program with ./program0 fileName)
