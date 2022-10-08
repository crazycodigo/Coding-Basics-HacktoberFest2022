package LeetcodeSort;

import java.lang.reflect.Array;
import java.util.Arrays;

public class SetMismatch {
    public static void main(String[] args) {
        int [] arr = {1,3,3};
        System.out.println(Arrays.toString(findErrorNums(arr)));

    }
    static int[] findErrorNums(int[] nums){
        cyclicSort(nums);
        for(int i = 0; i <nums.length ; i++){
            if(nums[0] != 1){
                return new int[] {i+1, i+2};
            }
            if(nums[i] != i+1){
                return new int[] {nums[i], i+1};
            }
        }
        return null;
    }

    static void cyclicSort(int[] arr){
        int i = 0;
        while(i<arr.length){
            int correct = arr[i]-1;
            if(arr[i] != arr[correct]){
                swap(arr, i, correct);
            }else {
                i++;
            }
        }
    }
    static void swap(int[] arr , int first , int second){
        int temp = arr[second];
        arr[second] = arr[first];
        arr[first] = temp;
    }
}