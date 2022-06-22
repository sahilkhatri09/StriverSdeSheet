//recursion
class Solution {
    int getMax(vector<vector<int>>&num,int m,int n,int idx){
        if(idx == num.size())return 0;
        int take = 0;
        if(num[idx][0] <= m && num[idx][1] <= n){
            take = 1 + getMax(num , m - num[idx][0] , n - num[idx][1] , idx + 1);
        }
        int ignore = getMax(num , m , n , idx + 1);
        return max(take , ignore);
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int strSize = strs.size();
        vector<vector<int>> num(strSize,vector<int>(2,0));
        for(int i=0; i<strs.size(); i++){
            int one = 0;
            int zero = 0;
            for(int j=0; j<strs[i].size(); j++){
                if(strs[i][j] == '0')zero++;
                else one++;
            }
            num[i][0] = zero;
            num[i][1] = one;
        }
        
        return getMax(num,m,n,0);
    }
};

//memo
class Solution {
    int dp[600][101][101];
    int getMax(vector<vector<int>>&num,int m,int n,int idx){
        if(idx == num.size())return 0;
        if(dp[idx][m][n])return dp[idx][m][n];
        int take = 0;
        if(num[idx][0] <= m && num[idx][1] <= n){
            take = 1 + getMax(num , m - num[idx][0] , n - num[idx][1] , idx + 1);
        }
        int ignore = getMax(num , m , n , idx + 1);
        return dp[idx][m][n]=max(take , ignore);
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int strSize = strs.size();
        vector<vector<int>> num(strSize,vector<int>(2,0));
        for(int i=0; i<strs.size(); i++){
            int one = 0;
            int zero = 0;
            for(int j=0; j<strs[i].size(); j++){
                if(strs[i][j] == '0')zero++;
                else one++;
            }
            num[i][0] = zero;
            num[i][1] = one;
        }
        
        return getMax(num,m,n,0);
    }
};

//iterative
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len = strs.size();
        int dp[len+1][m+1][n+1];
        memset(dp, 0, sizeof dp);
        
        for(int k=1; k<=len; k++){
            int ones = count(strs[k-1].begin(), strs[k-1].end(), '1');
            int zeros = strs[k-1].size()-ones;
            for(int i=0;i<=m;i++){
                for(int j=0;j<=n;j++){
                    if(ones<=j && zeros <=i){
                        dp[k][i][j] = max(dp[k-1][i][j],1 + dp[k-1][i-zeros][j-ones]);
                    }
                    else{
                        dp[k][i][j] = dp[k-1][i][j];
                    }
                }
            }
        }
        return dp[len][m][n];
    }
};