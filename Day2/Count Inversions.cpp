#include <bits/stdc++.h> 
long long merge(int left,int mid,int right,long long temp[],long long *arr){
    int i=left;
    int j= mid+1;
    int k= left;
    long long ans=0;
    while(i<=mid && j<=right){
        if(arr[i]<=arr[j]){
            temp[k++]=arr[i++];
        }
        else{
            temp[k++]=arr[j++];
            ans+=(mid-i+1);
        }
    }
    while(i<=mid)temp[k++]=arr[i++];
    while(j<=right)temp[k++]=arr[j++];
    for(int i=left;i<=right;i++){
        arr[i]=temp[i];
    }
    return ans;
}
long long mergeSort(int left,int right,long long temp[],long long *arr){
    long long ans =0;
       if(left<right){
           int mid = (right + left)/2;
          ans+= mergeSort( left, mid, temp,arr);
          ans+= mergeSort( mid +1, right , temp,arr);
          ans+= merge(left,mid,right,temp,arr);
       }
    return ans;
}
long long getInversions(long long *arr, int n){
    // Write your code here.
    long long  temp[n];
    return mergeSort(0,n-1,temp,arr);
}