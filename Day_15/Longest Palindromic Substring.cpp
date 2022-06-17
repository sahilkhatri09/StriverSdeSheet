class Solution {
public:
    string longestPalindrome(string s) {
        int ans = 0;
        int n = s.size();
         int start = 0 , end = 0;
        for(int i = 0; i < n; i++){
            int left = i - 1;
            int right = i;
            while(left >= 0 && right < n && s[left] == s[right] ){
                left--;
                right++;
            }
            if(right - left - 1 > ans){
                ans = right - left - 1;
              start = left + 1;
              end = right;
            }
        }
        for(int i = 0; i < n; i++){
            int left = i - 1;
            int right = i + 1;
            while(left >=0 && right < n && s[left] == s[right]){
                left--;
                right++;
            }
             if(right - left > ans){
                ans = right - left;
              start = left + 1;
              end = right;
            }
        }
        return s.substr(start , end - start);
    }
};

// Approach 2
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        bool dp[n][n];
        int start = 0,l = 0;
        for(int g = 0; g < n; g++){
            for(int j = g , i = 0; j < n; j++ , i++){
              if(g == 0){
                  dp[i][j] = true;
                  
              }
              else if(g == 1){
                  if(s[i] == s[j]) dp[i][j] = true;
                  else dp[i][j] = false;
              }
              else{
                  if(dp[i + 1][j - 1] == false || s[i] != s[j]) dp[i][j] = false;
                  else dp[i][j] = true;
              }
              if(dp[i][j]){
                  start = i , l = g;
              }
            }
        }return s.substr(start , l + 1);
    }
};