'''
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

Each number in candidates may only be used once in the combination.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8,
A solution set is:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5,
A solution set is:
[
  [1,2,2],
  [5]
]
'''
class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        res = []
        candidates.sort()
        self.dfs(candidates, target, 0, [], res)
        return res
    
    def dfs(self, nums, target, index, path, res):
        if target <0:
            return 
        if target == 0:
            res.append(path)
            return 
        for i in range(index,len(nums)):
            if nums[i]>target:
                break
            if (i == index or nums[i]!=nums[i-1]):
                self.dfs(nums, target-nums[i], i+1, path + [nums[i]], res)

'''
This works as below:
start with first item in the list. subtract this number from target and search that difference in rest of the list.
each subsequent recursion removes some target to be tracked.
If target becomes negative at any stage, this path is not true
If target becomes zero, then this path is true

Final end happens when the loop i in range(0,len(nums)) is completed.
'''
