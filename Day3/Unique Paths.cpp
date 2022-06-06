// Approach 1 O(n*m)
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,1));
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j]=dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};

// Approach 2 O(n-1) or O(m-1)
class Solution {
public:
    int uniquePaths(int m, int k) {
        int n = m + k -2;
        int r = m-1;
        int num = 1;
        int den = 1;
        double ans = 1;
        for(int i = 1; i <= r; i++){
            ans = ans * ( n - r + i) / i;
        }
        
        return int(ans);
    }
};