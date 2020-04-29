/*
Given a non-empty binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.

Example 1:

Input: [1,2,3]

       1
      / \
     2   3

Output: 6

Example 2:

Input: [-10,9,20,null,null,15,7]

   -10
   / \
  9  20
    /  \
   15   7

Output: 42

*/

//Solution

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int max_ = -INT_MAX;
public:
    int PathSum(TreeNode* root) {
        if(root == NULL)
            return 0;
        int left_s = max(0,PathSum(root->left));
        int right_s = max(0,PathSum(root->right));
        max_ = max(max_, left_s+right_s+root->val);
        return max(left_s,right_s) + root->val;
        
    }
    int maxPathSum(TreeNode* root) {
        if(root == NULL)
            return 0;
        PathSum(root);
        return max_;
    }
};
