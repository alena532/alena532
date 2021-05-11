all: BuildMain BuildTests RunTests Clean

BuildMain:
	g++ -o main  main.cpp

BuildTests:
	g++ -o test -Dmain=_main main.cpp test.cpp

RunProgram:
	./main

RunTests:
	./test

Clean: 
	rm -rf bin