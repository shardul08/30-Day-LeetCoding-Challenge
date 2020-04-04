/*
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Example:

Input: [0,1,0,3,12]
Output: [1,3,12,0,0]

Note:

1. You must do this in-place without making a copy of the array.
2. Minimize the total number of operations.

*/

//Solution using two pointers

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i,j;
        int n = nums.size();
        i = 0;
        while(i<n && nums[i] != 0)
            i++;
        j = i+1;
        while(j < n) {
            if(nums[j] != 0) {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                i++;
            }
            j++;
        }
    }
};

/*
Complexity analysis

Time: O(N)
Space: O(1)
*/
