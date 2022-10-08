package LeetcodeSort;

import java.util.ArrayList;
import java.util.List;

public class AllDuplicateNumber {
    public static void main(String[] args) {
        int [] arr = {1};
        List<Integer> ans = findDuplicates(arr);
        System.out.println(ans);

    }
    static List<Integer> findDuplicates(int[] nums) {
        List<Integer> list = new ArrayList<>();
        cyclicSort(nums);
        for (int index = 0; index <nums.length; index++) {
            if(nums[index] != index+1){
                list.add(nums[index]);
            }
        }
        return list;
    }
    static void cyclicSort(int[] arr){
        int i = 0;
        while (i< arr.length){
            int correctIndex = arr[i]-1;
            if (arr[i] != arr[correctIndex]){
                swap(arr, i, correctIndex);
            }else {
                i++;
            }
        }
    }
    static void swap(int[] arr, int first , int second){
        int temp = arr[second];
        arr[second] = arr[first];
        arr[first] = temp;
    }
}

