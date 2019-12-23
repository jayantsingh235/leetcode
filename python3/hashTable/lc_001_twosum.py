class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        complement_map = {}
        for i, number in enumerate(nums):
            if number in complement_map: 
                return [complement_map[number], i]
            else: 
                complement_map[target - number] = i
