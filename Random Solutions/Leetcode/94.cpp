

// 94. Binary Tree Inorder Traversal


// Iterative approach

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        while(!st.empty() or root){
            while(root){
                st.push(root);
                root=root->left;
            }
            root=st.top();
            ans.push_back(root->val);
            st.pop();
            root=root->right;
        }
        return ans;
    }
};


// recursive approach

class Solution {
public:
    vector<int> v;
    
    void inord(TreeNode* root){
        if(root==NULL)return;
        if(root->left)inord(root->left);
        v.push_back(root->val);
        if(root->right)inord(root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        inord(root);
        return v;
    }
};

