/*
Given an unsorted integer array, find the smallest missing positive integer.

Example 1:
Input: [1,2,0]
Output: 3

Example 2:
Input: [3,4,-1,1]
Output: 2

Example 3:
Input: [7,8,9,11,12]
Output: 1
Note:

Your algorithm should run in O(n) time and uses constant extra space.
*/
/*
// Using a map
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int maxVal, i, j;
        maxVal = INT_MIN;
        map<int, int> validMap;

        for (i = 0; i < nums.size(); i++) {
            if (nums[i] > maxVal) {
                maxVal = nums[i];
            }
            if (nums[i] > 0 ) {
                validMap.insert(pair<int, int>(nums[i], 1));
            }
        }
        for (i = 1; i <=maxVal; i++) {
            if (validMap.count(i) > 0) {
                continue;
            } else {
                break;
            }
        }
        return i;
    }
};
*/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int sz = nums.size();
        int i=0;
        while(i<sz) {
            if(nums[i]==(i+1) || nums[i]<=0 || nums[i]>sz || nums[i]==nums[nums[i]-1]) {
                i++; continue;
            }
            int temp = nums[i];
            nums[i] = nums[temp-1];
            nums[temp-1] = temp;
        }
        for(i=0;i<sz;i++) {
            if(nums[i]!=(i+1)) break;
        }
        return i+1;
    }
};
