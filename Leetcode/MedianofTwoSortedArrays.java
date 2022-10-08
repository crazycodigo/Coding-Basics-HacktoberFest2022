package LeetCodeSearch;

public class MedianofTwoSortedArrays {
    public static void main(String[] args) {
        int[] arr = {1,3};
        int[] arr1 = {4,8,9,10};
        System.out.println(findMedianSortedArrays(arr, arr1));
    }
    static double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int a = nums1.length;
        int b = nums2.length;
        int l = a+b;
        int[] c = new int[l];
        System.arraycopy(nums1, 0, c, 0, a);
        System.arraycopy(nums2, 0, c, a, b);

        if (c.length % 2 == 0){
            int mid = c.length/2;
            return (c[mid]+c[mid-1])/2;
        }else {
            return c[c.length/2];
        }
    }
}