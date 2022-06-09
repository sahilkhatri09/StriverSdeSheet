class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        unordered_map<int,int> mp;
        
        for(auto m : nums2){
            while(s.size() && m > s.top()){
                mp[s.top()] = m;
                s.pop();
            }
            s.push(m);
        }
        int n = nums1.size();
        vector<int>res(n , -1);
        
        for(int i=0; i<n; i++){
            if(mp.find(nums1[i]) != mp.end()){
                res[i] = mp[nums1[i]];
            }
        }
        return res;
    }
};