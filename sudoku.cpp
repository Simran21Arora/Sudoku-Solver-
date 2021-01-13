#include<iostream>
using namespace std;
void inputSudoku(int board[9][9])
{
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			cin>>board[i][j];
		}
		cout<<"\n";
	}
}

bool checkInput(int board[9][9])
{
  int r=0,c=0,i,j,m,n;
  while(r<=8 && c<=9)
  {
	for(i=0;i<9;i++)
	{
		if(board[r][i]>0)
		{
			for(j=0;j<9;j++)
			{
				if(board[r][i]==board[r][j] && i!=j)
				{
					return false;
				}
			}
		}
	}
	for(i=0;i<9;i++)
	{
		if(board[i][c]>0)
		{
			for(j=0;j<9;j++)
			{
				if(board[i][c]==board[j][c] && i!=j)
				{
					return false;
				}
			}
		}
	}
	
	int startRow=r-r%3;
	int startCol=c-c%3;
	
	for(i=startRow;i<startRow+3;i++)
	{
		for(j=startCol;j<startCol+3;j++) 
		{
			if(board[i][j]>0)
			{
				for(m=startRow;m<startRow+3;m++)
				{
					for(n=startCol;n<startCol+3;n++)
					{
						if(board[i][j]==board[m][n] && i!=m && j!=n)
						{
							return false;
						}
					}
				}
			}
		}
	}
	
	r++;
	c++;
  }
  
  return true;
}

bool isSafe(int board[9][9],int row,int col,int n)
{
	for(int i=0;i<9;i++)
	{
		if(board[row][i]==n)
		{
			return false;
		}
	}
	
	for(int i=0;i<9;i++)
	{
		if(board[i][col]==n)
		{
			return false;
		}
	}
	
	int startRow=row-row%3;
	int startCol=col-col%3;
	
	for(int i=startRow;i<startRow+3;i++)
	{
		for(int j=startCol;j<startCol+3;j++)
		{
			if(board[i][j]==n)
			{
				return false;
			}
		}
	}
	
	return true;
}
bool sudokuSolver(int board[9][9],int row,int col)
{
	if(row==8 && col==9)
	{
		return true;
	}
	
	if(col==9)
	{
		row++;
		col=0;
	}
	
	if(board[row][col]>0)
	{
		return sudokuSolver(board,row,col+1);
	}
	
	for(int i=1;i<=9;i++)
	{
		if(isSafe(board,row,col,i))
		{
			board[row][col]=i;
			
			if(sudokuSolver(board,row,col+1))
			{
				return true;
			}
		}
		
		board[row][col]=0;
	}
	
	return false;
}
void print(int board[9][9])
{
	int i,j;
	
	cout<<"\n";
	
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			cout<<board[i][j]<<" ";
		}
		cout<<"\n";
	}
}

int main()
{
	int board[9][9]={0},row=0,col=0;
	
	inputSudoku(board);
	
	if(checkInput(board))
	{
       	if(sudokuSolver(board,row,col))
       	{
		    print(board);
       	}
       	else
	    {
	     	cout<<"Solution does not exist!! Try another sudoku..\n";
      	}
    }
    else
    {
    	cout<<"\nYOU HAVE ENTERED INCORRECT VALUES IN SUDOKU. Please re-enter your values..";
    	while(!checkInput(board))
		{
			inputSudoku(board);
		}
        if(checkInput(board))
	    {
       	    if(sudokuSolver(board,row,col))
       	    {
		        print(board);
         	}
       	    else
	        {
	     	    cout<<"Solution does not exist!! Try another sudoku..\n";
         	}
        }
	}
return 0;
}
