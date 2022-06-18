class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        queue<TreeNode*> q;
        if(root)q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int>temp;
            while(n--){
                TreeNode* curNode = q.front();
                q.pop();
                temp.push_back(curNode->val);
                if(curNode->left)q.push(curNode->left);
                if(curNode->right)q.push(curNode->right);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};