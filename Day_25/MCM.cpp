//recursive
class Solution{
    int getMcm(int arr[] , int i,int j){
        if(i+1 == j)return 0;
        int mini = INT_MAX;
         for(int k = i+1;k<j;k++){
            int temp = getMcm(arr,i,k) + getMcm(arr,k,j) + arr[i]*arr[k]*arr[j];
            mini = min(temp,mini);
         }
        return mini;
    }
public:
    int matrixMultiplication(int N, int arr[])
    {
       return getMcm(arr,0,N-1);
    }
};

//memo
class Solution{
public:
    int helper(vector<vector<int>>&dp,int arr[],int i,int j){
        if(i>=j)return 0;
        int ans=INT_MAX;
        if(dp[i][j]!=-1)return dp[i][j];
        for(int k=i;k<j;k++){
            int a=helper(dp,arr,i,k);
            int b=helper(dp,arr,k+1,j);
            int c=arr[k]*arr[i-1]*arr[j];
            ans=min(ans,a+b+c);
        }
        return dp[i][j]=ans;
    }
    int matrixMultiplication(int N, int arr[])
    {
        vector<vector<int>>dp(N,vector<int>(N,-1));
        return helper(dp,arr,1,N-1);
    }
};


//iterative
class Solution{
   
public:
    int matrixMultiplication(int N, int arr[])
    {
       int dp[N][N];
       memset(dp,0,sizeof dp);
       for(int L=3;L<=N;L++){
           for(int i=0;i<=N-L;i++){
               int j = i+L-1;
               dp[i][j] = INT_MAX;
               for(int k=i+1;k<j;k++){
                   int temp = dp[i][k] + dp[k][j] + arr[i]*arr[k]*arr[j];
                   dp[i][j] = min(dp[i][j] , temp);
               }
           }
       }
      return dp[0][N-1];
    }
};