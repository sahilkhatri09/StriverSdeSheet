//recursive , backtracking
class Solution{
    vector<string>subStrings;
    void getSubstr(string &s,string &f,int idx){
       if(idx == s.size()){
           if(f=="")return;
           subStrings.push_back(f);
           return;
       }
       f += s[idx];
       getSubstr(s,f,idx+1);
       f.pop_back();
       getSubstr(s,f,idx+1);
    }
	public:
		vector<string> AllPossibleStrings(string s){
		    subStrings.clear();
		    string temp = "";
		    getSubstr(s,temp,0);
		    sort(subStrings.begin(),subStrings.end());
		    return subStrings;
		}
};

//bit 
class Solution{
	public:
		vector<string> AllPossibleStrings(string s){
		    vector<string>strings;
		    int n = s.size();
		    int totalStr = 1 << n;
		    for(int len = 1; len < totalStr; len++ ){
		        string temp = "";
		        for(int i = 0; i < n; i++){
		            int curIdx = 1<<i;
		            if(len & curIdx){
		                temp += s[i];
		            }
		        }
		        
		        strings.push_back(temp);
		    }
		    sort(strings.begin() , strings.end());
		    return strings;
		}
};