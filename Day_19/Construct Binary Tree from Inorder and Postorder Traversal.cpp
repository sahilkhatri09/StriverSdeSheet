class Solution {
public:
    TreeNode* getTree(int iStart,int iEnd,int pStart,int pEnd,unordered_map<int,int>&m,vector<int>&inorder,vector<int>&postorder){
        
        if(pStart > pEnd || iStart > iEnd){
            return NULL;
        }
        int curVal = postorder[pEnd];
        int curIdx = m[curVal];
        int curN = curIdx - iStart;
        
        TreeNode* root = new TreeNode(curVal);
        root->left = getTree(iStart , iStart + curN - 1, pStart , pStart +  curN - 1 , m , inorder , postorder);
        root->right = getTree(iStart + curN + 1 , iEnd , pStart + curN , pEnd - 1 , m , inorder , postorder);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int>m;
        int iSize = inorder.size();
        int pSize = postorder.size();
        for(int i = 0; i<iSize; i++) m[inorder[i]] = i;
        return getTree(0 , iSize - 1 , 0 , pSize - 1 , m , inorder , postorder);
    }
};