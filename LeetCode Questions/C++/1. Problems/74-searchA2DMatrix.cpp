// 74. Search a 2D Matrix
// Medium

// Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

// Integers in each row are sorted from left to right.
// The first integer of each row is greater than the last integer of the previous row.

// Example 1:
// Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
// Output: true

// Example 2:
// Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
// Output: false

// Constraints:
// m == matrix.length
// n == matrix[i].length
// 1 <= m, n <= 100
// -104 <= matrix[i][j], target <= 104

// CODE:

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {

        int rows = matrix.size();
        int cols = matrix[0].size();

        int s = 0;
        int e = rows * cols - 1;
        int m = s + (e - s) / 2;

        while (s <= e)
        {
            int ele = matrix[m / cols][m % cols];
            if (ele == target)
            {
                return 1;
            }
            else if (ele < target)
                s = m + 1;
            else
                e = m - 1;

            m = s + (e - s) / 2;
        }
        return 0;
    }
};
