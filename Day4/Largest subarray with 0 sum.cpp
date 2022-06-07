class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
       unordered_map<int,int>m;
       int sum = 0;
       int ans =0;
       m[0] = -1;
       for(int i=0; i<n; i++){
           sum += A[i];
           if(m.find(sum) != m.end()){
               ans = max (i-m[sum], ans);
           }
           else{
               m[sum] = i;
           }
       }
       return ans;
    }
};