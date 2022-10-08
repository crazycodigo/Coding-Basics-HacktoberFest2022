package LeetCodeSearch;

public class CountNegativeInt {
    public static void main(String[] args) {
        int[][] arr = {
                {1, 2, 3, -1},
                {-1, -2, -3, -4},
                {-5, 5, 8, 3}
        };
        System.out.println(countNegatives(arr));

    }
    static int countNegatives(int[][] grid) {
        int count = 0;
        for (int row = 0; row < grid.length; row++) {
            for (int col = 0; col < grid[row].length; col++) {
                if (grid[row][col]<0){
                    count++;
                }
            }
        }
       return count;
    }
}
