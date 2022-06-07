class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>m;
        vector<int>ans;
        for(int i=0; i<nums.size(); i++){
            int req=target-nums[i];
            if(m.find(req)==m.end()){
                m[nums[i]]=i;
            }
            else{
                ans.push_back(m[req]);
                ans.push_back(i);
                break;
            }
        }
        return ans;
    }
};