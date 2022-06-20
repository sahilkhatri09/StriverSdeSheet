class Solution {
    TreeNode* getBst(int start,int end,vector<int>&preorder){
        if(start > end)return NULL;
        int idx = start;
        while(idx <= end && preorder[idx]<=preorder[start])idx++;
        TreeNode* root = new TreeNode(preorder[start]);
        root->left = getBst(start + 1,idx -1,preorder);
        root->right = getBst(idx,end,preorder);
        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return getBst(0,preorder.size() - 1,preorder);
    }
};