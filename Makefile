giveQuestion: Sudoku.o giveQuestion.o solve.o transform.o
	g++ -o giveQuestion giveQuestion.o Sudoku.o
	g++ -o solve solve.o Sudoku.o
	g++ -o transform transform.o Sudoku.o

Sudoku.o: Sudoku.cpp Sudoku.h
	g++ -c Sudoku.cpp

giveQuestion.o: giveQuestion.cpp Sudoku.h
	g++ -c giveQuestion.cpp

solve.o: solve.cpp Sudoku.h
	g++ -c solve.cpp

transform.o: transform.cpp Sudoku.h
	g++ -c transform.cpp

clean:
	rm -rf *.o
