/*
Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
*/

class Solution {
private:
    int searchLeft (vector<int>& nums, int target, int low, int high) {
        int mid;
        if (low > high) {
            return low;
        }
        while (low <= high) {
            mid = low + (high - low)/2;
            if (nums[mid] == target) {
                high = mid - 1;
            } else if (nums[mid] < target) {
                low = mid + 1;
            }
        }
        return low;
    }
    int searchRight (vector<int>& nums, int target, int low, int high) {
        int mid;
        if (low > high) {
            return high;
        }
        while (low <= high) {
            mid = low + (high - low)/2;
            if (nums[mid] == target) {
                low = mid + 1;
            } else if (nums[mid] > target) {
                high = mid - 1;
            }
        }
        return high;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> answer = {-1, -1};
        int low, high, mid;
        high = nums.size();
        if (high == 0)
            return answer;
        if (high == 1) {
            if (target == nums[high-1]) {
                answer[0] = 0;
                answer[1] = 0;
            }
            return answer;
        }
        low = 0;
        high--;
        while (low <= high) {
            mid = low + (high - low)/2;
            if (nums[mid] == target) {
                answer[0] = searchLeft (nums, target, low, mid - 1);
                answer[1] = searchRight (nums, target, mid + 1, high);
                break;
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return answer;
    }
};
