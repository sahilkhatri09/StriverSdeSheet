class Solution {
    int diameter;
    int getDiameter(TreeNode* root){
        if(root == NULL)return 0;
        int lh = getDiameter(root->left);
        int rh = getDiameter(root->right);
        diameter = max(diameter, lh + rh);
        return 1 + max(lh,rh);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        diameter = 0;
        getDiameter(root);
        return diameter;
    }
};