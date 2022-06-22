//recursion
class Solution {
    int getDist(int i,int j,string &word1,string &word2){
        if(i==word1.size()) return word2.size() - j;
        if(j == word2.size()) return word1.size()-i;
        if(word1[i] == word2[j]){
            return getDist(i+1,j+1,word1,word2);
        }
        int insert = getDist(i+1,j,word1,word2);
        int del    = getDist(i,j+1,word1,word2);
        int rep = getDist(i+1,j+1,word1,word2);
        return 1 + min({insert,del,rep});
    }
public:
    int minDistance(string word1, string word2) {
      return  getDist(0,0,word1,word2);
    }
};

//memo
class Solution {
    vector<vector<int>>dp;
    int getDist(int i,int j,string &word1,string &word2){
        if(i==word1.size()) return word2.size() - j;
        if(j == word2.size()) return word1.size()-i;
        if(dp[i][j] != -1)return dp[i][j];
        if(word1[i] == word2[j]){
            return dp[i][j] = getDist(i+1,j+1,word1,word2);
        }
        int insert = getDist(i+1,j,word1,word2);
        int del    = getDist(i,j+1,word1,word2);
        int rep = getDist(i+1,j+1,word1,word2);
        return dp[i][j] = 1 + min({insert,del,rep});
    }
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        dp.resize(n,vector<int>(m,-1));
      return  getDist(0,0,word1,word2);
    }
};

//iterative
class Solution {
 
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        int dp[n+1][m+1];
        for(int i=0;i<=n;i++)dp[i][0]=i;
        for(int i=0;i<=m;i++)dp[0][i]=i;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j] = 1 + min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});
                }
            }
        }
        return dp[n][m];
    }
};