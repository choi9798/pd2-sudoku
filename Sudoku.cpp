#include "Sudoku.h"

Sudoku::Sudoku()
{
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			real_map[i][j] = 0;
			map[i][j] = 0;
		}
	}
	transform();
}

void Sudoku::giveQuestion()
{
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			cout << real_map[i][j] << " ";
		}
		cout << endl;
	}
}

void Sudoku::readIn()
{
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			real_map[i][j] = map[i][j];
		}
	}
}

void Sudoku::transform()
{
	srand(time(NULL));
	changeNum(rand()%9+1, rand()%9+1);
	changeRow(rand()%3, rand()%3);
	changeCol(rand()%3, rand()%3);
	rotate(rand()%101);
	flip(rand()%2);
}


void Sudoku::changeNum(int a, int b)
{
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			if(map[i][j] == a)
			{
				map[i][j] = b;
				continue;
			}
			else if(map[i][j] == b)
			{
				map[i][j] = a;
				continue;
			}
		}
	}
}

void Sudoku::changeRow(int a, int b)
{
	int temp;
	if((a>=0 && a<=2 && b>=3 && b<=5) || (b>=0 && b<=2 && a>=3 && a<=5))
	{
		for(int i=1;i<=3;i++)
		{
			for(int j=1;j<=9;j++)
			{
				temp = map[i-1][j-1];
				map[i-1][j-1] = map[i+3-1][j-1];
				map[i+3-1][j-1] = temp;
			}
		}
	}
	else if((a>=0 && a<=2 && b>=6 && b<=8) || (b>=0 && b<=2 && a>=6 && a<=8))
	{
		for(int i=1;i<=3;i++)
		{
			for(int j=1;j<=9;j++)
			{
				temp = map[i-1][j-1];
				map[i-1][j-1] = map[i+6-1][j-1];
				map[i+6-1][j-1] = temp;
			}
		}
	}
	else if((a>=3 && a<=5 && b>=6 && b<=8) || (b>=3 && b<=5 && a>=6 && a<=8))
	{
		for(int i=3;i<=6;i++)
		{
			for(int j=1;j<=9;j++)
			{
				temp = map[i-1][j-1];
				map[i-1][j-1] = map[i+3-1][j-1];
				map[i+3-1][j-1] = temp;
			}
		}
	}
}

void Sudoku::changeCol(int a, int b)
{
	int temp;
	if((a>=0 && a<=2 && b>=3 && b<=5) || (b>=0 && b<=2 && a>=3 && a<=5))
	{
		for(int i=1;i<=3;i++)
		{
			for(int j=1;j<=9;j++)
			{
				temp = map[j-1][i-1];
				map[j-1][i-1] = map[j+3-1][i-1];
				map[j+3-1][i-1] = temp;
			}
		}
	}
	else if((a>=0 && a<=2 && b>=6 && b<=8) || (b>=0 && b<=2 && a>=6 && a<=8))
	{
		for(int i=1;i<=3;i++)
		{
			for(int j=1;j<=9;j++)
			{
				temp = map[j-1][i-1];
				map[j-1][i-1] = map[j+6-1][i-1];
				map[j+6-1][i-1] = temp;
			}
		}
	}
	else if((a>=3 && a<=5 && b>=6 && b<=8) || (b>=3 && b<=5 && a>=6 && a<=8))
	{
		for(int i=4;i<=6;i++)
		{
			for(int j=1;j<=9;j++)
			{
				temp = map[j-1][i-1];
				map[j-1][i-1] = map[j-1][i+3-1];
				map[j-1][i+3-1] = temp;
			}
		}
	}
}

void Sudoku::rotate(int n)
{
	int temp;
	if(n%4 != 0)
	{
		if(n%4 == 1)
		{
			for(int i=0;i<5;i++)
			{
				for(int j=0+i;j<8-i;j++)
				{
					temp = map[i][j];
					map[i][j] = map[i][8-j];
					map[i][8-j] = map[8-i][8-j];
					map[8-i][8-j] = map[8-i][j];
					map[8-i][j] = temp;
				}
			}
		}
		else if(n%4 == 2)
		{
			for(int k=1;k<=2;k++)
			{
				for(int i=0;i<5;i++)
				{
					for(int j=0+i;j<8-i;j++)
					{
						temp = map[i][j];
						map[i][j] = map[i][8-j];
						map[i][8-j] = map[8-i][8-j];
						map[8-i][8-j] = map[8-i][j];
						map[8-i][j] = temp;
					}
				}
			}
		}
		else if(n%4 == 3)
		{
			for(int i=0;i<5;i++)
			{
				for(int j=0+i;j<8-i;j++)
				{
					temp = map[i][j];
					map[i][j] = map[8-i][j];
					map[8-i][j] = map[8-i][8-j];
					map[8-i][8-j] = map[i][8-j];
					map[i][8-j] = temp;
				}
			}
		}
	}
}

void Sudoku::flip(int n)
{
	int temp;
	if(n==0)
	{
		for(int i=0;i<9;i++)
		{
			temp = map[0][i];
			map[0][i] = map[8][i];
			map[8][i] = temp;

			temp = map[1][i];
			map[1][i] = map[7][i];
			map[7][i] = temp;

			temp = map[2][i];
			map[2][i] = map[6][i];
			map[6][i] = temp;
			
			temp = map[3][i];
			map[3][i] = map[5][i];
			map[5][i] = temp;
		}
	}
	else if(n==1)
     {
         for(int i=0;i<9;i++)
         {
             temp = map[i][0];
             map[i][0] = map[i][8];
             map[i][8] = temp;

             temp = map[i][1];
             map[i][1] = map[i][7];
             map[i][7] = temp;

             temp = map[i][2];
             map[i][2] = map[i][6];
             map[i][6] = temp;

             temp = map[i][3];
             map[i][3] = map[i][5];
             map[i][5] = temp;
         }
    }
}

