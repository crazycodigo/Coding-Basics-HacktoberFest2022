// 48. Rotate Image
// Medium

// You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

// You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

// Example 1:
// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [[7,4,1],[8,5,2],[9,6,3]]

// Example 2:
// Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
// Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]

// Constraints:

// n == matrix.length == matrix[i].length
// 1 <= n <= 20
// -1000 <= matrix[i][j] <= 1000

// CODE:

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {

        int rows = matrix.size();
        int cols = matrix[0].size();

        int temp = 0;
        // transposing

        for (int i = 0; i < rows; i++)
        {
            for (int j = i; j < cols; j++)
            {
                temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }

        // swapping first and last col

        int fcol = 0;
        int lcol = cols - 1;
        while (fcol < lcol)
        {
            for (int i = 0; i < rows; i++)
            {
                temp = matrix[i][fcol];
                matrix[i][fcol] = matrix[i][lcol];
                matrix[i][lcol] = temp;
            }
            fcol++;
            lcol--;
        }
    }
};