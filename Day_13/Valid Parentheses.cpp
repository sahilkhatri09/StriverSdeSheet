class Solution {
public:
    bool isValid(string s) {
        stack<char> ans;
        ans.push(s[0]);
        
        for(int i=1;i<s.size();i++){
        if(s[i] == '(' || s[i] == '[' || s[i] == '{') ans.push(s[i]);
        else if(ans.size() > 0 && s[i] == '}' && ans.top() == '{')ans.pop();
        else if(ans.size() > 0 && s[i] == ']' && ans.top() == '[')ans.pop();
        else if(ans.size() > 0 && s[i] == ')' && ans.top() == '(')ans.pop();
        else return false;
        }
        return ans.empty();
    }
};