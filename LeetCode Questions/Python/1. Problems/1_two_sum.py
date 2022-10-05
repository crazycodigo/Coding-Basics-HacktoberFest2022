# https://leetcode.com/problems/two-sum/

class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        hashmap = {}
        for i in range(len(nums)):
            if target - nums[i] in hashmap:
                return hashmap[target - nums[i]], i
            else:
                hashmap[nums[i]] = i