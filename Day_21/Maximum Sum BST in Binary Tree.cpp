class Node{
    public:
    int min,max,sum;
    bool isbst;
    Node(){
        min = INT_MAX;
        max = INT_MIN;
        sum = 0;
        isbst = true;
    }
};
class Solution {
    int ans ;
    Node* getMaxSum(TreeNode* root){
        Node* curNode = new Node();
        if(root == NULL)return curNode;
        
        Node* ls = getMaxSum(root->left);
        Node* rs = getMaxSum(root->right);
        
        if(ls->isbst && rs->isbst){
            if(ls->max < root->val && rs->min > root->val){
                curNode->min = min(root->val,ls->min);
                curNode->max = max(root->val,rs->max);
                curNode->sum += (root->val + ls->sum + rs->sum);
                ans = max(ans,curNode->sum);
            }
            else{
                curNode->isbst = false;
            }
        }
        else{
            curNode->isbst = false;
        }
        return curNode;
    }
    
public:
    int maxSumBST(TreeNode* root) {
        ans = 0;
        getMaxSum(root);
        return ans;
    }
};