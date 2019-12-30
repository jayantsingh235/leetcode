/*
Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.

Example:

Input: [1,8,6,2,5,4,8,3,7]
Output: 49
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        /*
        int i, j, area, len, tarea;
        area = j = len = tarea = 0;
        for (i = 0; i < height.size(); i++) {
            for (j = i + 1; j < height.size(); j++) {
                len = (height[i] < height[j] ? height[i] : height[j]);
                tarea = len * (j - i);
                if (tarea > area)
                    area = tarea;
            }
        }
        return area;
        */
        int i = 0, j = height.size() - 1, max_area = 0;
        while(i < j)  {
            max_area = max (max_area, min(height[i],height[j]) * (j-i));
            if(height[i] < height[j])
                i++;
            else
                j--;
        }
        return max_area;
    }
};
