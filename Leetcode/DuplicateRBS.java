package LeetCodeSearch;

public class DuplicateRBS {
    public static void main(String[] args) {
        int[] arr = {0};
        System.out.println(search(arr, 0));
    }
    static boolean search(int[] nums, int target) {
        int pivot = findPivotWithDuplicates(nums);
        if (pivot == -1){
            return binarySearch(nums, 0, nums.length-1, target);
        }
        if (nums[pivot] == target){
            return true;
        }
        if (nums[0] <= target ){
            return binarySearch(nums, 0, pivot-1, target);
        }else {
            return binarySearch(nums, pivot+1, nums.length-1, target);
        }
    }
    static int findPivotWithDuplicates(int[] arr) {
        int start = 0;
        int end = arr.length - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (mid < end && arr[mid] > arr[mid + 1]) {
                return mid;
            }
            if (mid > start && arr[mid] < arr[mid - 1]) {
                return mid-1;
            }
            if (arr[mid] == arr[start] && arr[mid] == arr[end]) {
                if (start < end && arr[start] > arr[start + 1]) {
                    return start;
                }
                start++;
                if (end > start && arr[end] < arr[end - 1]) {
                    return end - 1;
                }
                end--;
            }
            else if(arr[start] < arr[mid] || (arr[start] == arr[mid] && arr[mid] > arr[end])) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return -1;
    }
    static boolean binarySearch(int[] arr, int start, int end , int target){
        while (start<=end){
            int mid = start+(end-start)/2;
            if (target == arr[mid]){
                return true;
            }
            if (target<arr[mid]){
                end = mid-1;
            }else if (target>arr[mid]){
                start=mid+1;
            }else {
                return true;
            }
        }
        return false;
    }
}
