package LeetcodeSort;

public class PowerOfTwo {
    public static void main(String[] args) {
        int num = 1;
        System.out.println(twoPower(num));
    }
    static boolean twoPower(int n){
        int bit = 1;
        return helper(n, bit);
    }

    private static boolean helper(int num, int bit) {
        if (num<=bit){
            return true;
        }
        if ((num & bit) == 0){
            return helper(num, bit<<1);
        }
        return false;
    }
}
