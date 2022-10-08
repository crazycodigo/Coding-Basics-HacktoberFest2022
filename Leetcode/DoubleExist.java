package LeetCodeSearch;

public class DoubleExist {
    public static void main(String[] args) {
        int[] arr = {-20,8,-6,-14,0,-19,14,4};
        System.out.println(checkIfExist(arr));
    }
    static boolean checkIfExist(int[] arr) {
        int rows = 0;
        int col = arr.length;
        for (int row = 0; row < col; row++) {
            for (int eRow = col-1; eRow>=0; eRow--){
                if (arr[row]*2 == arr[eRow] || arr[row]==arr[eRow]*2){
                    return true;
                }
            }
        }
        return false;
    }
}
