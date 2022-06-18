void getLeft(TreeNode<int>* root,vector<int>&ans){
    if(root == NULL || (root->left == NULL && root->right == NULL))return;
    ans.push_back(root->data);
    if(root->left)getLeft(root->left,ans);
    else getLeft(root->right,ans);
}
void getLeaf(TreeNode<int>* root,vector<int>&ans){
    if(root == NULL)return;
    if(root->left == NULL && root->right==NULL){
        ans.push_back(root->data);
    }
    getLeaf(root->left,ans);
    getLeaf(root->right,ans);
}
void getRight(TreeNode<int>* root,vector<int> &ans){
    if(root == NULL ||(root->left == NULL && root->right == NULL))return;
    if(root->right)getRight(root->right,ans);
    else getRight(root->left,ans);
    ans.push_back(root->data);
}
vector<int> traverseBoundary(TreeNode<int>* root){
    vector<int>ans;
    if(root)ans.push_back(root->data);
    getLeft(root->left,ans);
    getLeaf(root->left,ans);
    getLeaf(root->right,ans);
    getRight(root->right,ans);
    return ans;
}