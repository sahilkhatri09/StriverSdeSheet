class Solution {
public:
    void getLps(vector<int> &lps , string &needle){
        int j = 0;
        int i = 1;
        int n = needle.size();
        while(i < n){
            if(needle[i] == needle[j]){
                lps[i] = j + 1;
                i++;
                j++;
            }
            else{
                if(j != 0){
                    j = lps[j - 1];
                }
                else{
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        
        vector<int>lps(m , 0);
        getLps(lps,needle);
        int i = 0 , j = 0;
        while(i < n && j < m){
            if(haystack[i] == needle[j]){
                i++;
                j++;
            }
            else{
                if(j != 0){
                    j = lps[j - 1];
                }
                else{
                    i++;
                }
            }
        }
        if(j == m) return i - m ;
        return -1;
    }
};