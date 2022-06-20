class Solution {
public:
    void flatten(TreeNode* root) {
        stack<TreeNode*>st;
        if(root)st.push(root);
        TreeNode* head ;
        while(!st.empty()){
            head = st.top();
            st.pop();
            if(head->right)st.push(head->right);
            if(head->left)st.push(head->left);
            if(!st.empty()){
                head->left = NULL;
                head->right = st.top();
                head= head->right;
            }
        }
    }
};