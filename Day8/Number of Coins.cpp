	int minCoins(int coins[], int M, int V) 
	{ 
        vector<int> minCoin(V+1,INT_MAX-3);
        minCoin[0] = 0;
        for (int i=0; i<V+1; i++){
            for(int j=0; j<M; j++){
                int curVal = i - coins[j];
                if(curVal >=0){
                    minCoin[i] = min(minCoin[i] ,1 + minCoin[i-coins[j]]);
                }
            }
        }
        if(minCoin[V] == INT_MAX-3)return -1;
        return minCoin[V];
	} 