int findCelebrity(int n) {
    int a=0;
    for(int i=1;i<n;i++)if(knows(a,i))a=i;
    for(int i=0;i<n;i++){if(knows(a,i))return -1;}
    for(int i=0;i<n;i++)if(!knows(i,a)&&i!=a)return -1;
        return a;
}