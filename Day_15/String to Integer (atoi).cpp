class Solution {
public:
    int myAtoi(string s) {
        int res = 0;
        bool positive = true;
        int i = 0;
        int n = s.size();
        
        while(i < n && s[i] == ' ')i++;
        if(i == n)return res;
        
        if(s[i] == '-'){
            positive = false;
            i++;
        }
        else if(s[i] == '+'){
            positive = true;
            i++;
        }
        
        while(i < n && s[i] >= '0' && s[i] <= '9'){
            int cur = s[i] - '0';
            if(positive){
                if(res > INT_MAX / 10 || (res == INT_MAX / 10 && cur >= INT_MAX % 10)){
                     return INT_MAX;
                }
            }
            else{
                if(res*-1 < INT_MIN / 10 || (res*-1 == INT_MIN / 10 && cur*-1 <= INT_MIN % 10)){
                    return INT_MIN;
                }
            }
            i++;
            res = res * 10 + cur;
        }
        if(! positive) return -1 * res;
        return res;
    }
};