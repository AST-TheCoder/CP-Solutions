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
 
ll n,s;
ll mod=998244353;
ll bigmod(ll v,ll p){
 if(!p) return 1;
 if(p%2) return (v*bigmod(v,p-1))%mod;
 ll x=bigmod(v,p/2);
 return (x*x)%mod;
}
 
ll solve(ll k){
 if(k==s) return 0;
 
 ll z=s-k;
 ll o=s-k;
 ll ans=(n*(n-1))%mod;
 o=(2*o*z)%mod;
 ans=(ans*bigmod(o,mod-2))%mod;
 ans=(ans+solve(k+1))%mod;
 return ans;
}
 
int main()
{   
 
 ll t;
 cin>>t;
 
 while(t--){
  s=0;
  ll k=0;
  cin>>n;
  ll a[n+1];
 
  for(ll i=1;i<=n;i++){
   cin>>a[i];
   s+=a[i];
  }
 
  for(ll i=n;i>=n-s+1;i--){
   k+=a[i];
  }
  ll ans=solve(k);
  cout<<ans<<endl;
 }
 
 return 0;
}