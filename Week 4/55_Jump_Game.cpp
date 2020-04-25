/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

Example 1:

Input: [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

Example 2:

Input: [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.

*/

//Solution

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_possible = 0;
        int n = nums.size();
        int cur_pos = 0;
        while(cur_pos < n) {
            if(max_possible >= n-1)
                return true;
            if(nums[cur_pos] == 0) {
                if(max_possible == cur_pos)
                    return false;
            }
            int cur_max = cur_pos + nums[cur_pos];
            if(cur_max > max_possible)
                max_possible = cur_max;
            cur_pos++;
        }
        return true;
    }
};

/*
Complextity analysis
Time: O(N)
Space: O(1)
*/
