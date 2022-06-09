double findNthRootOfM(int n, long long m) {

    double t=1.000000/n;
    double ans=pow(m,t);
    return ans;

}

//     approach 2
double expo(double num ,int n){
    if(n == 0)return 1.0;
    if(n == 0)return 0.0;
    if(n%2 == 0){
        double temp = expo(num , n/2);
        return temp*temp;
    }
    return num*(expo(num , n - 1));
}

double findNthRootOfM(int n, long long m) {
	double low = 1;
    double high = m;
    double diff = 1e-7;
    while((high - low) > diff){
        double mid = (high -low)/2.0 + low;
        double temp = expo ( mid , n);
        if(temp < m){
            low = mid;
        }
        else{
            high = mid;
        }
    }
    return low;
}

