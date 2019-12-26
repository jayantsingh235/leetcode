/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Your algorithm's runtime complexity must be in the order of O(log n).

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
*/
class Solution {
private:
    int regularBST (vector<int>& nums, int target, int low, int high) {
        int mid = 0;
        int flag = 0;
        while (low <= high) {
            mid = low + (high - low)/2;
            if (nums[mid] == target) {
                flag = 1;
                break;
            } else if (target <= nums[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        if (flag)
            return mid;
        else
            return -1;
    }
public:
    int search(vector<int>& nums, int target) {
        int low, high, mid, flag;
        low = flag = 0;
        high = nums.size() - 1;
        if (high == -1)
            return -1;
        if (high == 0)
            return (target == nums[high] ? high: -1);
        while (low <= high) {
            if (nums[low] <= nums[high]) {
                return regularBST (nums, target, low, high);
            }
            mid = low + (high - low)/2;
            if (nums[mid] == target) {
                flag = 1;
                break;
            }
            if (nums[mid] >= nums[low]) {
                if ((target < nums[mid]) && (target >= nums[low])) {
                    return regularBST (nums, target, low, mid);
                }
                low = mid + 1;
                continue;
            } else if ((target > nums[mid]) && (target <= nums[high])) {
                return regularBST (nums, target, mid + 1, high);
            }
            high = mid - 1;
        }
        if (flag)
            return mid;
        else
            return -1;
    }
};
