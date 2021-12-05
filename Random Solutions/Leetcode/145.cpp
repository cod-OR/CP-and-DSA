

// 145. Binary Tree Postorder Traversal

// Iterative approach

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> todo;
        TreeNode* currentNode = root;
        TreeNode* prev = NULL;
        vector<int> order;
        
        while(currentNode || !todo.empty()){
            
            while(currentNode){
                todo.push(currentNode);
                currentNode = currentNode->left;
            }
            currentNode = todo.top();
            if(currentNode->right  and currentNode->right != prev){
                currentNode = currentNode->right;
            }
            else{
                order.push_back(currentNode->val);
                prev = currentNode;
                currentNode=NULL;
                todo.pop();
            }
        }
        
        return order;
    }
};


// recursive approach


class Solution {
public:
    vector<int> v;
    void postorder(TreeNode* root) {
        if(root==NULL)return ;
        
        if(root->left)
            postorder(root->left);
        
        if(root->right)
            postorder(root->right);
        
        v.push_back(root->val);
        
    }
    vector<int> postorderTraversal(TreeNode* root) {
        postorder(root);
        return v;
    }
        
};
