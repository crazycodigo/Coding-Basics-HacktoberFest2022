package LeetCodeSearch;

public class BadVersion {
    public static void main(String[] args) {

    }
    public int firstBadVersion(int n) {
        int start = 0;
        int end = n;


        while (start < end) {
            int mid = start + (end - start) / 2;
            //if (isBadVersion(mid)) {
                end = mid;
            //} else {
                start = start + 1;
           // }
        }
        return end;
    }
}
