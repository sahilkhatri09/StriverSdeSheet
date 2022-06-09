#include <algorithm>
vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries){
	//	Write your coode here.
    sort(arr.begin(),arr.end());
    vector<int>ans;
    int temp = 0;
    for(int i=0; i<queries.size(); i++){
        int temp = -1 ;
        for(int j=0; j<arr.size(); j++){
            if(arr[j] > queries[i][1])break;
            temp = max(temp , queries[i][0]^arr[j]);
        }
        ans.push_back(temp);
    }
    return ans;
}