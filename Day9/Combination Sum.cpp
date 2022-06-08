class Solution {
public:
    vector<vector<int>> ans;
    void helper(vector<int> &temp,vector<int>&candidates,int &curSum ,int i,int &target){
        if(i == candidates.size() || curSum > target)return;
        if(curSum == target){
            ans.push_back(temp);
            return;
        }
        curSum += candidates[i];
        temp.push_back(candidates[i]);
        helper(temp , candidates , curSum , i, target);
        
        curSum -=candidates[i];
        temp.pop_back();
        helper(temp , candidates,curSum ,i+1, target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>temp;
        int curSum = 0;
        helper(temp,candidates,curSum,0,target);
        return ans;
    }
};