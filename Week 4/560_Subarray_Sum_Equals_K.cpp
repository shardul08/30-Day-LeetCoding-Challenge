/*
Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.

Example 1:

Input:nums = [1,1,1], k = 2
Output: 2

Note:

    The length of the array is in range [1, 20,000].
    The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].

*/

//Solution

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> presum;
        int sum = 0,res = 0;
        presum.emplace(0,1);
        for(int a:nums){
            sum += a;
            if(presum.find(sum-k) != presum.end())
                res += presum.find(sum-k)->second;
            auto it = presum.find(sum);
            if(it == presum.end())
                presum.emplace(sum,1);
            else{
                 it->second += 1;
            }
        }
       
        return res;
    }
};
