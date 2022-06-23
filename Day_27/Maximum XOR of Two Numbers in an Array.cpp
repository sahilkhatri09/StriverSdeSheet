class Node{
    public:
    Node* left,*right;
    Node(){
        left = NULL;
        right = NULL;
    }
};
class Solution {
     void insert(int a,Node* root){
        int bitcount = 30;
        while(bitcount>=0){
            int k = 1<<bitcount;
            if(k&a){
                if(root->right == NULL){
                    root->right = new Node();
                }
                root = root->right;
            }
            else{
                if(root->left == NULL){
                    root->left = new Node();
                }
                root = root->left;
            }
            bitcount--;
        }
    }
    
    int getMax(int a , Node* root){
        int ans = 0;
        int bitCount = 30;
        while(bitCount >= 0){
            int k = 1 << bitCount;
            if(a & k){
                if(root->left != NULL){
                    root=root->left;
                }
                else{
                    root = root->right;
                    ans |= k;
                }
            }
            else{
                if(root->right != NULL){
                    ans |= k;
                    root = root->right;
                }
                else{
                    root = root->left;
                }
            }
            bitCount--;
        }
        return ans;
    }
public:
    int findMaximumXOR(vector<int>& nums) {
        Node* root = new Node();
        Node* cur = root;
        for(int i = 0; i < nums.size(); i++){
            insert(nums[i],cur);
        }
        int temp = 0;
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
           temp = getMax(nums[i],root);
            ans = max(ans,temp^nums[i]);
        }
        return ans;
    }
};