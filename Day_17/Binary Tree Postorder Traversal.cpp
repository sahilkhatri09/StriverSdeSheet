class Solution {
    vector<int> ans;
    void getPost(TreeNode* root){
        if(root == NULL)return;
        if(root->left)getPost(root->left);
        if(root->right)getPost(root->right);
        ans.push_back(root->val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        ans.clear();
        getPost(root);
        return ans;
    }
};

//Approach 2
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*>st1;
        vector<int>ans;
        if(root)st1.push(root);
        while(!st1.empty()){
            TreeNode* curNode = st1.top();
            st1.pop();
            ans.push_back(curNode->val);
            
            if(curNode->left)st1.push(curNode->left);
            if(curNode->right)st1.push(curNode->right);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};