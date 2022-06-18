
class Solution {
    vector<int> ans;
    void getPre(TreeNode* root){
        if(root == NULL)return;
        ans.push_back(root->val);
        if(root->left)getPre(root->left);
        if(root->right)getPre(root->right);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        ans.clear();
        getPre(root);
        return ans;
    }
};

//Approach 2
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*>st;
        if(root)st.push(root);
        vector<int> ans;
        while(!st.empty()){
            TreeNode* curNode = st.top();
            st.pop();
            ans.push_back(curNode->val);
            if(curNode->right)st.push(curNode->right);
            if(curNode->left)st.push(curNode->left);
        }
        return ans;
    }
};