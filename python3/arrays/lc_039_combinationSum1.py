'''
Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

The same repeated number may be chosen from candidates unlimited number of times.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: candidates = [2,3,6,7], target = 7,
A solution set is:
[
  [7],
  [2,2,3]
]
Example 2:

Input: candidates = [2,3,5], target = 8,
A solution set is:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]
'''
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        solution = {}
        i = 0
        while i <= target:
            solution[i] = []
            i = i + 1        
        candidates.sort()
        if target < 0:
            return []
        if target < candidates[0]:
            pass
        if target == 0 and candidates[0] > 0:
            solution[target].append([])
        i = candidates[0]
        while i <= target:
            for item in candidates:
                key = i - item
                tsol = []
                if key < 0:
                    break
                if (key == 0):
                    tsol.append(item)
                    solution[i].append(tsol)
                    break
                if len(solution[key]) == 0:
                    #i = i + 1
                    continue
                if len(solution[key]) > 0:
                    for solItem in solution[key]:
                        tsol = []
                        tsol.append(item)
                        tsol = tsol + solItem
                        tsol.sort()
                        if tsol not in solution[i]:
                            solution[i].append(tsol)
                    if key in candidates:
                        pass
            i = i + 1
        print (solution[target])
        return solution[target]
