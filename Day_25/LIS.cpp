//Approach 1 Recursion 2^n , n
class Solution {
    int getLis(vector<int>&nums , int idx , int prev){
        if(idx >= nums.size())return 0;
        int take = 0;
        if(nums[idx] > prev){
            take = 1 + getLis(nums,idx + 1,nums[idx]);
        }
        int ignore = getLis(nums , idx + 1, prev);
        return max(take , ignore);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        return getLis(nums,0,INT_MIN);
    }
};

//Approach 2 Recursion + memo N^2 , N^2
class Solution {
    vector<vector<int>>dp;
    int getLis(vector<int>&nums , int idx , int prev){
        if(idx >= nums.size())return 0;
        
        if(dp[idx][prev + 1] != -1)return dp[idx][prev + 1];
        
        int take = 0;
        if(prev == -1|| nums[idx] > nums[prev]) take = 1 + getLis(nums,idx + 1,idx);
        int ignore = getLis(nums , idx + 1, prev);
        
        return dp[idx][prev + 1] = max(take , ignore);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n,vector<int>(n + 1,-1));
        return getLis(nums,0,-1);
    }
};

//Approach 3 Recursion + space optimize N^2 , N
class Solution {
    vector<int>dp;
    int getLis(vector<int>&nums , int idx , int prev){
        if(idx >= nums.size())return 0;
        
        if(dp[prev + 1] != -1)return dp[prev + 1];
        
        int take = 0;
        if(prev == -1|| nums[idx] > nums[prev]) take = 1 + getLis(nums,idx + 1,idx);
        int ignore = getLis(nums , idx + 1, prev);
        
    return dp[prev + 1] = max(take , ignore);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n,-1);
        return getLis(nums,0,-1);
    }
};

// Approach 4 iterative N^2 N
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;
        vector<int>dp(n,1);
        for(int i=0; i<nums.size(); i++){
            for(int j=0; j<i; j++){
                if(nums[i] > nums[j]){
                    dp[i] = max(dp[i],dp[j] + 1);
                    ans = max(ans,dp[i]);
                }
            }
        }
        return ans;
    }
};

//Approach 5 binary Search NLogn , N

class Solution {
    int getLower(int a , vector<int>&nums){
        int n = nums.size();
        int l = 0;
        int h = n -1;
        int ans = n - 1;
        while(l <= h){
            int mid = (l + h) / 2;
            if(nums[mid] >= a){
                ans = mid;
                h = mid - 1;
            }
            else l = mid + 1;
        }
    return ans;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> seq;
        seq.push_back(nums[0]);
        
        int n = nums.size();
        for(int i=1; i<n; i++){
            if(nums[i] > seq.back()){
                seq.push_back(nums[i]);
            }
            else{
                int idx = getLower(nums[i] , seq);
                seq[idx] = nums[i];
            }
        }
        return seq.size();
    }
};
