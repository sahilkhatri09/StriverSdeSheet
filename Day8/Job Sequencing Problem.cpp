class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    static bool cmp(Job &A, Job &B){
        return A.profit> B.profit;
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr,arr+n,cmp);
        int maxdead = 0;
        for(int i=0; i<n; i++){
            maxdead = max(maxdead , arr[i].dead);
        }
        
        vector<bool> timeline(maxdead + 1,false);
        int jobs = 0;
        int profit = 0;
        for(int i=0; i<n; i++){
            int k = arr[i].dead;
            while(k>0 && timeline[k] == true)k--;
            if(k != 0){
                timeline[k] = true;
                jobs++;
                profit += arr[i].profit;
            }
        }
        return {jobs,profit};
    } 
};
