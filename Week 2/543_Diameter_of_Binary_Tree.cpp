/*
 Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

Example:
Given a binary tree

          1
         / \
        2   3
       / \     
      4   5    

Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].

Note: The length of path between two nodes is represented by the number of edges between them. 
*/

//Soltion Using DFS to calculate max(left depth + right depth) at every node

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int max_d = 0;
    int dfs(TreeNode* root) {
        if(root == NULL)
            return 0;
        int left_d = dfs(root->left);
        int right_d = dfs(root->right);
        if(left_d + right_d > max_d)
            max_d = left_d + right_d;
        return max(1+left_d,1+right_d);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL)
            return 0;
        dfs(root);
        return max_d;
    }
};

/*
Complexity analysis
Time: O(N)
Space: O(d)
N: Number of nodes
d: Max depth of tree
*/
