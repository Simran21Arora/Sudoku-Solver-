# Sudoku-Solver-
PROJECT  - SUDOKU  SOLVER

About Sudoku : Sudoku is a logic-based, number-placement puzzle in which the objective is to fill a 9x9 grid with digits so that each column, each row and each of the nine 3x3 subgrids that compose the grid contain all of the digits from 1 to 9. 

About Sudoku Solver : In this project Sudoku solver is made which takes Sudoku unsolved 9x9 grid as input and gives solved Sudoku grid as output. Programming language used in this project is c++.

Functions created in this project : 

•	void inputSudoku(int board[9][9]) : This function takes unsolved sudoku input from user in the board[9][9].

•	bool checkInput(int board[9][9]) : This function checks whether the input given user by is correct or not, i.e.., it checks that there should not be repetition of numbers from 1 to 9 in any row, column or any 3x3 subgrid. If there is repetition of number in any row, column or 3x3 subgrid the it returns false and user will be asked to input values again.

•	bool isSafe(int board[9][9],int row,int col,int n) : This function checks whether the number to be placed at that index is safe or not, i.e.., it checks whether the number to be assigned is present in same row ,column or 3x3 subgrid then it returns false else it returns true.

•	bool sudokuSolver(int board[9][9],int row,int col) : This function solves the Sudoku till there is any unsolved position left in it. It iterates through each index row and column wise and checks and assigns correct numbers to it. It runs till last row and column and checks that all the positions are filled with correct answers and returns true and if there exists no solution for this particular unsolved Sudoku then it returns false. 

•	void print(int board[9][9]) : This function prints the complete solved Sudoku.

•	int main() :  main() function calls inputSudoku(board) function that inputs the Sudoku. Then if checkInput(board) function returns true then sudokuSolver(board,row,col) is called if this function also returns true then print(board) function is called which prints the Sudoku solution. If sudokuSolver(board,row,col) function returns false then it prints that no solution exists for this Sudoku. If checkInput(board) function returns false then user is prompted to enter values in Sudoku again till user enters the correct Sudoku to be solved and when user enters correct board then sudokuSolver(board,row,col) and print(board) will be called.
