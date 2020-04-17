/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

Input:
11110
11010
11000
00000

Output: 1

Example 2:

Input:
11000
11000
00100
00011

Output: 3

*/

//Solution Usinf DFS to convert all connected 0's to 1

class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        if(grid[i][j] == '0')
            return;
        grid[i][j] = '0';
        if(j+1 < grid[0].size())
            dfs(grid,i,j+1);
        if(i+1 < grid.size())
            dfs(grid,i+1,j);
        if(j-1 >= 0)
            dfs(grid,i,j-1);
        if(i-1 >= 0)
            dfs(grid,i-1,j);
     }
    
    int numIslands(vector<vector<char>>& grid) {
        int num_islands = 0;
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[0].size();j++) {
                if(grid[i][j] == '1') {
                    num_islands++;
                    dfs(grid,i,j);
                }
            }
        }
        return num_islands;
    }
};

/*
Complexity analysis
Time: O(MN)
Space: O(1)  (not considering recursive stack)
*/
