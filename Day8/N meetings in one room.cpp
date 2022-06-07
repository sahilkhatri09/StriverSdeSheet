int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int,int>>v;
        for(int i=0; i<n; i++){
            int stime = start[i];
            int etime = end[i];
            v.push_back({stime , etime});
        }
        
        sort(v.begin() , v.end());
        int preEnd = v[0].second;
        int meetings = 1;
        for(int i=1; i<n; i++){
            int stime = v[i].first;
            int etime = v[i].second;
            
            if(stime > preEnd){
                meetings++;
                preEnd = etime;
            }
            else if(etime < preEnd){
                preEnd = etime;
            }
            
        }
        return meetings;
    }