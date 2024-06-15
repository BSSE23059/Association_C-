all: ./a.out

compRun:
	g++ -std=c++11 main.cpp Course.cpp Student.cpp Enrollment.cpp -o r.exe

compTest:
	g++ -std=c++11 test.cpp -o a.out

test: clean compTest; ./a.out

run: compRun; ./r.exe

clean:
	rm -f *.out
