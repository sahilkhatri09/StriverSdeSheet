//recursive
class Solution
{ 
    int getEggs(int n,int k){
        if(k == 0 ) return 0;
        if(n ==1)return k;
        int ans = INT_MAX;
        for(int i=1;i<=k;i++){
           int  temp = max(getEggs(n-1,i-1) , getEggs(n,k-i));
             ans = min(ans,temp);
        }
        return 1 + ans;
    }
    public:
   
    int eggDrop(int n, int k) 
    {
       return getEggs(n,k);
    }
};


//memo
class Solution
{    vector<vector<int>>dp;
    int getEggs(int n,int k){
        if(k == 0 ) return 0;
        if(n ==1)return k;
        if(dp[n][k] != -1)return dp[n][k];
        int ans = INT_MAX;
        for(int i=1;i<=k;i++){
           int  temp = max(getEggs(n-1,i-1) , getEggs(n,k-i));
             ans = min(ans,temp);
        }
        return dp[n][k] = 1 + ans;
    }
    public:
   
    int eggDrop(int n, int k) 
    {
        dp.resize(n+1,vector<int>(k+1,-1));
       return getEggs(n,k);
    }
};

//iterative
class Solution
{ 
    public:
   
    int eggDrop(int n, int k) 
    {
       int dp[n+1][k+1];
       for(int i=0;i<k+1;i++)dp[1][i] = i;
       for(int i=0;i<n+1;i++)dp[i][0] = 0;
       
       for(int i=2;i<n+1;i++){
           for(int j=1;j<k+1;j++){
               dp[i][j] = INT_MAX;
               for(int l=1;l<=j;l++){
                   int temp = 1 + max(dp[i-1][l-1],dp[i][j-l]);
                   dp[i][j] = min(dp[i][j],temp);
               }
               
           }
       }
       return dp[n][k];
    }
};