#include "sudoku.h"

void Sudoku::transform()
{
	readIn();
	change();
}

void Sudoku::change()
{
	srand(time(NULL));
	changeNum(rand()%9, rand()%9, rand()%9, rand()%9);
	changeRow(rand()%3, rand()%3);
	changeCol(rand()%3, rand()%3);
	rotate(rand()%101);
	flip(rand()%2);
}
