#include <iostream>
#include <cstdlib>
#include<time.h>

using namespace std;

// N is the size of the 2D matrix N*N
#define N 9

// A utility function to print grid 
void print(int arr[N][N])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cout << arr[i][j] << " ";
		cout << endl;
	}
}





bool isSafe(int grid[N][N], int row, int col, int num)
{
	
    //we start from the left top to solve the sudoku and if any number in col is equal to the number we assigned then return false
	for (int x = 0; x <= 8; x++)
		{if (grid[row][x] == num)
			{return false;}
		    
		}

	//we check downward for the number with similar value in row if found then return false
	for (int x = 0; x <= 8; x++)
		{if (grid[x][col] == num)
			{return false;}
		}

	//check the sub block that number belongs to for the number with same value if found return false
	int startRow = row - row % 3,
			startCol = col - col % 3;

	for (int i = 0; i < 3; i++)
		{for (int j = 0; j < 3; j++)
			{if (grid[i + startRow][j + startCol] == num)
				{return false;}
			}
		}
    //if number with same value is not found the return true
	return true;
}







bool solveSudoku(int grid[N][N], int row, int col)
{
	//we start from coordinate 0,0 if we reach the last point then return true which means sudoku is solved
	if (row == N - 1 && col == N)
		return true;

	//if we reach to the last column number we get to the next row
	if (col == N) {
		row++;
		col = 0;
	}

	//if there is already a number in the bock we are currently on then move to the next block
	if (grid[row][col] > 0)
		{return solveSudoku(grid, row, col + 1);}



    //if the number is zero then we need to fill the correct number i the block
	for (int num = 1; num <= N; num++)
	{
		
		//checking if num is correct for the selected position as of now
		if (isSafe(grid, row, col, num))
		{
			
		    //assigning num to the selected position
			grid[row][col] = num;
		
			//checking if the this num is also correct for future solving
			if (solveSudoku(grid, row, col + 1))
				return true;
		}
	    //if num is not correct then assigning 0 again to the selected place (for next loop num will be changed and we weill check again for the same position)
		grid[row][col] = 0;
	}
	return false;
}

//sample sudoku
/*0 0 0 0 5 8 4 0 0
2 4 0 9 0 0 0 8 3
0 0 8 0 3 2 9 0 5
0 0 0 0 9 0 0 0 0
7 0 2 5 0 0 3 0 9
8 1 0 0 0 3 2 5 0
4 9 7 8 0 0 1 0 2
0 0 0 3 7 0 5 0 0
5 0 3 1 2 0 7 0 0*/





int main()
{
    char start='n';
    do{
	int choice;
	cout<<"1. I want a new sudoku proplem "<<endl;
	cout<<"2. I have a new sudoku problem and need its solution"<<endl;
    cin>>choice;
	int grid[N][N];
    if(choice==2)//if user wants to get the puzzel solved
	{
	    cout<<"Enter your sudoku -"<<endl;
		for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			cin>>grid[i][j];
		}
	}

	if (solveSudoku(grid, 0, 0))
	{cout<<endl;
	cout<<endl;
		print(grid);}
	else
	{	cout << "no solution exists " << endl;}
		cout<<"do you want to quit y/n"<<endl;
		cin>>start;
		
      
	return 0;
	}	else if(choice==1)//if user wants to get a new puzzel
	{
		//marking all elements of the puzzel 0 innitially
		for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			grid[i][j]=0;
		}
	}
	  srand(time(0));
	  grid[0][0]=rand()%9;//assigning a random number at 0,0
	  grid[3][3]=rand()%9;//assigning a random number at 3,3 just for the reason so that every time the suduko solve function solve the function differently
        solveSudoku(grid, 0, 1);//solving the sudoku
		srand(time(0));//using this function rand does not keep returning the same value
	    int no_of_blocks=50+rand()%10;//selecting how many blocks we need to delete to make it a problem in a sudoku puzzel
		for(int i=0;i<no_of_blocks;i++)
		{
			
			int row1=0,col1=0;
			row1=rand()%9;
			col1=rand()%9;
			grid[row1][col1]=0;
		}
		print(grid);
		cout<<"do you want to quit y/n"<<endl;
		cin>>start;
	}else{
		cout<<"invalid input"<<endl;
	}
    }while(start=='n');
    return 0;
}
