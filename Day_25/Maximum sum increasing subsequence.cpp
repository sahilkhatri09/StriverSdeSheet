//recursion
class Solution{
		
    int getSum(int arr[] , int n , int prev){
        if(n < 0)return 0;
        int take = 0;
        if(prev == -1 || arr[n] < arr[prev]){
            take = arr[n] + getSum(arr,n - 1,n);
        }
        int ignore = getSum(arr,n - 1, prev);
        return max(take,ignore);
    }
	public:
	int maxSumIS(int arr[], int n)  
	{  
	    return getSum(arr,n-1,-1);
	}  
};

// memo
class Solution{
    vector<vector<int>>dp;
    int getSum(int arr[] , int n , int prev){
        if(n < 0)return 0;
        if(dp[n][prev+1] != -1)return dp[n][prev+1];
        int take = 0;
        if(prev == -1 || arr[n] < arr[prev]){
            take = arr[n] + getSum(arr,n - 1,n);
        }
        int ignore = getSum(arr,n - 1, prev);
        return dp[n][prev+1] = max(take,ignore);
    }
	public:
	int maxSumIS(int arr[], int n)  
	{  
	    dp.resize(n,vector<int>(n+1,-1));
	    return getSum(arr,n-1,-1);
	}  
};

//space optimazation
class Solution{
    vector<int> dp;
    int getSum(int arr[] , int n , int prev){
        if(n < 0)return 0;
        if(dp[prev+1] != -1)return dp[prev+1];
        int take = 0;
        if(prev == -1 || arr[n] < arr[prev]){
            take = arr[n] + getSum(arr,n - 1,n);
        }
        int ignore = getSum(arr,n - 1, prev);
        return dp[prev+1] = max(take,ignore);
    }
	public:
	int maxSumIS(int arr[], int n)  
	{  
	    dp.resize(n + 1,-1);
	    return getSum(arr,n-1,-1);
	}  
};

// iterative
class Solution{
   
	public:
	int maxSumIS(int arr[], int n)  
	{  
	  int dp[n];
	  int ans = 0;
	  for(int i=0;i<n;i++){
	      dp[i] = arr[i];
	      for(int j=0;j<i;j++){
	         if(arr[j] < arr[i]){
	             dp[i] = max(dp[i],dp[j] + arr[i]);
	         }
	      }
	      ans = max(ans,dp[i]);
	  }
	  return ans;
	}  
};