/*
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.

*/

//Solution Kdane's algorithm

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = nums[0], max_so_far=0;
        for(int i=0;i<nums.size();i++) {
            max_so_far += nums[i];
            max_sum = max(max_sum,max_so_far);
            max_so_far = max_so_far > 0 ? max_so_far : 0;
        }
        return max_sum;
    }
};

/*
Complexity analysis
Time: O(N)
Space: O(1)
*/
