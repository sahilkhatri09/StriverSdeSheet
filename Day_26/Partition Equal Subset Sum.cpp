//recursion
class Solution {
    bool getPart(vector<int>& nums,int idx, int sum){
        if(sum == 0)return true;
        if(idx < 0 || sum < 0) return false;
        return getPart(nums,idx-1,sum-nums[idx]) || getPart(nums,idx-1,sum);
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i=0; i<nums.size(); i++)sum += nums[i];
        if(sum%2 != 0)return false;
        return getPart(nums,nums.size() - 1,sum/2);
    }
};

//memo
class Solution {
    vector<vector<int>>dp;
    bool getPart(vector<int>& nums,int idx, int sum){
        if(sum == 0)return true;
        if(idx < 0 || sum < 0) return false;
        if(dp[sum][idx] != -1)return dp[sum][idx];
        return dp[sum][idx] = getPart(nums,idx-1,sum-nums[idx]) || getPart(nums,idx-1,sum);
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i=0; i<nums.size(); i++)sum += nums[i];
        if(sum%2 != 0)return false;
        dp.resize(sum+1,vector<int>(nums.size(),-1));
        return getPart(nums,nums.size() - 1,sum/2);
    }
};

//space optimize
class Solution {
   vector<int>dp;
    bool getPart(vector<int>& nums,int idx, int sum){
        if(sum == 0)return true;
        if(idx < 0 || sum < 0) return false;
        if(dp[sum] != -1)return dp[sum];
        return dp[sum] = getPart(nums,idx-1,sum-nums[idx]) || getPart(nums,idx-1,sum);
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i=0; i<nums.size(); i++)sum += nums[i];
        if(sum%2 != 0)return false;
        dp.resize(sum+1,-1);
        return getPart(nums,nums.size() - 1,sum/2);
    }
};

//iterative
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0; i<nums.size(); i++) sum += nums[i];
        if(sum%2 != 0) return false;
        
        sum/=2;
        bool dp[sum + 1];
        dp[0] = true;
        
        for(int i=1; i<=sum; i++)
            dp[i] = false;
        for(int i=0;i<nums.size();i++)
            for(int j=sum;j>=1;j--)
                if((j>=nums[i] && dp[j-nums[i]]))
                    dp[j]=true;
    
        return dp[sum];
    }
};