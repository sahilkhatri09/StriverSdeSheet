class Solution {
public:
   
    int widthOfBinaryTree(TreeNode* root) {
            
       queue<pair<TreeNode*,long long>>q;
        q.push({root,0});
        long long ans=0;
        while(!q.empty()){
            int k=q.size();
            int m=q.size();
            long long sahil;
            long long mini=INT_MAX,maxi=-1;
            while(k>0){
                if(k==m)sahil=q.front().second;
                TreeNode* curNode=q.front().first;
                long long curVal=q.front().second-sahil;
                q.pop();
                mini=min(mini,curVal);
                maxi=max(maxi,curVal);
                if(curNode->left){
                    q.push({curNode->left,2*curVal});
                }
                if(curNode->right){
                    q.push({curNode->right,2*curVal+1});
                }
                k--;
            }
            if(mini!=INT_MAX&&maxi!=-1){
                ans=max(ans,maxi-mini+1);
            }
        }
        return ans;

    }
};