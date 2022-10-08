package LeetcodeSort;
// this is for find only one duplicate in array
public class DuplicateNumber {
    public static void main(String[] args) {
        int[] nums = {3,1,3,4,2};
        int ans = findDuplicate(nums);
        System.out.println(ans);

    }

    static int findDuplicate(int[] nums) {
        cyclicSort(nums);
        for (int i = 0; i < nums.length ; i++) {
            if (nums[i] != i+1){
                return nums[i];
            }
        }
        return -1;
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

