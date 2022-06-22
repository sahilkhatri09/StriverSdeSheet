//Recursive
class Solution {
    int len_total;
    int getMin(vector<int>&cuts , int start_idx , int end_idx){
        if(end_idx < start_idx) return 0;
        int mini = INT_MAX;
        int start_len = 0;
        int end_len = len_total;
        if(start_idx != 0)start_len = cuts[start_idx -1];
        if(end_idx != cuts.size()-1)end_len = cuts[end_idx + 1];
        
        for(int idx = start_idx;idx <= end_idx ;idx++){
           int temp = (end_len - start_len) + getMin(cuts,start_idx,idx-1) + getMin(cuts,idx+1,end_idx);
            mini = min(temp,mini);
        }
        return mini;
    }
public:
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        len_total = n;
        return getMin(cuts,0,cuts.size()-1);
    }
};

//Memo
class Solution {
    int len_total;
    vector<vector<int>>dp;
    int getMin(vector<int>&cuts , int start_idx , int end_idx){
        if(end_idx < start_idx) return 0;
        if(dp[start_idx][end_idx] != -1)return dp[start_idx][end_idx];
        int mini = INT_MAX;
        int start_len = 0;
        int end_len = len_total;
        if(start_idx != 0)start_len = cuts[start_idx -1];
        if(end_idx != cuts.size()-1)end_len = cuts[end_idx + 1];
        
        for(int idx = start_idx;idx <= end_idx ;idx++){
           int temp = (end_len - start_len) + getMin(cuts,start_idx,idx-1) + getMin(cuts,idx+1,end_idx);
            mini = min(temp,mini);
        }
        return dp[start_idx][end_idx] = mini;
    }
public:
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        len_total = n;
        dp.resize(cuts.size(),vector<int>(cuts.size(),-1));
        return getMin(cuts,0,cuts.size()-1);
    }
};

//iterative
class Solution {
   
public:
    int minCost(int k, vector<int>& cuts) {
        int n = cuts.size();
        cuts.push_back(0);
        cuts.push_back(k);
        sort(cuts.begin(),cuts.end());
        int dp[n+2][n+2];
        memset(dp,0,sizeof dp);
       
        for(int i=n;i>=1;i--){
            for(int j=i;j<=n;j++){
                int mini = INT_MAX;
                int sl = cuts[i-1];
                int el = cuts[j+1];
                for(int k=i;k<=j;k++){
                    mini = min(mini,el-sl + dp[i][k-1]+dp[k+1][j]);
                }
                dp[i][j] = mini;
            }
        }
        return dp[1][n];
    }
};