class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       vector< bool > visited(256 , false);
       int maxLen = 0;
       int j = 0;
        for(int i = 0; i < s.size(); i++){
            int curIdx = s[i];
            if(visited[curIdx] == true){
                while(visited[curIdx] == true){
                    visited[s[j]] = false;
                    j++;
                }
            }
            
            visited[curIdx] = true;
            maxLen = max(maxLen , i - j + 1);
        }
        return maxLen;
    }
};