class Solution
{
public:
     vector<int>sumOfSubsets;
    void helper(vector<int> &arr , int i , int &curSum , int N){
        if(i == N){
            sumOfSubsets.push_back(curSum);
            return;
        }
        curSum+=arr[i];
        helper(arr,i+1,curSum,N);
        curSum-=arr[i];
        helper(arr,i+1,curSum,N);
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {   
        int curSum = 0;
        helper(arr,0,curSum,N);
        return sumOfSubsets;
    }
};