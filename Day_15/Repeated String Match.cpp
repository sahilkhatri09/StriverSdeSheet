class Solution {
    bool robinKarp(string &src ,string &target){
        long long base = 1000000007;
        long long power = 1;
        int n = src.size();
        int m = target.size();
        
        for(int i = 0; i < m; i++){
            power = (power * 31) % base;
        }
        
        long long targetCode = 0;
        for(int i = 0;i < m; i++){
            targetCode = (targetCode * 31 + target[i]) % base;
        }
        
        long long hashCode = 0;
        for(int i = 0; i < n; i++){
            hashCode = (hashCode * 31 + src[i]) % base;
            if(i < m - 1) continue;
            else if(i >= m){
                hashCode = (hashCode - (src[i - m]) * power ) % base;
            }
            if(hashCode < 0)hashCode += base;
            if(hashCode == targetCode){
                return true;
            }
        }
        return false;
    }
public:
    int repeatedStringMatch(string a, string b) {
        int count = 0;
        string compare = a;
        while(compare.size() < b.size()){
            compare += a;
            count++;
        }
        if(robinKarp(compare , b) != false)return count + 1;
        compare += a;
        if(robinKarp(compare , b) != false)return count + 2;
        
        return -1;
    }
};