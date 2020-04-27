/*
Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

Example:

Input: 

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

Output: 4

*/

//Solution

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty())
            return 0;
        int n = matrix.size();
        int m = matrix[0].size();
        int max_len = 0;
        vector<vector<int>> dp(n,vector<int>(m,0));

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(i==0 || j==0)
                    dp[i][j] = matrix[i][j]-48;
                else {
                    if(matrix[i][j] == '1')
                        dp[i][j] = min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1])) + 1;
                }
                max_len = max(max_len,dp[i][j]);
            }
        }

        return max_len*max_len;        
    }
};

/*
Complexity analysis
Time: O(MN)
Space: O(MN)
*/
