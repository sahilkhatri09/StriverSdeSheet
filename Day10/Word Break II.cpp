#include<set>
vector<string>ans;
void helper(string temp,set<string> &us,int idx,string &s){
    if(idx == s.size()){
        ans.push_back(temp);
        return;
    }
    for(int i =idx ;i<s.size();i++){
      string  curString = s.substr(idx , i - idx + 1);
        if(us.find(curString) != us.end()){
            if(temp.size() == 0){
                helper(temp + curString,us,i+1,s);
            }
            else{
                helper(temp + " " + curString,us, i+1, s);
            }
        }
    }
}
vector<string> wordBreak(string &s, vector<string> &dictionary)
{    ans.clear();
    set<string> us(dictionary.begin(),dictionary.end());
     string temp ="";
    helper(temp,us,0,s);
    return ans;
}