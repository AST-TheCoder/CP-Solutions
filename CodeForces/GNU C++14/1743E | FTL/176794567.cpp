#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
#define ll long long int
#define pb push_back
#define all(x) x.begin(),x.end()
#define Max 10000000000000000
 
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using min_heap=priority_queue<T, vector<T>, greater<T>>;
 
ll dp[5001][5001];
ll p1,t1,p2,t2,s;
 
ll solve(ll h,ll c){
 if(h<=0) return 0;
 if(dp[h][c]!=-1) return dp[h][c];
 dp[h][c]=Max;
 
 ll need=(c+1)*t1,pass=c*t1;
 ll shot2=need/t2-pass/t2;
 ll x=solve(h-(shot2*p2-shot2*s)-(p1-s),c+1)+t1;
 
 shot2=pass/t2;
 ll pass2=c*t1-shot2*t2;
 ll need2=t2-pass2;
 ll y=solve(h-(p1+p2-s),0)+max(need2,t1);
 
 return dp[h][c]=min(x,y);
}
 
int main()
{   
 
 ll h;
 cin>>p1>>t1>>p2>>t2>>h>>s;
 if(t1>t2){
  swap(p1,p2);
  swap(t1,t2);
 }
 memset(dp,-1,sizeof(dp));
 
 ll ans=solve(h,0);
 cout<<ans<<endl;
 
 return 0;
}