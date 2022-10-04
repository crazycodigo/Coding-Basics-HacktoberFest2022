class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> map = new HashMap<>();
        
        int i = 0;
        for (int num : nums) {
            if (map.get(target - num) != null) {
                return new int[] {i, (int) map.get(target - num)};
            }
            map.put(num, i);
            i++;
        }
        return new int[] {-1, -1};
    }
}
