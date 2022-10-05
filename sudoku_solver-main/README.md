
# Sudoku-Solver
This is a program which solves 9x9 Sudoku puzzles. **Written completely in C++** and **built wholly from scratch**, this program reads input either from a user or from a file containing the Sudoku values and solves the puzzle. It employs concepts such as backtracking and recursion.

### Getting Started
* Simply download the ```main.cpp``` file and run it using any standard c++ compiler.
* Once downloaded, compiled and run; the program will require the user to input the Sudoku puzzle into it. There are two ways to do this.
    * The user can either input the values manually one-by-one when the program is running.
    * The user can write all the values into a file, seperated by whitespaces. The file can have any name or extension. When the program is running, the user will be prompted to simply enter the name of the file (with extension). **Below** is an example of how the contents of such a file might look. 
    Look at the ```sample1.txt``` files for more examples.
    
        ```
        3 0 6 5 0 8 4 0 0
        5 2 0 0 0 0 0 0 0
        0 8 7 0 0 0 0 3 1
        0 0 3 0 1 0 0 8 0
        9 0 0 8 6 3 0 0 5
        0 5 0 0 9 0 6 0 0
        1 3 0 0 0 0 2 5 0
        0 0 0 0 0 0 0 7 4
        0 0 5 2 0 6 3 0 0
        ```

* Once solved, the Sudoku puzzles shall be displayed like this.
    ```

    ++===================++=================++
    
    [ 3   1   6]    [5   7   8]    [4   9   2]
    [ 5   2   9]    [1   3   4]    [7   6   8]
    [ 4   8   7]    [6   2   9]    [5   3   1]
    -------------++-------------++----------
    [ 2   6   3]    [4   1   5]    [9   8   7]
    [ 9   7   4]    [8   6   3]    [1   2   5]
    [ 8   5   1]    [7   9   2]    [6   4   3]
    -------------++-------------++----------
    [ 1   3   8]    [9   4   7]    [2   5   6]
    [ 6   9   2]    [3   5   1]    [8   7   4]
    [ 7   4   5]    [2   8   6]    [3   1   9]
    
    ++===================++=================++
    ```

### How It Works
This particular algorithm employs the use of backtracking, one of the more common methods to solve Sudoku puzzles. I have written a simple algorithm to give an idea of how the program works.

1. Start.
2. We start with the first empty cell.
3. We generate a list of possible valid values that can be filled in that cell.
4. We iterate over this list and start with the first value. This value is placed in the required cell.
5. We move on to the next cell. We again generate a list of possibilities. However, if no list can be generated, then this means that there is something wrong with the value of the previous cell. We then move back to the previous cell and place the next value on the generated list in the cell now. We repeat this step until the current cell has a valid value placed inside it.
6. We stop when we reach the 81st cell (the last cell in a Sudoku puzzle) and have placed a valid value.
7. The puzzle has now been solved.
8. Stop.
