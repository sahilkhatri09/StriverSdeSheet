class Solution {
public:
    int romanToInt(string s) {
        unordered_map< string , int > m;
        m["I"] = 1;
        m["V"] = 5;
        m["X"] = 10;
        m["L"] = 50;
        m["C"] = 100;
        m["D"] = 500;
        m["M"] = 1000;
        m["IV"] = 4;
        m["IX"] = 9;
        m["XL"] = 40;
        m["XC"] = 90;
        m["CD"] = 400;
        m["CM"] = 900;
        int ans = 0;
        string c = "";
        string d = "";
        for(int i = 0;i < s.size(); i++){
            c += s[i];
            int cur = m[c];
            
            int next = -1;
            if(i < s.size() - 1){
                d += s[i+1];
                next = m[d];
            }
            
            if(next > cur){
                 c += d;
                ans += m[c];
                i++;
            }
            else {
                ans += cur;
            }
            c = "";
            d = "";
        }
        return ans;
    }
};