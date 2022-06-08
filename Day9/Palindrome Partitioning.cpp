class Solution {
    vector<vector<string>>ans;
public:
    bool isValid(string &s ,int start,int end){
        while(start < end){
            if(s[start] != s[end])return false;
            start++; end--;
        }
        return true;
    }
    void helper(vector<string> &temp, int idx ,string &s){
        if(idx == s.size()){ans.push_back(temp); return;}
        
        for(int i = idx; i<s.size(); i++){
            if(!isValid(s, idx, i)) continue;
            string t = s.substr(idx, i-idx+1);
            temp.push_back(t);
            helper(temp, i+1, s);
            temp.pop_back();
        }
        
    }
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        helper(temp, 0, s);
        return ans;
    }
};