class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        vector<pair<double,int>>ratio;
        for(int i=0; i<n; i++){
            double val = (arr[i].value * 1.0) / arr[i].weight;
            ratio.push_back({ val,i });
        }
        sort(ratio.begin() , ratio.end());
        double ans = 0;
        for(int i=n-1; i>=0; i--){
            int curIdx = ratio[i].second;
            int curWeight = arr[curIdx].weight;
            double curValue = ratio[i].first;
            if(curWeight < W){
                ans += (curValue * curWeight) ;
                W = W - curWeight;
            }
            else {
                ans += ((1.0 * curValue) * W);
                break;
            }
        }
        return ans;
    }
        
};
