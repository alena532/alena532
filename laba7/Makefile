all: BuildMain BuildTests RunTests Clean

BuildMain:
	g++ -o bgf/main  bgf/main.cpp

BuildTests:
	g++ -ftest-coverage -fprofile-arcs -O0 -o bgf/test -Dmain=_main bgf/main.cpp bgf/test.cpp

RunProgram:
	bgf/main

RunTests:
	bgf/test
	gcov -abcfu bgf/test.cpp


Clean: 
	rm -rf bin