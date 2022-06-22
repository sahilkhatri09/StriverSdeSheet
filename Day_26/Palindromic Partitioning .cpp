//recursion
class Solution{
    bool isPalin(string &s){
        int i=0,j=s.size()-1;
        while(i<j){
            if(s[i] != s[j])return false;
            i++;j--;
        }
        return true;
    }
    int miniPartition(string &str,int idx){
        if(idx == str.size())return 0;
        int ans = INT_MAX;
        for(int i =idx;i<str.size();i++){
            string temp = str.substr(idx,i-idx+1);
            if(isPalin(temp)){
                ans = min(ans,1 + miniPartition(str,i+1));
            }
        }
        return ans;
    }
public:
    int palindromicPartition(string str)
    {
       return miniPartition(str,0)-1;
    }
};

//memo
class Solution{
    vector<int>dp;
    bool isPalin(string &s){
        int i=0,j=s.size()-1;
        while(i<j){
            if(s[i] != s[j])return false;
            i++;j--;
        }
        return true;
    }
    int miniPartition(string &str,int idx){
        if(idx == str.size())return 0;
        if(dp[idx] != -1)return dp[idx];
        int ans = INT_MAX;
        for(int i =idx;i<str.size();i++){
            string temp = str.substr(idx,i-idx+1);
            if(isPalin(temp)){
                ans = min(ans,1 + miniPartition(str,i+1));
            }
        }
        return dp[idx]=ans;
    }
public:
    int palindromicPartition(string str)
    {
        dp.resize(str.size(),-1);
       return miniPartition(str,0)-1;
    }
};

//iterative
class Solution{
    vector<int>dp;
    bool isPalin(string s){
        int i=0,j=s.size()-1;
        while(i<j){
            if(s[i] != s[j])return false;
            i++;j--;
        }
        return true;
    }
public:
    int palindromicPartition(string str)
    {
        int n = str.size();
       int dp[n+1];
       dp[0]=0;
       
       for(int i=1;i<=n;i++){
           dp[i]=INT_MAX;
           for(int j=0;j<i;j++){
               if(dp[j] != INT_MAX && isPalin(str.substr(j,i-j))){
                   dp[i] = min(dp[i],dp[j]+1);
               }
           }
       }
       return dp[n]-1;
    }
};