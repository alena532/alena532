all: BuildMain BuildTests RunTests Clean

BuildMain:
	gcc -o  main main.c -std=c89

BuildTests:
	gcc -o test -Dmain=_main main.c test.c

RunProgram:
	./main

RunTests:
	./test

Clean: 
	rm -rf bin