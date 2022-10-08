package LeetcodeSort;

import java.lang.reflect.Array;
import java.util.Arrays;

public class MissingNumber {
    public static void main(String[] args) {
        int [] arr = {0, 2, 3, 4};
        int ans = cyclic(arr);
        System.out.println(ans);

    }
   /* static int missing(int[] nums){

    }*/
    static int cyclic(int[] nums ){
        int i = 0;
        while (i<nums.length){
            int correct = nums[i];
            if (nums[i]< nums.length && nums[i] != nums[correct]){
                swap(nums, i, correct);
            }else {
                i +=1;
            }
        }
        for (int j = 0; j < nums.length; j++) {
            if (nums[j] != j){
                return j;
            }

        }
        return nums.length;
    }
    static void swap(int[] arr, int first, int second){
        int temp = arr[second];
        arr[second] = arr[first];
        arr[first] = temp;
    }
}
