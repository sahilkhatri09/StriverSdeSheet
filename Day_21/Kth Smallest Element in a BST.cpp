class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int ans = -1;
        stack<TreeNode*>st;
        while(!st.empty() || root){
            if(root){
                st.push(root);
                root = root->left;
            }
            else{
                root = st.top();
                st.pop();
                k--;
                if(k==0){ans = root->val;break;}
                root = root->right;
            }
        }
        return ans;
    }
};