bool Sudoku::checkUnity(int arr[])
{
	int arr_unity[9];
	for(int i=0;i<9;i++)
	{
		arr_unity[i] = 0;
	}
	for(int i=0;i<9;i++)
	{
		++arr_unity[arr[i]-1];
	}
	for(int i=0;i<9;i++)
	{
		if(arr_unity[i] != 1)
			return false;
	}
	return true;
}

bool Sudoku::isCorrect()
{
	bool check_result;
	int check_arr[9];

	for(int i=0;i<9;i++) // check rows
	{
		for(int j=0;j<9;j++)
		{
			check_arr[j] = real_map[i][j];
		}
		check_result = checkUnity(check_arr);
		if(check_result == false)
		{
			return false;
		}
	}
	for(int i=0;i<9;i++) // check columns
	{
		for(int j=0;j<9;j++)
		{
			check_arr[j] = real_map[j][i];
		}
		check_result = checkUnity(check_arr);
		if(check_result == false)
		{
			return false;
		}
	}
	/* check cells */
	for(int k=0;k<3;k++)
	{
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				check_arr[3*i+j] = real_map[i][3*k+j];
			}
		}
		check_result = checkUnity(check_arr);
		if(check_result == false)
			return false;
	}
	for(int k=0;k<3;k++)
	{
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				check_arr[3*i+j] = real_map[i+3][3*k+j];
			}
		}
		check_result = checkUnity(check_arr);
		if(check_result == false)
			return false;
	}
	for(int k=0;k<3;k++)
	{
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				check_arr[3*i+j] = real_map[i+6][3*k+j];
			}
		}
		check_result = checkUnity(check_arr);
		if(check_result == false)
			return false;
	}
	/* check cells */
	return true;
}

bool Sudoku::nozero()
{
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			if(real_map[i][j] == 0)
			{
				return false;
			}
		}
	}
	return true;
}

void Sudoku::possible(int arr[][9])
{
	int existed[9];
	int n=0;
	int sRow, sCol;
	int row, col;
	for(int i=0;i<9;i++)
	{
		possible_num[i] = 0;
		existed[i] = 0;
	}
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			if(real_map[i][j] == 0)
			{
				row = i;
				col = j;
				break;
			}
		}
	}
	for(int j=0;j<9;j++)
	{
		if(arr[row][j] != 0)
		{
			existed[arr[row][j]-1] = 1;
		}
	}
	for(int i=0;i<9;i++)
	{
		if(arr[i][col] != 0)
		{
			existed[arr[i][col]-1] = 1;
		}
	}
	if(row >= 0 && row<=2)
		sRow = 0;
	else if(row>=3 && row<=5)
		sRow = 3;
	else if(row>=6 && row<=8)
		sRow = 6;
	if(col >= 0 && col<=2)
         sCol = 0;
    else if(col>=3 && col<=5)
         sCol = 3;
    else if(col>=6 && col<=8)
         sCol = 6;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(arr[i+sRow][j+sCol] != 0)
			{
				existed[arr[i+sRow][j+sCol]-1] = 1;
			}
		}
	}
	for(int i=0;i<9;i++)
	{
		if(existed[i] == 0)
		{
			possible_num[n] = i+1;
			n++;
		}
	}
}

void Sudoku::zero_position()
{
	int n=0;
	for(int i=0;i<9;i++)
	{
		zero_posRow[i] = 0;
		zero_posCol[i] = 0;
	}
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			if(real_map[i][j] == 0)
			{
				zero_posRow[n] = i;
				zero_posCol[n] = j;
				n++;
			}
		}
	}
}

void Sudoku::backtrack()
{
	int k=0;
	if(isCorrect() != true)
	{
		real_map[zero_posRow[index]][zero_posCol[index]] = 0;
		possible(real_map);
		return;
	}
	if(nozero() == true)
	{
		for(int i=0;i<9;i++)
		{
			for(int j=0;j<9;j++)
			{
				ans[i][j] = real_map[i][j];
				answer++;
				if(answer>=2)
				{
					cout << "2" << endl;
					exit(0);
				}
				real_map[zero_posRow[index]][zero_posCol[index]] = 0;
				possible(real_map);
				return;
			}
		}
	}
	possible(real_map);
	index++;
	if(possible_num[0] == 0)
	{
		index--;
		real_map[zero_posRow[index]][zero_posCol[index]] = 0;
		possible(real_map);
		return;
	}
	if(answer>=2)
	{
		cout << "2" << endl;
		exit(0);
	}
	while(possible_num[k] > 0)
	{
		real_map[zero_posRow[index]][zero_posCol[index]] = possible_num[k];
		k++;
		backtrack();
	}
	index--;
	if(index<0)
		return;
	real_map[zero_posRow[index]][zero_posCol[index]] = 0;
	possible(real_map);
}

void Sudoku::solve()
{
	if(isCorrect() == false)
	{
		cout << "0" << endl;
		exit(0);
	}
	else if(nozero() == true && isCorrect() == true)
	{
		cout << "1" << endl;
		exit(0);
	}
	zero_position();
	answer = 0;
	index = -1;
	backtrack();
	if(answer == 0)
	{
		cout << "0" <<endl;
		exit(0);
	}
	else if(answer == 1)
	{
		cout << "1" << endl;
		for(int i=0;i<9;i++)
		{
			for(int j=0;j<9;j++)
			{
				cout << ans[i][j] << " ";
			}
			cout << endl;
		}
		exit(0);
	}
}


