class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        int n = strs.size();
        if(n == 1)return strs[0];
        
        for(int i = 0;i < strs[0].size(); i++){
            for(int j = 1;j < strs.size(); j++){
                if(strs[j].size() < i + 1){
                    return ans;
                }
                if(strs[j][i] != strs[0][i]){
                    return ans;
                }
            }
            ans += strs[0][i];
        }
        return ans;
    }
};

//Approach 2
class Solution {
public:
    string longestCommonPrefix(vector<string>& str) {
           int n = str.size();
        if(n==0) return "";
        
        string ans  = "";
        sort(begin(str), end(str));
        string a = str[0];
        string b = str[n-1];
        
        for(int i=0; i<a.size(); i++){
            if(a[i]==b[i]){
                ans = ans + a[i];
            }
            else{
                break;
            }
        }
        
        return ans;
    }
};