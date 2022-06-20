class Solution
{
    public:
    int kthLargest(Node *root, int K)
    {
        stack<Node*>st;
        int ans = -1;
        while(root || !st.empty()){
            if(root){
                st.push(root);
                root = root->right;
            }
            else{
                root = st.top();
                K--;
                st.pop();
                if(K==0){
                    ans = root->data;
                    break;
                }
                root = root->left;
            }
        }
        return ans;
    }
};
