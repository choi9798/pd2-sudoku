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
		bool isCorrect();
		bool nozero();
		void zero_position();
		void possible(int arr[][9]);
		void backtrack();
	private:
		int map[9][9] = {{0,3,0,5,0,0,8,0,4},
		                 {0,0,0,0,7,0,0,6,0},
		                 {0,8,0,2,3,0,9,1,5},
		                 {0,0,8,0,5,3,2,0,0},
		                 {0,0,0,9,0,2,0,0,0},
		                 {0,0,5,1,8,0,4,0,0},
		                 {9,2,7,0,6,8,0,5,0},
		                 {0,1,0,0,2,0,0,0,0},
		                 {5,0,6,0,0,1,0,2,0}};
		int real_map[9][9];
		int ans[9][9];
		int possible_num[9];
		int zero_posRow[9];
		int zero_posCol[9];
		int answer = 0;
		int index;
};
