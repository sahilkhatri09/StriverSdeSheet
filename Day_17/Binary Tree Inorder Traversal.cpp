class Solution {
    vector<int> answer;
    void getInorder(TreeNode* root){
        if(root == NULL) return;
        if(root->left)getInorder(root->left);
        answer.push_back(root -> val);
        if(root->right)getInorder(root->right);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        answer.clear();
        getInorder(root);
        return answer;
    }
};

// Approach 2
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* cur = root;
        vector<int> getIn;
        while(cur || !st.empty()){
            if(cur){
                st.push(cur);
                cur = cur->left;
            }
            else{
                cur = st.top();
                getIn.push_back(cur->val);
                st.pop();
                cur = cur->right;
            }
        }
        return getIn;
    }
};