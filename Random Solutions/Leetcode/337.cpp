

// 337. House Robber III

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
    pair<int, int> dfs(TreeNode* root){
        
        // returns a pair - {solution for current node , sum of solutions of children of current node }
        
        if(!root)return {0,0};
        
        pair<int, int> l = dfs(root->left);
        pair<int, int> r = dfs(root->right);
        
        
        // sum of children of current node is sum of first member of l and r
        int sum = l.first+r.first;
        
        return {max(sum , root->val + l.second + r.second) , sum };
          
    }
    
public:
    int rob(TreeNode* root) {
        
        pair<int, int> p = dfs(root);
        
        // If we rob the root, we cannot rob its children
        // And if we decide not to rob the root, then this is same as saying solving the problem for left and rright subtrees and adding them
        
        // the dfs function returns a pair
        // first one consideres robbing the root
        // second one is the sum of solutions of left and right subtrees
        // max of them will be the solution for whole tree
        
        return max(p.first, p.second);
        
    }
    
};
