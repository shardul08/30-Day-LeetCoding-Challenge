/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example:

Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.

*/

//Solution DP solution to store min path sum at each point

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<int>> minPath(r,(vector<int> (c,0)));
        minPath[0][0] = grid[0][0];
        for(int i=1;i<r;i++)
            minPath[i][0] = minPath[i-1][0] + grid[i][0];
        for(int i=1;i<c;i++)
            minPath[0][i] = minPath[0][i-1] + grid[0][i];
        for(int i=1;i<r;i++) {
            for(int j=1;j<c;j++) {
                minPath[i][j] = grid[i][j] + min(minPath[i-1][j],minPath[i][j-1]);
            }
        }
        
        return minPath[r-1][c-1];        
    }
};

/*
Complexity analysis
Time: O(MN)
Space: O(MN)
*/
