package LeetCodeSearch;

public class InsertPosition {
    public static void main(String[] args) {
        int[] arr = {3,5,7,9,10};
        int target = 8;
        System.out.println(searchInsert(arr, target));

    }
    static int searchInsert(int[] nums, int target) {
        int start = 0;
        int end = nums.length-1;

        while (start<=end){
            int mid = start+(end-start)/2;
            if(nums[mid] == target) {
                return mid;
            }

            if (nums[mid]>target){
                end = mid-1;
            }else {
                start = mid+1;

            }
        }
        return start;
    }
}
