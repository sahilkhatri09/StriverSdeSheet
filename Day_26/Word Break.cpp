//recursive
class Solution
{
    bool getPossi(string &A,set<string>&s,int idx){
        if(idx == A.size())return true;
        for(int i=idx;i<A.size();i++){
            string temp = A.substr(idx,i-idx+1);
            if(s.find(temp) != s.end()){
                if(getPossi(A,s,i+1))return true;
            }
        }
        return false;
    }
public:
    int wordBreak(string A, vector<string> &B) {
        set<string> s(B.begin(),B.end());
        if(getPossi(A,s,0))return 1;
        return 0;
    }
};

//memo 
class Solution
{    vector<int>dp;
    bool getPossi(string &A,set<string>&s,int idx){
        if(idx == A.size())return true;
        if(dp[idx] != -1)return dp[idx];
        for(int i=idx;i<A.size();i++){
            string temp = A.substr(idx,i-idx+1);
            if(s.find(temp) != s.end()){
                if(getPossi(A,s,i+1))return dp[idx]=true;
            }
        }
        return dp[idx]=false;
    }
public:
    int wordBreak(string A, vector<string> &B) {
        set<string> s(B.begin(),B.end());
        dp.resize(A.size(),-1);
        if(getPossi(A,s,0))return 1;
        return 0;
    }
};

//iterative
class Solution
{  
public:
    int wordBreak(string A, vector<string> &B) {
        set<string> s(B.begin(),B.end());
        int n = A.size();
        bool dp[n+1];
        dp[0] = true;
       for(int i=1;i<=n;i++){
           dp[i] = false;
           for(int j=0;j<i;j++){
               if(dp[j] && s.find(A.substr(j,i-j)) != s.end()){
                   dp[i] = true;
                   break;
               }
           }
       }
       return dp[n];
    }
};
