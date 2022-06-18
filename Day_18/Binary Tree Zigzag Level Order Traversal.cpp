class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        queue<TreeNode*>q;
        bool lToR = true;
        if(root)q.push(root);
        
        while(!q.empty()){
            int n = q.size();
            vector<int>temp(n,0);
            int m = n;
            
            while(n--){
                TreeNode* curNode = q.front();
                q.pop();
                if(curNode->left)q.push(curNode->left);
                if(curNode->right)q.push(curNode->right);
                if(lToR){
                    temp[m - n - 1] = curNode->val;
                }
                else{
                    temp[n]= curNode->val;
                }
            }
            lToR = !lToR;
            ans.push_back(temp);
        }
        return ans;
    }
};