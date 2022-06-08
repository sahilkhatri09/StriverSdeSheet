class Solution {
    vector<vector<int>>ans;
public:
    void helper(vector<int> &candidates,vector<int> &temp , int &curSum ,int idx,int &target){
       
        if(curSum == target) {
            ans.push_back(temp);
            return; }
        
        for(int i = idx;i<candidates.size(); i++){
            if(candidates[i] + curSum > target)continue;
            if( i>idx && candidates[i] == candidates[i-1])continue;
            curSum +=candidates[i];
            temp.push_back(candidates[i]);
            helper(candidates, temp,curSum,i+1,target);
            curSum -=candidates[i];
            temp.pop_back();
    
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int>temp;
        int curSum = 0;
        helper(candidates , temp, curSum, 0, target);
        return ans;
    }
};