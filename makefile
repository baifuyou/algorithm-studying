assemblyLine : assemblyLine.c
	gcc -Wall -g -o $@ $^ -lm
