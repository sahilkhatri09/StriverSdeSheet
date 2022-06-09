// JAI SHRI RAM
// Sahil Khatri's Template

#include<iostream>
#include<vector>
#include<utility>
#include<unordered_set>
#include<unordered_map>
#include<string>
#include<stack>
#include<set>
#include<queue>
#include<map>
#include<climits>
#include<list>
#include<deque>
#include<cstring>
#include<bitset>
#include<algorithm>
using namespace std;

#define int long long
#define mod 1000000007

int dir[8][2] = {{+1, +0}, {-1, +0}, {+0, +1}, {+0, -1}, {-1, -1}, {+1, +1}, {+1, -1}, {-1, +1}};
bool isPossible(int stall[] , int c,int n,int dist){
     int pre = stall[0];
     int count = 1;
     for(int i=1; i<n; i++){
       if(stall[i] - pre >= dist){
         pre = stall[i];
         count++;
       }
     }
     if(count < c)return false;
     return true;
}
void solve(){
   int n,c;
   cin>>n>>c;
   int stall[n];
   int low = 0;
   int high =0;
   for(int i=0; i<n; i++){
     cin>>stall[i];
     high += stall[i];
   }
   sort(stall , stall + n);
    int ans = 0;
    while(low <= high){
      int mid = (high + low) / 2;
      bool possible = isPossible(stall,c,n,mid);
      if(possible){
        ans = mid;
        low = mid + 1;
      } 
      else{
        high = mid - 1;
      }
    }
    cout<<ans<<endl;

}
int32_t main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin>>t;
  while(t--)solve();
}