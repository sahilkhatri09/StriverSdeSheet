class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        int i = n - 1;
        string ans = "";
        
        while(i >= 0){
            while(i >= 0 && s[i] == ' ') i--;
            if(i == -1)break;
           
            int j = i;
            while(j >= 0 && s[j] != ' ')j--;
            
            if(ans != ""){
                ans += " ";
                ans += s.substr(j + 1 , i - j);
            }
            else{
                ans += s.substr(j + 1 , i - j);
            }
            
            i = j;
        }
        return ans;
    }
};