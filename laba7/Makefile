all: BuildMain BuildTests RunTests Clean

BuildMain:
	g++ -o main main.cpp

BuildTests:
	g++ -ftest-coverage -fprofile-arcs -O0 -o test -Dmain=_main main.cpp test.cpp

RunProgram:
	main

RunTests:
	test
	gcov -abcfu test.cpp


Clean: 
	rm -rf bin