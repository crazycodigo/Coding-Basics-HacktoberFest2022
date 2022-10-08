package LeetcodeSort;

import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class TargetAfterSorting {
    public static void main(String[] args) {
        int[] arr = {1,4,3};
        List<Integer> ans =aftersorting(arr, 4);
        System.out.println((ans));
        sort(arr);
        System.out.println(Arrays.toString(arr));
    }
    static List<Integer> aftersorting(int[] nums, int target) {
        sort(nums);
        ArrayList<Integer> list = new ArrayList<>();
        for (int i = 0; i <= nums.length-1; i++) {
            if (nums[i]==target){
                list.add(i);
            }
        }
        return list;
    }
    static void sort(int[] arr){
        boolean swapped;
        for (int i = 0; i < arr.length-1; i++) {
            swapped = false;
            for (int j = 1; j <= arr.length-1-i; j++) {
                if (arr[j]<arr[j-1]){
                    swap(arr, j-1, j);
                    swapped = true;
                }
            }
            if (!swapped){
                break;
            }
        }
    }
    static void swap(int[] arr, int start, int end){
        int temp = arr[end];
        arr[end]= arr[start];
        arr[start] = temp;
    }
}
