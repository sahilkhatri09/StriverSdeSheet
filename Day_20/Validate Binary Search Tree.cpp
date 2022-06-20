//Approach 1
class Solution {
    TreeNode* pre = NULL;
public:
    bool isValidBST(TreeNode* root) {
        if(root == NULL)return true;
        
        if(!isValidBST( root->left ))return false;
        if(pre != NULL && pre->val >= root->val)return false;
        pre = root;
        
        if(!isValidBST(root->right))return false;
        
        return true;
    }
};

//Approach 2
class Solution {
public:
    void inorder(TreeNode* root,vector<int> &in){
        if(root==NULL)return ;
        inorder(root->left,in);
        in.push_back(root->val);
        inorder(root->right,in);
    }
    bool isValidBST(TreeNode* root) {
        vector<int> in;
        inorder(root,in);
        for(int i=1;i<in.size();i++){
            if(in[i]<=in[i-1])return false;
        }
        return true;
    }
};

//Approach 3
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode* > st;
        TreeNode* cur = root;
        TreeNode* pre = NULL;
        while(!st.empty() || cur != NULL){
            if(cur != NULL){
                st.push(cur);
                cur = cur->left;
            }
            else{
                cur = st.top();
                if(pre != NULL && cur->val <= pre->val)return false;
                pre = cur;
                st.pop();
                cur = cur->right;
            }
        }
        return true;
    }
};

// Approach 4
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValid(root, NULL, NULL);
    }
    
    bool isValid(TreeNode* root, TreeNode* lower, TreeNode* upper){
        if(!root) return true;

        if(upper && root -> val >= upper->val)
            return false;
        if(lower && root -> val <= lower->val)
            return false;
        
        return isValid(root -> left, lower, root) && isValid(root -> right, root, upper);
    }
};