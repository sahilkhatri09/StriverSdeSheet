//Recursion
class Solution {
    int getLcs(int i,int j,string &text1,string &text2){
        if(i == text1.size() || j == text2.size())return 0;
        
        if(text1[i] == text2[j]){
            return = 1 + getLcs(i + 1,j + 1,text1,text2);
        }
        return  max( getLcs(i,j+1,text1,text2),getLcs(i+1,j,text1,text2) );
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        return getLcs(0,0,text1,text2);
    }
};

// Memo top down
class Solution {
    vector<vector<int>>dp;
    int getLcs(int i,int j,string &text1,string &text2){
        if(i == text1.size() || j == text2.size())return 0;
        if(dp[i][j] != -1)return dp[i][j];
        if(text1[i] == text2[j]){
          return dp[i][j] = 1 + getLcs(i + 1,j + 1,text1,text2);
        }
        return dp[i][j] = max( getLcs(i,j+1,text1,text2),getLcs(i+1,j,text1,text2) );
        
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        dp.resize(n,vector<int>(m,-1));
        return getLcs(0,0,text1,text2);
    }
};

// bottom up
class Solution {
    vector<vector<int>>dp;
    int getLcs(int i,int j,string &text1,string &text2){
        if(i < 0 || j < 0)return 0;
        if(dp[i][j] != -1)return dp[i][j];
        if(text1[i] == text2[j]){
          return dp[i][j] = 1 + getLcs(i - 1,j - 1,text1,text2);
        }
        return dp[i][j] = max( getLcs(i,j-1,text1,text2),getLcs(i-1,j,text1,text2) );
        
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        dp.resize(n,vector<int>(m,-1));
        return getLcs(n-1,m-1,text1,text2);
    }
};

//iterative
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
       vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i =1; i<=n; i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
};
