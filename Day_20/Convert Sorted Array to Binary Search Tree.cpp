class Solution {
    TreeNode* getBST(int start,int end,vector<int>&nums){
        if(start>end)return NULL;
        int mid = (start + end) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = getBST(start , mid - 1 , nums);
        root->right = getBST(mid + 1, end , nums);
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
          return getBST(0,nums.size()-1,nums);
    }
};