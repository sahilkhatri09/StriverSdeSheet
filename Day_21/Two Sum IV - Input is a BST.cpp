//Approach 1
class Solution {
    unordered_set<int> us;
public:
    
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL)return false;
        if(us.find(k-root->val)!=us.end())return true;
        us.insert(root->val);
        return findTarget(root->left,k)||findTarget(root->right,k);
    }
};

//Approach 2
class bstIterator{
    stack<TreeNode*>st;
    bool reverse;
    void pushAll(TreeNode* root){
        while(root){
            st.push(root);
            if(reverse){
                root = root->right;
            }
            else{
                root = root->left;
            }
        }
    }
    public : 
    bstIterator(TreeNode* root,bool isReverse){
        reverse = isReverse;
        pushAll(root);
    }
    int next(){
        TreeNode* temp = st.top();
        st.pop();
        if(reverse){
            pushAll(temp->left);
        }
        else{
            pushAll(temp->right);
        }
        return temp->val;
    }
};

class Solution {
    
public:
    bool findTarget(TreeNode* root, int k) {
        bstIterator l(root,false);
        bstIterator r(root,true);
        int i = l.next();
        int j = r.next();
        while(i < j){
            if(i + j == k)return true;
            else if(i + j > k){
                j = r.next();
            }
            else{
                i = l.next();
            }
        }
       return false; 
    }
};