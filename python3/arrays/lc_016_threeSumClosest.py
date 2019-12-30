'''
Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

Example:

Given array nums = [-1, 2, 1, -4], and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
'''
class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums.sort()
        used = []
        min_dist = sys.maxsize
        min_sum = sys.maxsize
        if len(nums) <= 3:
            return sum(nums)
        for idx, val in enumerate(nums):
            if val in used:
                continue
            used.append(val)
            left = idx + 1
            right = len(nums) - 1
            while (left < right):
                s =  val + nums[left] + nums[right]
                if s == target:
                    return s
                if abs(s - target) <= min_dist:
                    min_dist = abs(s - target)
                    min_sum = s
                if s < target:
                    left += 1
                else:
                    right -= 1
        return min_sum
