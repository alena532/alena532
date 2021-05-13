all: BuildMain BuildTests RunTests Clean

BuildMain:
	g++ -o main main.cpp Header.cpp

BuildTests:
	g++ -ftest-coverage -fprofile-arcs -O0 -o test -Dmain=_main main.cpp Header.cpp test.cpp

RunProgram:
	./main

RunTests:
	./test
	gcov -abcfu test.cpp
	gcov -abcfu main.cpp
	gcov -abcfu Header.cpp


Clean: 
	rm -rf bin