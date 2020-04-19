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

//Solution Finding the position of the smallest element ans searching in the rotated array with the known diaplacement

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int h = nums.size()-1;
        while(l<h){
            int mid = (l+h)/2;
            if(nums[mid] > nums[h])
                l = mid+1;
            else
                h = mid;
        }
        int rot = l;
        l = 0;
        h = nums.size()-1;
        while(l <= h){
            int mid = (l+h)/2;
            int realmid = (mid+rot)%nums.size();
            
            if(target < nums[realmid])
                h = mid-1;
            else if(target > nums[realmid])
                l = mid + 1;
            else
                return realmid;
        }
        return -1;
    }
};

/*
Complexity analysis
Time: O(logN)
Space: O(1)
*/
