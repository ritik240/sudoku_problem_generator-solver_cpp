# sudoku_problem_generator-solver_cpp

A sudoku problem generator and solver written in c++

ABOUT THE GAME:

Sudoku is a logic-based, combinatorial number-placement puzzle. In classic Sudoku, the objective is to fill a 9 × 9 grid with digits so that each column, each row, and each of the nine 3 × 3 subgrids that compose the grid (also called "boxes", "blocks", or "regions") contain all of the digits from 1 to 9. The puzzle setter provides a partially completed grid, which for a well-posed puzzle has a single solution.

A sudoku puzzle       
![image](https://user-images.githubusercontent.com/108234496/179342144-27abdc40-dd67-47bb-b60e-f9d4e730142d.png)



ABOUT THE PROGRAM:

1. Solver:

The solver part has a 'issafe' function that checks if the number selected by the code for a perticular position is correct or not. The code kees on checking for the correct number from 1 to 9 till it finds the correct one and moves to the next location. If it cant find a solution of the puzzel because of the numbers selected previously then it will backtrack to that number and look for another number that is sutable for that position and get us to the correct sudoku solution. This is a recursive algorithm that calls itself when it wants to move to the next block of the sudoku and backtracks to the original block when answer is not found through that number in the present block.




2. Sudoku generator:

To generate a new sudoku problem everytime the user need it, i first created an empty(zero in every block) sudoku grid and then filled two random numbers(1-9) at random two blockes such that they both satisfy the sudoku rules. we did this because these two random numbers will help us to create different and new sudoku everytime and decresing the posibility of same occurance. Now we send this grid to the solver part of the code to solve it and then after receiving a solved sudiku we empty(filling them with zero) some  blocks to make the solved sudoku a problem. 
