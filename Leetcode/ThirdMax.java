/*
package LeetcodeSort;

public class ThirdMax {
    public static void main(String[] args) {
        int[] arr = {1,2,3};
        int ans = thirdMax(arr);
        System.out.println(ans);

    }
    static int thirdMax(int[] nums) {
        cyclicSort(nums);
        if (nums.length>=3){
            //int max = nums[1];
            for (int i = 0; i < nums.length; i++) {
                if (){
                    return nums[i-2];
                }
            }
        }
        return nums[nums.length-1];
    }

    static void cyclicSort(int[] nums){
        int i = 0;
        while (i<nums.length){
            //int correctindex = nums[i]-1;
            if (nums[i]<nums.length &&  nums[i]>0 && nums[i]!=nums[nums[i]-1]   ){
                swap(nums, i, nums[i]-1);
            }else {
                i++;
            }
        }
    }
    static void swap(int[] arr , int first, int second){
        int temp = arr[second];
        arr[second] = arr[first];
        arr[first] = temp;
    }
}

*/
