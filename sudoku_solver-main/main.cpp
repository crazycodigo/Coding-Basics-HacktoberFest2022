#include <iostream>
#include <fstream>

using namespace std;

class SudokuFrame
{
public:
    SudokuFrame()
    {
        if (menu())
        {
            system("cls");
            cout << "Your puzzle has been solved!\n\n"
                 << endl;
            solve(sudokuFrame, 0, 0);
            cout << endl
                 << endl;
        }
    }
    void displayFrame();

private:
    int sudokuFrame[9][9]; // This will store the Sudoku
    bool menu();
    void readFrameValues();
    void readFrameValuesFile();
    void solve(int sudokuFrame[9][9], int row, int col);
    bool valid(int sudokuFrame[9][9], int row, int col, int po);
};
void SudokuFrame::displayFrame()
{
    cout << "++===================++=================++" << endl
         << endl;
    int rowIter, colIter;

    for (rowIter = 0; rowIter < 9; rowIter++)
    {
        for (colIter = 0; colIter < 9; colIter++)
        {
            if (colIter == 0)
            {
                cout << "[ " << sudokuFrame[rowIter][colIter] << "   ";
            }
            else if (colIter == 8)
            {
                cout << sudokuFrame[rowIter][colIter] << "]";
            }
            else if (colIter == 2 || colIter == 5)
            {
                cout << sudokuFrame[rowIter][colIter] << "]    [";
            }
            else
            {
                cout << sudokuFrame[rowIter][colIter] << "   ";
            }
        }
        if (rowIter == 2 || rowIter == 5)
        {
            cout << endl
                 << "-------------++-------------++----------" << endl;
        }
        else
        {
            cout << endl;
        }
    }
    cout << endl
         << "++===================++=================++";
}

bool SudokuFrame::menu()
{
    cout << "\t\t\t\t**********Sudoku Solver************\n";
    cout << "Welcome to Sudoku Solver!" << endl;
    cout << "Before we start solving, You need to input the puzzle into this program" << endl
         << endl;
    cout << "You can either:-\n";
    cout << "1 for Input the puzzle by entering the values manually." << endl;
    cout << "2 for Input the puzzle by reading a file with values in it." << endl;

    int option;
    cin >> option;

    if (option == 1)
    {
        readFrameValues();
        return true;
    }
    else if (option == 2)
    {
        readFrameValuesFile();
        return true;
    }
    else
    {
        cout << "Oops!! You have entered wrong value...Please try again!!" << endl;
        return false;
    }
    return true;
}

void SudokuFrame::readFrameValues()
{
    cout << endl
         << endl
         << "Enter the value if value is between (1 to 9)" << endl;
    cout << "Enter 0 if cell is empty" << endl;

    for (int rowiter = 0; rowiter < 9; rowiter++)
    {
        for (int coliter = 0; coliter < 9; coliter++)
        {
            int current_value;

            cout << "Enter the value for cell[" << rowiter + 1 << "][" << coliter + 1 << "] --> ";
            cin >> current_value;

            if (current_value <= 0 || current_value > 9)
            {
                while (true)
                {
                    cout << "Oops !! You have entered wrong value!! Try again!! " << endl;
                    cout << "Enter the value for cell[" << rowiter + 1 << "][" << coliter + 1 << "] --> ";
                    cin >> current_value;

                    if (current_value >= 0 && current_value <= 9)
                    {
                        break;
                    }
                }
            }
            sudokuFrame[rowiter][coliter] = current_value;
        }
    }
}

void SudokuFrame::readFrameValuesFile()
{

    string filename; // Getting filename from the user

    cout << endl
         << endl
         << "Enter the name of the file that contains the Sudoku puzzle." << endl;
    cout << "\t --> ";
    cin >> filename;

    ifstream sudokufile;
    sudokufile.open(filename, ios::in);

    for (int rowiter = 0; rowiter < 9; rowiter++)
    {
        for (int coliter = 0; coliter < 9; coliter++)
        {
            int current_value;

            sudokufile >> current_value;

            if (!(current_value >= 0 && current_value <= 9))
            {
                cout << endl
                     << "Value " << ((rowiter * 9) + coliter + 1) << filename << " seems to be wrong..Try again with different value" << endl;
                exit(EXIT_FAILURE);
            }

            sudokuFrame[rowiter][coliter] = current_value;

            if (sudokufile.eof())
            {
                break;
            }
        }
    }

    sudokufile.close();
}

void SudokuFrame::solve(int sudokuFrame[9][9], int current_row, int current_col)
{

    if (current_row == 9)
    {
        displayFrame();
        return;
    }
    int row = 0, col = 0;
    if (current_col == 8)
    {
        row = current_row + 1;
        col = 0;
    }
    else
    {
        row = current_row;
        col = current_col + 1;
    }

    if (sudokuFrame[current_row][current_col] != 0)
    {
        solve(sudokuFrame, row, col);
    }
    else
    {
        for (int po = 1; po <= 9; po++)
        {
            if (valid(sudokuFrame, current_row, current_col, po) == true)
            {
                sudokuFrame[current_row][current_col] = po;
                solve(sudokuFrame, row, col);
                sudokuFrame[current_row][current_col] = 0;
            }
        }
    }
}

bool SudokuFrame::valid(int sudokuFrame[9][9], int row, int col, int val)
{
    for (int j = 0; j < 9; j++)
    {
        if (sudokuFrame[row][j] == val)
        {
            return false;
        }
    }
    for (int i = 0; i < 9; i++)
    {
        if (sudokuFrame[i][col] == val)
        {
            return false;
        }
    }

    int cori = 3 * (row / 3), corj = 3 * (col / 3);

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (sudokuFrame[cori + i][corj + j] == val)
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    SudokuFrame solver;
    return 0;
}
