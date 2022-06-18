
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,vector<int>>m;
        queue<pair<TreeNode* ,int>>q;
        vector<vector<int>> ans;
        q.push({root,0});
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

        while(!q.empty()){
            int n = q.size();
            while(n--){
            TreeNode* curNode = q.front().first;
            int curWidth = q.front().second;
            q.pop();
            pq.push({curNode->val,curWidth});
            
            if(curNode->left)q.push({curNode->left , curWidth - 1});
            if(curNode->right)q.push({curNode->right , curWidth + 1});
            }
            while(!pq.empty()){
                int curVal = pq.top().first;
                int curWidth = pq.top().second;
                m[curWidth].push_back(curVal);
                pq.pop();
            }
        }
        map<int,vector<int>> :: iterator it;
        
        for(it = m.begin(); it != m.end(); it++){
            ans.push_back(it->second);
        }
        return ans;
    }
};