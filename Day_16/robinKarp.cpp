class Solution {
public:
    int strStr(string haystack, string needle) {
        long long base = 1000000007;
        long long power = 1;
        int n = haystack.size();
        int m = needle.size();
        for(int i = 0; i < m; i++){
            power = (power * 31) % base;
        }
        
        long long targetCode = 0;
        for(int i = 0; i < m; i++){
            targetCode = (targetCode * 31 + needle[i]) % base;
        }
        long long hashCode = 0;
        for(int i = 0; i < n; i++){
            hashCode = (hashCode * 31 + haystack[i]) % base;
            if(i < m - 1)continue;
            if(i >= m) hashCode = (hashCode - haystack[i - m] * power) % base;
            if(hashCode < 0)hashCode += base;
            if(hashCode == targetCode) {
                return i - m + 1;
            }
        }
        return -1;
    }
};