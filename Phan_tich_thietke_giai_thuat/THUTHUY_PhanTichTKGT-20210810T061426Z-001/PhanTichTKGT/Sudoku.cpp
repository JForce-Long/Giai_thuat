#include <iostream>
#include <stdlib.h>
#include <fstream>
using namespace std;

int s[9][9], n;

void Input()
{
	fstream f;
	//f.open("input.txt");
	f.open("input2.txt");
//	f>>n;
	for(int i=0; i<9;i++)
	{
		for(int j=0; j<9; j++)
		{
			f>>s[i][j];
		}
	}
	f.close();
}

void print(int S[][9])
{
	int i=0, j=0;
	for(i=0; i<9;i++)
	{
		for(j=0; j<9; j++)
			cout << S[i][j] << " ";
		cout << endl;
	}
}
int feasible(int S[][9], int x, int y, int k)
{
    int i = 0, j = 0;
    
    for(i = 0; i <9 ; i++)
        if(S[x][i] == k) 
			return 0;
			
    for(i = 0; i <9 ; i++)
        if(S[i][y] == k) 
			return 0;

    int a = x/3, b = y/3;
    for(i = 3*a; i < 3*a+3; i++)
        for(j = 3*b; j < 3*b+3; j++)
            if(S[i][j] == k) 
				return 0;

    return 1;
}

void Sudoku(int S[][9], int x, int y){
    if(y == 9)
	{
        if(x == 8)
		{
            print(S);
            exit(0);
        } 
		else
            Sudoku(S, x+1,0);
    } 
	else if(S[x][y] == 0)
	{
        for (int k = 1; k <=9; k++)
            if(feasible(S,x,y,k))
			{
                S[x][y] = k;
                Sudoku(S, x, y+1);
                S[x][y] = 0;
            }
    } 
	else
        Sudoku(S,x,y+1);
}

int main()
{
	Input();
	print(s);
	cout << endl;
	Sudoku(s,0,0);
	return 0;
}
