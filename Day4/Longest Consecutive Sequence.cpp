class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
         unordered_set<int>s(nums.begin(),nums.end());
        int longestSeq = 0;
        
        for(int i=0; i<nums.size() ;i++){
            if(s.find(nums[i] - 1) != s.end()) continue;
            int j = 1;
            while(s.find(nums[i] + j) != s.end())j++;
            longestSeq = max(longestSeq , j);
        }
        return longestSeq;
    }
};