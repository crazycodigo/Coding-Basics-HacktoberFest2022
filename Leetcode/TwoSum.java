package LeetCodeSearch;

import java.lang.reflect.Array;
import java.util.Arrays;

public class TwoSum {
    /*Input: numbers = [2,7,11,15], target = 9
    Output: [1,2]
    Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].
}*/
    public static void main(String[] args) {
        int[] arr = {2,7,11,15};
        int target = 9;
        System.out.println(Arrays.toString(twoSum(arr, target)));

    }
    static int[] twoSum(int[] numbers, int target) {
        int start = 0;
        int end = numbers.length-1;
        while (start<end){
            int sum = numbers[start]+numbers[end];
            if(sum == target){
                return new int[] {numbers[start], numbers[end]};
            }
            if(sum>target){
                end--;
            }else {
                start++;
            }
        }
        return null;
    }
}