class BSTIterator {
    stack<TreeNode*>st;
    void partialInorder(TreeNode* root){
        while(root){
            st.push(root);
            root = root->left;
        }
    }
public:
    BSTIterator(TreeNode* root) {
        partialInorder(root);
    }
    
    int next() {
        TreeNode* temp = st.top();
        st.pop();
        partialInorder(temp->right);
        return temp->val;
    }
    
    bool hasNext() {
        return st.size();
    }
};

