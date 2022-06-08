class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int>factorials;
        vector<int> choice;
        int fact =1;
        factorials.push_back(1);
        for(int i = 1; i<= n; i++){
            fact = fact * i;
            factorials.push_back(fact);
            choice.push_back(i);
        }
        string ans = "";
        k--;
        while(n>0){
            int num = k/(factorials[n-1]);
            string a = to_string(choice[num]);
            ans+= a;
            choice.erase(choice.begin() + num );
            k = k - num*factorials[n-1];
            n--;
        }
        return ans;
    }
};