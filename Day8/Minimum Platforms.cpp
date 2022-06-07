 int findPlatform(int arr[], int dep[], int n)
    {
         vector<int>platform(2402,0);
         for(int i=0; i<n;i++){
             int in = arr[i];
             int out = dep[i]+1;// important
             platform[in]++;
             platform[out]--;
         }
         int minPlat = 0;
         int temp = 0;
         for(int i=0; i<2402; i++){
             temp = temp + platform[i];
             minPlat = max(minPlat , temp);
         }
         return minPlat;
    }
};

//Aproach 2
int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	sort(arr,arr + n);
    	sort(dep,dep + n);
    	int count = 1;
    	int i = 1;
    	int j = 0;
    	int ans = 1;
    	while(i<n && j<n){
    	    if(arr[i] <= dep[j]){
    	        count++;
    	        i++;
    	    }
    	    else{
    	        count--;
    	        j++;
    	    }
    	    ans = max(ans, count);
    	}
    	return ans;
    }