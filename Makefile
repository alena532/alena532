all: BuildMain Tests

BuildMain:
	gcc -o  main main.c -std=c89
Tests:
	./main
	diff file.txt test.txt
