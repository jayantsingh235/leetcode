/*
Given an array nums and a value val, remove all instances of that value in-place and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.

Example 1:

Given nums = [3,2,2,3], val = 3,

Your function should return length = 2, with the first two elements of nums being 2.

It doesn't matter what you leave beyond the returned length.
*/
class Solution {
public:
    int findSwapLocation(int prev, int data, vector<int>& nums) {
        int i;
        for (i = prev; i >=0; i--) {
            if (nums[i] != data)
                break;
        }
        return i;
    }
    int removeElement(vector<int>& nums, int val) {
        int i, sl, temp;
        if (nums.size() == 0)
            return 0;

        sl = findSwapLocation (nums.size() - 1, val, nums);
        if (sl == -1)
            return 0;
        for (i = 0; i < sl; i++) {
            if (nums[i] == val) {
                // cout << sl << endl;
                temp = nums[sl];
                nums[sl] = nums[i];
                nums[i] = temp;
                sl = findSwapLocation ((sl - 1), val, nums);
                if (sl < (i+1))
                    return (i+1);
            }
        }
        i++;
        return (i);
    }
};
