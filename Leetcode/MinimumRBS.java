package LeetCodeSearch;

public class MinimumRBS {
    public static void main(String[] args) {
        int[] arr = {5, 6, 7, 8, 0,1,2,3};
        int[] nums = {11, 12, 13, 14};
        System.out.println(findMin(nums));
    }

    static int findMin(int[] nums) {
        int start = 0;
        int end = nums.length - 1;

        while (start < end) {
            int mid = start + (end - start) / 2;
            if (end>mid && nums[mid + 1] < nums[mid]) {
                return nums[mid + 1];
            }
            if (mid>start && nums[mid - 1] > nums[mid]) {
                return nums[mid];
            }
            if (nums[mid]>nums[end]){
                start = mid+1;
            }else {
                end = mid;
            }
        }
        return nums[start];
    }
}