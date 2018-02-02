# O(n) Time
class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        jian_dict={}
        for i in range(len(nums)):
            if nums[i] in jian_dict:
                return [jian_dict[nums[i]],i]
            else:
                jian_dict[target-nums[i]] = i