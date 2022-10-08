package LeetcodeSort;

public class FirstMissingPositive {
    public static void main(String[] args) {
        int[] arr = {7,8,9,11,12};
        int ans = firstMissingPositive(arr);
        System.out.println(ans);

    }

    static int firstMissingPositive(int[] nums) {
        cyclicSort(nums);
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] != i+1){
                return i+1;
            }
        }
        return nums.length+1;
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

