
// 144. Binary Tree Preorder Traversal

// Iterative approach

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> auxi;
        TreeNode* currentNode = root;
        vector<int> order;
        
        while(currentNode || !auxi.empty()){
            
            while(currentNode){
                order.push_back(currentNode->val);
                auxi.push(currentNode);
                currentNode = currentNode->left;
            }
            currentNode = auxi.top();
            auxi.pop();
            currentNode = currentNode -> right;
        }
        
        return order;
        
    }
};


// Recursive approach

class Solution {
public:
    vector<int> v;
    void preorder(TreeNode* root){
        if(!root)return;
        v.push_back(root->val);
        preorder(root->left);
        preorder(root->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        preorder(root);
        return v;
    }
};
