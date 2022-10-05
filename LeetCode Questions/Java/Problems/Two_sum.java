//https://leetcode.com/problems/two-sum/description/
//https://leetcode.com/problems/two-sum/submissions/499947235/

class Solution {
    public int[] twoSum(int[] nums, int target) {
        int op[] = new int[2];
		
		HashMap<Integer,Integer> map = new HashMap<Integer,Integer>();
		for(int i=0;i<nums.length;i++) {
			int val = nums[i];
			int rem = target - val;
			if(map.containsKey(rem)) {
				op[0] = map.get(rem);
				op[1] = i;
			} else {
				map.put(val,i);
			}
		}
		return op;
        
    }
    
}
