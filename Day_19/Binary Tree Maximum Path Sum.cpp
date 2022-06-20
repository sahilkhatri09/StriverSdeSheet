class Solution {
    int ans;
    int getMaxSum(TreeNode* root){
        if(root == NULL)return 0;
        int lSum = max(0 , getMaxSum(root->left));
        int rSum = max(0 , getMaxSum(root->right));
        ans = max(root->val + lSum + rSum , ans);
     
        return root->val + max(lSum,rSum);
    }
public:
    int maxPathSum(TreeNode* root) {
        ans = INT_MIN;
       getMaxSum(root);
        return ans;
    }
};