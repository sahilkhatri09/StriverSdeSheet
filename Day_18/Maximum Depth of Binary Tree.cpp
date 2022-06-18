
class Solution {
public:
    int maxDepth(TreeNode* root) {
        int depth = 0;
        queue<TreeNode*>q;
        if(root)q.push(root);
        while(!q.empty()){
            int n = q.size();
            depth++;
            while(n--){
                TreeNode* curNode = q.front();
                q.pop();
                
                if(curNode->left)q.push(curNode->left);
                if(curNode->right)q.push(curNode->right);
            }
        }
        return depth;
    }
};