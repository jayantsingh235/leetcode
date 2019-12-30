'''
Find all unique triplets in the array which gives the sum of zero.
Note: The solution set must not contain duplicate triplets.

Example:
Given array nums = [-1, 0, 1, 2, -1, -4],
A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]

Key insights:
1.  use a sorted array
2.  once sorted, a triplet can be formed while keeping a number fixed and using everything after it.
    for example, if a[2] is being used to check if 2 other numbers can be used to make the target sum,
    then we check a[3:]. The case of a[0] and a[1] would be handled when they were fixed.
3.  In this problem, the target is 0. If a positive number is encountered, all the numbers after it are positive.
    They can't add up to give 0

'''
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        result = []
        used = []
        for idx, val in enumerate(nums):
            if val > 0:
                break
            if val in used:
                continue
            used.append(val)
            target = -val
            sol2 = []
            left = idx + 1
            right = len(nums) - 1
            found = []
            while (left < right):
                if nums[left] + nums[right] == target:
                    sol2 = [nums[left], nums[right]]
                    if sol2 not in found:
                        found.append(sol2)
                        res = [val, nums[left], nums[right]]
                        result.append(res)
                    left += 1
                    continue
                elif nums[left] + nums[right] < target:
                    left += 1
                else:
                    right -= 1
            
        return result
