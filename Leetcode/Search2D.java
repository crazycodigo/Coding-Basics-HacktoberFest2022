package LeetCodeSearch;

public class Search2D {
    public static void main(String[] args) {
        int[][] matrix = {
                {-5},
        };
        System.out.println(searchMatrix(matrix, -10));

    }
    static boolean searchMatrix(int[][] matrix, int target) {
        int row = matrix.length;
        int col = matrix[0].length;

        int rStart = 0;
        int eCol = col - 1;

        while (rStart < row) {
            if (matrix[rStart][eCol] == target) {
                return true;
            }
            if (eCol>0 && matrix[rStart][eCol] > target) {
                eCol--;
            } else {
                rStart++;
            }
        }
        return false;
    }
}
