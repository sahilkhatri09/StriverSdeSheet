bool getPath(vector<int> &ans ,TreeNode *A, int B){
     if(A == NULL)return false;
     ans.push_back(A->val);
     if(A->val == B)return true;
     if(getPath(ans , A->left , B)) return true;
     if(getPath(ans , A->right , B))return true;
     ans.pop_back();
     return false;
 }
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> ans;
    getPath(ans , A , B);
    return ans;
}
