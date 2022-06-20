class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       if(root == NULL || root->val==p->val || root->val == q->val)return root;
        TreeNode* ls = lowestCommonAncestor(root->left,p,q);
        TreeNode* rs = lowestCommonAncestor(root->right,p,q);
        if(ls && rs)return root;
        if(ls)return ls;
        return rs;
    }
};