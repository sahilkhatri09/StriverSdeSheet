//recursive
class Solution {
    int getCoins(vector<int>&coins,int amount,int idx){
        if(idx < 0)return INT_MAX - 1;
        if(amount == 0)return 0;
        int take = INT_MAX -1;
        if(amount >= coins[idx]){
            take =1 + getCoins(coins,amount - coins[idx],idx);
        }
        int ignore = getCoins(coins,amount,idx - 1);
        return min(take,ignore);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        
       int ans = getCoins(coins,amount,coins.size() - 1) ;
        return ans == INT_MAX - 1 ? -1 : ans;
    }
};

//memo
class Solution {
    vector<vector<int>>dp;
    int getCoins(vector<int>&coins,int amount,int idx){
        if(idx < 0)return INT_MAX - 1;
        if(amount == 0)return 0;
        if(dp[idx][amount] != -1)return dp[idx][amount];
        int take = INT_MAX -1;
        if(amount >= coins[idx]){
            take =1 + getCoins(coins,amount - coins[idx],idx);
        }
        int ignore = getCoins(coins,amount,idx - 1);
        return dp[idx][amount] = min(take,ignore);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        dp.resize(coins.size(),vector<int>(amount+1,-1));
       int ans = getCoins(coins,amount,coins.size() - 1) ;
        return ans == INT_MAX - 1 ? -1 : ans;
    }
};

//iterative
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int dp[n+1][amount+1];
       
        for(int i=0; i<=amount; i++) dp[0][i] = INT_MAX - 1;
        for(int i=0; i<=n; i++) dp[i][0] = 0;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=amount;j++){
                if(coins[i-1] <= j){
                    dp[i][j] = min(dp[i-1][j],1+dp[i][j-coins[i-1]]);
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
    return dp[n][amount]==INT_MAX-1 ? -1 : dp[n][amount];
    }
};

//space optimized
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int dp[amount+1];
        dp[0] = 0;
        for(int i=1;i<=amount;i++){
            dp[i]=INT_MAX-1;
            for(int j=0;j<coins.size();j++){
                if(i-coins[j]>=0){
                    dp[i]=min(dp[i-coins[j]]+1,dp[i]);
                }
            }
        }
        return dp[amount]==INT_MAX-1 ? -1 : dp[amount];
    }
};

//time optimization
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int dp[amount+1];
        sort(coins.begin(),coins.end());
        dp[0] = 0;
        for(int i=1;i<=amount;i++){
            dp[i]=INT_MAX-1;
            for(int j=0;j<coins.size();j++){
                if(coins[j] > i)break;
                dp[i] = min(dp[i-coins[j]]+1,dp[i]);
            }
        }
        return dp[amount]==INT_MAX-1 ? -1 : dp[amount];
    }
};