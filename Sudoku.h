#include<iostream>
#include<cstdlib>
using namespace std;

class Sudoku {
	public:
		Sudoku();
		void giveQuestion();
		void readIn();
		void solve();
		void changeNum(int a, int b);
		void changeRow(int a, int b);
		void changeCol(int a, int b);
		void rotate(int n);
		void flip(int n);
		void transform();
		bool checkUnity(int arr[]);
		bool isCorrect() = true;
		bool nozero() = false;
		void zero_position();
		void possible(int arr[][9]);
		void backtrack();
	private:
		int map[9][9];
		int real_map[9][9];
		int ans[9][9];
		int possible_num[9];
		int zero_posRow[9];
		int zero_posCol[9];
		int answer = 0;
		int index;
};
