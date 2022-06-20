  TreeNode* getTree(int pStart,int pEnd,int iStart,int iEnd,unordered_map<int,int>&m,vector<int>&preorder,vector<int>&inorder){
        if(pStart > pEnd || iStart > iEnd)return NULL;
        int curVal = preorder[pStart];
        int curIdx = m[curVal];
        int curN = curIdx - iStart;
        
        TreeNode* root =new TreeNode(curVal);
        root->left = getTree(pStart + 1,pStart + curN,iStart,curIdx - 1,m,preorder,inorder);
        root->right = getTree(pStart + curN + 1,pEnd,curIdx + 1,iEnd,m,preorder,inorder);
        
        return root;

    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //preorder 3 9 20 15 7
        //inorder  9 3 15 20 7
        unordered_map<int,int>m;
        for(int i = 0; i < inorder.size(); i++)m[inorder[i]]=i;
        return getTree(0,preorder.size()-1,0,inorder.size()-1,m,preorder,inorder);
    }
};