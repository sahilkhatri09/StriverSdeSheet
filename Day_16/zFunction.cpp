class Solution {
    vector<int> zFunction(string &s) {
    int n = s.length();
    vector<int> z(n , 0);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);
        
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        
        if (i + z[i] - 1 > r)
            l = i;
            r = i + z[i] - 1;
    }
    return z;
}
public:
    int strStr(string haystack, string needle) {
        string temp = needle + "$" + haystack;
        vector<int> z = zFunction(temp);
        int n = needle.length();
        
        for(int i = 1; i < z.size(); i++){
            if(z[i] == n)return i - n - 1;
        }
        
        return -1;
    }
};