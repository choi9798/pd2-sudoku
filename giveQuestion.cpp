#include "sudoku.h"

void Sudoku::changeNum(int a, int b, int c, int d)
{
	int temp;
	temp = map[a][b];
	map[a][b] = map[c][d];
	map[c][d] = temp;
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
