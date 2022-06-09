void heapify(vector<int> &heap ,int i){
    int l = 2*i + 1;
    int r = 2*i + 2;
    int n = heap.size();
    int smallest = i;
    if(l < n && heap[l] < heap[smallest])smallest = l;
    if(r < n && heap[r] < heap[smallest])smallest = r;
    if(smallest != i){
        swap(heap[smallest] , heap[i]);
        heapify(heap , smallest);
    }
    
}

vector<int> minHeap(int n, vector<vector<int>>& q) {
    vector<int> ans;
    vector<int>heap;
       for(int i=0; i<q.size(); i++){
        int type = q[i][0];
        if(type == 0){
            int val;
            val = q[i][1];
            heap.push_back(val);
            int cur = heap.size()-1;
            int par = (cur - 1)/2;
            while(cur!=0 && heap[cur]<heap[par]){
                swap(heap[cur] , heap[par]);
                cur = par;
                par = (cur - 1) / 2;
            }
        }
        else{
            int last = heap.size()-1;
            ans.push_back(heap[0]);
            swap(heap[0] , heap[last]);
            heap.pop_back();
            heapify(heap , 0);
        }
    }
    return ans;
    
}

